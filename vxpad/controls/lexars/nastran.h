void TextCtrl::SetLexarAsNASTRAN(wxStyledTextCtrl* text)
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
    text->SetCaretLineBackground(wxColour(0,0,0));

    wxString CppWordlist1 = wxT("MAXIMUM DISPLACEMENTS T1 T2 T3 R1 R2 R3 FX FY FZ MX MY MZ ENDDATA CEND ECHO SPC REAL SORT1 DISPLACEMENT SPCFORCES GPFORCE FORCE BEGIN PARAM SOL SUBCASE TITLE");

    wxString CppWordlist2 = wxT("MAT1 SPC1 LOAD PLOAD4 SPCADD GRID CELAS1 PELAS CBAR PBAR CROD PROD CTRIA3 PSHELL CQUAD4");


    // a sample list of keywords, I haven't included them all to keep it short...
    text->SetKeyWords(0, CppWordlist1);
    text->SetKeyWords(1, CppWordlist2);
}
