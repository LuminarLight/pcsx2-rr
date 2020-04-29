/*  PCSX2 - PS2 Emulator for PCs
 *  Copyright (C) 2002-2020  PCSX2 Dev Team
 *
 *  PCSX2 is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU Lesser General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  PCSX2 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with PCSX2.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#include "PrecompiledHeader.h"

#include <vector>

#include "AppSaveStates.h"
#include "AppGameDatabase.h"
#include "DebugTools/Debug.h"
#include "Counters.h"

#include "Recording/InputRecording.h"
#include "Recording/RecordingControls.h"

InputRecording g_InputRecording;

// Tag and save framecount along with savestate
void SaveStateBase::InputRecordingFreeze()
{
	FreezeTag("InputRecording");
	Freeze(g_FrameCount);

	if (g_FrameCount > 0 && IsLoading())
	{
		g_InputRecordingData.AddUndoCount();
	}
}

InputRecording::InputRecording()
{
	// NOTE - No multi-tap support, only two controllers
	for (int i = 0; i < 2; i++)
	{
		padData[i] = new PadData();
	}
}

void InputRecording::setVirtualPadPtr(VirtualPad *ptr, int port)
{
	virtualPads[port] = ptr;
}

// Main func for handling controller input data
// - Called by Sio.cpp::sioWriteController
void InputRecording::ControllerInterrupt(u8 &data, u8 &port, u16 &bufCount, u8 buf[])
{
	// NOTE - No Multi-Tap Support
	// Only examine controllers 1 / 2
	if (port != 0 && port != 1)
	{
		return;
	}

	/*
		This appears to try to ensure that we are only paying attention
		to the frames that matter, the ones that are reading from
		the controller.

		See - Lilypad.cpp::PADpoll - https://github.com/PCSX2/pcsx2/blob/v1.5.0-dev/plugins/LilyPad/LilyPad.cpp#L1193
		0x42 is the magic number for the default read query
	*/
	if (bufCount == 1)
	{
		fInterruptFrame = data == 0x42;
		if (!fInterruptFrame)
		{
			return;
		}
	}
	else if ( bufCount == 2 )
	{
		/*
			See - LilyPad.cpp::PADpoll - https://github.com/PCSX2/pcsx2/blob/v1.5.0-dev/plugins/LilyPad/LilyPad.cpp#L1194
			0x5A is always the second byte in the buffer
			when the normal READ_DATA_AND_VIBRRATE (0x42)
			query is executed, this looks like a sanity check
		*/
		if (buf[bufCount] != 0x5A)
		{
			fInterruptFrame = false;
			return;
		}
	}

	if (!fInterruptFrame
		// We do not want to record or save the first two
		// bytes in the data returned from LilyPad
		|| bufCount < 3)
	{
		return;
	}

	u8 &bufVal = buf[bufCount];
	const u16 bufIndex = bufCount - 3;

	// If we are replaying a movie, there should be NO modifications to the inputs
	// Grab the byte from the movie file and overwrite whatever the PAD is inputting
	if (state == INPUT_RECORDING_MODE_REPLAY)
	{
		if (InputRecordingData.GetMaxFrame() <= g_FrameCount)
		{
			// Pause the emulation but the movie is not closed
			g_RecordingControls.Pause();
			return;
		}
		u8 tmp = 0;
		if (InputRecordingData.ReadKeyBuf(tmp, g_FrameCount, port, bufIndex))
		{
			// Overwrite value originally provided by the PAD plugin
			bufVal = tmp;
			// Update controller data state for future VirtualPad / logging usage.
			padData[port]->UpdateControllerData(bufIndex, bufVal);
			if (virtualPads[port] != NULL && virtualPads[port]->IsShown())
			{
				virtualPads[port]->UpdateControllerData(bufIndex, padData[port]);
			}
		}
		return;
	}

	// Update controller data state for future VirtualPad / logging usage.
	padData[port]->UpdateControllerData(bufIndex, bufVal);

	if (virtualPads[port] != NULL && virtualPads[port]->IsShown())
	{
		// If the VirtualPad updated the PadData, we have to update the buffer
		// before committing it to the recording / sending it to the game
		if (virtualPads[port]->UpdateControllerData(bufIndex, padData[port]))
		{
			bufVal = padData[port]->PollControllerData(bufIndex);
		}
	}

	// If we have reached the end of the pad data, log it out
    if (bufIndex == PadData::END_INDEX_CONTROLLER_BUFFER) {
		padData[port]->LogPadData();
		if (virtualPads[port] != NULL && virtualPads[port]->IsShown())
		{
			virtualPads[port]->Redraw();
		}
	}

	// Finally, commit the byte to the movie file if we are recording
	if (state == INPUT_RECORDING_MODE_RECORD)
	{
		InputRecordingData.UpdateFrameMax(g_FrameCount);
		InputRecordingData.WriteKeyBuf(g_FrameCount, port, bufIndex, bufVal);
	}
}


