/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "AppSettings.hpp"
#include "Constants.hpp"

AppSettings::AppSettings(const wxString &appName) {
    mp_config = new wxConfig(appName);

    // If there isn't a setting, writes a new one with default values
    if (getAppVersion().Cmp(APP_VERSION) != 0)
        setDefaultValues();
}

AppSettings::~AppSettings() {
    delete mp_config;
}

void AppSettings::setDefaultValues() {
    setAppVersion(APP_VERSION);
    setLastOpenDir(DEFAULT_VALUE_LastOpenDir);

    setBitrate(DEFAULT_VALUE_Bitrate);
    setMode(DEFAULT_VALUE_Mode);
    setEnableOutDir(DEFAULT_VALUE_EnableOutDir);
    setOutDir(DEFAULT_VALUE_OutDir);
    setDeleteFiles(DEFAULT_VALUE_DeleteFiles);

    setEnabledVBR(DEFAULT_VALUE_EnabledVBR);
    setMaxBitrate(DEFAULT_VALUE_MaxBitrate);
    setDisableVBRTag(DEFAULT_VALUE_DisableVBRTag);
    setEnforceMinBitrate(DEFAULT_VALUE_EnforceMinBitrate);
    setUseABR(DEFAULT_VALUE_UseABR);
    setVBRQuality(DEFAULT_VALUE_VBRQuality);
    setAverageBitrateABR(DEFAULT_VALUE_AverageBitrateABR);

    setResampling(DEFAULT_VALUE_Resampling);
    setHighpassEnabled(DEFAULT_VALUE_HighpassEnabled);
    setHighpassFreq(DEFAULT_VALUE_HighpassFreq);
    setHighpassWidth(DEFAULT_VALUE_HighpassWidth);
    setHighpassWidth(DEFAULT_VALUE_HighpassWidth);
    setLowpassEnabled(DEFAULT_VALUE_LowpassEnabled);
    setLowpassFreq(DEFAULT_VALUE_LowpassFreq);
    setLowpassWidthEnabled(DEFAULT_VALUE_LowpassWidthEnabled);
    setLowpassWidth(DEFAULT_VALUE_LowpassWidth);

    setMarkNonOriginal(DEFAULT_VALUE_MarkNonOriginal);
    setMarkCopyright(DEFAULT_VALUE_MarkCopyright);
    setCrc(DEFAULT_VALUE_Crc);
    setEnforceISO(DEFAULT_VALUE_EnforceISO);
    setAlgorithmQualitySel(DEFAULT_VALUE_AlgorithmQualitySel);
    setCustomOptions(DEFAULT_VALUE_CustomOptions);
    setCustomOptionsText(DEFAULT_VALUE_CustomOptionsText);
}

void AppSettings::flush() {
    mp_config->Flush();
}

