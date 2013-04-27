/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "frmSettings.h"
#include "Global.h"

//(*InternalHeaders(frmSettings)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(frmSettings)
const long frmSettings::ID_STATICTEXT2 = wxNewId();
const long frmSettings::ID_SLIDER1 = wxNewId();
const long frmSettings::ID_CHOICE4 = wxNewId();
const long frmSettings::ID_TEXTCTRL2 = wxNewId();
const long frmSettings::ID_BUTTON5 = wxNewId();
const long frmSettings::ID_RADIOBUTTON1 = wxNewId();
const long frmSettings::ID_RADIOBUTTON2 = wxNewId();
const long frmSettings::ID_TEXTCTRL1 = wxNewId();
const long frmSettings::ID_BUTTON3 = wxNewId();
const long frmSettings::ID_CHECKBOX7 = wxNewId();
const long frmSettings::ID_PANEL6 = wxNewId();
const long frmSettings::ID_CHECKBOX4 = wxNewId();
const long frmSettings::ID_STATICTEXT4 = wxNewId();
const long frmSettings::ID_SLIDER2 = wxNewId();
const long frmSettings::ID_CHECKBOX5 = wxNewId();
const long frmSettings::ID_CHECKBOX6 = wxNewId();
const long frmSettings::ID_CHECKBOX8 = wxNewId();
const long frmSettings::ID_STATICTEXT3 = wxNewId();
const long frmSettings::ID_SPINCTRL1 = wxNewId();
const long frmSettings::ID_STATICTEXT5 = wxNewId();
const long frmSettings::ID_SPINCTRL2 = wxNewId();
const long frmSettings::ID_PANEL2 = wxNewId();
const long frmSettings::ID_CHECKBOX2 = wxNewId();
const long frmSettings::ID_CHECKBOX3 = wxNewId();
const long frmSettings::ID_CHECKBOX1 = wxNewId();
const long frmSettings::ID_CHECKBOX13 = wxNewId();
const long frmSettings::ID_STATICTEXT7 = wxNewId();
const long frmSettings::ID_CHOICE2 = wxNewId();
const long frmSettings::ID_STATICTEXT8 = wxNewId();
const long frmSettings::ID_TEXTCTRL3 = wxNewId();
const long frmSettings::ID_PANEL1 = wxNewId();
const long frmSettings::ID_CHOICE5 = wxNewId();
const long frmSettings::ID_CHECKBOX15 = wxNewId();
const long frmSettings::ID_SPINCTRL3 = wxNewId();
const long frmSettings::ID_CHECKBOX16 = wxNewId();
const long frmSettings::ID_SPINCTRL4 = wxNewId();
const long frmSettings::ID_CHECKBOX17 = wxNewId();
const long frmSettings::ID_SPINCTRL5 = wxNewId();
const long frmSettings::ID_CHECKBOX18 = wxNewId();
const long frmSettings::ID_SPINCTRL6 = wxNewId();
const long frmSettings::ID_PANEL4 = wxNewId();
const long frmSettings::ID_NOTEBOOK1 = wxNewId();
const long frmSettings::ID_BUTTON1 = wxNewId();
const long frmSettings::ID_BUTTON2 = wxNewId();
const long frmSettings::ID_BUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(frmSettings, wxDialog)
//(*EventTable(frmSettings)
//*)
END_EVENT_TABLE()

