/*
 *	  wxLame - A free front-end for the LAME MP3 encoder.
 *    Copyright (C) 2011  Cristiano Nunes
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/************************************************************************
 * Name:      wxLame
 * Purpose:   A free front-end for the LAME MP3 encoder.
 * Author:    Cristiano Nunes (cfgnunes@gmail.com)
 * Created:   2010-12-23
 * Copyright: Copyright (C) 2011  Cristiano Nunes
 * License:   licensed under the GNU General Public License, version 3
 *            http://www.gnu.org/licenses/gpl-3.0.html
 ************************************************************************/

#include "wxLameApp.h"

//(*AppHeaders
#include "frmMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxLameApp);

bool wxLameApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        frmMain* Frame = new frmMain(0);
        Frame->Show();
        SetTopWindow(Frame);
    }
    //*)
    return wxsOK;
}
