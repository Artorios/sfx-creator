#include "sfxGUIApp.h"

//(*AppHeaders
#include "sfxGUIMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(sfxGUIApp);

bool sfxGUIApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	sfxGUIDialog Dlg(0);
        if(argc==2)
        {
            Dlg.SetSource(wxString(argv[1], wxConvUTF8)); // Convert second parameter argv[1] from char* to wxString
        }
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;
}