// GUI Handler - Stop recording
void InputRecording::Stop()
{
	state = INPUT_RECORDING_MODE_NONE;
	if (InputRecordingData.Close())
	{
		recordingConLog(L"[REC]: InputRecording Recording Stopped.\n");
	}
}

// GUI Handler - Start recording
void InputRecording::Create(wxString FileName, bool fromSaveState, wxString authorName)
{
	g_RecordingControls.Pause();
	Stop();

	// create
	if (!InputRecordingData.Open(FileName, true, fromSaveState))
	{
		return;
	}
	// Set author name
	if (!authorName.IsEmpty())
	{
		InputRecordingData.GetHeader().SetAuthor(authorName);
	}
	// Set Game Name
	// Code loosely taken from AppCoreThread.cpp to resolve the Game Name
	// Fallback is ISO name
	wxString gameName;
	const wxString gameKey(SysGetDiscID());
	if (!gameKey.IsEmpty())
	{
		if (IGameDatabase* GameDB = AppHost_GetGameDatabase())
		{
			Game_Data game;
			if (GameDB->findGame(game, gameKey))
			{
				gameName = game.getString("Name");
				gameName += L" (" + game.getString("Region") + L")";
			}
		}
	}
	InputRecordingData.GetHeader().SetGameName(!gameName.IsEmpty() ? gameName : Path::GetFilename(g_Conf->CurrentIso));
	InputRecordingData.WriteHeader();
	state = INPUT_RECORDING_MODE_RECORD;
	recordingConLog(wxString::Format(L"[REC]: Started new recording - [%s]\n", FileName));

	// In every case, we reset the g_FrameCount
	g_FrameCount = 0;
}

// GUI Handler - Play a recording
void InputRecording::Play(wxString FileName, bool fromSaveState)
{
	g_RecordingControls.Pause();
	Stop();

	if (!InputRecordingData.Open(FileName, false, false))
	{
		return;
	}
	if (!InputRecordingData.ReadHeaderAndCheck())
	{
		recordingConLog(L"[REC]: This file is not a correct InputRecording file.\n");
		InputRecordingData.Close();
		return;
	}
	// Check author name
	if (!g_Conf->CurrentIso.IsEmpty())
	{
		if (Path::GetFilename(g_Conf->CurrentIso) != InputRecordingData.GetHeader().gameName)
		{
			recordingConLog(L"[REC]: Information on CD in Movie file is Different.\n");
		}
	}
	state = INPUT_RECORDING_MODE_REPLAY;
	recordingConLog(wxString::Format(L"[REC]: Replaying movie - [%s]\n", FileName));
	recordingConLog(wxString::Format(L"[REC]: Recording File Version: %d\n", InputRecordingData.GetHeader().version));
	recordingConLog(wxString::Format(L"[REC]: Associated Game Name / ISO Filename: %s\n", InputRecordingData.GetHeader().gameName));
	recordingConLog(wxString::Format(L"[REC]: Author: %s\n", InputRecordingData.GetHeader().author));
	recordingConLog(wxString::Format(L"[REC]: MaxFrame: %d\n", InputRecordingData.GetMaxFrame()));
	recordingConLog(wxString::Format(L"[REC]: UndoCount: %d\n", InputRecordingData.GetUndoCount()));
}

// Keybind Handler - Toggle between recording input and not
void InputRecording::RecordModeToggle()
{
	if (state == INPUT_RECORDING_MODE_REPLAY)
	{
		state = INPUT_RECORDING_MODE_RECORD;
		recordingConLog("[REC]: Record mode ON.\n");
	}
	else if (state == INPUT_RECORDING_MODE_RECORD)
	{
		state = INPUT_RECORDING_MODE_REPLAY;
		recordingConLog("[REC]: Replay mode ON.\n");
	}
}

INPUT_RECORDING_MODE InputRecording::GetModeState()
{
	return state;
}

InputRecordingFile & InputRecording::GetInputRecordingData()
{
	return InputRecordingData;
}

bool InputRecording::IsInterruptFrame()
{
	return fInterruptFrame;
}