wxString AppSettings::getStringLameOptions() const {
    wxString lameOptions;

    if (getCustomOptions()) {
        lameOptions.append(getCustomOptionsText());
        return lameOptions;
    }

    // Bitrate
    lameOptions.append(_T("-b ") + wxString::Format(_T("%i "), getBitrate()));

    // Mode
    switch (getMode()) {
        default:
        case MODE_JOINT:
            lameOptions.append(_T("-m j "));
            break;
        case MODE_SIMPLE:
            lameOptions.append(_T("-m s "));
            break;
        case MODE_FORCE:
            lameOptions.append(_T("-m f "));
            break;
        case MODE_DUAL_MONO:
            lameOptions.append(_T("-m d "));
            break;
        case MODE_MONO:
            lameOptions.append(_T("-m m "));
            break;
    }

    // Crc
    if (getCrc())
        lameOptions.append(_T("-p "));

    // MarkNonOriginal
    if (getMarkNonOriginal())
        lameOptions.append(_T("-o "));

    // MarkCopyright
    if (getMarkCopyright())
        lameOptions.append(_T("-c "));

    // VBR
    if (getEnabledVBR()) {
        if (!getUseABR())
            // VBR quality
            lameOptions.append(_T("-V ") + wxString::Format(_T("%i "), getVBRQuality()));
        else
            // ABR bitrate
            lameOptions.append(_T("--abr ") + wxString::Format(_T("%i "), getAverageBitrateABR()));

        // VBR max bitrate
        lameOptions.append(_T("-B ") + wxString::Format(_T("%i "), getMaxBitrate()));

        // Disable TAG
        if (getDisableVBRTag())
            lameOptions.append(_T("-t "));

        // EnforceMinBitrate
        if (getEnforceMinBitrate())
            lameOptions.append(_T("-F "));
    }

    if (getEnforceISO())
        lameOptions.append(_T("--strictly-enforce-ISO "));

    if (getAlgorithmQualitySel() > 0)
        lameOptions.append(_T("-q ") + wxString::Format(_T("%i "), getAlgorithmQualitySel() - 1));

    if (getResampling() > 0)
        lameOptions.append(_T("--resample ") + RESAMPLING_VALUES[getResampling() - 1] + _T(" "));

    if (getHighpassEnabled())
        lameOptions.append(_T("--highpass ") + wxString::Format(_T("%i "), getHighpassFreq()));

    if (getHighpassEnabled() && getHighpassWidthEnabled())
        lameOptions.append(_T("--highpass-width ") + wxString::Format(_T("%i "), getHighpassWidth()));

    if (getLowpassEnabled())
        lameOptions.append(_T("--lowpass ") + wxString::Format(_T("%i "), getLowpassFreq()));

    if (getLowpassEnabled() && getLowpassWidth())
        lameOptions.append(_T("--lowpass-width ") + wxString::Format(_T("%i "), getLowpassWidth()));

    lameOptions.Trim();
    return lameOptions;
}

// Gets

wxString AppSettings::getAppVersion() const {
    wxString value = wxEmptyString;
    mp_config->Read(CONFIG_GROUP_SYSTEM + CONFIG_STR_AppVersion, &value);
    return value;
}

wxString AppSettings::getLastOpenDir() const {
    wxString value = wxEmptyString;
    mp_config->Read(CONFIG_GROUP_SYSTEM + CONFIG_STR_LastOpenDir, &value);
    return value;
}

int AppSettings::getBitrate() const {
    int value;
    mp_config->Read(CONFIG_GROUP_GENERAL + CONFIG_STR_Bitrate, &value);
    return value;
}

int AppSettings::getMode() const {
    int value;
    mp_config->Read(CONFIG_GROUP_GENERAL + CONFIG_STR_Mode, &value);
    return value;
}

bool AppSettings::getEnableOutDir() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_GENERAL + CONFIG_STR_EnableOutDir, &value);
    return value;
}

wxString AppSettings::getOutDir() const {
    wxString value = wxEmptyString;
    mp_config->Read(CONFIG_GROUP_GENERAL + CONFIG_STR_OutDir, &value);
    return value;
}

bool AppSettings::getDeleteFiles() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_GENERAL + CONFIG_STR_DeleteFiles, &value);
    return value;
}

bool AppSettings::getEnabledVBR() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_VBR + CONFIG_STR_EnabledVBR, &value);
    return value;
}

int AppSettings::getMaxBitrate() const {
    int value;
    mp_config->Read(CONFIG_GROUP_VBR + CONFIG_STR_MaxBitrate, &value);
    return value;
}

bool AppSettings::getDisableVBRTag() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_VBR + CONFIG_STR_DisableVBRTag, &value);
    return value;
}

bool AppSettings::getEnforceMinBitrate() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_VBR + CONFIG_STR_EnforceMinBitrate, &value);
    return value;
}

bool AppSettings::getUseABR() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_VBR + CONFIG_STR_UseABR, &value);
    return value;
}

int AppSettings::getVBRQuality() const {
    int value;
    mp_config->Read(CONFIG_GROUP_VBR + CONFIG_STR_VBRQuality, &value);
    return value;
}

