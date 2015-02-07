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

#include <wx/filedlg.h>
#include <wx/dirdlg.h>

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
: mp_configBase(configBase) {
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
    g_lblBitrate = new wxStaticText(Panel6, ID_STATICTEXT2, _("Current bitrate:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticBoxSizer1->Add(g_lblBitrate, 0, wxALL | wxEXPAND | wxALIGN_LEFT | wxALIGN_TOP, 5);
    g_sldBitrate = new wxSlider(Panel6, ID_SLIDER1, 0, 0, 1, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS | wxSL_SELRANGE, wxDefaultValidator, _T("ID_SLIDER1"));
    StaticBoxSizer1->Add(g_sldBitrate, 0, wxEXPAND | wxALIGN_LEFT | wxALIGN_TOP, 5);
    BoxSizer4->Add(StaticBoxSizer1, 1, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxVERTICAL, Panel6, _("Mode"));
    g_chcMode = new wxChoice(Panel6, ID_CHOICE4, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
    g_chcMode->Append(_("default"));
    g_chcMode->Append(_("joint"));
    g_chcMode->Append(_("simple"));
    g_chcMode->Append(_("force"));
    g_chcMode->Append(_("dual-mono"));
    g_chcMode->Append(_("mono"));
    StaticBoxSizer4->Add(g_chcMode, 0, wxALL | wxEXPAND | wxALIGN_LEFT | wxALIGN_TOP, 5);
    BoxSizer4->Add(StaticBoxSizer4, 1, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer4, 0, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel6, _("LAME executable"));
    g_txtLameExecutable = new wxTextCtrl(Panel6, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticBoxSizer2->Add(g_txtLameExecutable, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    g_btnLameExecutable = new wxButton(Panel6, ID_BUTTON5, wxEmptyString, wxDefaultPosition, wxSize(22, 22), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    StaticBoxSizer2->Add(g_btnLameExecutable, 0, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(StaticBoxSizer2, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, Panel6, _("Output directory"));
    g_optUseSameDir = new wxRadioButton(Panel6, ID_RADIOBUTTON1, _("Same as input directory"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    StaticBoxSizer3->Add(g_optUseSameDir, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    g_optEnableOutDir = new wxRadioButton(Panel6, ID_RADIOBUTTON2, _("Use below:"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    StaticBoxSizer3->Add(g_optEnableOutDir, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    g_txtOutputDirectory = new wxTextCtrl(Panel6, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer2->Add(g_txtOutputDirectory, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    g_btnOutputDirectory = new wxButton(Panel6, ID_BUTTON3, wxEmptyString, wxDefaultPosition, wxSize(22, 21), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer2->Add(g_btnOutputDirectory, 0, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3->Add(BoxSizer2, 0, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(StaticBoxSizer3, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer8 = new wxStaticBoxSizer(wxHORIZONTAL, Panel6, _("Filing"));
    g_chkDeleteFiles = new wxCheckBox(Panel6, ID_CHECKBOX7, _("Delete source file after processing"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX7"));
    g_chkDeleteFiles->SetValue(false);
    StaticBoxSizer8->Add(g_chkDeleteFiles, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    BoxSizer3->Add(StaticBoxSizer8, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    Panel6->SetSizer(BoxSizer3);
    BoxSizer3->Fit(Panel6);
    BoxSizer3->SetSizeHints(Panel6);
    Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer6 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer10 = new wxStaticBoxSizer(wxHORIZONTAL, Panel2, _("VBR"));
    g_chkEnabledVBR = new wxCheckBox(Panel2, ID_CHECKBOX4, _("Enable Variable Bitrate (VBR)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
    g_chkEnabledVBR->SetValue(false);
    StaticBoxSizer10->Add(g_chkEnabledVBR, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    BoxSizer6->Add(StaticBoxSizer10, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer9 = new wxStaticBoxSizer(wxVERTICAL, Panel2, _("Maximum VBR bitrate"));
    g_lblBitrateVBR = new wxStaticText(Panel2, ID_STATICTEXT4, _("Current bitrate:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticBoxSizer9->Add(g_lblBitrateVBR, 0, wxALL | wxEXPAND | wxALIGN_LEFT | wxALIGN_TOP, 5);
    g_sldBitrateVBR = new wxSlider(Panel2, ID_SLIDER2, 0, 0, 1, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS | wxSL_SELRANGE, wxDefaultValidator, _T("ID_SLIDER2"));
    StaticBoxSizer9->Add(g_sldBitrateVBR, 0, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7->Add(StaticBoxSizer9, 1, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6->Add(BoxSizer7, 0, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer11 = new wxStaticBoxSizer(wxVERTICAL, Panel2, _("Others"));
    g_chkDisableVBRTag = new wxCheckBox(Panel2, ID_CHECKBOX5, _("Disable writing of VBR Tag"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
    g_chkDisableVBRTag->SetValue(false);
    StaticBoxSizer11->Add(g_chkDisableVBRTag, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    g_chkEnforceMinBitrate = new wxCheckBox(Panel2, ID_CHECKBOX6, _("Strictly enforce minimum bitrate"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX6"));
    g_chkEnforceMinBitrate->SetValue(false);
    StaticBoxSizer11->Add(g_chkEnforceMinBitrate, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    g_chkUseABR = new wxCheckBox(Panel2, ID_CHECKBOX8, _("Use ABR instead VBR"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX8"));
    g_chkUseABR->SetValue(false);
    StaticBoxSizer11->Add(g_chkUseABR, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    FlexGridSizer4 = new wxFlexGridSizer(2, 2, 0, 0);
    g_lblVBRQuality = new wxStaticText(Panel2, ID_STATICTEXT3, _("Quality of VBR encoding:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer4->Add(g_lblVBRQuality, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
    g_spcVBRQuality = new wxSpinCtrl(Panel2, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 9, 0, _T("ID_SPINCTRL1"));
    g_spcVBRQuality->SetValue(_T("0"));
    FlexGridSizer4->Add(g_spcVBRQuality, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    g_lblABR = new wxStaticText(Panel2, ID_STATICTEXT5, _("Average bitrate encoding ABR:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer4->Add(g_lblABR, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
    g_spcAverageBitrateABR = new wxSpinCtrl(Panel2, ID_SPINCTRL2, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 8, 320, 0, _T("ID_SPINCTRL2"));
    g_spcAverageBitrateABR->SetValue(_T("0"));
    FlexGridSizer4->Add(g_spcAverageBitrateABR, 0, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer11->Add(FlexGridSizer4, 0, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8->Add(StaticBoxSizer11, 1, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6->Add(BoxSizer8, 0, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    Panel2->SetSizer(BoxSizer6);
    BoxSizer6->Fit(Panel2);
    BoxSizer6->SetSizeHints(Panel2);
    Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer7 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Flags"));
    g_chkMarkNonOriginal = new wxCheckBox(Panel1, ID_CHECKBOX2, _("Mark as non-original"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    g_chkMarkNonOriginal->SetValue(false);
    StaticBoxSizer7->Add(g_chkMarkNonOriginal, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    g_chkMarkCopyright = new wxCheckBox(Panel1, ID_CHECKBOX3, _("Mark as copyright"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    g_chkMarkCopyright->SetValue(false);
    StaticBoxSizer7->Add(g_chkMarkCopyright, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    g_chkCrc = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Include CRC error detection"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    g_chkCrc->SetValue(false);
    StaticBoxSizer7->Add(g_chkCrc, 0, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    g_chkEnforceISO = new wxCheckBox(Panel1, ID_CHECKBOX13, _("Comply as much as possible to ISO MPEG spec"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX13"));
    g_chkEnforceISO->SetValue(false);
    StaticBoxSizer7->Add(g_chkEnforceISO, 1, wxALL | wxALIGN_LEFT | wxALIGN_TOP, 2);
    BoxSizer5->Add(StaticBoxSizer7, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Options"));
    FlexGridSizer1 = new wxFlexGridSizer(2, 2, 0, 0);
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("Algorithm quality selection:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    FlexGridSizer1->Add(StaticText7, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
    g_chcAlgorithmQualitySel = new wxChoice(Panel1, ID_CHOICE2, wxDefaultPosition, wxSize(200, -1), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    FlexGridSizer1->Add(g_chcAlgorithmQualitySel, 0, wxALL | wxEXPAND | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _("Custom options:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    FlexGridSizer1->Add(StaticText8, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 5);
    g_txtCustomOptions = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer1->Add(g_txtCustomOptions, 0, wxALL | wxEXPAND | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer6->Add(FlexGridSizer1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5->Add(StaticBoxSizer6, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer5);
    BoxSizer5->Fit(Panel1);
    BoxSizer5->SetSizeHints(Panel1);
    Panel4 = new wxPanel(Notebook1, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    BoxSizer13 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer12 = new wxStaticBoxSizer(wxHORIZONTAL, Panel4, _("Output sampling frequency"));
    g_chcResampling = new wxChoice(Panel4, ID_CHOICE5, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE5"));
    StaticBoxSizer12->Add(g_chcResampling, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer13->Add(StaticBoxSizer12, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer13 = new wxStaticBoxSizer(wxHORIZONTAL, Panel4, _("Highpass filter"));
    FlexGridSizer2 = new wxFlexGridSizer(2, 2, 0, 0);
    g_chkHighpass = new wxCheckBox(Panel4, ID_CHECKBOX15, _("Highpass filtering frequency (in Hz):"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX15"));
    g_chkHighpass->SetValue(false);
    FlexGridSizer2->Add(g_chkHighpass, 0, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 2);
    g_spcHighpassFreq = new wxSpinCtrl(Panel4, ID_SPINCTRL3, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 50, 50000, 0, _T("ID_SPINCTRL3"));
    g_spcHighpassFreq->SetValue(_T("0"));
    FlexGridSizer2->Add(g_spcHighpassFreq, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    g_chkHighpassWidth = new wxCheckBox(Panel4, ID_CHECKBOX16, _("Width of Highpass filter (in Hz):"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX16"));
    g_chkHighpassWidth->SetValue(false);
    FlexGridSizer2->Add(g_chkHighpassWidth, 0, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 2);
    g_spcHighpassWidth = new wxSpinCtrl(Panel4, ID_SPINCTRL4, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 50, 50000, 0, _T("ID_SPINCTRL4"));
    g_spcHighpassWidth->SetValue(_T("0"));
    FlexGridSizer2->Add(g_spcHighpassWidth, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer13->Add(FlexGridSizer2, 0, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer13->Add(StaticBoxSizer13, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer14 = new wxStaticBoxSizer(wxHORIZONTAL, Panel4, _("Lowpass filter"));
    FlexGridSizer3 = new wxFlexGridSizer(2, 2, 0, 0);
    g_chkLowpass = new wxCheckBox(Panel4, ID_CHECKBOX17, _("Lowpass filtering frequency (in Hz):"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX17"));
    g_chkLowpass->SetValue(false);
    FlexGridSizer3->Add(g_chkLowpass, 0, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 2);
    g_spcLowpassFreq = new wxSpinCtrl(Panel4, ID_SPINCTRL5, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 50, 50000, 0, _T("ID_SPINCTRL5"));
    g_spcLowpassFreq->SetValue(_T("0"));
    FlexGridSizer3->Add(g_spcLowpassFreq, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    g_chkLowpassWidth = new wxCheckBox(Panel4, ID_CHECKBOX18, _("Width of Lowpass filter (in Hz):"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX18"));
    g_chkLowpassWidth->SetValue(false);
    FlexGridSizer3->Add(g_chkLowpassWidth, 0, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 2);
    g_spcLowpassWidth = new wxSpinCtrl(Panel4, ID_SPINCTRL6, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 50, 50000, 0, _T("ID_SPINCTRL6"));
    g_spcLowpassWidth->SetValue(_T("0"));
    FlexGridSizer3->Add(g_spcLowpassWidth, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer14->Add(FlexGridSizer3, 0, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer13->Add(StaticBoxSizer14, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    Panel4->SetSizer(BoxSizer13);
    BoxSizer13->Fit(Panel4);
    BoxSizer13->SetSizeHints(Panel4);
    Notebook1->AddPage(Panel6, _("General"), false);
    Notebook1->AddPage(Panel2, _("VBR"), false);
    Notebook1->AddPage(Panel1, _("Advanced"), false);
    Notebook1->AddPage(Panel4, _("Audio processing"), false);
    BoxSizer1->Add(Notebook1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
    g_btnDefault = new wxButton(this, ID_BUTTON1, _("Restore defaults"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer10->Add(g_btnDefault, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    g_btnOK = new wxButton(this, ID_BUTTON2, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer10->Add(g_btnOK, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    g_btnCancel = new wxButton(this, ID_BUTTON4, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer10->Add(g_btnCancel, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer10, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_SLIDER1, wxEVT_COMMAND_SLIDER_UPDATED, (wxObjectEventFunction) & frmSettings::OnsldBitrateCmdSliderUpdated);
    Connect(ID_BUTTON5, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & frmSettings::OnbtnLameExecutableClick);
    Connect(ID_RADIOBUTTON1, wxEVT_COMMAND_RADIOBUTTON_SELECTED, (wxObjectEventFunction) & frmSettings::updateDisabledControlsEvent);
    Connect(ID_RADIOBUTTON2, wxEVT_COMMAND_RADIOBUTTON_SELECTED, (wxObjectEventFunction) & frmSettings::updateDisabledControlsEvent);
    Connect(ID_BUTTON3, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & frmSettings::OnbtnOutputDirectoryClick);
    Connect(ID_CHECKBOX4, wxEVT_COMMAND_CHECKBOX_CLICKED, (wxObjectEventFunction) & frmSettings::updateDisabledControlsEvent);
    Connect(ID_SLIDER2, wxEVT_COMMAND_SLIDER_UPDATED, (wxObjectEventFunction) & frmSettings::OnsldBitrateVBRCmdSliderUpdated);
    Connect(ID_CHECKBOX8, wxEVT_COMMAND_CHECKBOX_CLICKED, (wxObjectEventFunction) & frmSettings::updateDisabledControlsEvent);
    Connect(ID_CHECKBOX15, wxEVT_COMMAND_CHECKBOX_CLICKED, (wxObjectEventFunction) & frmSettings::updateDisabledControlsEvent);
    Connect(ID_CHECKBOX16, wxEVT_COMMAND_CHECKBOX_CLICKED, (wxObjectEventFunction) & frmSettings::updateDisabledControlsEvent);
    Connect(ID_CHECKBOX17, wxEVT_COMMAND_CHECKBOX_CLICKED, (wxObjectEventFunction) & frmSettings::updateDisabledControlsEvent);
    Connect(ID_CHECKBOX18, wxEVT_COMMAND_CHECKBOX_CLICKED, (wxObjectEventFunction) & frmSettings::updateDisabledControlsEvent);
    Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & frmSettings::OnbtnDefaultClick);
    Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & frmSettings::OnbtnOKClick);
    Connect(ID_BUTTON4, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & frmSettings::OnbtnCancelClick);
    //*)

    // Set labels of controls
    setLabelsControls();

    // Updates the values controls according to the configuration file
    updateValueControls();

    // Updates the controls that should be disabled
    updateDisabledControls();
}

frmSettings::~frmSettings() {
    //(*Destroy(frmSettings)
    //*)
}

void frmSettings::OnbtnOKClick(wxCommandEvent& event) {
    saveValuesConfig();
    Close();
}

void frmSettings::OnbtnCancelClick(wxCommandEvent& event) {
    Close();
}

void frmSettings::OnbtnDefaultClick(wxCommandEvent& event) {
    defaultValueControls();
    updateDisabledControls();
}

void frmSettings::OnsldBitrateCmdSliderUpdated(wxScrollEvent& event) {
    int number = g_sldBitrate->GetValue();
    g_lblBitrate->SetLabel(_("Current bitrate:") + wxString::Format(_T(" %i"), BITRATE_VALUES[number]) + _T(" kbit"));

    event.Skip();
}

void frmSettings::OnsldBitrateVBRCmdSliderUpdated(wxScrollEvent& event) {
    int number = g_sldBitrateVBR->GetValue();
    g_lblBitrateVBR->SetLabel(_("Current bitrate:") + wxString::Format(_T(" %i"), BITRATE_VALUES[number]) + _T(" kbit"));

    event.Skip();
}

void frmSettings::updateDisabledControlsEvent(wxCommandEvent& event) {
    updateDisabledControls();
}

void frmSettings::OnbtnLameExecutableClick(wxCommandEvent& event) {
    wxFileDialog fileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_OPEN);
    if (fileDialog.ShowModal() == wxID_OK) {
        g_txtLameExecutable->Clear();
        g_txtLameExecutable->WriteText(fileDialog.GetPath());
    }
}

void frmSettings::OnbtnOutputDirectoryClick(wxCommandEvent& event) {
    wxDirDialog dirDialog(this, _("Select directory"), wxEmptyString, wxDD_DEFAULT_STYLE);
    if (dirDialog.ShowModal() == wxID_OK) {
        g_txtOutputDirectory->Clear();
        g_txtOutputDirectory->WriteText(dirDialog.GetPath());
    }
}

void frmSettings::updateValueControls() {
    int i;
    wxScrollEvent evt;

    // General controls
    for (i = 0; BITRATE_VALUES[i] != mp_configBase->getBitrate(); i++);
    g_sldBitrate->SetValue(i);
    OnsldBitrateCmdSliderUpdated(evt);
    g_txtOutputDirectory->Clear();
    g_txtOutputDirectory->WriteText(mp_configBase->getOutDir());
    g_optEnableOutDir->SetValue(mp_configBase->getEnableOutDir());
    g_optUseSameDir->SetValue(!mp_configBase->getEnableOutDir());
    g_chcMode->SetSelection(mp_configBase->getMode());
    g_txtLameExecutable->Clear();
    g_txtLameExecutable->WriteText(mp_configBase->getEncoderExecutable());

    // Advanced controls
    g_chkCrc->SetValue(mp_configBase->getCrc());
    g_chkDeleteFiles->SetValue(mp_configBase->getDeleteFiles());
    g_chkMarkNonOriginal->SetValue(mp_configBase->getMarkNonOriginal());
    g_chkMarkCopyright->SetValue(mp_configBase->getMarkCopyright());

    // VBR controls
    g_chkEnabledVBR->SetValue(mp_configBase->getEnabledVBR());
    g_spcVBRQuality->SetValue(mp_configBase->getVBRQuality());
    for (i = 0; BITRATE_VALUES[i] != mp_configBase->getMaxBitrate(); i++);
    g_sldBitrateVBR->SetValue(i);
    OnsldBitrateVBRCmdSliderUpdated(evt);
    g_chkDisableVBRTag->SetValue(mp_configBase->getDisableVBRTag());
    g_chkEnforceMinBitrate->SetValue(mp_configBase->getEnforceMinBitrate());
    g_chkUseABR->SetValue(mp_configBase->getUseABR());
    g_spcAverageBitrateABR->SetValue(mp_configBase->getAverageBitrateABR());

    // Expert controls
    g_chkEnforceISO->SetValue(mp_configBase->getEnforceISO());
    g_chcAlgorithmQualitySel->SetSelection(mp_configBase->getAlgorithmQualitySel());
    g_txtCustomOptions->Clear();
    g_txtCustomOptions->WriteText(mp_configBase->getCustomOptions());

    // Audio controls
    g_chcResampling->SetSelection(mp_configBase->getResampling());
    g_chkHighpass->SetValue(mp_configBase->getHighpassEnabled());
    g_spcHighpassFreq->SetValue(mp_configBase->getHighpassFreq());
    g_chkHighpassWidth->SetValue(mp_configBase->getHighpassWidthEnabled());
    g_spcHighpassWidth->SetValue(mp_configBase->getHighpassWidth());
    g_chkLowpass->SetValue(mp_configBase->getLowpassEnabled());
    g_spcLowpassFreq->SetValue(mp_configBase->getLowpassFreq());
    g_chkLowpassWidth->SetValue(mp_configBase->getLowpassWidthEnabled());
    g_spcLowpassWidth->SetValue(mp_configBase->getLowpassWidth());
}

void frmSettings::updateDisabledControls() {
    // General controls
    g_txtOutputDirectory->Enable(g_optEnableOutDir->GetValue());
    g_btnOutputDirectory->Enable(g_optEnableOutDir->GetValue());

    // VBR controls
    g_lblBitrateVBR->Enable(g_chkEnabledVBR->GetValue());
    g_sldBitrateVBR->Enable(g_chkEnabledVBR->GetValue());
    g_spcVBRQuality->Enable(g_chkEnabledVBR->GetValue() && !g_chkUseABR->GetValue());
    g_lblVBRQuality->Enable(g_chkEnabledVBR->GetValue() && !g_chkUseABR->GetValue());
    g_chkDisableVBRTag->Enable(g_chkEnabledVBR->GetValue());
    g_chkEnforceMinBitrate->Enable(g_chkEnabledVBR->GetValue());
    g_chkUseABR->Enable(g_chkEnabledVBR->GetValue());
    g_lblABR->Enable(g_chkEnabledVBR->GetValue() && g_chkUseABR->GetValue());
    g_spcAverageBitrateABR->Enable(g_chkEnabledVBR->GetValue() && g_chkUseABR->GetValue());

    // Audio controls
    g_spcHighpassFreq->Enable(g_chkHighpass->GetValue());
    g_chkHighpassWidth->Enable(g_chkHighpass->GetValue());
    g_spcHighpassWidth->Enable(g_chkHighpass->GetValue() && g_chkHighpassWidth->GetValue());
    g_spcLowpassFreq->Enable(g_chkLowpass->GetValue());
    g_chkLowpassWidth->Enable(g_chkLowpass->GetValue());
    g_spcLowpassWidth->Enable(g_chkLowpass->GetValue() && g_chkLowpassWidth->GetValue());
}

void frmSettings::saveValuesConfig() {
    // General controls
    mp_configBase->setBitrate(BITRATE_VALUES[g_sldBitrate->GetValue()]);
    mp_configBase->setOutDir(g_txtOutputDirectory->GetLineText(0));
    mp_configBase->setEnableOutDir(g_optEnableOutDir->GetValue());
    mp_configBase->setMode(g_chcMode->GetCurrentSelection());
    mp_configBase->setEncoderExecutable(g_txtLameExecutable->GetLineText(0));

    // Advanced controls
    mp_configBase->setCrc(g_chkCrc->GetValue());
    mp_configBase->setDeleteFiles(g_chkDeleteFiles->GetValue());
    mp_configBase->setMarkNonOriginal(g_chkMarkNonOriginal->GetValue());
    mp_configBase->setMarkCopyright(g_chkMarkCopyright->GetValue());

    // VBR controls
    mp_configBase->setEnabledVBR(g_chkEnabledVBR->GetValue());
    mp_configBase->setVBRQuality(g_spcVBRQuality->GetValue());
    mp_configBase->setMaxBitrate(BITRATE_VALUES[g_sldBitrateVBR->GetValue()]);
    mp_configBase->setDisableVBRTag(g_chkDisableVBRTag->GetValue());
    mp_configBase->setEnforceMinBitrate(g_chkEnforceMinBitrate->GetValue());
    mp_configBase->setUseABR(g_chkUseABR->GetValue());
    mp_configBase->setAverageBitrateABR(g_spcAverageBitrateABR->GetValue());

    // Expert controls
    mp_configBase->setEnforceISO(g_chkEnforceISO->GetValue());
    mp_configBase->setAlgorithmQualitySel(g_chcAlgorithmQualitySel->GetSelection());
    mp_configBase->setCustomOptions(g_txtCustomOptions->GetLineText(0));

    // Audio controls
    mp_configBase->setResampling(g_chcResampling->GetCurrentSelection());
    mp_configBase->setHighpassEnabled(g_chkHighpass->GetValue());
    mp_configBase->setHighpassFreq(g_spcHighpassFreq->GetValue());
    mp_configBase->setHighpassWidthEnabled(g_chkHighpassWidth->GetValue());
    mp_configBase->setHighpassWidth(g_spcHighpassWidth->GetValue());
    mp_configBase->setLowpassEnabled(g_chkLowpass->GetValue());
    mp_configBase->setLowpassFreq(g_spcLowpassFreq->GetValue());
    mp_configBase->setLowpassWidthEnabled(g_chkLowpassWidth->GetValue());
    mp_configBase->setLowpassWidth(g_spcLowpassWidth->GetValue());

    mp_configBase->configFlush();
}

void frmSettings::defaultValueControls() {
    int i;
    wxScrollEvent evt;

    // General controls
    for (i = 0; BITRATE_VALUES[i] != DEFAULT_VALUE_Bitrate; i++);
    g_sldBitrate->SetValue(i);
    OnsldBitrateCmdSliderUpdated(evt);
    g_txtOutputDirectory->Clear();
    g_txtOutputDirectory->WriteText(DEFAULT_VALUE_OutDir);

    g_optEnableOutDir->SetValue(DEFAULT_VALUE_EnableOutDir);
    g_optUseSameDir->SetValue(!DEFAULT_VALUE_EnableOutDir);
    g_chcMode->SetSelection(DEFAULT_VALUE_Mode);
    g_txtLameExecutable->Clear();
    g_txtLameExecutable->WriteText(DEFAULT_VALUE_EncoderExecutable);

    // Advanced controls
    g_chkCrc->SetValue(DEFAULT_VALUE_Crc);
    g_chkDeleteFiles->SetValue(DEFAULT_VALUE_DeleteFiles);
    g_chkMarkNonOriginal->SetValue(DEFAULT_VALUE_MarkNonOriginal);
    g_chkMarkCopyright->SetValue(DEFAULT_VALUE_MarkCopyright);

    // VBR controls
    g_chkEnabledVBR->SetValue(DEFAULT_VALUE_EnabledVBR);
    g_spcVBRQuality->SetValue(DEFAULT_VALUE_VBRQuality);
    for (i = 0; BITRATE_VALUES[i] != DEFAULT_VALUE_MaxBitrate; i++);
    g_sldBitrateVBR->SetValue(i);
    OnsldBitrateVBRCmdSliderUpdated(evt);
    g_chkDisableVBRTag->SetValue(DEFAULT_VALUE_DisableVBRTag);
    g_chkEnforceMinBitrate->SetValue(DEFAULT_VALUE_EnforceMinBitrate);
    g_chkUseABR->SetValue(DEFAULT_VALUE_UseABR);
    g_spcAverageBitrateABR->SetValue(DEFAULT_VALUE_AverageBitrateABR);

    // Expert controls
    g_chkEnforceISO->SetValue(DEFAULT_VALUE_EnforceISO);
    g_chcAlgorithmQualitySel->SetSelection(DEFAULT_VALUE_AlgorithmQualitySel);
    g_txtCustomOptions->Clear();
    g_txtCustomOptions->WriteText(DEFAULT_VALUE_CustomOptions);

    // Audio controls
    g_chcResampling->SetSelection(DEFAULT_VALUE_Resampling);
    g_chkHighpass->SetValue(DEFAULT_VALUE_HighpassEnabled);
    g_spcHighpassFreq->SetValue(DEFAULT_VALUE_HighpassFreq);
    g_chkHighpassWidth->SetValue(DEFAULT_VALUE_HighpassWidthEnabled);
    g_spcHighpassWidth->SetValue(DEFAULT_VALUE_HighpassWidth);
    g_chkLowpass->SetValue(DEFAULT_VALUE_LowpassEnabled);
    g_spcLowpassFreq->SetValue(DEFAULT_VALUE_LowpassFreq);
    g_chkLowpassWidth->SetValue(DEFAULT_VALUE_LowpassWidthEnabled);
    g_spcLowpassWidth->SetValue(DEFAULT_VALUE_LowpassWidth);
}

void frmSettings::setLabelsControls() {
    // Sets the size of the sliders
    g_sldBitrate->SetMax(BITRATE_VALUES_SIZE - 1);
    g_sldBitrateVBR->SetMax(BITRATE_VALUES_SIZE - 1);

    g_chcResampling->Append(_("default (automatic)"));
    g_chcResampling->Append(_T("8 kHz"));
    g_chcResampling->Append(_T("11.025 kHz"));
    g_chcResampling->Append(_T("12 kHz"));
    g_chcResampling->Append(_T("16 kHz"));
    g_chcResampling->Append(_T("22.05 kHz"));
    g_chcResampling->Append(_T("24 kHz"));
    g_chcResampling->Append(_T("32 kHz"));
    g_chcResampling->Append(_T("44.1 kHz"));
    g_chcResampling->Append(_T("48 kHz"));

    g_chcAlgorithmQualitySel->Append(_("default"));
    g_chcAlgorithmQualitySel->Append(_("0 (highest quality, slow)"));
    g_chcAlgorithmQualitySel->Append(_T("1"));
    g_chcAlgorithmQualitySel->Append(_T("2"));
    g_chcAlgorithmQualitySel->Append(_T("3"));
    g_chcAlgorithmQualitySel->Append(_T("4"));
    g_chcAlgorithmQualitySel->Append(_T("5"));
    g_chcAlgorithmQualitySel->Append(_T("6"));
    g_chcAlgorithmQualitySel->Append(_T("7"));
    g_chcAlgorithmQualitySel->Append(_T("8"));
    g_chcAlgorithmQualitySel->Append(_("9 (lowest quality, fast)"));

    g_btnLameExecutable->SetLabel(_T("..."));
    g_btnOutputDirectory->SetLabel(_T("..."));
}
