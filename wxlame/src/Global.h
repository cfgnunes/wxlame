/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <wx/string.h>

const wxString	APP_NAME = wxT("wxLame");
const wxString	APP_VERSION = wxT("2.4");
const wxString	APP_NAME_WITH_VERSION = APP_NAME + wxT(" v") + APP_VERSION;

const wxString APP_AUTHOR = _T("Cristiano Nunes <cfgnunes@gmail.com>");
const wxString APP_COPYRIGHT = _T("(C) 2011-2013 Cristiano Nunes <cfgnunes@gmail.com>");
const wxString	APP_WEBSITE = wxT("http://sourceforge.net/projects/wxlame/");

const wxString  APP_WILDCARD_EXT = wxT("Audio files|*.mp3;*.wav;*.aif;*.aiff;*.ape;*.MP3;*.WAV;*.AIF;*.AIFF;*.APE|MP3 files (*.mp3)|*.mp3;*.MP3|Wave files (*.wav)|*.wav;*.WAV|AIFF files (*.aif;*.aiff)|*.aif;*.aiff;*.AIF;*.AIFF|Monkey's audio files (*.ape)|*.ape;*.APE");
const wxString  APP_OPEN_EXT = wxT("mp3;wav;aif;aiff;ape");

const int		BITRATE_VALUES[] = {8, 16, 24, 32, 40, 48, 56, 64, 80, 96, 112, 128, 144, 160, 192, 224, 256, 320};
const int		BITRATE_VALUES_SIZE = 18;

const wxString	RESAMPLING_VALUES[] = {wxT("8"), wxT("11.025"), wxT("12"), wxT("16"), wxT("22.05"), wxT("24"), wxT("32"), wxT("44.1"), wxT("48")};
const int		RESAMPLING_VALUES_SIZE = 9;

#ifdef __LINUX__
const wxString	RESOURCE_DIR = wxT("/usr/share/wxlame/resource/");
#else
const wxString	RESOURCE_DIR = wxT("resource/");
#endif

#endif // GLOBAL_H_INCLUDED
