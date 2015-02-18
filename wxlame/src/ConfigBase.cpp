/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "ConfigBase.h"
#include "Global.h"

ConfigBase::ConfigBase(const wxString& appName) {
    mp_config = new wxConfig(appName);

    // If there isn't a setting, writes a new one with default values
    if (!mp_config->Exists(CONFIG_GENERAL_GROUP))
        setDefaultConfig();
}

ConfigBase::~ConfigBase() {
    delete mp_config;
}

void ConfigBase::setDefaultConfig() {
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

    setMarkNonOriginal(DEFAULT_VALUE_MarkNonOriginal);
    setMarkCopyright(DEFAULT_VALUE_MarkCopyright);
    setCrc(DEFAULT_VALUE_Crc);
    setEnforceISO(DEFAULT_VALUE_EnforceISO);
    setAlgorithmQualitySel(DEFAULT_VALUE_AlgorithmQualitySel);
    setCustomOptions(DEFAULT_VALUE_CustomOptions);

    setResampling(DEFAULT_VALUE_Resampling);
    setHighpassEnabled(DEFAULT_VALUE_HighpassEnabled);
    setHighpassFreq(DEFAULT_VALUE_HighpassFreq);
    setHighpassWidth(DEFAULT_VALUE_HighpassWidth);
    setHighpassWidth(DEFAULT_VALUE_HighpassWidth);
    setLowpassEnabled(DEFAULT_VALUE_LowpassEnabled);
    setLowpassFreq(DEFAULT_VALUE_LowpassFreq);
    setLowpassWidthEnabled(DEFAULT_VALUE_LowpassWidthEnabled);
    setLowpassWidth(DEFAULT_VALUE_LowpassWidth);
}

void ConfigBase::configFlush() {
    mp_config->Flush();
}

