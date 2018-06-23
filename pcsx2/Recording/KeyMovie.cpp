#include "PrecompiledHeader.h"

#include "MemoryTypes.h"
#include "Common.h"
#include "Counters.h"	// use"g_FrameCount"
#include "SaveState.h"	// create "SaveStateBase::keymovieFreeze()"
#include "AppSaveStates.h"	// use "States_GetCurrentSlot()"

#include "Recording/MovieControls.h"
#include "KeyMovie.h"

#include <vector>


KeyMovie g_KeyMovie;

//-----------------------------------------------
// Save or Load - Save frame number
// Save or load - �Ńt���[�����̕ۑ�
//-----------------------------------------------
void SaveStateBase::keymovieFreeze()
{
	FreezeTag("keymovie");
	Freeze(g_FrameCount);	// Somehow the function saved the frame successfully
							// Freeze�֐��łȂ���frame�̕ۑ������܂�������

	if (IsLoading()) {
		g_KeyMovieData.addUndoCount();
	}
}

//----------------------------------
// Main func for handling recording and inputting controller data
// Called by Sio.cpp::sioWriteController
//----------------------------------
void KeyMovie::ControllerInterrupt(u8 &data, u8 &port, u16 & bufCount, u8 buf[])
{
	// Only examine controllers 1 / 2
	if (port < 0 || 1 < port )
		return;

	//==========================
	// This appears to try to ensure that we are only paying attention
	// to the frames that matter, the ones that are reading from
	// the controller.
	//
	// See - Lilypad.cpp:1254
	// 0x42 is the magic number for the default read query
	//
	// NOTE: this appears to possibly break if you have logging enabled in LilyPad's config!
	//==========================
	if (bufCount == 1) {
		if (data == 0x42)
		{
			fInterruptFrame = true;
		}
		else {
			fInterruptFrame = false;
			return;
		}
	}
	else if ( bufCount == 2 ){
		// See - LilyPad.cpp:1255
		// 0x5A is always the second byte in the buffer
		// when the normal READ_DATA_AND_VIBRRATE (0x42)
		// query is executed, this looks like a sanity check
		if (buf[bufCount] != 0x5A) {
			fInterruptFrame = false;
			return;
		}
	}

	if (!fInterruptFrame)
		return;

	if (state == NONE)
		return;

	// We do not want to record or save the first two
	// bytes in the return from LilyPad
	if (bufCount < 3)
		return;

	//---------------
	// Read or Write
	//---------------
	const u8 &nowBuf = buf[bufCount];
	if (state == RECORD)
	{
		keyMovieData.updateFrameMax(g_FrameCount);
		keyMovieData.writeKeyBuf(g_FrameCount, port, bufCount - 3, nowBuf);
	}
	else if (state == REPLAY)
	{
		if (keyMovieData.getMaxFrame() <= g_FrameCount)
		{
			// Pause the emulation but the movie is not closed
			g_MovieControls.Pause();
			return;
		}
		u8 tmp = 0;
		if (keyMovieData.readKeyBuf(tmp, g_FrameCount, port, bufCount - 3)) {
			buf[bufCount] = tmp;
		}
	}
}


//----------------------------------
// stop
//----------------------------------
void KeyMovie::Stop() {
	state = NONE;
	if (keyMovieData.Close()) {
		tasConLog(L"[REC]: KeyMovie Recording Stopped.\n");
	}
}

//----------------------------------
// start
//----------------------------------
void KeyMovie::Start(wxString FileName,bool fReadOnly, VmStateBuffer* ss)
{
	g_MovieControls.Pause();
	Stop();

	if (fReadOnly)
	{
		if (!keyMovieData.Open(FileName, false)) {
			return;
		}
		if (!keyMovieData.readHeaderAndCheck()) {
			tasConLog(L"[REC]: This file is not a correct KeyMovie file.\n");
			keyMovieData.Close();
			return;
		}
		// cdrom
		if (!g_Conf->CurrentIso.IsEmpty())
		{
			if (Path::GetFilename(g_Conf->CurrentIso) != keyMovieData.getHeader().cdrom) {
				tasConLog(L"[REC]: Information on CD in Movie file is Different.\n");
			}
		}
		state = REPLAY;
		tasConLog(wxString::Format(L"[REC]: Replaying movie - [%s]\n",FileName));
		tasConLog(wxString::Format(L"MaxFrame: %d\n", keyMovieData.getMaxFrame()));
		tasConLog(wxString::Format(L"UndoCount: %d\n", keyMovieData.getUndoCount()));
	}
	else
	{
		// backup
		wxString bpfile = wxString::Format(L"%s_backup", FileName);
		if (wxCopyFile( FileName , bpfile, false)) {
			tasConLog(wxString::Format(L"[REC]: Created backup movie file - [%s]\n", bpfile));
		}
		// create
		if (!keyMovieData.Open(FileName, true, ss)) {
			return;
		}
		// cdrom
		if (!g_Conf->CurrentIso.IsEmpty())
		{
			keyMovieData.getHeader().setCdrom(Path::GetFilename(g_Conf->CurrentIso));
		}
		keyMovieData.writeHeader();
		keyMovieData.writeSavestate();

		state = RECORD;
		tasConLog(wxString::Format(L"[REC]: Started new recording - [%s]\n", FileName));
	}
	// In every case, we reset the g_FrameCount
	g_FrameCount = 0;
}

//----------------------------------
// shortcut key
//----------------------------------
void KeyMovie::RecordModeToggle()
{
	if (state == REPLAY) {
		state = RECORD;
		tasConLog("[REC]: Record mode ON.\n");
	}
	else if (state == RECORD) {
		state = REPLAY;
		tasConLog("[REC]: Replay mode ON.\n");
	}
}