int AppSettings::getAverageBitrateABR() const {
    int value;
    mp_config->Read(CONFIG_GROUP_VBR + CONFIG_STR_AverageBitrateABR, &value);
    return value;
}

int AppSettings::getResampling() const {
    int value;
    mp_config->Read(CONFIG_GROUP_AUDIO + CONFIG_STR_Resampling, &value);
    return value;
}

bool AppSettings::getHighpassEnabled() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_AUDIO + CONFIG_STR_HighpassEnabled, &value);
    return value;
}

int AppSettings::getHighpassFreq() const {
    int value;
    mp_config->Read(CONFIG_GROUP_AUDIO + CONFIG_STR_HighpassFreq, &value);
    return value;
}

bool AppSettings::getHighpassWidthEnabled() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_AUDIO + CONFIG_STR_HighpassWidthEnabled, &value);
    return value;
}

int AppSettings::getHighpassWidth() const {
    int value;
    mp_config->Read(CONFIG_GROUP_AUDIO + CONFIG_STR_HighpassWidth, &value);
    return value;
}

bool AppSettings::getLowpassEnabled() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_AUDIO + CONFIG_STR_LowpassEnabled, &value);
    return value;
}

int AppSettings::getLowpassFreq() const {
    int value;
    mp_config->Read(CONFIG_GROUP_AUDIO + CONFIG_STR_LowpassFreq, &value);
    return value;
}

bool AppSettings::getLowpassWidthEnabled() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_AUDIO + CONFIG_STR_LowpassWidthEnabled, &value);
    return value;
}

int AppSettings::getLowpassWidth() const {
    int value;
    mp_config->Read(CONFIG_GROUP_AUDIO + CONFIG_STR_LowpassWidth, &value);
    return value;
}

bool AppSettings::getMarkNonOriginal() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_ADVANCED + CONFIG_STR_MarkNonOriginal, &value);
    return value;
}

bool AppSettings::getMarkCopyright() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_ADVANCED + CONFIG_STR_MarkCopyright, &value);
    return value;
}

bool AppSettings::getCrc() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_ADVANCED + CONFIG_STR_Crc, &value);
    return value;
}

bool AppSettings::getEnforceISO() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_ADVANCED + CONFIG_STR_EnforceISO, &value);
    return value;
}

int AppSettings::getAlgorithmQualitySel() const {
    int value;
    mp_config->Read(CONFIG_GROUP_ADVANCED + CONFIG_STR_AlgorithmQualitySel, &value);
    return value;
}

bool AppSettings::getCustomOptions() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_ADVANCED + CONFIG_STR_CustomOptions, &value);
    return value;
}

wxString AppSettings::getCustomOptionsText() const {
    wxString value = wxEmptyString;
    mp_config->Read(CONFIG_GROUP_ADVANCED + CONFIG_STR_CustomOptionsText, &value);
    return value;
}

// Sets

void AppSettings::setAppVersion(wxString value) {
    mp_config->Write(CONFIG_GROUP_SYSTEM + CONFIG_STR_AppVersion, value);
}

void AppSettings::setLastOpenDir(wxString value) {
    mp_config->Write(CONFIG_GROUP_SYSTEM + CONFIG_STR_LastOpenDir, value);
}

void AppSettings::setBitrate(int value) {
    mp_config->Write(CONFIG_GROUP_GENERAL + CONFIG_STR_Bitrate, value);
}

void AppSettings::setMode(int value) {
    mp_config->Write(CONFIG_GROUP_GENERAL + CONFIG_STR_Mode, value);
}

void AppSettings::setEnableOutDir(bool value) {
    mp_config->Write(CONFIG_GROUP_GENERAL + CONFIG_STR_EnableOutDir, value);
}

void AppSettings::setOutDir(wxString value) {
    mp_config->Write(CONFIG_GROUP_GENERAL + CONFIG_STR_OutDir, value);
}

void AppSettings::setDeleteFiles(bool value) {
    mp_config->Write(CONFIG_GROUP_GENERAL + CONFIG_STR_DeleteFiles, value);
}

