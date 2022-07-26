///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Jan  3 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/listctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/toolbar.h>
#include <wx/timer.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/statbox.h>
#include <wx/choice.h>
#include <wx/radiobut.h>
#include <wx/filepicker.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/spinctrl.h>
#include <wx/textctrl.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/gauge.h>

///////////////////////////////////////////////////////////////////////////

#define ID_ADD_FOLDER 1000
#define ID_ADD_FILES 1001
#define ID_EXIT 1002
#define ID_REMOVE_FILES 1003
#define ID_CLEAR_LIST 1004
#define ID_SETTINGS 1005
#define ID_ENCODE 1006
#define ID_DECODE 1007
#define ID_WEBSITE 1008
#define ID_TOOL_WEBSITE 1009
#define ID_ABOUT 1010

///////////////////////////////////////////////////////////////////////////////
/// Class FrameMain
///////////////////////////////////////////////////////////////////////////////
class FrameMain : public wxFrame
{
	private:

	protected:
		wxListCtrl* gui_lstFiles;
		wxMenuBar* gui_mainMenuBar;
		wxMenu* gui_mnbFile;
		wxMenu* gui_mnbEdit;
		wxMenu* gui_mnbActions;
		wxMenu* gui_mnbHelp;
		wxStatusBar* gui_mainStatusBar;
		wxToolBar* gui_mainToolBar;
		wxToolBarToolBase* gui_tbAddFolder;
		wxToolBarToolBase* gui_tbAddFiles;
		wxToolBarToolBase* gui_tbRemoveFiles;
		wxToolBarToolBase* gui_tbClearList;
		wxToolBarToolBase* gui_tbEncode;
		wxToolBarToolBase* gui_tbDecode;
		wxToolBarToolBase* gui_tbSettings;
		wxToolBarToolBase* gui_tbAbout;
		wxMenu* gui_mainMenu;
		wxTimer m_timer1;

		// Virtual event handlers, overide them in your derived class
		virtual void OnlstFilesDeleteItem( wxListEvent& event ) { event.Skip(); }
		virtual void OnlstFilesInsertItem( wxListEvent& event ) { event.Skip(); }
		virtual void OnlstFilesItemSelect( wxListEvent& event ) { event.Skip(); }
		virtual void OnlstFilesItemRClick( wxListEvent& event ) { event.Skip(); }
		virtual void OnlstFilesKeyDown( wxListEvent& event ) { event.Skip(); }
		virtual void mnuAddDirectory( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuAddFiles( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuRemoveFiles( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuClearList( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuSettings( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuEncode( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuDecode( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuToolWebsite( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuWebsite( wxCommandEvent& event ) { event.Skip(); }
		virtual void mnuAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTimer1Trigger( wxTimerEvent& event ) { event.Skip(); }


	public:

		FrameMain( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 790,450 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~FrameMain();

		void FrameMainOnContextMenu( wxMouseEvent &event )
		{
		this->PopupMenu( gui_mainMenu, event.GetPosition() );
		}

};

///////////////////////////////////////////////////////////////////////////////
/// Class DialogSettings
///////////////////////////////////////////////////////////////////////////////
class DialogSettings : public wxDialog
{
	private:

	protected:
		wxStaticText* gui_lblBitrate;
		wxSlider* gui_sldBitrate;
		wxChoice* gui_chcMode;
		wxRadioButton* gui_optUseSameDir;
		wxRadioButton* gui_optEnableOutDir;
		wxDirPickerCtrl* gui_dpkOutputDirectory;
		wxCheckBox* gui_chkDeleteFiles;
		wxCheckBox* gui_chkEnabledVBR;
		wxStaticText* gui_lblBitrateVBR;
		wxSlider* gui_sldBitrateVBR;
		wxCheckBox* gui_chkDisableVBRTag;
		wxCheckBox* gui_chkEnforceMinBitrate;
		wxCheckBox* gui_chkUseABR;
		wxStaticText* gui_lblVBRQuality;
		wxSpinCtrl* gui_spcVBRQuality;
		wxStaticText* gui_lblABR;
		wxSpinCtrl* gui_spcAverageBitrateABR;
		wxChoice* gui_chcResampling;
		wxCheckBox* gui_chkHighpass;
		wxSpinCtrl* gui_spcHighpassFreq;
		wxCheckBox* gui_chkHighpassWidth;
		wxSpinCtrl* gui_spcHighpassWidth;
		wxCheckBox* gui_chkLowpass;
		wxSpinCtrl* gui_spcLowpassFreq;
		wxCheckBox* gui_chkLowpassWidth;
		wxSpinCtrl* gui_spcLowpassWidth;
		wxCheckBox* gui_chkMarkNonOriginal;
		wxCheckBox* gui_chkMarkCopyright;
		wxCheckBox* gui_chkCrc;
		wxCheckBox* gui_chkEnforceISO;
		wxStaticText* gui_lblQualitySelection;
		wxChoice* gui_chcAlgorithmQualitySel;
		wxCheckBox* gui_chkCustomOptions;
		wxTextCtrl* gui_txtCustomOptions;
		wxButton* gui_btnDefault;
		wxButton* gui_btnOK;
		wxButton* gui_btnCancel;

		// Virtual event handlers, overide them in your derived class
		virtual void OnsldBitrateCmdSliderUpdated( wxScrollEvent& event ) { event.Skip(); }
		virtual void updateDisabledControlsEvent( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnsldBitrateVBRCmdSliderUpdated( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnbtnDefaultClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnbtnOKClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnbtnCancelClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		DialogSettings( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~DialogSettings();

};

///////////////////////////////////////////////////////////////////////////////
/// Class DialogProgress
///////////////////////////////////////////////////////////////////////////////
class DialogProgress : public wxDialog
{
	private:

	protected:
		wxStaticText* gui_lblStatusList;
		wxGauge* gui_gaugeListProgress;
		wxStaticText* gui_lblStatusFile;
		wxGauge* gui_gaugeFileProgress;
		wxButton* gui_btnCancel;
		wxTimer m_timer2;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnIdle( wxIdleEvent& event ) { event.Skip(); }
		virtual void OnInit( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void OnbtnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTimer2Trigger( wxTimerEvent& event ) { event.Skip(); }


	public:

		DialogProgress( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Progress"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~DialogProgress();

};