wxString ConfigBase::getStringLameOptions() const {
    wxString lameOptions;

    // Bitrate
    lameOptions.append(_T("-b ") + wxString::Format(_T("%i "), getBitrate()));

    // Mode
    switch (getMode()) {
        case 1:
            lameOptions.append(_T("-m j "));
            break;
        case 2:
            lameOptions.append(_T("-m s "));
            break;
        case 3:
            lameOptions.append(_T("-m f "));
            break;
        case 4:
            lameOptions.append(_T("-m d "));
            break;
        case 5:
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

    lameOptions.append(getCustomOptions());

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

// Gets...

wxString ConfigBase::getLastOpenDir() const {
    wxString value = wxEmptyString;
    mp_config->Read(CONFIG_SYSTEM_GROUP + CONFIG_STR_LastOpenDir, &value);
    return value;
}

int ConfigBase::getBitrate() const {
    int value;
    mp_config->Read(CONFIG_GENERAL_GROUP + CONFIG_STR_Bitrate, &value);
    return value;
}

int ConfigBase::getMode() const {
    int value;
    mp_config->Read(CONFIG_GENERAL_GROUP + CONFIG_STR_Mode, &value);
    return value;
}

bool ConfigBase::getEnableOutDir() const {
    bool value;
    mp_config->Read(CONFIG_GENERAL_GROUP + CONFIG_STR_EnableOutDir, &value);
    return value;
}

wxString ConfigBase::getOutDir() const {
    wxString value = wxEmptyString;
    mp_config->Read(CONFIG_GENERAL_GROUP + CONFIG_STR_OutDir, &value);
    return value;
}

bool ConfigBase::getDeleteFiles() const {
    bool value;
    mp_config->Read(CONFIG_GENERAL_GROUP + CONFIG_STR_DeleteFiles, &value);
    return value;
}

bool ConfigBase::getEnabledVBR() const {
    bool value;
    mp_config->Read(CONFIG_VBR_GROUP + CONFIG_STR_EnabledVBR, &value);
    return value;
}

int ConfigBase::getMaxBitrate() const {
    int value;
    mp_config->Read(CONFIG_VBR_GROUP + CONFIG_STR_MaxBitrate, &value);
    return value;
}

bool ConfigBase::getDisableVBRTag() const {
    bool value;
    mp_config->Read(CONFIG_VBR_GROUP + CONFIG_STR_DisableVBRTag, &value);
    return value;
}

bool ConfigBase::getEnforceMinBitrate() const {
    bool value;
    mp_config->Read(CONFIG_VBR_GROUP + CONFIG_STR_EnforceMinBitrate, &value);
    return value;
}

bool ConfigBase::getUseABR() const {
    bool value;
    mp_config->Read(CONFIG_VBR_GROUP + CONFIG_STR_UseABR, &value);
    return value;
}

int ConfigBase::getVBRQuality() const {
    int value;
    mp_config->Read(CONFIG_VBR_GROUP + CONFIG_STR_VBRQuality, &value);
    return value;
}

int ConfigBase::getAverageBitrateABR() const {
    int value;
    mp_config->Read(CONFIG_VBR_GROUP + CONFIG_STR_AverageBitrateABR, &value);
    return value;
}

bool ConfigBase::getMarkNonOriginal() const {
    bool value;
    mp_config->Read(CONFIG_ADVANCED_GROUP + CONFIG_STR_MarkNonOriginal, &value);
    return value;
}

bool ConfigBase::getMarkCopyright() const {
    bool value;
    mp_config->Read(CONFIG_ADVANCED_GROUP + CONFIG_STR_MarkCopyright, &value);
    return value;
}

bool ConfigBase::getCrc() const {
    bool value;
    mp_config->Read(CONFIG_ADVANCED_GROUP + CONFIG_STR_Crc, &value);
    return value;
}

bool ConfigBase::getEnforceISO() const {
    bool value;
    mp_config->Read(CONFIG_ADVANCED_GROUP + CONFIG_STR_EnforceISO, &value);
    return value;
}

int ConfigBase::getAlgorithmQualitySel() const {
    int value;
    mp_config->Read(CONFIG_ADVANCED_GROUP + CONFIG_STR_AlgorithmQualitySel, &value);
    return value;
}

wxString ConfigBase::getCustomOptions() const {
    wxString value = wxEmptyString;
    mp_config->Read(CONFIG_ADVANCED_GROUP + CONFIG_STR_CustomOptions, &value);
    return value;
}

int ConfigBase::getResampling() const {
    int value;
    mp_config->Read(CONFIG_AUDIO_GROUP + CONFIG_STR_Resampling, &value);
    return value;
}

bool ConfigBase::getHighpassEnabled() const {
    bool value;
    mp_config->Read(CONFIG_AUDIO_GROUP + CONFIG_STR_HighpassEnabled, &value);
    return value;
}

int ConfigBase::getHighpassFreq() const {
    int value;
    mp_config->Read(CONFIG_AUDIO_GROUP + CONFIG_STR_HighpassFreq, &value);
    return value;
}

bool ConfigBase::getHighpassWidthEnabled() const {
    bool value;
    mp_config->Read(CONFIG_AUDIO_GROUP + CONFIG_STR_HighpassWidthEnabled, &value);
    return value;
}

int ConfigBase::getHighpassWidth() const {
    int value;
    mp_config->Read(CONFIG_AUDIO_GROUP + CONFIG_STR_HighpassWidth, &value);
    return value;
}

bool ConfigBase::getLowpassEnabled() const {
    bool value;
    mp_config->Read(CONFIG_AUDIO_GROUP + CONFIG_STR_LowpassEnabled, &value);
    return value;
}

int ConfigBase::getLowpassFreq() const {
    int value;
    mp_config->Read(CONFIG_AUDIO_GROUP + CONFIG_STR_LowpassFreq, &value);
    return value;
}

bool ConfigBase::getLowpassWidthEnabled() const {
    bool value;
    mp_config->Read(CONFIG_AUDIO_GROUP + CONFIG_STR_LowpassWidthEnabled, &value);
    return value;
}

int ConfigBase::getLowpassWidth() const {
    int value;
    mp_config->Read(CONFIG_AUDIO_GROUP + CONFIG_STR_LowpassWidth, &value);
    return value;
}

// Sets...

void ConfigBase::setLastOpenDir(wxString value) {
    mp_config->Write(CONFIG_SYSTEM_GROUP + CONFIG_STR_LastOpenDir, value);
}

void ConfigBase::setBitrate(int value) {
    mp_config->Write(CONFIG_GENERAL_GROUP + CONFIG_STR_Bitrate, value);
}

void ConfigBase::setMode(int value) {
    mp_config->Write(CONFIG_GENERAL_GROUP + CONFIG_STR_Mode, value);
}

void ConfigBase::setEnableOutDir(bool value) {
    mp_config->Write(CONFIG_GENERAL_GROUP + CONFIG_STR_EnableOutDir, value);
}

void ConfigBase::setOutDir(wxString value) {
    mp_config->Write(CONFIG_GENERAL_GROUP + CONFIG_STR_OutDir, value);
}

void ConfigBase::setDeleteFiles(bool value) {
    mp_config->Write(CONFIG_GENERAL_GROUP + CONFIG_STR_DeleteFiles, value);
}

void ConfigBase::setEnabledVBR(bool value) {
    mp_config->Write(CONFIG_VBR_GROUP + CONFIG_STR_EnabledVBR, value);
}

void ConfigBase::setMaxBitrate(int value) {
    mp_config->Write(CONFIG_VBR_GROUP + CONFIG_STR_MaxBitrate, value);
}

void ConfigBase::setDisableVBRTag(bool value) {
    mp_config->Write(CONFIG_VBR_GROUP + CONFIG_STR_DisableVBRTag, value);
}

void ConfigBase::setEnforceMinBitrate(bool value) {
    mp_config->Write(CONFIG_VBR_GROUP + CONFIG_STR_EnforceMinBitrate, value);
}

void ConfigBase::setUseABR(bool value) {
    mp_config->Write(CONFIG_VBR_GROUP + CONFIG_STR_UseABR, value);
}

void ConfigBase::setVBRQuality(int value) {
    mp_config->Write(CONFIG_VBR_GROUP + CONFIG_STR_VBRQuality, value);
}

void ConfigBase::setAverageBitrateABR(int value) {
    mp_config->Write(CONFIG_VBR_GROUP + CONFIG_STR_AverageBitrateABR, value);
}

void ConfigBase::setMarkNonOriginal(bool value) {
    mp_config->Write(CONFIG_ADVANCED_GROUP + CONFIG_STR_MarkNonOriginal, value);
}

void ConfigBase::setMarkCopyright(bool value) {
    mp_config->Write(CONFIG_ADVANCED_GROUP + CONFIG_STR_MarkCopyright, value);
}

void ConfigBase::setCrc(bool value) {
    mp_config->Write(CONFIG_ADVANCED_GROUP + CONFIG_STR_Crc, value);
}

void ConfigBase::setEnforceISO(bool value) {
    mp_config->Write(CONFIG_ADVANCED_GROUP + CONFIG_STR_EnforceISO, value);
}

void ConfigBase::setAlgorithmQualitySel(int value) {
    mp_config->Write(CONFIG_ADVANCED_GROUP + CONFIG_STR_AlgorithmQualitySel, value);
}

void ConfigBase::setCustomOptions(wxString value) {
    mp_config->Write(CONFIG_ADVANCED_GROUP + CONFIG_STR_CustomOptions, value);
}

void ConfigBase::setResampling(int value) {
    mp_config->Write(CONFIG_AUDIO_GROUP + CONFIG_STR_Resampling, value);
}

void ConfigBase::setHighpassEnabled(bool value) {
    mp_config->Write(CONFIG_AUDIO_GROUP + CONFIG_STR_HighpassEnabled, value);
}

void ConfigBase::setHighpassFreq(int value) {
    mp_config->Write(CONFIG_AUDIO_GROUP + CONFIG_STR_HighpassFreq, value);
}

void ConfigBase::setHighpassWidthEnabled(bool value) {
    mp_config->Write(CONFIG_AUDIO_GROUP + CONFIG_STR_HighpassWidthEnabled, value);
}

void ConfigBase::setHighpassWidth(int value) {
    mp_config->Write(CONFIG_AUDIO_GROUP + CONFIG_STR_HighpassWidth, value);
    ;
}

void ConfigBase::setLowpassEnabled(bool value) {
    mp_config->Write(CONFIG_AUDIO_GROUP + CONFIG_STR_LowpassEnabled, value);
}

void ConfigBase::setLowpassFreq(int value) {
    mp_config->Write(CONFIG_AUDIO_GROUP + CONFIG_STR_LowpassFreq, value);
}

void ConfigBase::setLowpassWidthEnabled(bool value) {
    mp_config->Write(CONFIG_AUDIO_GROUP + CONFIG_STR_LowpassWidthEnabled, value);
}

void ConfigBase::setLowpassWidth(int value) {
    mp_config->Write(CONFIG_AUDIO_GROUP + CONFIG_STR_LowpassWidth, value);
}
