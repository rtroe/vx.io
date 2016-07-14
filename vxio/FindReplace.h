#ifndef FINDREPLACE_H
#define FINDREPLACE_H
#include "wxcrafter.h"

class FindReplace : public FindReplaceBase
{
public:
    FindReplace(wxWindow* parent);
    virtual ~FindReplace();
    
    void SetFocusForFind(wxString);
    void SetFocusForReplace(wxString);
    
protected:
    virtual void OnTxtcntrl_findTextEnter(wxCommandEvent& event);
    virtual void OnTxtcntrl_findTextUpdated(wxCommandEvent& event);
    virtual void OnBtn_findButtonClicked(wxCommandEvent& event);
    virtual void OnBtn_findnextButtonClicked(wxCommandEvent& event);
    virtual void OnBtn_findprevButtonClicked(wxCommandEvent& event);
    virtual void OnBtn_wholewordTogglebuttonClicked(wxCommandEvent& event);
    virtual void OnMatchcaseTogglebuttonClicked(wxCommandEvent& event);
    virtual void OnReplaceallButtonClicked(wxCommandEvent& event);
    virtual void OnReplacenextButtonClicked(wxCommandEvent& event);
};
#endif // FINDREPLACE_H
