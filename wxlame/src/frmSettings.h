/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef FRMLAMEOPTIONS_H
#define FRMLAMEOPTIONS_H

#include "ConfigBase.h"

//(*Headers(frmSettings)
#include <wx/spinctrl.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/radiobut.h>
#include <wx/panel.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
//*)

class frmSettings : public wxDialog {
public:

    frmSettings(wxWindow* parent, ConfigBase* configBase, wxWindowID id = wxID_ANY);
    virtual ~frmSettings();

    //(*Declarations(frmSettings)
    wxCheckBox* g_chkEnabledVBR;
    wxSpinCtrl* g_spcLowpassWidth;
    wxStaticText* g_lblBitrateVBR;
    wxPanel* Panel1;
    wxPanel* Panel6;
    wxRadioButton* g_optUseSameDir;
    wxCheckBox* g_chkEnforceMinBitrate;
    wxCheckBox* g_chkDisableVBRTag;
    wxSpinCtrl* g_spcAverageBitrateABR;
    wxStaticText* g_lblVBRQuality;
    wxButton* g_btnLameExecutable;
    wxButton* g_btnCancel;
    wxButton* g_btnOK;
    wxChoice* g_chcAlgorithmQualitySel;
    wxSpinCtrl* g_spcHighpassFreq;
    wxPanel* Panel2;
    wxSpinCtrl* g_spcVBRQuality;
    wxCheckBox* g_chkDeleteFiles;
    wxStaticText* g_lblBitrate;
    wxCheckBox* g_chkHighpass;
    wxPanel* Panel4;
    wxSpinCtrl* g_spcLowpassFreq;
    wxCheckBox* g_chkMarkNonOriginal;
    wxCheckBox* g_chkUseABR;
    wxChoice* g_chcResampling;
    wxSlider* g_sldBitrateVBR;
    wxStaticText* StaticText8;
    wxCheckBox* g_chkCrc;
    wxTextCtrl* g_txtLameExecutable;
    wxCheckBox* g_chkLowpassWidth;
    wxButton* g_btnOutputDirectory;
    wxStaticText* StaticText7;
    wxChoice* g_chcMode;
    wxSlider* g_sldBitrate;
    wxNotebook* Notebook1;
    wxCheckBox* g_chkMarkCopyright;
    wxRadioButton* g_optEnableOutDir;
    wxCheckBox* g_chkLowpass;
    wxCheckBox* g_chkEnforceISO;
    wxButton* g_btnDefault;
    wxTextCtrl* g_txtOutputDirectory;
    wxTextCtrl* g_txtCustomOptions;
    wxStaticText* g_lblABR;
    wxCheckBox* g_chkHighpassWidth;
    wxSpinCtrl* g_spcHighpassWidth;
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
    void setLabelsControls();

    ConfigBase *mp_configBase;

    DECLARE_EVENT_TABLE()
};

#endif
