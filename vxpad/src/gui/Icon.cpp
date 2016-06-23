
#include "../../include/gui/Icon.h"
#include <wx/xrc/xmlres.h>

vxIcons::vxIcons()
{
    AppIcon16 = wxXmlResource::Get()->LoadBitmap(wxT("Addin16"));
    
    FileTypeScript = wxXmlResource::Get()->LoadBitmap(wxT("file_ext_script"));
    
    //File IO
    FileNew16 = wxXmlResource::Get()->LoadBitmap(wxT("file_new_16"));
    FileOpen16 = wxXmlResource::Get()->LoadBitmap(wxT("file_open_16"));
    Save16 = wxXmlResource::Get()->LoadBitmap(wxT("file_save_16"));
    SaveAs16 = wxXmlResource::Get()->LoadBitmap(wxT("file_saveas_16"));
    SaveAll16 = wxXmlResource::Get()->LoadBitmap(wxT("file_saveall_16"));
    
    //File Operations
    Undo16 = wxXmlResource::Get()->LoadBitmap(wxT("undo_16"));
    Redo16 = wxXmlResource::Get()->LoadBitmap(wxT("redo_16"));
    Cut16 = wxXmlResource::Get()->LoadBitmap(wxT("cut16"));
    Copy16 = wxXmlResource::Get()->LoadBitmap(wxT("copy_16"));
    Paste16 = wxXmlResource::Get()->LoadBitmap(wxT("paste_16"));
    
    //System Information
    AppSettings16 = wxXmlResource::Get()->LoadBitmap(wxT("AppSettings16"));
    Treeview16 = wxXmlResource::Get()->LoadBitmap(wxT("projectTree16"));
    Properties16 = wxXmlResource::Get()->LoadBitmap(wxT("prop16"));
    Console16 = wxXmlResource::Get()->LoadBitmap(wxT("console16"));
    ManageAddins16 = wxXmlResource::Get()->LoadBitmap(wxT("Addin16"));
    
    
    ToUpperCase = wxXmlResource::Get()->LoadBitmap(wxT("text_allcaps"));
    ToLowerCase = wxXmlResource::Get()->LoadBitmap(wxT("text_smallcaps"));
    ToggleEndline = wxXmlResource::Get()->LoadBitmap(wxT("tgle_endln"));
    
    FindWord = wxXmlResource::Get()->LoadBitmap(wxT("table_tab_search"));
    FindNext = wxXmlResource::Get()->LoadBitmap(wxT("search_plus"));
    FindPrev  = wxXmlResource::Get()->LoadBitmap(wxT("search_minus"));    
}

vxIcons::~vxIcons()
{
       
}