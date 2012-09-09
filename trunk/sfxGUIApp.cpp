#include "sfxGUIApp.h"

//(*AppHeaders
#include "sfxGUIMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(sfxGUIApp);

bool sfxGUIApp::OnInit()
{
    //(*AppInitialize
    wxInitAllImageHandlers();
    sfxGUIDialog Dlg(0);
    SetTopWindow(&Dlg);
    Dlg.ShowModal();
    return false;
    //*)
}