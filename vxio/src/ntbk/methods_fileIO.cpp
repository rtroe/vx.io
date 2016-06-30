#include "MainFrame.h"



void MainFrame::New(wxCommandEvent& WXUNUSED(event))
{
    m_ntbk->AddPage(CreateStyleTextCtrl(wxString::Format(wxT("newFile %i"), INT_NewFileList)),
                    wxString::Format(wxT("newFile %i"), INT_NewFileList),
                    true,
                    vxAppImgs->FileTypeScript);
    
    ConsoleWriteLine("vx.IO.New('"+wxString::Format(wxT("newFile %i"), INT_NewFileList)+"')");
    
    INT_NewFileList++;
    SetToolbarStatus();
    
}

void MainFrame::Open(wxCommandEvent& WXUNUSED(event))
{
    wxFileDialog* OpenDialog = new wxFileDialog(
        this, _("Choose a file to open"), wxEmptyString, wxEmptyString, fileFilter, wxFD_OPEN, wxDefaultPosition);

    // Creates a "open file" dialog with 4 file types
    if(OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "Cancel"
    {
        
    ConsoleWriteLine("vx.IO.Open('"+OpenDialog->GetPath()+"')");
    
        m_ntbk->AddPage(
            CreateStyleTextCtrl(OpenDialog->GetPath()), OpenDialog->GetFilename(), true, vxAppImgs->FileTypeScript);
    }
    // Clean up after ourselves
    OpenDialog->Destroy();
    SetToolbarStatus();
}

void MainFrame::SaveActiveFile()
{
    ConsoleWriteLine("vx.IO.Save('"+GetActiveDocument()->FilePath+"')");
    if(GetActiveDocument()->IsNewFile == true) {
        SaveActiveFileAs();
    } else {
        GetActiveDocument()->Save();
        SetToolbarStatus();
    }
}

void MainFrame::SaveActiveFileAs()
{
    wxFileDialog* SaveDialog = new wxFileDialog(this,
                                                _("Save File As..."),
                                                wxEmptyString,
                                                wxEmptyString,
                                                fileFilter,
                                                wxFD_SAVE | wxFD_OVERWRITE_PROMPT,
                                                wxDefaultPosition);

    // Creates a Save Dialog with 4 file types
    if(SaveDialog->ShowModal() == wxID_OK) // If the user clicked "OK"
    {
        GetActiveDocument()->FilePath = SaveDialog->GetPath();
        GetActiveDocument()->FileName = SaveDialog->GetFilename();
        // set the path of our current document to the file the user chose to save under
        GetActiveDocument()->Save(); // Save the file to the selected path
    }

    // Clean up after ourselves
    SaveDialog->Destroy();
    SetToolbarStatus();
}
void MainFrame::SaveAllOpenFIles()
{
}

void MainFrame::Save(wxCommandEvent& WXUNUSED(event))
{
    SaveActiveFile();
}

void MainFrame::SaveAs(wxCommandEvent& WXUNUSED(event))
{
    SaveActiveFileAs();
}


void MainFrame::Undo(wxCommandEvent& WXUNUSED(event))
{
    GetActiveDocument()->Undo();
    SetToolbarStatus();
}

void MainFrame::Redo(wxCommandEvent& WXUNUSED(event))
{
    GetActiveDocument()->Redo();
    SetToolbarStatus();
}

/***********************************************************/

void MainFrame::Cut(wxCommandEvent& WXUNUSED(event))
{
    GetActiveDocument()->Cut();
    SetToolbarStatus();
}

void MainFrame::Copy(wxCommandEvent& WXUNUSED(event))
{
    GetActiveDocument()->Copy();
    SetToolbarStatus();
}

void MainFrame::Paste(wxCommandEvent& WXUNUSED(event))
{
    GetActiveDocument()->Paste();
    SetToolbarStatus();
}