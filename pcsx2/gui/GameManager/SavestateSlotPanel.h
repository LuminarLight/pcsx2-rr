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

#pragma once

#include "AppConfig.h"

#include <wx/statbmp.h>
#include <wx/wx.h>

class SavestateSlotPanel : public wxPanel
{
public:
	SavestateSlotPanel(wxWindow* parent, AppConfig::GameManagerOptions& options, int slot, bool isBackup, wxDateTime updatedAt, bool isEmpty, bool isShown = true);

	void setTimestamp(wxDateTime updatedAt);
	void setIsEmpty(bool isEmpty);

	void unhighlightAndCollapse();
	void updateLabel();
	void updatePreview();
	void selectSlot(bool selected = true);

private:
	AppConfig::GameManagerOptions& options;

	const wxColour slotSelectedColour = wxColour(196, 238, 255);
	const wxColour slotSelectedColourDark = wxColour(0, 37, 51);
	const wxColour slotHighlightedColour = wxColour(77, 204, 255);
	const wxColour slotHighlightedColourDark = wxColour(0, 55, 77);

	bool useDarkColours = false;

	const int baseImageX = 133;
	const int baseImageY = 100;
	const int expandedPreviewScaleFactor = 2;

	const int slot = 0;
	const bool backup = false;
	bool slotSelected = false;
	bool expanded = false;
	wxDateTime updatedAt;
	bool isEmpty;

	void initComponents();
	void initPreview(bool update = false);
	void bindClickEvents(std::vector<wxWindow*> args);
	void panelItemClicked(wxMouseEvent& evt);
	void panelItemDoubleClicked(wxMouseEvent& evt);

	wxString getTimestamp();
	wxString getLabel(bool expandedVersion);

	/// Collapsed Widgets
	wxBoxSizer* collapsedSizer;
	wxStaticText* collapsedLabel;
	// wxWidgets doesn't allow for non-uniform border amounts, so we have to add a dummy element
	wxStaticText* collapsedBackupLeftPad;
	wxStaticBitmap* collapsedPreview;
	/// Expanded Widgets
	wxBoxSizer* expandedSizer;
	wxFlexGridSizer* expandedMetadataSizer;
	wxStaticText* expandedLabel;
	wxStaticText* expandedTimestamp;
	// wxWidgets doesn't allow for non-uniform border amounts, so we have to add a dummy element
	wxStaticText* expandedBackupLeftPad;
	wxStaticBitmap* expandedPreview;
};
