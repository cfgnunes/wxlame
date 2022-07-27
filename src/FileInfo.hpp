/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef FILE_INFO_HPP
#define FILE_INFO_HPP

#include <wx/filename.h>
#include <wx/string.h>

class FileInfo {
  public:
    FileInfo(const wxString &fileName);
    virtual ~FileInfo();

    wxFileName getFileName() const;

  private:
    wxFileName m_fileName;
};

#endif // FILE_INFO_HPP
