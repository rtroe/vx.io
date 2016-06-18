#include <wx/app.h>
#include <wx/event.h>
#include "MainFrame.h"
#include <wx/image.h>

// Define the MainApp
class MainApp : public wxApp
{
public:
    MainApp() {}
    virtual ~MainApp() {}

    virtual bool OnInit() {
        
        /*
    bool SHOW_DEBUG_CONSOLE = false;
    if(SHOW_DEBUG_CONSOLE)
    {
        AllocConsole() ;
        AttachConsole( GetCurrentProcessId() ) ;
        freopen( "CON", "w", stdout ) ;
    }
*/
        
        // Add the common image handlers
        wxImage::AddHandler( new wxPNGHandler );
        wxImage::AddHandler( new wxJPEGHandler );

        MainFrame *mainFrame = new MainFrame(NULL,
                                 wxID_ANY,
                                 wxT("vx.io"),
                                 wxDefaultPosition,
                                 wxSize(800, 600));
                                 
        SetTopWindow(mainFrame);
        return GetTopWindow()->Show();
    }
};

DECLARE_APP(MainApp)
IMPLEMENT_APP(MainApp)
