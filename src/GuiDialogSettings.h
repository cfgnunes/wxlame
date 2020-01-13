/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef GUIDIALOGSETTINGS_H
#define GUIDIALOGSETTINGS_H

#include "Gui.h"
#include "ConfigBase.h"

class GuiDialogSettings : public DialogSettings {
public:
    GuiDialogSettings(wxWindow *parent, ConfigBase *configBase);

    virtual ~GuiDialogSettings();

protected:
    void OnsldBitrateCmdSliderUpdated(wxScrollEvent &event);

    void updateDisabledControlsEvent(wxCommandEvent &event);

    void OnsldBitrateVBRCmdSliderUpdated(wxScrollEvent &event);

    void OnbtnDefaultClick(wxCommandEvent &event);

    void OnbtnOKClick(wxCommandEvent &event);

    void OnbtnCancelClick(wxCommandEvent &event);

private:
    void updateValueControls();

    void updateDisabledControls();

    void defaultValueControls();

    void saveValuesConfig();

    void setLabelsControls();

    ConfigBase *mp_configBase;
};

#endif // GUIDIALOGSETTINGS_H
