/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "GuiDialogSettings.h"
#include "Constants.h"

GuiDialogSettings::GuiDialogSettings(wxWindow *parent, ConfigBase *configBase)
    : DialogSettings(parent), mp_configBase(configBase) {
    // Set labels of controls
    setLabelsControls();

    // Updates the values controls according to the configuration file
    updateValueControls();

    // Updates the controls that should be disabled
    updateDisabledControls();
}

GuiDialogSettings::~GuiDialogSettings() {
}

void GuiDialogSettings::OnsldBitrateCmdSliderUpdated(wxScrollEvent &event) {
    int number = gui_sldBitrate->GetValue();
    gui_lblBitrate->SetLabel(_("Current bitrate:") + wxString::Format(_T(" %i"), BITRATE_VALUES[number]) + _T(" kbit"));

    event.Skip();
}

void GuiDialogSettings::updateDisabledControlsEvent(wxCommandEvent &event) {
    updateDisabledControls();
    event.Skip(false);
}

void GuiDialogSettings::OnsldBitrateVBRCmdSliderUpdated(wxScrollEvent &event) {
    int number = gui_sldBitrateVBR->GetValue();
    gui_lblBitrateVBR->SetLabel(
        _("Current bitrate:") + wxString::Format(_T(" %i"), BITRATE_VALUES[number]) + _T(" kbit"));

    event.Skip();
}

void GuiDialogSettings::OnbtnDefaultClick(wxCommandEvent &event) {
    defaultValueControls();
    updateDisabledControls();
    event.Skip(false);
}

void GuiDialogSettings::OnbtnOKClick(wxCommandEvent &event) {
    saveValuesConfig();
    Close();
    event.Skip(false);
}

void GuiDialogSettings::OnbtnCancelClick(wxCommandEvent &event) {
    Close();
    event.Skip(false);
}

void GuiDialogSettings::updateValueControls() {
    int i;
    wxScrollEvent evt;

    // General controls
    for (i = 0; BITRATE_VALUES[i] != mp_configBase->getBitrate(); i++);
    gui_sldBitrate->SetValue(i);
    OnsldBitrateCmdSliderUpdated(evt);
    gui_dpkOutputDirectory->SetPath(mp_configBase->getOutDir());
    gui_optEnableOutDir->SetValue(mp_configBase->getEnableOutDir());
    gui_optUseSameDir->SetValue(!mp_configBase->getEnableOutDir());
    gui_chcMode->SetSelection(mp_configBase->getMode());

    // VBR controls
    gui_chkEnabledVBR->SetValue(mp_configBase->getEnabledVBR());
    gui_spcVBRQuality->SetValue(mp_configBase->getVBRQuality());
    for (i = 0; BITRATE_VALUES[i] != mp_configBase->getMaxBitrate(); i++);
    gui_sldBitrateVBR->SetValue(i);
    OnsldBitrateVBRCmdSliderUpdated(evt);
    gui_chkDisableVBRTag->SetValue(mp_configBase->getDisableVBRTag());
    gui_chkEnforceMinBitrate->SetValue(mp_configBase->getEnforceMinBitrate());
    gui_chkUseABR->SetValue(mp_configBase->getUseABR());
    gui_spcAverageBitrateABR->SetValue(mp_configBase->getAverageBitrateABR());

    // Audio controls
    gui_chcResampling->SetSelection(mp_configBase->getResampling());
    gui_chkHighpass->SetValue(mp_configBase->getHighpassEnabled());
    gui_spcHighpassFreq->SetValue(mp_configBase->getHighpassFreq());
    gui_chkHighpassWidth->SetValue(mp_configBase->getHighpassWidthEnabled());
    gui_spcHighpassWidth->SetValue(mp_configBase->getHighpassWidth());
    gui_chkLowpass->SetValue(mp_configBase->getLowpassEnabled());
    gui_spcLowpassFreq->SetValue(mp_configBase->getLowpassFreq());
    gui_chkLowpassWidth->SetValue(mp_configBase->getLowpassWidthEnabled());
    gui_spcLowpassWidth->SetValue(mp_configBase->getLowpassWidth());

    // Advanced controls
    gui_chkCrc->SetValue(mp_configBase->getCrc());
    gui_chkDeleteFiles->SetValue(mp_configBase->getDeleteFiles());
    gui_chkMarkNonOriginal->SetValue(mp_configBase->getMarkNonOriginal());
    gui_chkMarkCopyright->SetValue(mp_configBase->getMarkCopyright());
    gui_chkEnforceISO->SetValue(mp_configBase->getEnforceISO());
    gui_chcAlgorithmQualitySel->SetSelection(mp_configBase->getAlgorithmQualitySel());
    gui_txtCustomOptions->Clear();
    gui_chkCustomOptions->SetValue(mp_configBase->getCustomOptions());
    gui_txtCustomOptions->WriteText(mp_configBase->getCustomOptionsText());
}

