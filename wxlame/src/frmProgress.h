/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef FRMPROGRESS_H
#define FRMPROGRESS_H

//(*Headers(frmProgress)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/timer.h>
#include <wx/gauge.h>
//*)

#include <wx/process.h>
#include <wx/listctrl.h>
#include "ConfigBase.h"

enum
{
    LAME_ENCODE = 0,
    LAME_DECODE = 1,
};

class frmProgress : public wxDialog
{
public:

    frmProgress(wxWindow* parent, ConfigBase* configBase, wxListCtrl* listFiles, int workType, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
    virtual ~frmProgress();

    //(*Declarations(frmProgress)
    wxStaticText* lblStatusFile;
    wxButton* btnCancel;
    wxGauge* gaugeListProgress;
    wxGauge* gaugeFileProgress;
    wxStaticText* lblStatusList;
    wxTimer Timer1;
    //*)

protected:

    //(*Identifiers(frmProgress)
    static const long ID_STATICTEXT1;
    static const long ID_GAUGE1;
    static const long ID_STATICTEXT2;
    static const long ID_GAUGE2;
    static const long ID_BUTTON1;
    static const long ID_TIMER1;
    //*)

private:

    //(*Handlers(frmProgress)
    void OnTimer1Trigger(wxTimerEvent& event);
    void OnbtnCancelClick(wxCommandEvent& event);
    void OnInit(wxInitDialogEvent& event);
    void OnClose(wxCloseEvent& event);
    //*)

    void OnIdle(wxIdleEvent& event);
    void OnProcessTerm(wxProcessEvent& event);
    void processNextFile();
    void finishedWork();
    void stringToGaugeUpdate(const wxString & inputString);
    void stringLabelsUpdate();

    ConfigBase* configBase;
    wxListCtrl* listFiles;
    wxProcess* process;
    int fileIterator;
    int workType;
    bool workingProgress;
    long processPID;
    wxString inputString;

    DECLARE_EVENT_TABLE()
};

#endif
