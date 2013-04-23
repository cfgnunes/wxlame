/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef FRMLAMEOPTIONS_H
#define FRMLAMEOPTIONS_H

#include "ConfigBase.h"

//(*Headers(frmSettings)
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/spinctrl.h>
#include <wx/radiobut.h>
#include <wx/slider.h>
#include <wx/panel.h>
#include <wx/filedlg.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dirdlg.h>
#include <wx/dialog.h>
//*)

class frmSettings : public wxDialog
{
public:

    frmSettings(wxWindow* parent, ConfigBase* configBase, wxWindowID id = wxID_ANY);
    virtual ~frmSettings();

    //(*Declarations(frmSettings)
    wxCheckBox* chkHighpass;
    wxChoice* chcMode;
    wxCheckBox* chkEnabledVBR;
    wxCheckBox* chkEnforceMinBitrate;
    wxSpinCtrl* spcAverageBitrateABR;
    wxTextCtrl* txtOutputDirectory;
    wxStaticText* lblBitrate;
    wxNotebook* Notebook1;
    wxChoice* chcResampling;
    wxPanel* Panel4;
    wxCheckBox* chkLowpassWidth;
    wxButton* btnCancel;
    wxButton* btnLameExecutable;
    wxButton* btnOutputDirectory;
    wxCheckBox* chkHighpassWidth;
    wxSlider* sldBitrate;
    wxCheckBox* chkEnforceISO;
    wxTextCtrl* txtCustomOptions;
    wxStaticText* StaticText8;
    wxChoice* chcAlgorithmQualitySel;
    wxPanel* Panel1;
    wxFileDialog* FileDialog1;
    wxButton* btnOK;
    wxPanel* Panel6;
    wxCheckBox* chkMarkCopyright;
    wxSpinCtrl* spcHighpassFreq;
    wxSpinCtrl* spcVBRQuality;
    wxCheckBox* chkDeleteFiles;
    wxStaticText* StaticText7;
    wxTextCtrl* txtLameExecutable;
    wxStaticText* lblBitrateVBR;
    wxDirDialog* DirDialog1;
    wxCheckBox* chkDisableVBRTag;
    wxStaticText* lblABR;
    wxCheckBox* chkLowpass;
    wxSpinCtrl* spcLowpassWidth;
    wxCheckBox* chkCrc;
    wxCheckBox* chkUseABR;
    wxPanel* Panel2;
    wxCheckBox* chkMarkNonOriginal;
    wxRadioButton* optUseSameDir;
    wxSpinCtrl* spcHighpassWidth;
    wxButton* btnDefault;
    wxSpinCtrl* spcLowpassFreq;
    wxRadioButton* optEnableOutDir;
    wxSlider* sldBitrateVBR;
    wxStaticText* lblVBRQuality;
    //*)

protected:

    //(*Identifiers(frmSettings)
    static const long ID_STATICTEXT2;
    static const long ID_SLIDER1;
    static const long ID_CHOICE4;
    static const long ID_TEXTCTRL2;
    static const long ID_BUTTON5;
    static const long ID_RADIOBUTTON1;
    static const long ID_RADIOBUTTON2;
    static const long ID_TEXTCTRL1;
    static const long ID_BUTTON3;
    static const long ID_CHECKBOX7;
    static const long ID_PANEL6;
    static const long ID_CHECKBOX4;
    static const long ID_STATICTEXT4;
    static const long ID_SLIDER2;
    static const long ID_CHECKBOX5;
    static const long ID_CHECKBOX6;
    static const long ID_CHECKBOX8;
    static const long ID_STATICTEXT3;
    static const long ID_SPINCTRL1;
    static const long ID_STATICTEXT5;
    static const long ID_SPINCTRL2;
    static const long ID_PANEL2;
    static const long ID_CHECKBOX2;
    static const long ID_CHECKBOX3;
    static const long ID_CHECKBOX1;
    static const long ID_CHECKBOX13;
    static const long ID_STATICTEXT7;
    static const long ID_CHOICE2;
    static const long ID_STATICTEXT8;
    static const long ID_TEXTCTRL3;
    static const long ID_PANEL1;
    static const long ID_CHOICE5;
    static const long ID_CHECKBOX15;
    static const long ID_SPINCTRL3;
    static const long ID_CHECKBOX16;
    static const long ID_SPINCTRL4;
    static const long ID_CHECKBOX17;
    static const long ID_SPINCTRL5;
    static const long ID_CHECKBOX18;
    static const long ID_SPINCTRL6;
    static const long ID_PANEL4;
    static const long ID_NOTEBOOK1;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_BUTTON4;
    //*)

private:

    //(*Handlers(frmSettings)
    void OnbtnOKClick(wxCommandEvent& event);
    void OnbtnCancelClick(wxCommandEvent& event);
    void OnoptCustomSelect(wxCommandEvent& event);
    void OnbtnDirectoryClick(wxCommandEvent& event);
    void OnsldBitrateCmdSliderUpdated(wxScrollEvent& event);
    void OnsldBitrateVBRCmdSliderUpdated(wxScrollEvent& event);
    void updateDisabledControlsEvent(wxCommandEvent& event);
    void OnbtnDefaultClick(wxCommandEvent& event);
    void OnbtnLameExecutableClick(wxCommandEvent& event);
    void OnbtnOutputDirectoryClick(wxCommandEvent& event);
    //*)

    void updateValueControls();
    void updateDisabledControls();
    void defaultValueControls();
    void saveValuesConfig();

    ConfigBase* configBase;
    DECLARE_EVENT_TABLE()
};

#endif