void GuiDialogSettings::updateDisabledControls() {
    // General controls
    gui_dpkOutputDirectory->Enable(gui_optEnableOutDir->GetValue());

    // VBR controls
    gui_lblBitrateVBR->Enable(gui_chkEnabledVBR->GetValue());
    gui_sldBitrateVBR->Enable(gui_chkEnabledVBR->GetValue());
    gui_spcVBRQuality->Enable(gui_chkEnabledVBR->GetValue() && !gui_chkUseABR->GetValue());
    gui_lblVBRQuality->Enable(gui_chkEnabledVBR->GetValue() && !gui_chkUseABR->GetValue());
    gui_chkDisableVBRTag->Enable(gui_chkEnabledVBR->GetValue());
    gui_chkEnforceMinBitrate->Enable(gui_chkEnabledVBR->GetValue());
    gui_chkUseABR->Enable(gui_chkEnabledVBR->GetValue());
    gui_lblABR->Enable(gui_chkEnabledVBR->GetValue() && gui_chkUseABR->GetValue());
    gui_spcAverageBitrateABR->Enable(gui_chkEnabledVBR->GetValue() && gui_chkUseABR->GetValue());

    // Audio controls
    gui_spcHighpassFreq->Enable(gui_chkHighpass->GetValue());
    gui_chkHighpassWidth->Enable(gui_chkHighpass->GetValue());
    gui_spcHighpassWidth->Enable(gui_chkHighpass->GetValue() && gui_chkHighpassWidth->GetValue());
    gui_spcLowpassFreq->Enable(gui_chkLowpass->GetValue());
    gui_chkLowpassWidth->Enable(gui_chkLowpass->GetValue());
    gui_spcLowpassWidth->Enable(gui_chkLowpass->GetValue() && gui_chkLowpassWidth->GetValue());

    // Advanced controls
    gui_txtCustomOptions->Enable(gui_chkCustomOptions->GetValue());
}

void GuiDialogSettings::saveValuesConfig() {
    // General controls
    mp_configBase->setBitrate(BITRATE_VALUES[gui_sldBitrate->GetValue()]);
    mp_configBase->setOutDir(gui_dpkOutputDirectory->GetDirName().GetPath());
    mp_configBase->setEnableOutDir(gui_optEnableOutDir->GetValue());
    mp_configBase->setMode(gui_chcMode->GetCurrentSelection());

    // VBR controls
    mp_configBase->setEnabledVBR(gui_chkEnabledVBR->GetValue());
    mp_configBase->setVBRQuality(gui_spcVBRQuality->GetValue());
    mp_configBase->setMaxBitrate(BITRATE_VALUES[gui_sldBitrateVBR->GetValue()]);
    mp_configBase->setDisableVBRTag(gui_chkDisableVBRTag->GetValue());
    mp_configBase->setEnforceMinBitrate(gui_chkEnforceMinBitrate->GetValue());
    mp_configBase->setUseABR(gui_chkUseABR->GetValue());
    mp_configBase->setAverageBitrateABR(gui_spcAverageBitrateABR->GetValue());

    // Audio controls
    mp_configBase->setResampling(gui_chcResampling->GetCurrentSelection());
    mp_configBase->setHighpassEnabled(gui_chkHighpass->GetValue());
    mp_configBase->setHighpassFreq(gui_spcHighpassFreq->GetValue());
    mp_configBase->setHighpassWidthEnabled(gui_chkHighpassWidth->GetValue());
    mp_configBase->setHighpassWidth(gui_spcHighpassWidth->GetValue());
    mp_configBase->setLowpassEnabled(gui_chkLowpass->GetValue());
    mp_configBase->setLowpassFreq(gui_spcLowpassFreq->GetValue());
    mp_configBase->setLowpassWidthEnabled(gui_chkLowpassWidth->GetValue());
    mp_configBase->setLowpassWidth(gui_spcLowpassWidth->GetValue());

    // Advanced controls
    mp_configBase->setCrc(gui_chkCrc->GetValue());
    mp_configBase->setDeleteFiles(gui_chkDeleteFiles->GetValue());
    mp_configBase->setMarkNonOriginal(gui_chkMarkNonOriginal->GetValue());
    mp_configBase->setMarkCopyright(gui_chkMarkCopyright->GetValue());
    mp_configBase->setEnforceISO(gui_chkEnforceISO->GetValue());
    mp_configBase->setAlgorithmQualitySel(gui_chcAlgorithmQualitySel->GetSelection());
    mp_configBase->setCustomOptions(gui_chkCustomOptions->GetValue());
    mp_configBase->setCustomOptionsText(gui_txtCustomOptions->GetLineText(0));

    mp_configBase->configFlush();
}