frmSettings::frmSettings(wxWindow* parent, ConfigBase* configBase, wxWindowID id)
: configBase(configBase)
{
    //(*Initialize(frmSettings)
    wxStaticBoxSizer* StaticBoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer10;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer7;
    wxBoxSizer* BoxSizer10;
    wxStaticBoxSizer* StaticBoxSizer12;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer13;
    wxBoxSizer* BoxSizer2;
    wxFlexGridSizer* FlexGridSizer4;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer13;
    wxFlexGridSizer* FlexGridSizer3;
    wxStaticBoxSizer* StaticBoxSizer8;
    wxBoxSizer* BoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer9;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer6;
    wxBoxSizer* BoxSizer8;
    wxStaticBoxSizer* StaticBoxSizer14;
    wxBoxSizer* BoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer11;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, _("Settings"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
    Panel6 = new wxPanel(Notebook1, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel6, _("Bitrate"));
    lblBitrate = new wxStaticText(Panel6, ID_STATICTEXT2, _("Current bitrate:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticBoxSizer1->Add(lblBitrate, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    sldBitrate = new wxSlider(Panel6, ID_SLIDER1, 0, 0, 0, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_SELRANGE, wxDefaultValidator, _T("ID_SLIDER1"));
    StaticBoxSizer1->Add(sldBitrate, 0, wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BoxSizer4->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxVERTICAL, Panel6, _("Mode"));
    chcMode = new wxChoice(Panel6, ID_CHOICE4, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
    chcMode->Append(_("default"));
    chcMode->Append(_("joint"));
    chcMode->Append(_("simple"));
    chcMode->Append(_("force"));
    chcMode->Append(_("dual-mono"));
    chcMode->Append(_("mono"));
    StaticBoxSizer4->Add(chcMode, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BoxSizer4->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer4, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel6, _("LAME executable"));
    txtLameExecutable = new wxTextCtrl(Panel6, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticBoxSizer2->Add(txtLameExecutable, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    btnLameExecutable = new wxButton(Panel6, ID_BUTTON5, wxEmptyString, wxDefaultPosition, wxSize(22,22), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    StaticBoxSizer2->Add(btnLameExecutable, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(StaticBoxSizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, Panel6, _("Output directory"));
    optUseSameDir = new wxRadioButton(Panel6, ID_RADIOBUTTON1, _("Same as input directory"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    StaticBoxSizer3->Add(optUseSameDir, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 2);
    optEnableOutDir = new wxRadioButton(Panel6, ID_RADIOBUTTON2, _("Use below:"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    StaticBoxSizer3->Add(optEnableOutDir, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 2);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    txtOutputDirectory = new wxTextCtrl(Panel6, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer2->Add(txtOutputDirectory, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    btnOutputDirectory = new wxButton(Panel6, ID_BUTTON3, wxEmptyString, wxDefaultPosition, wxSize(22,21), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer2->Add(btnOutputDirectory, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3->Add(BoxSizer2, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(StaticBoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer8 = new wxStaticBoxSizer(wxHORIZONTAL, Panel6, _("Filing"));
    chkDeleteFiles = new wxCheckBox(Panel6, ID_CHECKBOX7, _("Delete source file after processing"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX7"));
    chkDeleteFiles->SetValue(false);
    StaticBoxSizer8->Add(chkDeleteFiles, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 2);
    BoxSizer3->Add(StaticBoxSizer8, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel6->SetSizer(BoxSizer3);
    BoxSizer3->Fit(Panel6);
    BoxSizer3->SetSizeHints(Panel6);
    Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer6 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer10 = new wxStaticBoxSizer(wxHORIZONTAL, Panel2, _("VBR"));
    chkEnabledVBR = new wxCheckBox(Panel2, ID_CHECKBOX4, _("Enable Variable Bitrate (VBR)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
    chkEnabledVBR->SetValue(false);
    StaticBoxSizer10->Add(chkEnabledVBR, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 2);
    BoxSizer6->Add(StaticBoxSizer10, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer9 = new wxStaticBoxSizer(wxVERTICAL, Panel2, _("Maximum VBR bitrate"));
    lblBitrateVBR = new wxStaticText(Panel2, ID_STATICTEXT4, _("Current bitrate:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticBoxSizer9->Add(lblBitrateVBR, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    sldBitrateVBR = new wxSlider(Panel2, ID_SLIDER2, 0, 0, 0, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_SELRANGE, wxDefaultValidator, _T("ID_SLIDER2"));
    StaticBoxSizer9->Add(sldBitrateVBR, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7->Add(StaticBoxSizer9, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6->Add(BoxSizer7, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer11 = new wxStaticBoxSizer(wxVERTICAL, Panel2, _("Others"));
    chkDisableVBRTag = new wxCheckBox(Panel2, ID_CHECKBOX5, _("Disable writing of VBR Tag"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
    chkDisableVBRTag->SetValue(false);
    StaticBoxSizer11->Add(chkDisableVBRTag, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 2);
    chkEnforceMinBitrate = new wxCheckBox(Panel2, ID_CHECKBOX6, _("Strictly enforce minimum bitrate"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX6"));
    chkEnforceMinBitrate->SetValue(false);
    StaticBoxSizer11->Add(chkEnforceMinBitrate, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 2);
    chkUseABR = new wxCheckBox(Panel2, ID_CHECKBOX8, _("Use ABR instead VBR"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX8"));
    chkUseABR->SetValue(false);
    StaticBoxSizer11->Add(chkUseABR, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 2);
    FlexGridSizer4 = new wxFlexGridSizer(2, 2, 0, 0);
    lblVBRQuality = new wxStaticText(Panel2, ID_STATICTEXT3, _("Quality of VBR encoding:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer4->Add(lblVBRQuality, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    spcVBRQuality = new wxSpinCtrl(Panel2, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 9, 0, _T("ID_SPINCTRL1"));
    spcVBRQuality->SetValue(_T("0"));
    FlexGridSizer4->Add(spcVBRQuality, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    lblABR = new wxStaticText(Panel2, ID_STATICTEXT5, _("Average bitrate encoding ABR:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer4->Add(lblABR, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    spcAverageBitrateABR = new wxSpinCtrl(Panel2, ID_SPINCTRL2, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 8, 320, 0, _T("ID_SPINCTRL2"));
    spcAverageBitrateABR->SetValue(_T("0"));
    FlexGridSizer4->Add(spcAverageBitrateABR, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer11->Add(FlexGridSizer4, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8->Add(StaticBoxSizer11, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6->Add(BoxSizer8, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel2->SetSizer(BoxSizer6);
    BoxSizer6->Fit(Panel2);
    BoxSizer6->SetSizeHints(Panel2);
    Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer7 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Flags"));
    chkMarkNonOriginal = new wxCheckBox(Panel1, ID_CHECKBOX2, _("Mark as non-original"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    chkMarkNonOriginal->SetValue(false);
    StaticBoxSizer7->Add(chkMarkNonOriginal, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 2);
    chkMarkCopyright = new wxCheckBox(Panel1, ID_CHECKBOX3, _("Mark as copyright"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    chkMarkCopyright->SetValue(false);
    StaticBoxSizer7->Add(chkMarkCopyright, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 2);
    chkCrc = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Include CRC error detection"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    chkCrc->SetValue(false);
    StaticBoxSizer7->Add(chkCrc, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 2);
    chkEnforceISO = new wxCheckBox(Panel1, ID_CHECKBOX13, _("Comply as much as possible to ISO MPEG spec"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX13"));
    chkEnforceISO->SetValue(false);
    StaticBoxSizer7->Add(chkEnforceISO, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 2);
    BoxSizer5->Add(StaticBoxSizer7, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Options"));
    FlexGridSizer1 = new wxFlexGridSizer(2, 2, 0, 0);
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("Algorithm quality selection:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    FlexGridSizer1->Add(StaticText7, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    chcAlgorithmQualitySel = new wxChoice(Panel1, ID_CHOICE2, wxDefaultPosition, wxSize(200,-1), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    FlexGridSizer1->Add(chcAlgorithmQualitySel, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _("Custom options:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    FlexGridSizer1->Add(StaticText8, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    txtCustomOptions = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer1->Add(txtCustomOptions, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer6->Add(FlexGridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5->Add(StaticBoxSizer6, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer5);
    BoxSizer5->Fit(Panel1);
    BoxSizer5->SetSizeHints(Panel1);
    Panel4 = new wxPanel(Notebook1, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    BoxSizer13 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer12 = new wxStaticBoxSizer(wxHORIZONTAL, Panel4, _("Output sampling frequency"));
    chcResampling = new wxChoice(Panel4, ID_CHOICE5, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE5"));
    StaticBoxSizer12->Add(chcResampling, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer13->Add(StaticBoxSizer12, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer13 = new wxStaticBoxSizer(wxHORIZONTAL, Panel4, _("Highpass filter"));
    FlexGridSizer2 = new wxFlexGridSizer(2, 2, 0, 0);
    chkHighpass = new wxCheckBox(Panel4, ID_CHECKBOX15, _("Highpass filtering frequency (in Hz):"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX15"));
    chkHighpass->SetValue(false);
    FlexGridSizer2->Add(chkHighpass, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
    spcHighpassFreq = new wxSpinCtrl(Panel4, ID_SPINCTRL3, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 50, 50000, 0, _T("ID_SPINCTRL3"));
    spcHighpassFreq->SetValue(_T("0"));
    FlexGridSizer2->Add(spcHighpassFreq, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    chkHighpassWidth = new wxCheckBox(Panel4, ID_CHECKBOX16, _("Width of Highpass filter (in Hz):"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX16"));
    chkHighpassWidth->SetValue(false);
    FlexGridSizer2->Add(chkHighpassWidth, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
    spcHighpassWidth = new wxSpinCtrl(Panel4, ID_SPINCTRL4, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 50, 50000, 0, _T("ID_SPINCTRL4"));
    spcHighpassWidth->SetValue(_T("0"));
    FlexGridSizer2->Add(spcHighpassWidth, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer13->Add(FlexGridSizer2, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer13->Add(StaticBoxSizer13, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer14 = new wxStaticBoxSizer(wxHORIZONTAL, Panel4, _("Lowpass filter"));
    FlexGridSizer3 = new wxFlexGridSizer(2, 2, 0, 0);
    chkLowpass = new wxCheckBox(Panel4, ID_CHECKBOX17, _("Lowpass filtering frequency (in Hz):"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX17"));
    chkLowpass->SetValue(false);
    FlexGridSizer3->Add(chkLowpass, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
    spcLowpassFreq = new wxSpinCtrl(Panel4, ID_SPINCTRL5, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 50, 50000, 0, _T("ID_SPINCTRL5"));
    spcLowpassFreq->SetValue(_T("0"));
    FlexGridSizer3->Add(spcLowpassFreq, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    chkLowpassWidth = new wxCheckBox(Panel4, ID_CHECKBOX18, _("Width of Lowpass filter (in Hz):"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX18"));
    chkLowpassWidth->SetValue(false);
    FlexGridSizer3->Add(chkLowpassWidth, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
    spcLowpassWidth = new wxSpinCtrl(Panel4, ID_SPINCTRL6, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 50, 50000, 0, _T("ID_SPINCTRL6"));
    spcLowpassWidth->SetValue(_T("0"));
    FlexGridSizer3->Add(spcLowpassWidth, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer14->Add(FlexGridSizer3, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer13->Add(StaticBoxSizer14, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel4->SetSizer(BoxSizer13);
    BoxSizer13->Fit(Panel4);
    BoxSizer13->SetSizeHints(Panel4);
    Notebook1->AddPage(Panel6, _("General"), false);
    Notebook1->AddPage(Panel2, _("VBR"), false);
    Notebook1->AddPage(Panel1, _("Advanced"), false);
    Notebook1->AddPage(Panel4, _("Audio processing"), false);
    BoxSizer1->Add(Notebook1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
    btnDefault = new wxButton(this, ID_BUTTON1, _("Restore defaults"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer10->Add(btnDefault, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnOK = new wxButton(this, ID_BUTTON2, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer10->Add(btnOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnCancel = new wxButton(this, ID_BUTTON4, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer10->Add(btnCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer10, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    DirDialog1 = new wxDirDialog(this, _("Select directory"), wxEmptyString, wxDD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxDirDialog"));
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE|wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_SLIDER1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&frmSettings::OnsldBitrateCmdSliderUpdated);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&frmSettings::OnbtnLameExecutableClick);
    Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&frmSettings::updateDisabledControlsEvent);
    Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&frmSettings::updateDisabledControlsEvent);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&frmSettings::OnbtnOutputDirectoryClick);
    Connect(ID_CHECKBOX4,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&frmSettings::updateDisabledControlsEvent);
    Connect(ID_SLIDER2,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&frmSettings::OnsldBitrateVBRCmdSliderUpdated);
    Connect(ID_CHECKBOX8,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&frmSettings::updateDisabledControlsEvent);
    Connect(ID_CHECKBOX15,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&frmSettings::updateDisabledControlsEvent);
    Connect(ID_CHECKBOX16,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&frmSettings::updateDisabledControlsEvent);
    Connect(ID_CHECKBOX17,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&frmSettings::updateDisabledControlsEvent);
    Connect(ID_CHECKBOX18,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&frmSettings::updateDisabledControlsEvent);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&frmSettings::OnbtnDefaultClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&frmSettings::OnbtnOKClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&frmSettings::OnbtnCancelClick);
    //*)

    // Sets the size of the sliders
    sldBitrate->SetMax(BITRATE_VALUES_SIZE - 1);
    sldBitrateVBR->SetMax(BITRATE_VALUES_SIZE - 1);

    // Set labels of controls
    setLabelsControls();

    // Updates the values controls according to the configuration file
    updateValueControls();

    // Updates the controls that should be disabled
    updateDisabledControls();
}

frmSettings::~frmSettings()
{
    //(*Destroy(frmSettings)
    //*)
}

void frmSettings::OnbtnOKClick(wxCommandEvent& event)
{
    saveValuesConfig();
    Close();
}

void frmSettings::OnbtnCancelClick(wxCommandEvent& event)
{
    Close();
}

void frmSettings::OnbtnDefaultClick(wxCommandEvent& event)
{
    defaultValueControls();
    updateDisabledControls();
}

void frmSettings::OnsldBitrateCmdSliderUpdated(wxScrollEvent& event)
{
    int number = sldBitrate->GetValue();
    lblBitrate->SetLabel(_("Current bitrate:") + wxString::Format(_T(" %i"), BITRATE_VALUES[number]) + _T(" kbit"));
}

void frmSettings::OnsldBitrateVBRCmdSliderUpdated(wxScrollEvent& event)
{
    int number = sldBitrateVBR->GetValue();
    lblBitrateVBR->SetLabel(_("Current bitrate:") + wxString::Format(_T(" %i"), BITRATE_VALUES[number]) + _T(" kbit"));
}

void frmSettings::updateDisabledControlsEvent(wxCommandEvent& event)
{
    updateDisabledControls();
}

void frmSettings::OnbtnLameExecutableClick(wxCommandEvent& event)
{
    if (FileDialog1->ShowModal() == wxID_OK)
    {
        txtLameExecutable->Clear();
        txtLameExecutable->WriteText(FileDialog1->GetPath());
    }
}

void frmSettings::OnbtnOutputDirectoryClick(wxCommandEvent& event)
{
    if (DirDialog1->ShowModal() == wxID_OK)
    {
        txtOutputDirectory->Clear();
        txtOutputDirectory->WriteText(DirDialog1->GetPath());
    }
}

void frmSettings::updateValueControls()
{
    int i;
    wxScrollEvent evt;

    // General controls
    for (i = 0; BITRATE_VALUES[i] != configBase->getBitrate(); i++);
    sldBitrate->SetValue(i);
    OnsldBitrateCmdSliderUpdated(evt);
    txtOutputDirectory->Clear();
    txtOutputDirectory->WriteText(configBase->getOutDir());
    optEnableOutDir->SetValue(configBase->getEnableOutDir());
    optUseSameDir->SetValue(!configBase->getEnableOutDir());
    chcMode->SetSelection(configBase->getMode());
    txtLameExecutable->Clear();
    txtLameExecutable->WriteText(configBase->getEncoderExecutable());

    // Advanced controls
    chkCrc->SetValue(configBase->getCrc());
    chkDeleteFiles->SetValue(configBase->getDeleteFiles());
    chkMarkNonOriginal->SetValue(configBase->getMarkNonOriginal());
    chkMarkCopyright->SetValue(configBase->getMarkCopyright());

    // VBR controls
    chkEnabledVBR->SetValue(configBase->getEnabledVBR());
    spcVBRQuality->SetValue(configBase->getVBRQuality());
    for (i = 0; BITRATE_VALUES[i] != configBase->getMaxBitrate(); i++);
    sldBitrateVBR->SetValue(i);
    OnsldBitrateVBRCmdSliderUpdated(evt);
    chkDisableVBRTag->SetValue(configBase->getDisableVBRTag());
    chkEnforceMinBitrate->SetValue(configBase->getEnforceMinBitrate());
    chkUseABR->SetValue(configBase->getUseABR());
    spcAverageBitrateABR->SetValue(configBase->getAverageBitrateABR());

    // Expert controls
    chkEnforceISO->SetValue(configBase->getEnforceISO());
    chcAlgorithmQualitySel->SetSelection(configBase->getAlgorithmQualitySel());
    txtCustomOptions->Clear();
    txtCustomOptions->WriteText(configBase->getCustomOptions());

    // Audio controls
    chcResampling->SetSelection(configBase->getResampling());
    chkHighpass->SetValue(configBase->getHighpassEnabled());
    spcHighpassFreq->SetValue(configBase->getHighpassFreq());
    chkHighpassWidth->SetValue(configBase->getHighpassWidthEnabled());
    spcHighpassWidth->SetValue(configBase->getHighpassWidth());
    chkLowpass->SetValue(configBase->getLowpassEnabled());
    spcLowpassFreq->SetValue(configBase->getLowpassFreq());
    chkLowpassWidth->SetValue(configBase->getLowpassWidthEnabled());
    spcLowpassWidth->SetValue(configBase->getLowpassWidth());
}

void frmSettings::updateDisabledControls()
{
    // General controls
    txtOutputDirectory->Enable(optEnableOutDir->GetValue());
    btnOutputDirectory->Enable(optEnableOutDir->GetValue());

    // VBR controls
    lblBitrateVBR->Enable(chkEnabledVBR->GetValue());
    sldBitrateVBR->Enable(chkEnabledVBR->GetValue());
    spcVBRQuality->Enable(chkEnabledVBR->GetValue() && !chkUseABR->GetValue());
    lblVBRQuality->Enable(chkEnabledVBR->GetValue() && !chkUseABR->GetValue());
    chkDisableVBRTag->Enable(chkEnabledVBR->GetValue());
    chkEnforceMinBitrate->Enable(chkEnabledVBR->GetValue());
    chkUseABR->Enable(chkEnabledVBR->GetValue());
    lblABR->Enable(chkEnabledVBR->GetValue() && chkUseABR->GetValue());
    spcAverageBitrateABR->Enable(chkEnabledVBR->GetValue() && chkUseABR->GetValue());

    // Audio controls
    spcHighpassFreq->Enable(chkHighpass->GetValue());
    chkHighpassWidth->Enable(chkHighpass->GetValue());
    spcHighpassWidth->Enable(chkHighpass->GetValue() && chkHighpassWidth->GetValue());
    spcLowpassFreq->Enable(chkLowpass->GetValue());
    chkLowpassWidth->Enable(chkLowpass->GetValue());
    spcLowpassWidth->Enable(chkLowpass->GetValue() && chkLowpassWidth->GetValue());
}

void frmSettings::saveValuesConfig()
{
    // General controls
    configBase->setBitrate(BITRATE_VALUES[sldBitrate->GetValue()]);
    configBase->setOutDir(txtOutputDirectory->GetLineText(0));
    configBase->setEnableOutDir(optEnableOutDir->GetValue());
    configBase->setMode(chcMode->GetCurrentSelection());
    configBase->setEncoderExecutable(txtLameExecutable->GetLineText(0));

    // Advanced controls
    configBase->setCrc(chkCrc->GetValue());
    configBase->setDeleteFiles(chkDeleteFiles->GetValue());
    configBase->setMarkNonOriginal(chkMarkNonOriginal->GetValue());
    configBase->setMarkCopyright(chkMarkCopyright->GetValue());

    // VBR controls
    configBase->setEnabledVBR(chkEnabledVBR->GetValue());
    configBase->setVBRQuality(spcVBRQuality->GetValue());
    configBase->setMaxBitrate(BITRATE_VALUES[sldBitrateVBR->GetValue()]);
    configBase->setDisableVBRTag(chkDisableVBRTag->GetValue());
    configBase->setEnforceMinBitrate(chkEnforceMinBitrate->GetValue());
    configBase->setUseABR(chkUseABR->GetValue());
    configBase->setAverageBitrateABR(spcAverageBitrateABR->GetValue());

    // Expert controls
    configBase->setEnforceISO(chkEnforceISO->GetValue());
    configBase->setAlgorithmQualitySel(chcAlgorithmQualitySel->GetSelection());
    configBase->setCustomOptions(txtCustomOptions->GetLineText(0));

    // Audio controls
    configBase->setResampling(chcResampling->GetCurrentSelection());
    configBase->setHighpassEnabled(chkHighpass->GetValue());
    configBase->setHighpassFreq(spcHighpassFreq->GetValue());
    configBase->setHighpassWidthEnabled(chkHighpassWidth->GetValue());
    configBase->setHighpassWidth(spcHighpassWidth->GetValue());
    configBase->setLowpassEnabled(chkLowpass->GetValue());
    configBase->setLowpassFreq(spcLowpassFreq->GetValue());
    configBase->setLowpassWidthEnabled(chkLowpassWidth->GetValue());
    configBase->setLowpassWidth(spcLowpassWidth->GetValue());

    configBase->setConfigFlush();
}

void frmSettings::defaultValueControls()
{
    int i;
    wxScrollEvent evt;

    // General controls
    for (i = 0; BITRATE_VALUES[i] != DEFAULT_VALUE_Bitrate; i++);
    sldBitrate->SetValue(i);
    OnsldBitrateCmdSliderUpdated(evt);
    txtOutputDirectory->Clear();
    txtOutputDirectory->WriteText(DEFAULT_VALUE_OutDir);

    optEnableOutDir->SetValue(DEFAULT_VALUE_EnableOutDir);
    optUseSameDir->SetValue(!DEFAULT_VALUE_EnableOutDir);
    chcMode->SetSelection(DEFAULT_VALUE_Mode);
    txtLameExecutable->Clear();
    txtLameExecutable->WriteText(DEFAULT_VALUE_EncoderExecutable);

    // Advanced controls
    chkCrc->SetValue(DEFAULT_VALUE_Crc);
    chkDeleteFiles->SetValue(DEFAULT_VALUE_DeleteFiles);
    chkMarkNonOriginal->SetValue(DEFAULT_VALUE_MarkNonOriginal);
    chkMarkCopyright->SetValue(DEFAULT_VALUE_MarkCopyright);

    // VBR controls
    chkEnabledVBR->SetValue(DEFAULT_VALUE_EnabledVBR);
    spcVBRQuality->SetValue(DEFAULT_VALUE_VBRQuality);
    for (i = 0; BITRATE_VALUES[i] != DEFAULT_VALUE_MaxBitrate; i++);
    sldBitrateVBR->SetValue(i);
    OnsldBitrateVBRCmdSliderUpdated(evt);
    chkDisableVBRTag->SetValue(DEFAULT_VALUE_DisableVBRTag);
    chkEnforceMinBitrate->SetValue(DEFAULT_VALUE_EnforceMinBitrate);
    chkUseABR->SetValue(DEFAULT_VALUE_UseABR);
    spcAverageBitrateABR->SetValue(DEFAULT_VALUE_AverageBitrateABR);

    // Expert controls
    chkEnforceISO->SetValue(DEFAULT_VALUE_EnforceISO);
    chcAlgorithmQualitySel->SetSelection(DEFAULT_VALUE_AlgorithmQualitySel);
    txtCustomOptions->Clear();
    txtCustomOptions->WriteText(DEFAULT_VALUE_CustomOptions);

    // Audio controls
    chcResampling->SetSelection(DEFAULT_VALUE_Resampling);
    chkHighpass->SetValue(DEFAULT_VALUE_HighpassEnabled);
    spcHighpassFreq->SetValue(DEFAULT_VALUE_HighpassFreq);
    chkHighpassWidth->SetValue(DEFAULT_VALUE_HighpassWidthEnabled);
    spcHighpassWidth->SetValue(DEFAULT_VALUE_HighpassWidth);
    chkLowpass->SetValue(DEFAULT_VALUE_LowpassEnabled);
    spcLowpassFreq->SetValue(DEFAULT_VALUE_LowpassFreq);
    chkLowpassWidth->SetValue(DEFAULT_VALUE_LowpassWidthEnabled);
    spcLowpassWidth->SetValue(DEFAULT_VALUE_LowpassWidth);
}

void frmSettings::setLabelsControls()
{
    chcResampling->Append(_("default (automatic)"));
    chcResampling->Append(_T("8 kHz"));
    chcResampling->Append(_T("11.025 kHz"));
    chcResampling->Append(_T("12 kHz"));
    chcResampling->Append(_T("16 kHz"));
    chcResampling->Append(_T("22.05 kHz"));
    chcResampling->Append(_T("24 kHz"));
    chcResampling->Append(_T("32 kHz"));
    chcResampling->Append(_T("44.1 kHz"));
    chcResampling->Append(_T("48 kHz"));

    chcAlgorithmQualitySel->Append(_("default"));
    chcAlgorithmQualitySel->Append(_("0 (highest quality, slow)"));
    chcAlgorithmQualitySel->Append(_T("1"));
    chcAlgorithmQualitySel->Append(_T("2"));
    chcAlgorithmQualitySel->Append(_T("3"));
    chcAlgorithmQualitySel->Append(_T("4"));
    chcAlgorithmQualitySel->Append(_T("5"));
    chcAlgorithmQualitySel->Append(_T("6"));
    chcAlgorithmQualitySel->Append(_T("7"));
    chcAlgorithmQualitySel->Append(_T("8"));
    chcAlgorithmQualitySel->Append(_("9 (lowest quality, fast)"));

    btnLameExecutable->SetLabel(_T("..."));
    btnOutputDirectory->SetLabel(_T("..."));
}

