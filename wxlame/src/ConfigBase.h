/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef CONFIGBASE_H
#define CONFIGBASE_H

#include <wx/string.h>
#include <wx/config.h>

// Config Group Strings
const wxString CONFIG_SYSTEM_GROUP = _T("/System/");
const wxString CONFIG_GENERAL_GROUP = _T("/General/");
const wxString CONFIG_ADVANCED_GROUP = _T("/Advanced/");
const wxString CONFIG_VBR_GROUP = _T("/VBR/");
const wxString CONFIG_AUDIO_GROUP = _T("/Audio/");

// Config Strings
const wxString CONFIG_STR_LastOpenDir = _T("LastOpenDir");
const wxString CONFIG_STR_Bitrate = _T("Bitrate");
const wxString CONFIG_STR_Mode = _T("Mode");
const wxString CONFIG_STR_EncoderExecutable = _T("EncoderExecutable");
const wxString CONFIG_STR_EnableOutDir = _T("EnableOutDir");
const wxString CONFIG_STR_OutDir = _T("OutDir");
const wxString CONFIG_STR_DeleteFiles = _T("DeleteFiles");
const wxString CONFIG_STR_EnabledVBR = _T("EnabledVBR");
const wxString CONFIG_STR_MaxBitrate = _T("MaxBitrate");
const wxString CONFIG_STR_DisableVBRTag = _T("DisableVBRTag");
const wxString CONFIG_STR_EnforceMinBitrate = _T("EnforceMinBitrate");
const wxString CONFIG_STR_UseABR = _T("UseABR");
const wxString CONFIG_STR_VBRQuality = _T("VBRQuality");
const wxString CONFIG_STR_AverageBitrateABR = _T("AverageBitrateABR");
const wxString CONFIG_STR_MarkNonOriginal = _T("MarkNonOriginal");
const wxString CONFIG_STR_MarkCopyright = _T("MarkCopyright");
const wxString CONFIG_STR_Crc = _T("Crc");
const wxString CONFIG_STR_EnforceISO = _T("EnforceISO");
const wxString CONFIG_STR_AlgorithmQualitySel = _T("AlgorithmQualitySel");
const wxString CONFIG_STR_CustomOptions = _T("CustomOptions");
const wxString CONFIG_STR_Resampling = _T("Resampling");
const wxString CONFIG_STR_HighpassEnabled = _T("HighpassEnabled");
const wxString CONFIG_STR_HighpassFreq = _T("HighpassFreq");
const wxString CONFIG_STR_HighpassWidthEnabled = _T("HighpassWidthEnabled");
const wxString CONFIG_STR_HighpassWidth = _T("HighpassWidth");
const wxString CONFIG_STR_LowpassEnabled = _T("LowpassEnabled");
const wxString CONFIG_STR_LowpassFreq = _T("LowpassFreq");
const wxString CONFIG_STR_LowpassWidthEnabled = _T("LowpassWidthEnabled");
const wxString CONFIG_STR_LowpassWidth = _T("LowpassWidth");

// Default Values
const wxString DEFAULT_VALUE_LastOpenDir = wxEmptyString;
const int DEFAULT_VALUE_Bitrate = 192;
const int DEFAULT_VALUE_Mode = 0;
const wxString DEFAULT_VALUE_EncoderExecutable = _T("lame");
const bool DEFAULT_VALUE_EnableOutDir = false;
const wxString DEFAULT_VALUE_OutDir = _T("output/");
const bool DEFAULT_VALUE_DeleteFiles = false;
const bool DEFAULT_VALUE_EnabledVBR = false;
const bool DEFAULT_VALUE_MaxBitrate = 320;
const bool DEFAULT_VALUE_DisableVBRTag = false;
const bool DEFAULT_VALUE_EnforceMinBitrate = false;
const bool DEFAULT_VALUE_UseABR = false;
const int DEFAULT_VALUE_VBRQuality = 4;
const int DEFAULT_VALUE_AverageBitrateABR = 128;
const bool DEFAULT_VALUE_MarkNonOriginal = false;
const bool DEFAULT_VALUE_MarkCopyright = false;
const bool DEFAULT_VALUE_Crc = false;
const bool DEFAULT_VALUE_EnforceISO = false;
const int DEFAULT_VALUE_AlgorithmQualitySel = 0;
const wxString DEFAULT_VALUE_CustomOptions = wxEmptyString;
const int DEFAULT_VALUE_Resampling = 0;
const bool DEFAULT_VALUE_HighpassEnabled = false;
const int DEFAULT_VALUE_HighpassFreq = 20000;
const bool DEFAULT_VALUE_HighpassWidthEnabled = false;
const int DEFAULT_VALUE_HighpassWidth = 20000;
const bool DEFAULT_VALUE_LowpassEnabled = false;
const int DEFAULT_VALUE_LowpassFreq = 20000;
const bool DEFAULT_VALUE_LowpassWidthEnabled = false;
const int DEFAULT_VALUE_LowpassWidth = 20000;

class ConfigBase {
public:
    ConfigBase(const wxString& appName = wxEmptyString);
    ~ConfigBase();

    void setDefaultConfig();
    void configFlush();
    wxString getStringLameOptions();

    // Gets...
    wxString getLastOpenDir();
    int getBitrate();
    int getMode();
    wxString getEncoderExecutable();
    bool getEnableOutDir();
    wxString getOutDir();
    bool getDeleteFiles();
    bool getEnabledVBR();
    int getMaxBitrate();
    bool getDisableVBRTag();
    bool getEnforceMinBitrate();
    bool getUseABR();
    int getVBRQuality();
    int getAverageBitrateABR();
    bool getMarkNonOriginal();
    bool getMarkCopyright();
    bool getCrc();
    bool getEnforceISO();
    int getAlgorithmQualitySel();
    wxString getCustomOptions();
    int getResampling();
    bool getHighpassEnabled();
    int getHighpassFreq();
    bool getHighpassWidthEnabled();
    int getHighpassWidth();
    bool getLowpassEnabled();
    int getLowpassFreq();
    bool getLowpassWidthEnabled();
    int getLowpassWidth();

    // Sets...
    void setLastOpenDir(wxString value);
    void setBitrate(int value);
    void setMode(int value);
    void setEncoderExecutable(wxString value);
    void setEnableOutDir(bool value);
    void setOutDir(wxString value);
    void setDeleteFiles(bool value);
    void setEnabledVBR(bool value);
    void setMaxBitrate(int value);
    void setDisableVBRTag(bool value);
    void setEnforceMinBitrate(bool value);
    void setUseABR(bool value);
    void setVBRQuality(int value);
    void setAverageBitrateABR(int value);
    void setMarkNonOriginal(bool value);
    void setMarkCopyright(bool value);
    void setCrc(bool value);
    void setEnforceISO(bool value);
    void setAlgorithmQualitySel(int value);
    void setCustomOptions(wxString value);
    void setResampling(int value);
    void setHighpassEnabled(bool value);
    void setHighpassFreq(int value);
    void setHighpassWidthEnabled(bool value);
    void setHighpassWidth(int value);
    void setLowpassEnabled(bool value);
    void setLowpassFreq(int value);
    void setLowpassWidthEnabled(bool value);
    void setLowpassWidth(int value);

private:
    wxConfig *mp_config;
};

#endif // CONFIGBASE_H
