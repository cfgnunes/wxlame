/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef CONFIGBASE_H
#define CONFIGBASE_H

#include <wx/string.h>
#include <wx/config.h>

// Config Group Strings
const wxString	CONFIG_SYSTEM_GROUP				= wxT("/System/");
const wxString	CONFIG_GENERAL_GROUP			= wxT("/General/");
const wxString	CONFIG_ADVANCED_GROUP			= wxT("/Advanced/");
const wxString	CONFIG_VBR_GROUP				= wxT("/VBR/");
const wxString	CONFIG_AUDIO_GROUP				= wxT("/Audio/");

// Config Strings

const wxString	CONFIG_STR_LastOpenDir			= wxT("LastOpenDir");

const wxString	CONFIG_STR_Bitrate				= wxT("Bitrate");
const wxString	CONFIG_STR_Mode					= wxT("Mode");
const wxString	CONFIG_STR_EncoderExecutable	= wxT("EncoderExecutable");
const wxString	CONFIG_STR_EnableOutDir			= wxT("EnableOutDir");
const wxString	CONFIG_STR_OutDir				= wxT("OutDir");
const wxString	CONFIG_STR_DeleteFiles			= wxT("DeleteFiles");

const wxString	CONFIG_STR_EnabledVBR			= wxT("EnabledVBR");
const wxString	CONFIG_STR_MaxBitrate			= wxT("MaxBitrate");
const wxString	CONFIG_STR_DisableVBRTag		= wxT("DisableVBRTag");
const wxString	CONFIG_STR_EnforceMinBitrate	= wxT("EnforceMinBitrate");
const wxString	CONFIG_STR_UseABR				= wxT("UseABR");
const wxString	CONFIG_STR_VBRQuality			= wxT("VBRQuality");
const wxString	CONFIG_STR_AverageBitrateABR	= wxT("AverageBitrateABR");

const wxString	CONFIG_STR_MarkNonOriginal		= wxT("MarkNonOriginal");
const wxString	CONFIG_STR_MarkCopyright		= wxT("MarkCopyright");
const wxString	CONFIG_STR_Crc					= wxT("Crc");
const wxString	CONFIG_STR_EnforceISO			= wxT("EnforceISO");
const wxString	CONFIG_STR_AlgorithmQualitySel	= wxT("AlgorithmQualitySel");
const wxString	CONFIG_STR_CustomOptions		= wxT("CustomOptions");

const wxString	CONFIG_STR_Resampling			= wxT("Resampling");
const wxString	CONFIG_STR_HighpassEnabled		= wxT("HighpassEnabled");
const wxString	CONFIG_STR_HighpassFreq			= wxT("HighpassFreq");
const wxString	CONFIG_STR_HighpassWidthEnabled	= wxT("HighpassWidthEnabled");
const wxString	CONFIG_STR_HighpassWidth		= wxT("HighpassWidth");;
const wxString	CONFIG_STR_LowpassEnabled		= wxT("LowpassEnabled");
const wxString	CONFIG_STR_LowpassFreq			= wxT("LowpassFreq");
const wxString	CONFIG_STR_LowpassWidthEnabled	= wxT("LowpassWidthEnabled");
const wxString	CONFIG_STR_LowpassWidth			= wxT("LowpassWidth");

// Default Values
const wxString	DEFAULT_VALUE_LastOpenDir			= wxEmptyString;

const int		DEFAULT_VALUE_Bitrate				= 128;
const int		DEFAULT_VALUE_Mode					= 0;
const wxString	DEFAULT_VALUE_EncoderExecutable		= wxT("lame");
const bool		DEFAULT_VALUE_EnableOutDir			= false;
const wxString	DEFAULT_VALUE_OutDir				= wxT("output/");
const bool		DEFAULT_VALUE_DeleteFiles			= false;

const bool		DEFAULT_VALUE_EnabledVBR			= false;
const bool		DEFAULT_VALUE_MaxBitrate			= 320;
const bool		DEFAULT_VALUE_DisableVBRTag			= false;
const bool		DEFAULT_VALUE_EnforceMinBitrate		= false;
const bool		DEFAULT_VALUE_UseABR				= false;
const int		DEFAULT_VALUE_VBRQuality			= 4;
const int		DEFAULT_VALUE_AverageBitrateABR		= 128;

const bool		DEFAULT_VALUE_MarkNonOriginal		= false;
const bool		DEFAULT_VALUE_MarkCopyright			= false;
const bool		DEFAULT_VALUE_Crc					= false;
const bool		DEFAULT_VALUE_EnforceISO			= false;
const int		DEFAULT_VALUE_AlgorithmQualitySel	= 0;
const wxString	DEFAULT_VALUE_CustomOptions			= wxEmptyString;

const int		DEFAULT_VALUE_Resampling			= 0;
const bool		DEFAULT_VALUE_HighpassEnabled		= false;
const int		DEFAULT_VALUE_HighpassFreq			= 20000;
const bool		DEFAULT_VALUE_HighpassWidthEnabled	= false;
const int		DEFAULT_VALUE_HighpassWidth			= 20000;
const bool		DEFAULT_VALUE_LowpassEnabled		= false;
const int		DEFAULT_VALUE_LowpassFreq			= 20000;
const bool		DEFAULT_VALUE_LowpassWidthEnabled	= false;
const int		DEFAULT_VALUE_LowpassWidth			= 20000;

class ConfigBase
{
public:
    ConfigBase(const wxString & appName = wxEmptyString);
    ~ConfigBase();

    void setDefaultConfig();
    void setConfigFlush();
    wxString getStringLameOptions();

    //gets...
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

    //sets...
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
    wxConfig *config;
};

#endif
