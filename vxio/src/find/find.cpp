#include "MainFrame.h"


void MainFrame::OnFind(wxCommandEvent& event)
{    
    /*
    //Only update the Find box if there's no selected text;
    if(GetActiveDocument()->GetSelectedText() != wxT("") && txtCntrl_Find->HasFocus() == false){
        txtCntrl_Find->Clear();
        txtCntrl_Find->AppendText(GetActiveDocument()->GetSelectedText());      
        event.Skip();
    }
    */
    txtCntrl_Find->SetFocus();
    m_mgr.GetPane(wxT("tb_find")).Show();
    m_mgr.Update();
    
    //Clear out the Results Vector
    FindResults.clear();
    FindResultIndex = 0;
    GetActiveDocument()->ClearSelections();
    
    int runningLineCount = 0;
    
    //Loop through all LInes
    for(int i = 0; i< GetActiveDocument()->GetLineCount(); i++)
    {
        wxString line = GetActiveDocument()->GetLine(i);
        
        
       int found = line.Find(txtCntrl_Find->GetLineText(0));
        
        //If the word is located on this line, add it to the collection
        if(found != wxNOT_FOUND)
        {
            FindResults.push_back({i, found, runningLineCount + found, runningLineCount + found + txtCntrl_Find->GetLineText(0).length()});
        } 

        //Keep running total of the position
        runningLineCount += line.length();
    }
    
    if(FindResults.size()>0)
    {        
        txtCntrl_Find->SetBackgroundColour(wxColor(255, 255, 255));
        GetActiveDocument()->SetSelection(FindResults[FindResultIndex].Start, FindResults[FindResultIndex].End);
    }
    else
    {        
            txtCntrl_Find->SetBackgroundColour(wxColor(255));
    }
    
    GetActiveDocument()->SetIndentationGuides(1);
    GetActiveDocument()->SetMultipleSelection(true);
    for(std::vector<FindResult>::iterator it = FindResults.begin(); it != FindResults.end(); ++it) {
            //std::cout<<"Start: "<<it->Start<<" End: "<< it->End<<std::endl;
            GetActiveDocument()->AddSelection(it->Start, it->End);
    }
}

void MainFrame::OnFindNext(wxCommandEvent& event)
{
    m_mgr.GetPane(wxT("tb_find")).Show();
    m_mgr.Update();
    
    GetActiveDocument()->ClearSelections();
    
    FindResultIndex++;
    
    if(FindResultIndex > FindResults.size()-1)
        FindResultIndex = 0;
    
        if(FindResults.size()>0)
    { 
        //First Set the Selection
        GetActiveDocument()->SetCurrentPos(FindResults[FindResultIndex].Start);
        GetActiveDocument()->SetSelection(FindResults[FindResultIndex].Start, FindResults[FindResultIndex].End);
        
        //Next check to see if it needs to be scrolled.
        int firstLine = GetActiveDocument()->GetFirstVisibleLine();
        int lastLine = firstLine + GetActiveDocument()->LinesOnScreen();
        int currentLine = FindResults[FindResultIndex].lineNumber;
        
        //std::cout<<"Start: "<<firstLine<<" End: "<< lastLine<<std::endl;
        
        if(currentLine < firstLine || currentLine > lastLine)        
            GetActiveDocument()->ScrollToLine(FindResults[FindResultIndex].lineNumber - 5);        
    }
}

void MainFrame::OnFindPrev(wxCommandEvent& event)
{
    m_mgr.GetPane(wxT("tb_find")).Show();
    m_mgr.Update();
    
        FindResultIndex--;
    
    if(FindResultIndex < 0)
        FindResultIndex = FindResults.size()  - 1;
    
        if(FindResults.size()>0)
    {        
        //First Set the Selection
        GetActiveDocument()->SetCurrentPos(FindResults[FindResultIndex].Start);
        GetActiveDocument()->SetSelection(FindResults[FindResultIndex].Start, FindResults[FindResultIndex].End);
        
        //Next check to see if it needs to be scrolled.
        int firstLine = GetActiveDocument()->GetFirstVisibleLine();
        int lastLine = firstLine + GetActiveDocument()->LinesOnScreen();
        int currentLine = FindResults[FindResultIndex].lineNumber;
        
        //std::cout<<"Start: "<<firstLine<<" End: "<< lastLine<<std::endl;
        
        if(currentLine < firstLine || currentLine > lastLine)        
            GetActiveDocument()->ScrollToLine(FindResults[FindResultIndex].lineNumber - 5);
    }
}


void MainFrame::OnReplace(wxCommandEvent& event)
{
    std::cout<<"Replace!!!"<<std::endl;
}

void MainFrame::OnReplaceNext(wxCommandEvent& event)
{
    std::cout<<"Replace Next!!!"<<std::endl;
}
