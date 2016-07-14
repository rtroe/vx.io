#include "MainFrame.h"

void MainFrame::Find(wxString searchText)
{
    // Clear out the Results Vector
    FindResults.clear();
    FindResultIndex = 0;
    GetActiveDocument()->ClearSelections();

    int runningLineCount = 0;

    // Loop through all LInes
    for(int i = 0; i < GetActiveDocument()->GetLineCount(); i++) {

        // Read in the current line
        wxString line = GetActiveDocument()->GetLine(i);

        // now do a first check to see if the line contains our text
        int found = line.Find(searchText);

        // Now set up our 'newStart' variable for doing recursive searching in case there is more than one instance of
        // the word we're searching for
        int newStart = 0;

        // First Make sure there's at least one letter to check
        if(searchText.length() > 0) {

            // This keeps track of the new 'substringed' line to perform recursive searches against.
            wxString recurLine = line;

            // Now Recursively Search through to find if there are any other copies of the word
            while(found != wxNOT_FOUND && found != -1 && recurLine.length() > 0) {
                // ij++;
                int chckLeng = searchText.length();
                newStart += found;

                FindResults.push_back(
                    { i, found, runningLineCount + newStart, runningLineCount + newStart + searchText.length() });

                // Incremement it Up One for the next way around
                newStart += chckLeng;

                // Now increment the Find up by the length of the word we're searching for
                found += chckLeng;

                // Now create the new Substring
                recurLine = recurLine.Mid(found);
                found = recurLine.Find(searchText);
            }
        }

        // Keep running total of the position
        runningLineCount += line.length();
    }

    // Now Select the Find Results
//    if(FindResults.size() > 0) {
//        txtCntrl_Find->SetBackgroundColour(wxColor(255, 255, 255));
//        GetActiveDocument()->SetSelection(FindResults[FindResultIndex].Start, FindResults[FindResultIndex].End);
//    } else {
//        txtCntrl_Find->SetBackgroundColour(wxColor(255));
//    }

    GetActiveDocument()->SetIndentationGuides(1);
    GetActiveDocument()->SetMultipleSelection(true);
    for(std::vector<FindResult>::iterator it = FindResults.begin(); it != FindResults.end(); ++it) {
        GetActiveDocument()->AddSelection(it->Start, it->End);
    }
    
    FindResultIndex = -1;
    FindNext();
}

void MainFrame::FindNext()
{
    GetActiveDocument()->ClearSelections();

    FindResultIndex++;

    if(FindResultIndex > FindResults.size() - 1)
        FindResultIndex = 0;

    if(FindResults.size() > 0) {
        // First Set the Selection
        GetActiveDocument()->SetCurrentPos(FindResults[FindResultIndex].Start);
        GetActiveDocument()->SetSelection(FindResults[FindResultIndex].Start, FindResults[FindResultIndex].End);

        // Next check to see if it needs to be scrolled.
        int firstLine = GetActiveDocument()->GetFirstVisibleLine();
        int lastLine = firstLine + GetActiveDocument()->LinesOnScreen();
        int currentLine = FindResults[FindResultIndex].lineNumber;

        // std::cout<<"Start: "<<firstLine<<" End: "<< lastLine<<std::endl;

        if(currentLine < firstLine || currentLine > lastLine)
            GetActiveDocument()->ScrollToLine(FindResults[FindResultIndex].lineNumber - 5);
    }
}

void MainFrame::FindPrev()
{
    GetActiveDocument()->ClearSelections();
    FindResultIndex--;

    if(FindResultIndex < 0)
        FindResultIndex = FindResults.size() - 1;

    if(FindResults.size() > 0) {
        // First Set the Selection
        GetActiveDocument()->SetCurrentPos(FindResults[FindResultIndex].Start);
        GetActiveDocument()->SetSelection(FindResults[FindResultIndex].Start, FindResults[FindResultIndex].End);

        // Next check to see if it needs to be scrolled.
        int firstLine = GetActiveDocument()->GetFirstVisibleLine();
        int lastLine = firstLine + GetActiveDocument()->LinesOnScreen();
        int currentLine = FindResults[FindResultIndex].lineNumber;

        // std::cout<<"Start: "<<firstLine<<" End: "<< lastLine<<std::endl;

        if(currentLine < firstLine || currentLine > lastLine)
            GetActiveDocument()->ScrollToLine(FindResults[FindResultIndex].lineNumber - 5);
    }
}

