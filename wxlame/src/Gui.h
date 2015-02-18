///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  6 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
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
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/spinctrl.h>
#include <wx/notebook.h>
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
/// Class Main
///////////////////////////////////////////////////////////////////////////////
class Main : public wxFrame 
{
	private:
	
	protected:
		wxListCtrl* g_lstFiles;
		wxMenuBar* g_mainMenuBar;
		wxMenu* g_mnbFile;
		wxMenu* g_mnbEdit;
		wxMenu* g_mnbActions;
		wxMenu* g_mnbHelp;
		wxStatusBar* g_mainStatusBar;
		wxToolBar* g_mainToolBar;
		wxToolBarToolBase* g_tbAddFolder; 
		wxToolBarToolBase* g_tbAddFiles; 
		wxToolBarToolBase* g_tbRemoveFiles; 
		wxToolBarToolBase* g_tbClearList; 
		wxToolBarToolBase* g_tbEncode; 
		wxToolBarToolBase* g_tbDecode; 
		wxToolBarToolBase* g_tbSettings; 
		wxToolBarToolBase* g_tbAbout; 
		wxMenu* g_mainMenu;
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
		
		Main( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 770,450 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~Main();
		
		void MainOnContextMenu( wxMouseEvent &event )
		{
			this->PopupMenu( g_mainMenu, event.GetPosition() );
		}
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Settings
///////////////////////////////////////////////////////////////////////////////
class Settings : public wxDialog 
{
	private:
	
	protected:
		wxNotebook* m_notebook1;
		wxPanel* m_panel1;
		wxStaticText* g_lblBitrate;
		wxSlider* g_sldBitrate;
		wxChoice* g_chcMode;
		wxRadioButton* g_optUseSameDir;
		wxRadioButton* g_optEnableOutDir;
		wxTextCtrl* g_txtOutputDirectory;
		wxButton* g_btnOutputDirectory;
		wxCheckBox* g_chkDeleteFiles;
		wxPanel* m_panel2;
		wxCheckBox* g_chkEnabledVBR;
		wxStaticText* g_lblBitrateVBR;
		wxSlider* g_sldBitrateVBR;
		wxCheckBox* g_chkDisableVBRTag;
		wxCheckBox* g_chkEnforceMinBitrate;
		wxCheckBox* g_chkUseABR;
		wxStaticText* g_lblVBRQuality;
		wxSpinCtrl* g_spcVBRQuality;
		wxStaticText* g_lblABR;
		wxSpinCtrl* g_spcAverageBitrateABR;
		wxPanel* m_panel3;
		wxCheckBox* g_chkMarkNonOriginal;
		wxCheckBox* g_chkMarkCopyright;
		wxCheckBox* g_chkCrc;
		wxCheckBox* g_chkEnforceISO;
		wxStaticText* g_lblQualitySelection;
		wxChoice* g_chcAlgorithmQualitySel;
		wxStaticText* g_lblCustomOptions;
		wxTextCtrl* g_txtCustomOptions;
		wxPanel* m_panel4;
		wxChoice* g_chcResampling;
		wxCheckBox* g_chkHighpass;
		wxSpinCtrl* g_spcHighpassFreq;
		wxCheckBox* g_chkHighpassWidth;
		wxSpinCtrl* g_spcHighpassWidth;
		wxCheckBox* g_chkLowpass;
		wxSpinCtrl* g_spcLowpassFreq;
		wxCheckBox* g_chkLowpassWidth;
		wxSpinCtrl* g_spcLowpassWidth;
		wxButton* g_btnDefault;
		wxButton* g_btnOK;
		wxButton* g_btnCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnsldBitrateCmdSliderUpdated( wxScrollEvent& event ) { event.Skip(); }
		virtual void updateDisabledControlsEvent( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnbtnOutputDirectoryClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnsldBitrateVBRCmdSliderUpdated( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnbtnDefaultClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnbtnOKClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnbtnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		Settings( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~Settings();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Progress
///////////////////////////////////////////////////////////////////////////////
class Progress : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* g_lblStatusList;
		wxGauge* g_gaugeListProgress;
		wxStaticText* g_lblStatusFile;
		wxGauge* g_gaugeFileProgress;
		wxButton* g_btnCancel;
		wxTimer m_timer2;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnIdle( wxIdleEvent& event ) { event.Skip(); }
		virtual void OnInit( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void OnbtnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTimer2Trigger( wxTimerEvent& event ) { event.Skip(); }
		
	
	public:
		
		Progress( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Progress"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~Progress();
	
};

#endif //__GUI_H__