void GuiDialogSettings::defaultValueControls() {
    int i;
    wxScrollEvent evt;

    // General controls
    for (i = 0; BITRATE_VALUES[i] != DEFAULT_VALUE_Bitrate; i++);
    gui_sldBitrate->SetValue(i);
    OnsldBitrateCmdSliderUpdated(evt);
    gui_dpkOutputDirectory->SetPath(DEFAULT_VALUE_OutDir);

    gui_optEnableOutDir->SetValue(DEFAULT_VALUE_EnableOutDir);
    gui_optUseSameDir->SetValue(!DEFAULT_VALUE_EnableOutDir);
    gui_chcMode->SetSelection(DEFAULT_VALUE_Mode);

    // VBR controls
    gui_chkEnabledVBR->SetValue(DEFAULT_VALUE_EnabledVBR);
    gui_spcVBRQuality->SetValue(DEFAULT_VALUE_VBRQuality);
    for (i = 0; BITRATE_VALUES[i] != DEFAULT_VALUE_MaxBitrate; i++);
    gui_sldBitrateVBR->SetValue(i);
    OnsldBitrateVBRCmdSliderUpdated(evt);
    gui_chkDisableVBRTag->SetValue(DEFAULT_VALUE_DisableVBRTag);
    gui_chkEnforceMinBitrate->SetValue(DEFAULT_VALUE_EnforceMinBitrate);
    gui_chkUseABR->SetValue(DEFAULT_VALUE_UseABR);
    gui_spcAverageBitrateABR->SetValue(DEFAULT_VALUE_AverageBitrateABR);

    // Audio controls
    gui_chcResampling->SetSelection(DEFAULT_VALUE_Resampling);
    gui_chkHighpass->SetValue(DEFAULT_VALUE_HighpassEnabled);
    gui_spcHighpassFreq->SetValue(DEFAULT_VALUE_HighpassFreq);
    gui_chkHighpassWidth->SetValue(DEFAULT_VALUE_HighpassWidthEnabled);
    gui_spcHighpassWidth->SetValue(DEFAULT_VALUE_HighpassWidth);
    gui_chkLowpass->SetValue(DEFAULT_VALUE_LowpassEnabled);
    gui_spcLowpassFreq->SetValue(DEFAULT_VALUE_LowpassFreq);
    gui_chkLowpassWidth->SetValue(DEFAULT_VALUE_LowpassWidthEnabled);
    gui_spcLowpassWidth->SetValue(DEFAULT_VALUE_LowpassWidth);

    // Advanced controls
    gui_chkCrc->SetValue(DEFAULT_VALUE_Crc);
    gui_chkDeleteFiles->SetValue(DEFAULT_VALUE_DeleteFiles);
    gui_chkMarkNonOriginal->SetValue(DEFAULT_VALUE_MarkNonOriginal);
    gui_chkMarkCopyright->SetValue(DEFAULT_VALUE_MarkCopyright);
    gui_chkEnforceISO->SetValue(DEFAULT_VALUE_EnforceISO);
    gui_chcAlgorithmQualitySel->SetSelection(DEFAULT_VALUE_AlgorithmQualitySel);
    gui_txtCustomOptions->Clear();
    gui_chkCustomOptions->SetValue(DEFAULT_VALUE_CustomOptions);
    gui_txtCustomOptions->WriteText(DEFAULT_VALUE_CustomOptionsText);
}

void GuiDialogSettings::setLabelsControls() {
    // Sets the size of the sliders
    gui_sldBitrate->SetMax(BITRATE_VALUES_SIZE - 1);
    gui_sldBitrateVBR->SetMax(BITRATE_VALUES_SIZE - 1);

    gui_chcResampling->Append(_("default (automatic)"));
    gui_chcResampling->Append(_T("8 kHz"));
    gui_chcResampling->Append(_T("11.025 kHz"));
    gui_chcResampling->Append(_T("12 kHz"));
    gui_chcResampling->Append(_T("16 kHz"));
    gui_chcResampling->Append(_T("22.05 kHz"));
    gui_chcResampling->Append(_T("24 kHz"));
    gui_chcResampling->Append(_T("32 kHz"));
    gui_chcResampling->Append(_T("44.1 kHz"));
    gui_chcResampling->Append(_T("48 kHz"));

    gui_chcAlgorithmQualitySel->Append(_("default"));
    gui_chcAlgorithmQualitySel->Append(_("0 (highest quality, slow)"));
    gui_chcAlgorithmQualitySel->Append(_T("1"));
    gui_chcAlgorithmQualitySel->Append(_T("2"));
    gui_chcAlgorithmQualitySel->Append(_T("3"));
    gui_chcAlgorithmQualitySel->Append(_T("4"));
    gui_chcAlgorithmQualitySel->Append(_T("5"));
    gui_chcAlgorithmQualitySel->Append(_T("6"));
    gui_chcAlgorithmQualitySel->Append(_T("7"));
    gui_chcAlgorithmQualitySel->Append(_T("8"));
    gui_chcAlgorithmQualitySel->Append(_("9 (lowest quality, fast)"));
}
