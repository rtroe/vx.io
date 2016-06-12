
#include "../../include/gui/Icon.h"
#include <wx/xrc/xmlres.h>

vxIcons::vxIcons()
{
    AppIcon16 = wxXmlResource::Get()->LoadBitmap(wxT("Addin16"));
    
    FileTypeScript = wxXmlResource::Get()->LoadBitmap(wxT("file_ext_script"));
    
    //File IO
    FileNew16 = wxXmlResource::Get()->LoadBitmap(wxT("file_new_16"));
    //FileNew32 = wxXmlResource::Get()->LoadBitmap(wxT("file_new_32"));
    FileOpen16 = wxXmlResource::Get()->LoadBitmap(wxT("file_open_16"));
    //FileOpen32 = wxXmlResource::Get()->LoadBitmap(wxT("file_open_32"));
    Save16 = wxXmlResource::Get()->LoadBitmap(wxT("file_save_16"));
    //Save32 = wxXmlResource::Get()->LoadBitmap(wxT("file_save_32"));
    SaveAs16 = wxXmlResource::Get()->LoadBitmap(wxT("file_saveas_16"));
    //SaveAs32 = wxXmlResource::Get()->LoadBitmap(wxT("file_saveas_32"));
    SaveAll16 = wxXmlResource::Get()->LoadBitmap(wxT("file_saveall_16"));
    //SaveAll32 = wxXmlResource::Get()->LoadBitmap(wxT("file_saveall_32"));
    
    //File Operations
    Undo16 = wxXmlResource::Get()->LoadBitmap(wxT("undo_16"));
    //Undo32 = wxXmlResource::Get()->LoadBitmap(wxT("undo_32"));
    Redo16 = wxXmlResource::Get()->LoadBitmap(wxT("redo_16"));
    //Redo32 = wxXmlResource::Get()->LoadBitmap(wxT("redo_32"));
    Cut16 = wxXmlResource::Get()->LoadBitmap(wxT("cut16"));
    //Cut32 = wxXmlResource::Get()->LoadBitmap(wxT("cut_32"));
    Copy16 = wxXmlResource::Get()->LoadBitmap(wxT("copy_16"));
    //Copy32 = wxXmlResource::Get()->LoadBitmap(wxT("copy_32"));
    Paste16 = wxXmlResource::Get()->LoadBitmap(wxT("paste_16"));
    //Paste32 = wxXmlResource::Get()->LoadBitmap(wxT("paste_32"));
    
    //System Information
    AppSettings16 = wxXmlResource::Get()->LoadBitmap(wxT("AppSettings16"));
    //SystemPerfomance16 = wxXmlResource::Get()->LoadBitmap(wxT("SysPerfm16"));
    Treeview16 = wxXmlResource::Get()->LoadBitmap(wxT("projectTree16"));
    Properties16 = wxXmlResource::Get()->LoadBitmap(wxT("prop16"));
    Console16 = wxXmlResource::Get()->LoadBitmap(wxT("console16"));
    ManageAddins16 = wxXmlResource::Get()->LoadBitmap(wxT("Addin16"));
}

vxIcons::~vxIcons()
{
       
}