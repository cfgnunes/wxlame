/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef FILEINFO_H
#define FILEINFO_H

#include <wx/object.h>
#include <wx/string.h>
#include <wx/filename.h>

// LIST (start)
#include <wx/dynarray.h>
class FileInfo;
WX_DECLARE_OBJARRAY(FileInfo, ArrayOfFiles);
// LIST (end)

class FileInfo : public wxObject
{
public:
    FileInfo(const wxString& fileName);
    virtual ~FileInfo();

    //gets...
    wxFileName getFileName();

    //sets...

private:
    wxFileName fileName;
};

#endif
