void TextCtrl::SetLexarAsCPP(wxStyledTextCtrl* text)
{

    SetLexarBase(text);
    text->SetLexer(wxSTC_LEX_CPP);

    text->StyleSetForeground (wxSTC_C_STRING,            wxColour(220,0, 220));
    text->StyleSetForeground (wxSTC_C_PREPROCESSOR,      wxColour(0,150,225));
    //text->StyleSetForeground (wxSTC_C_IDENTIFIER,        wxColour(40,0,60));
    text->StyleSetForeground (wxSTC_C_NUMBER,            wxColour(220,0,220));
    text->StyleSetForeground (wxSTC_C_CHARACTER,         wxColour(150,0,0));
    text->StyleSetForeground (wxSTC_C_WORD,              wxColour(255,128,0));
    text->StyleSetForeground (wxSTC_C_WORD2,             wxColour(0,190,190));
    text->StyleSetForeground (wxSTC_C_COMMENT,           wxColour(0,225,0));
    text->StyleSetForeground (wxSTC_C_COMMENTLINE,       wxColour(0,225,0));
    text->StyleSetForeground (wxSTC_C_COMMENTDOC,        wxColour(0,150,0));
    text->StyleSetForeground (wxSTC_C_COMMENTDOCKEYWORD, wxColour(0,0,200));
    text->StyleSetForeground (wxSTC_C_COMMENTDOCKEYWORDERROR, wxColour(0,0,200));
    text->StyleSetBold(wxSTC_C_WORD, true);
    text->StyleSetBold(wxSTC_C_WORD2, true);
    text->StyleSetBold(wxSTC_C_COMMENTDOCKEYWORD, true);
    text->SetCaretForeground(wxColour(225,225,225));
    text->SetSelBackground(true,wxColour(100,100,100));

    wxString CppWordlist1 = wxT("int float asm auto bool break case catch char class const const_cast continue default delete do double dynamic_cast else enum explicit mutable namespace new operator private protected public register reinterpret_cast return short signed sizeof static static_cast struct switch template this throw true try typedef typeid typename union unsigned using virtual void volatile wchar_t DECLARE_EVENT_TABLE EVT_MENU BEGIN_EVENT_TABLE while");

    wxString CppWordlist2 =
    wxT("wxArtProvider wxAuiNotebook wxAuiToolBarItem wxAuiToolBarItemArray wxAuiPaneInfoArray wxBitmap wxCommandEvent wxDefaultPosition wxDefaultSize wxGrid wxHtmlWindow wxMenuBar wxMenu wxPoint wxT wxTextCtrl wxTreeCtrl TextCtrl wxSize wxString wxWindow wxSizeEvent wxEraseEvent wxUpdateUIEvent wxStyledTextCtrl wxAuiManagerEvent wxAuiManager wxArrayString wxAuiToolBar");


    // a sample list of keywords, I haven't included them all to keep it short...
    text->SetKeyWords(0, CppWordlist1);
    text->SetKeyWords(1, CppWordlist2);
}
