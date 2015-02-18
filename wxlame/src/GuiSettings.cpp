/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "GuiSettings.h"
#include "Global.h"

#include <wx/filedlg.h>
#include <wx/dirdlg.h>

GuiSettings::GuiSettings(wxWindow* parent, ConfigBase* configBase)
: Settings(parent), mp_configBase(configBase) {
    // Set labels of controls
    setLabelsControls();

    // Updates the values controls according to the configuration file
    updateValueControls();

    // Updates the controls that should be disabled
    updateDisabledControls();
}

GuiSettings::~GuiSettings() {
}

void GuiSettings::OnsldBitrateCmdSliderUpdated(wxScrollEvent& event) {
    int number = g_sldBitrate->GetValue();
    g_lblBitrate->SetLabel(_("Current bitrate:") + wxString::Format(_T(" %i"), BITRATE_VALUES[number]) + _T(" kbit"));

    event.Skip();
}

void GuiSettings::updateDisabledControlsEvent(wxCommandEvent& event) {
    updateDisabledControls();
}

void GuiSettings::OnbtnOutputDirectoryClick(wxCommandEvent& event) {
    wxDirDialog dirDialog(this, _("Select directory"), wxEmptyString, wxDD_DEFAULT_STYLE);
    if (dirDialog.ShowModal() == wxID_OK) {
        g_txtOutputDirectory->Clear();
        g_txtOutputDirectory->WriteText(dirDialog.GetPath());
    }
}

void GuiSettings::OnsldBitrateVBRCmdSliderUpdated(wxScrollEvent& event) {
    int number = g_sldBitrateVBR->GetValue();
    g_lblBitrateVBR->SetLabel(_("Current bitrate:") + wxString::Format(_T(" %i"), BITRATE_VALUES[number]) + _T(" kbit"));

    event.Skip();
}

void GuiSettings::OnbtnDefaultClick(wxCommandEvent& event) {
    defaultValueControls();
    updateDisabledControls();
}

void GuiSettings::OnbtnOKClick(wxCommandEvent& event) {
    saveValuesConfig();
    Close();
}

void GuiSettings::OnbtnCancelClick(wxCommandEvent& event) {
    Close();
}

void GuiSettings::updateValueControls() {
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

void GuiSettings::updateDisabledControls() {
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

void GuiSettings::saveValuesConfig() {
    // General controls
    mp_configBase->setBitrate(BITRATE_VALUES[g_sldBitrate->GetValue()]);
    mp_configBase->setOutDir(g_txtOutputDirectory->GetLineText(0));
    mp_configBase->setEnableOutDir(g_optEnableOutDir->GetValue());
    mp_configBase->setMode(g_chcMode->GetCurrentSelection());

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

void GuiSettings::defaultValueControls() {
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

void GuiSettings::setLabelsControls() {
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

    g_btnOutputDirectory->SetLabel(_T("..."));
}
