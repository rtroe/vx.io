#include "FindReplace.h"
#include "MainFrame.h"

FindReplace::FindReplace(wxWindow* parent)
    : FindReplaceBase(parent)
{
}

FindReplace::~FindReplace()
{
}

void FindReplace::SetFocusForFind(wxString txtToFind)
{
    m_txtCntrl_Find->SetFocus();

    if(txtToFind != "") {
        m_txtCntrl_Find->SetValue(txtToFind);
        ((MainFrame*)GetParent())->Find(m_txtCntrl_Find->GetValue());

        m_txtCntrl_Find->SetSelection(txtToFind.length());
    }
}

void FindReplace::SetFocusForReplace(wxString txtToReplace)
{
    m_txtCntrl_Find->SetFocus();
    
        if(txtToReplace != "") {
        m_txtCntrl_Find->SetValue(txtToReplace);
        ((MainFrame*)GetParent())->Find(m_txtCntrl_Find->GetValue());

        m_txtCntrl_Find->SetSelection(0, txtToReplace.length()-2);
    }
    
    //m_txtCntrl_Find->SetSelection(txtToReplace.length());
}

// FIND CODE
/******************************************************************************/
void FindReplace::OnBtn_findButtonClicked(wxCommandEvent& event)
{
    ((MainFrame*)GetParent())->Find(m_txtCntrl_Find->GetValue());
    m_txtCntrl_Find->Append(m_txtCntrl_Find->GetValue());
}
void FindReplace::OnBtn_findnextButtonClicked(wxCommandEvent& event)
{
    ((MainFrame*)GetParent())->FindNext();
}
void FindReplace::OnBtn_findprevButtonClicked(wxCommandEvent& event)
{
    ((MainFrame*)GetParent())->FindPrev();
}
void FindReplace::OnBtn_wholewordTogglebuttonClicked(wxCommandEvent& event)
{
}
void FindReplace::OnMatchcaseTogglebuttonClicked(wxCommandEvent& event)
{
}
void FindReplace::OnTxtcntrl_findTextEnter(wxCommandEvent& event)
{
    std::cout<<"Enter"<<std::endl;
}
void FindReplace::OnTxtcntrl_findTextUpdated(wxCommandEvent& event)
{
    if(m_txtCntrl_Find->GetValue().length() > 0){
    ((MainFrame*)GetParent())->Find(m_txtCntrl_Find->GetValue());    
    }
}

// REPLACE CODE
/******************************************************************************/
void FindReplace::OnReplacenextButtonClicked(wxCommandEvent& event)
{
    if(m_txtCntrl_Find->GetValue().length() > 0){
    ((MainFrame*)GetParent())->ReplaceNext(m_txtCntrl_Find->GetValue(), m_txtCntrl_Repalce->GetValue());     
    } 
}
void FindReplace::OnReplaceallButtonClicked(wxCommandEvent& event)
{
     if(m_txtCntrl_Find->GetValue().length() > 0){
    ((MainFrame*)GetParent())->ReplaceAll(m_txtCntrl_Find->GetValue(), m_txtCntrl_Repalce->GetValue());     
    } 
}