void MainFrame::OnFind(wxCommandEvent& event)
{
    if(m_mgr.GetPane(wxT("wndw_FIndReplace")).IsShown()) {
        m_mgr.GetPane(wxT("wndw_FIndReplace")).Hide();
        m_mgr.Update();
    }
    m_mgr.GetPane(wxT("wndw_FIndReplace")).Show();
    m_mgr.GetPane(wxT("wndw_FIndReplace")).BestSize(800, 60);

    if(GetActiveDocument()->GetSelections() > 1){
        GetActiveDocument()->SetMainSelection(0);
        wndw_FIndReplace->SetFocusForFind(GetActiveDocument()->GetStringSelection());        
        //GetActiveDocument()->GetStringSelection();
    }
        //GetActiveDocument()->ClearSelections();
    else
        wndw_FIndReplace->SetFocusForFind(GetActiveDocument()->GetSelectedText());
    m_mgr.Update();
}

void MainFrame::OnFindNext(wxCommandEvent& event)
{
    // If it's already shown, there's no reason to reset the best size, it will only be set if it's not shown yet.
    m_mgr.GetPane(wxT("wndw_FIndReplace")).Show();
    m_mgr.GetPane(wxT("wndw_FIndReplace")).BestSize(800, 60);
    m_mgr.Update();

    FindNext();
}

void MainFrame::OnFindPrev(wxCommandEvent& event)
{
    // If it's already shown, there's no reason to reset the best size, it will only be set if it's not shown yet.
    m_mgr.GetPane(wxT("wndw_FIndReplace")).Show();
    m_mgr.GetPane(wxT("wndw_FIndReplace")).BestSize(800, 60);
    m_mgr.Update();

    FindPrev();
}







void MainFrame::ReplaceNext(wxString toReplace, wxString toReplaceWith)
{    
    Find(toReplace);
    FindNext();
    
    if(FindResults.size() > 0){
    GetActiveDocument()->ReplaceSelection(toReplaceWith);    
    }
}

void MainFrame::ReplaceAll(wxString toReplace, wxString toReplaceWith)
{    
    Find(toReplace);
    
    while(FindResults.size()>1){
    Find(toReplace);
    FindNext();
    
    GetActiveDocument()->ReplaceSelection(toReplaceWith);
    
    }
}





void MainFrame::OnReplace(wxCommandEvent& event)
{
    if(m_mgr.GetPane(wxT("wndw_FIndReplace")).IsShown()) {
        m_mgr.GetPane(wxT("wndw_FIndReplace")).Hide();
        m_mgr.Update();
    }
    m_mgr.GetPane(wxT("wndw_FIndReplace")).Show();
    m_mgr.GetPane(wxT("wndw_FIndReplace")).BestSize(800, 120);
    if(GetActiveDocument()->GetSelections() > 1)
        GetActiveDocument()->ClearSelections();
    else
        wndw_FIndReplace->SetFocusForReplace(GetActiveDocument()->GetSelectedText());
    m_mgr.Update();
}

void MainFrame::OnReplaceNext(wxCommandEvent& event)
{
    if(m_mgr.GetPane(wxT("wndw_FIndReplace")).IsShown()) {
        m_mgr.GetPane(wxT("wndw_FIndReplace")).Hide();
        m_mgr.Update();
    }
    m_mgr.GetPane(wxT("wndw_FIndReplace")).Show();
    m_mgr.GetPane(wxT("wndw_FIndReplace")).BestSize(800, 120);
    if(GetActiveDocument()->GetSelections() > 1)
        GetActiveDocument()->ClearSelections();
    else
        wndw_FIndReplace->SetFocusForReplace(GetActiveDocument()->GetSelectedText());
    m_mgr.Update();

    FindNext();
}
