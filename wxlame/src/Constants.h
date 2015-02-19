/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <wx/string.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>

const wxString APP_NAME = _T("wxLame");
const wxString APP_VERSION = _T("3.4");
const wxString APP_NAME_WITH_VERSION = APP_NAME + _T(" v") + APP_VERSION;

const wxString APP_AUTHOR = _T("Cristiano Nunes <cfgnunes@gmail.com>");
const wxString APP_COPYRIGHT = _T("(C) 2011-2015 Cristiano Nunes <cfgnunes@gmail.com>");
const wxString APP_WEBSITE = _T("http://sourceforge.net/projects/wxlame/");

const wxString APP_TOOL_EXECUTABLE = _T("lame");
const wxString APP_WILDCARD_EXT = _T("Audio files|*.mp3;*.wav;*.aif;*.aiff;*.ape;*.MP3;*.WAV;*.AIF;*.AIFF;*.APE|MP3 files (*.mp3)|*.mp3;*.MP3|Wave files (*.wav)|*.wav;*.WAV|AIFF files (*.aif;*.aiff)|*.aif;*.aiff;*.AIF;*.AIFF|Monkey's audio files (*.ape)|*.ape;*.APE");
const wxString APP_OPEN_EXT = _T("mp3;wav;aif;aiff;ape");

const int BITRATE_VALUES[] = {8, 16, 24, 32, 40, 48, 56, 64, 80, 96, 112, 128, 144, 160, 192, 224, 256, 320};
const int BITRATE_VALUES_SIZE = 18;

const wxString RESAMPLING_VALUES[] = {_T("8"), _T("11.025"), _T("12"), _T("16"), _T("22.05"), _T("24"), _T("32"), _T("44.1"), _T("48")};
const int RESAMPLING_VALUES_SIZE = 9;

// Config Group Strings
const wxString CONFIG_GROUP_SYSTEM = _T("/System/");
const wxString CONFIG_GROUP_GENERAL = _T("/General/");
const wxString CONFIG_GROUP_ADVANCED = _T("/Advanced/");
const wxString CONFIG_GROUP_VBR = _T("/VBR/");
const wxString CONFIG_GROUP_AUDIO = _T("/Audio/");

// Config Strings
const wxString CONFIG_STR_AppVersion = _T("AppVersion");
const wxString CONFIG_STR_LastOpenDir = _T("LastOpenDir");
const wxString CONFIG_STR_Bitrate = _T("Bitrate");
const wxString CONFIG_STR_Mode = _T("Mode");
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
const wxString CONFIG_STR_CustomOptionsText = _T("CustomOptionsText");
const wxString CONFIG_STR_Resampling = _T("Resampling");
const wxString CONFIG_STR_HighpassEnabled = _T("HighpassEnabled");
const wxString CONFIG_STR_HighpassFreq = _T("HighpassFreq");
const wxString CONFIG_STR_HighpassWidthEnabled = _T("HighpassWidthEnabled");
const wxString CONFIG_STR_HighpassWidth = _T("HighpassWidth");
const wxString CONFIG_STR_LowpassEnabled = _T("LowpassEnabled");
const wxString CONFIG_STR_LowpassFreq = _T("LowpassFreq");
const wxString CONFIG_STR_LowpassWidthEnabled = _T("LowpassWidthEnabled");
const wxString CONFIG_STR_LowpassWidth = _T("LowpassWidth");
const wxString CONFIG_STR_MarkNonOriginal = _T("MarkNonOriginal");
const wxString CONFIG_STR_MarkCopyright = _T("MarkCopyright");
const wxString CONFIG_STR_Crc = _T("Crc");
const wxString CONFIG_STR_EnforceISO = _T("EnforceISO");
const wxString CONFIG_STR_AlgorithmQualitySel = _T("AlgorithmQualitySel");
const wxString CONFIG_STR_CustomOptions = _T("CustomOptions");

// Default Values
const wxString DEFAULT_VALUE_LastOpenDir = wxFileName::GetHomeDir();
const int DEFAULT_VALUE_Bitrate = 192;
const int DEFAULT_VALUE_Mode = 0;
const bool DEFAULT_VALUE_EnableOutDir = false;
const wxString DEFAULT_VALUE_OutDir = wxFileName::GetHomeDir();
const bool DEFAULT_VALUE_DeleteFiles = false;
const bool DEFAULT_VALUE_EnabledVBR = false;
const int DEFAULT_VALUE_MaxBitrate = 320;
const bool DEFAULT_VALUE_DisableVBRTag = false;
const bool DEFAULT_VALUE_EnforceMinBitrate = false;
const bool DEFAULT_VALUE_UseABR = false;
const int DEFAULT_VALUE_VBRQuality = 4;
const int DEFAULT_VALUE_AverageBitrateABR = 128;
const int DEFAULT_VALUE_Resampling = 0;
const bool DEFAULT_VALUE_HighpassEnabled = false;
const int DEFAULT_VALUE_HighpassFreq = 20000;
const bool DEFAULT_VALUE_HighpassWidthEnabled = false;
const int DEFAULT_VALUE_HighpassWidth = 20000;
const bool DEFAULT_VALUE_LowpassEnabled = false;
const int DEFAULT_VALUE_LowpassFreq = 20000;
const bool DEFAULT_VALUE_LowpassWidthEnabled = false;
const int DEFAULT_VALUE_LowpassWidth = 20000;
const bool DEFAULT_VALUE_MarkNonOriginal = false;
const bool DEFAULT_VALUE_MarkCopyright = false;
const bool DEFAULT_VALUE_Crc = false;
const bool DEFAULT_VALUE_EnforceISO = false;
const int DEFAULT_VALUE_AlgorithmQualitySel = 0;
const bool DEFAULT_VALUE_CustomOptions = false;
const wxString DEFAULT_VALUE_CustomOptionsText = _T("-b 192 --clipdetect");

inline wxString GetResourceDir() {
#ifdef __LINUX__
    wxString resourceDir = _T("/usr/share/wxlame/resource/");
#else
    wxString executablePath = wxStandardPaths::Get().GetExecutablePath();
    wxFileName executableFilename(executablePath);
    wxString resourceDir = executableFilename.GetPath() + _T("/resource/");
#endif
    return resourceDir;
}

#endif // CONSTANTS_H