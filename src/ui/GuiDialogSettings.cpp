/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "GuiDialogSettings.hpp"
#include "../Constants.hpp"

GuiDialogSettings::GuiDialogSettings(wxWindow *parent, AppSettings *appSettings) : DialogSettings(parent), mp_appSettings(appSettings) {
    // Set labels of controls
    setLabelsControls();

    // Updates the values controls according to the configuration file
    updateValueControls();

    // Updates the controls that should be disabled
    updateDisabledControls();
}

GuiDialogSettings::~GuiDialogSettings() {
}

void GuiDialogSettings::OnsldBitrateSliderUpdated(wxScrollEvent &event) {
    int number = gui_sldBitrate->GetValue();
    wxString msg;
    msg += _("Current bitrate:");
    msg += wxString::Format(_T(" %i"), BITRATE_VALUES[number]);
    msg += _T(" kbit");
    gui_lblBitrate->SetLabel(msg);

    event.Skip();
}

void GuiDialogSettings::updateDisabledControlsEvent(wxCommandEvent &event) {
    updateDisabledControls();
    event.Skip(false);
}

void GuiDialogSettings::OnsldBitrateVBRSliderUpdated(wxScrollEvent &event) {
    int number = gui_sldBitrateVBR->GetValue();
    wxString msg;
    msg += _("Current bitrate:");
    msg += wxString::Format(_T(" %i"), BITRATE_VALUES[number]);
    msg += _T(" kbit");
    gui_lblBitrateVBR->SetLabel(msg);

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
    for (i = 0; BITRATE_VALUES[i] != mp_appSettings->getBitrate(); i++)
        ;
    gui_sldBitrate->SetValue(i);
    OnsldBitrateSliderUpdated(evt);
    gui_dpkOutputDirectory->SetPath(mp_appSettings->getOutDir());
    gui_optEnableOutDir->SetValue(mp_appSettings->getEnableOutDir());
    gui_optUseSameDir->SetValue(!mp_appSettings->getEnableOutDir());
    gui_chcMode->SetSelection(mp_appSettings->getMode());

    // VBR controls
    gui_chkEnabledVBR->SetValue(mp_appSettings->getEnabledVBR());
    gui_spcVBRQuality->SetValue(mp_appSettings->getVBRQuality());
    for (i = 0; BITRATE_VALUES[i] != mp_appSettings->getMaxBitrate(); i++)
        ;
    gui_sldBitrateVBR->SetValue(i);
    OnsldBitrateVBRSliderUpdated(evt);
    gui_chkDisableVBRTag->SetValue(mp_appSettings->getDisableVBRTag());
    gui_chkEnforceMinBitrate->SetValue(mp_appSettings->getEnforceMinBitrate());
    gui_chkUseABR->SetValue(mp_appSettings->getUseABR());
    gui_spcAverageBitrateABR->SetValue(mp_appSettings->getAverageBitrateABR());

    // Audio controls
    gui_chcResampling->SetSelection(mp_appSettings->getResampling());
    gui_chkHighpass->SetValue(mp_appSettings->getHighpassEnabled());
    gui_spcHighpassFreq->SetValue(mp_appSettings->getHighpassFreq());
    gui_chkHighpassWidth->SetValue(mp_appSettings->getHighpassWidthEnabled());
    gui_spcHighpassWidth->SetValue(mp_appSettings->getHighpassWidth());
    gui_chkLowpass->SetValue(mp_appSettings->getLowpassEnabled());
    gui_spcLowpassFreq->SetValue(mp_appSettings->getLowpassFreq());
    gui_chkLowpassWidth->SetValue(mp_appSettings->getLowpassWidthEnabled());
    gui_spcLowpassWidth->SetValue(mp_appSettings->getLowpassWidth());

    // Advanced controls
    gui_chkCrc->SetValue(mp_appSettings->getCrc());
    gui_chkDeleteFiles->SetValue(mp_appSettings->getDeleteFiles());
    gui_chkMarkNonOriginal->SetValue(mp_appSettings->getMarkNonOriginal());
    gui_chkMarkCopyright->SetValue(mp_appSettings->getMarkCopyright());
    gui_chkEnforceISO->SetValue(mp_appSettings->getEnforceISO());
    gui_chcAlgorithmQualitySel->SetSelection(mp_appSettings->getAlgorithmQualitySel());
    gui_txtCustomOptions->Clear();
    gui_chkCustomOptions->SetValue(mp_appSettings->getCustomOptions());
    gui_txtCustomOptions->WriteText(mp_appSettings->getCustomOptionsText());
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
    mp_appSettings->setBitrate(BITRATE_VALUES[gui_sldBitrate->GetValue()]);
    mp_appSettings->setOutDir(gui_dpkOutputDirectory->GetDirName().GetPath());
    mp_appSettings->setEnableOutDir(gui_optEnableOutDir->GetValue());
    mp_appSettings->setMode(gui_chcMode->GetCurrentSelection());

    // VBR controls
    mp_appSettings->setEnabledVBR(gui_chkEnabledVBR->GetValue());
    mp_appSettings->setVBRQuality(gui_spcVBRQuality->GetValue());
    mp_appSettings->setMaxBitrate(BITRATE_VALUES[gui_sldBitrateVBR->GetValue()]);
    mp_appSettings->setDisableVBRTag(gui_chkDisableVBRTag->GetValue());
    mp_appSettings->setEnforceMinBitrate(gui_chkEnforceMinBitrate->GetValue());
    mp_appSettings->setUseABR(gui_chkUseABR->GetValue());
    mp_appSettings->setAverageBitrateABR(gui_spcAverageBitrateABR->GetValue());

    // Audio controls
    mp_appSettings->setResampling(gui_chcResampling->GetCurrentSelection());
    mp_appSettings->setHighpassEnabled(gui_chkHighpass->GetValue());
    mp_appSettings->setHighpassFreq(gui_spcHighpassFreq->GetValue());
    mp_appSettings->setHighpassWidthEnabled(gui_chkHighpassWidth->GetValue());
    mp_appSettings->setHighpassWidth(gui_spcHighpassWidth->GetValue());
    mp_appSettings->setLowpassEnabled(gui_chkLowpass->GetValue());
    mp_appSettings->setLowpassFreq(gui_spcLowpassFreq->GetValue());
    mp_appSettings->setLowpassWidthEnabled(gui_chkLowpassWidth->GetValue());
    mp_appSettings->setLowpassWidth(gui_spcLowpassWidth->GetValue());

    // Advanced controls
    mp_appSettings->setCrc(gui_chkCrc->GetValue());
    mp_appSettings->setDeleteFiles(gui_chkDeleteFiles->GetValue());
    mp_appSettings->setMarkNonOriginal(gui_chkMarkNonOriginal->GetValue());
    mp_appSettings->setMarkCopyright(gui_chkMarkCopyright->GetValue());
    mp_appSettings->setEnforceISO(gui_chkEnforceISO->GetValue());
    mp_appSettings->setAlgorithmQualitySel(gui_chcAlgorithmQualitySel->GetSelection());
    mp_appSettings->setCustomOptions(gui_chkCustomOptions->GetValue());
    mp_appSettings->setCustomOptionsText(gui_txtCustomOptions->GetLineText(0));

    mp_appSettings->flush();
}

void GuiDialogSettings::defaultValueControls() {
    int i;
    wxScrollEvent evt;

    // General controls
    for (i = 0; BITRATE_VALUES[i] != DEFAULT_VALUE_Bitrate; i++)
        ;
    gui_sldBitrate->SetValue(i);
    OnsldBitrateSliderUpdated(evt);
    gui_dpkOutputDirectory->SetPath(DEFAULT_VALUE_OutDir);

    gui_optEnableOutDir->SetValue(DEFAULT_VALUE_EnableOutDir);
    gui_optUseSameDir->SetValue(!DEFAULT_VALUE_EnableOutDir);
    gui_chcMode->SetSelection(DEFAULT_VALUE_Mode);

    // VBR controls
    gui_chkEnabledVBR->SetValue(DEFAULT_VALUE_EnabledVBR);
    gui_spcVBRQuality->SetValue(DEFAULT_VALUE_VBRQuality);
    for (i = 0; BITRATE_VALUES[i] != DEFAULT_VALUE_MaxBitrate; i++)
        ;
    gui_sldBitrateVBR->SetValue(i);
    OnsldBitrateVBRSliderUpdated(evt);
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