void AppSettings::setEnabledVBR(bool value) {
    mp_config->Write(CONFIG_GROUP_VBR + CONFIG_STR_EnabledVBR, value);
}

void AppSettings::setMaxBitrate(int value) {
    mp_config->Write(CONFIG_GROUP_VBR + CONFIG_STR_MaxBitrate, value);
}

void AppSettings::setDisableVBRTag(bool value) {
    mp_config->Write(CONFIG_GROUP_VBR + CONFIG_STR_DisableVBRTag, value);
}

void AppSettings::setEnforceMinBitrate(bool value) {
    mp_config->Write(CONFIG_GROUP_VBR + CONFIG_STR_EnforceMinBitrate, value);
}

void AppSettings::setUseABR(bool value) {
    mp_config->Write(CONFIG_GROUP_VBR + CONFIG_STR_UseABR, value);
}

void AppSettings::setVBRQuality(int value) {
    mp_config->Write(CONFIG_GROUP_VBR + CONFIG_STR_VBRQuality, value);
}

void AppSettings::setAverageBitrateABR(int value) {
    mp_config->Write(CONFIG_GROUP_VBR + CONFIG_STR_AverageBitrateABR, value);
}

void AppSettings::setResampling(int value) {
    mp_config->Write(CONFIG_GROUP_AUDIO + CONFIG_STR_Resampling, value);
}

void AppSettings::setHighpassEnabled(bool value) {
    mp_config->Write(CONFIG_GROUP_AUDIO + CONFIG_STR_HighpassEnabled, value);
}

void AppSettings::setHighpassFreq(int value) {
    mp_config->Write(CONFIG_GROUP_AUDIO + CONFIG_STR_HighpassFreq, value);
}

void AppSettings::setHighpassWidthEnabled(bool value) {
    mp_config->Write(CONFIG_GROUP_AUDIO + CONFIG_STR_HighpassWidthEnabled, value);
}

void AppSettings::setHighpassWidth(int value) {
    mp_config->Write(CONFIG_GROUP_AUDIO + CONFIG_STR_HighpassWidth, value);;
}

void AppSettings::setLowpassEnabled(bool value) {
    mp_config->Write(CONFIG_GROUP_AUDIO + CONFIG_STR_LowpassEnabled, value);
}

void AppSettings::setLowpassFreq(int value) {
    mp_config->Write(CONFIG_GROUP_AUDIO + CONFIG_STR_LowpassFreq, value);
}

void AppSettings::setLowpassWidthEnabled(bool value) {
    mp_config->Write(CONFIG_GROUP_AUDIO + CONFIG_STR_LowpassWidthEnabled, value);
}

void AppSettings::setLowpassWidth(int value) {
    mp_config->Write(CONFIG_GROUP_AUDIO + CONFIG_STR_LowpassWidth, value);
}

void AppSettings::setMarkNonOriginal(bool value) {
    mp_config->Write(CONFIG_GROUP_ADVANCED + CONFIG_STR_MarkNonOriginal, value);
}

void AppSettings::setMarkCopyright(bool value) {
    mp_config->Write(CONFIG_GROUP_ADVANCED + CONFIG_STR_MarkCopyright, value);
}

void AppSettings::setCrc(bool value) {
    mp_config->Write(CONFIG_GROUP_ADVANCED + CONFIG_STR_Crc, value);
}

void AppSettings::setEnforceISO(bool value) {
    mp_config->Write(CONFIG_GROUP_ADVANCED + CONFIG_STR_EnforceISO, value);
}

void AppSettings::setAlgorithmQualitySel(int value) {
    mp_config->Write(CONFIG_GROUP_ADVANCED + CONFIG_STR_AlgorithmQualitySel, value);
}

void AppSettings::setCustomOptions(bool value) {
    mp_config->Write(CONFIG_GROUP_ADVANCED + CONFIG_STR_CustomOptions, value);
}

void AppSettings::setCustomOptionsText(wxString value) {
    mp_config->Write(CONFIG_GROUP_ADVANCED + CONFIG_STR_CustomOptionsText, value);
}
