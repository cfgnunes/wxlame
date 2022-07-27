/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "FileDrop.hpp"

FileDrop::FileDrop(ListCtrlManager *listManager) : mp_listManager(listManager) {
}

FileDrop::~FileDrop() {
}

bool FileDrop::OnDropFiles(wxCoord, wxCoord, const wxArrayString &filenames) {
    mp_listManager->insertFilesAndDir(filenames);
    return true;
}
