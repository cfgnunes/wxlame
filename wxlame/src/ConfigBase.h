/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef CONFIGBASE_H
#define CONFIGBASE_H

#include <wx/string.h>
#include <wx/config.h>

class ConfigBase {
public:
    ConfigBase(const wxString &appName = wxEmptyString);

    ~ConfigBase();

    void setDefaultConfig();

    void configFlush();

    wxString getStringLameOptions() const;

    // Gets...
    wxString getAppVersion() const;

    wxString getLastOpenDir() const;

    int getBitrate() const;

    int getMode() const;

    bool getEnableOutDir() const;

    wxString getOutDir() const;

    bool getDeleteFiles() const;

    bool getEnabledVBR() const;

    int getMaxBitrate() const;

    bool getDisableVBRTag() const;

    bool getEnforceMinBitrate() const;

    bool getUseABR() const;

    int getVBRQuality() const;

    int getAverageBitrateABR() const;

    int getResampling() const;

    bool getHighpassEnabled() const;

    int getHighpassFreq() const;

    bool getHighpassWidthEnabled() const;

    int getHighpassWidth() const;

    bool getLowpassEnabled() const;

    int getLowpassFreq() const;

    bool getLowpassWidthEnabled() const;

    int getLowpassWidth() const;

    bool getMarkNonOriginal() const;

    bool getMarkCopyright() const;

    bool getCrc() const;

    bool getEnforceISO() const;

    int getAlgorithmQualitySel() const;

    bool getCustomOptions() const;

    wxString getCustomOptionsText() const;

    // Sets...
    void setAppVersion(wxString value);

    void setLastOpenDir(wxString value);

    void setBitrate(int value);

    void setMode(int value);

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

    void setResampling(int value);

    void setHighpassEnabled(bool value);

    void setHighpassFreq(int value);

    void setHighpassWidthEnabled(bool value);

    void setHighpassWidth(int value);

    void setLowpassEnabled(bool value);

    void setLowpassFreq(int value);

    void setLowpassWidthEnabled(bool value);

    void setLowpassWidth(int value);

    void setMarkNonOriginal(bool value);

    void setMarkCopyright(bool value);

    void setCrc(bool value);

    void setEnforceISO(bool value);

    void setAlgorithmQualitySel(int value);

    void setCustomOptions(bool value);

    void setCustomOptionsText(wxString value);

private:
    wxConfig *mp_config;
};

#endif // CONFIGBASE_H
