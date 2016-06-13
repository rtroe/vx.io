#ifndef VXICONE_H
#define VXICONE_H

#include <wx/bitmap.h>

class vxIcons
{  
public:

    //File Type Icons
    wxBitmap AppIcon16;
    
    //File Type Icons
    wxBitmap FileTypeScript;
  
    //File IO and Operations
    wxBitmap FileNew16, FileNew32;
    wxBitmap FileOpen16, FileOpen32;
    wxBitmap Save16, Save32;
    wxBitmap SaveAs16, SaveAs32;
    wxBitmap SaveAll16, SaveAll32;
    wxBitmap Undo16, Undo32;
    wxBitmap Redo16, Redo32;
    wxBitmap Cut16, Cut32;
    wxBitmap Copy16, Copy32;
    wxBitmap Paste16, Paste32;
    
    //System Info
    wxBitmap AppSettings16;
    //wxBitmap SystemPerfomance16;
    wxBitmap Treeview16;
    wxBitmap Properties16;
    wxBitmap Console16;
    wxBitmap ManageAddins16;
    
    wxBitmap ToUpperCase, ToLowerCase;
    wxBitmap ToggleEndline;
    
    
    vxIcons();
    virtual ~vxIcons();
};

#endif //VXICONE_H