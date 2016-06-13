void vxTextCtrl::SetLexarBase(wxStyledTextCtrl* text)
{
StyleClearAll();
    //wxFont m_codeFont(9, wxFONTFAMILY_ROMAN  , wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    wxFont m_codeFont(8, wxFONTFAMILY_DEFAULT,
         wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, "Calibri");
    {
        int Nr;
        for (Nr = 0; Nr < wxSTC_STYLE_LASTPREDEFINED; Nr++)
            StyleSetFont (Nr, m_codeFont);
    }

    SetMarginWidth (MARGIN_LINE_NUMBERS, 50);
    StyleSetForeground (wxSTC_STYLE_LINENUMBER, wxColour (150, 150, 150) );
    StyleSetBackground (wxSTC_STYLE_LINENUMBER, wxColour (75, 75, 75));
    SetMarginType (MARGIN_LINE_NUMBERS, wxSTC_MARGIN_NUMBER);


    // ---- Enable code folding
    SetMarginType (MARGIN_FOLD, wxSTC_MARGIN_SYMBOL);
    SetMarginWidth(MARGIN_FOLD, 15);
    SetMarginMask (MARGIN_FOLD, wxSTC_MASK_FOLDERS);
    StyleSetBackground(MARGIN_FOLD, wxColor(200, 200, 200) );
    SetMarginSensitive(MARGIN_FOLD, true);

    // Properties found from http://www.scintilla.org/SciTEDoc.html
    SetProperty (wxT("fold"),         wxT("1") );
    SetProperty (wxT("fold.comment"), wxT("1") );
    SetProperty (wxT("fold.compact"), wxT("1") );



    wxColor grey( 100, 100, 100 );
    MarkerDefine (wxSTC_MARKNUM_FOLDER, wxSTC_MARK_ARROW );
    MarkerSetForeground (wxSTC_MARKNUM_FOLDER, grey);
    MarkerSetBackground (wxSTC_MARKNUM_FOLDER, grey);

    MarkerDefine (wxSTC_MARKNUM_FOLDEROPEN,    wxSTC_MARK_ARROWDOWN);
    MarkerSetForeground (wxSTC_MARKNUM_FOLDEROPEN, grey);
    MarkerSetBackground (wxSTC_MARKNUM_FOLDEROPEN, grey);

    MarkerDefine (wxSTC_MARKNUM_FOLDERSUB,     wxSTC_MARK_EMPTY);
    MarkerSetForeground (wxSTC_MARKNUM_FOLDERSUB, grey);
    MarkerSetBackground (wxSTC_MARKNUM_FOLDERSUB, grey);

    MarkerDefine (wxSTC_MARKNUM_FOLDEREND,     wxSTC_MARK_ARROW);
    MarkerSetForeground (wxSTC_MARKNUM_FOLDEREND, grey);
    MarkerSetBackground (wxSTC_MARKNUM_FOLDEREND, _T("WHITE"));

    MarkerDefine (wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_ARROWDOWN);
    MarkerSetForeground (wxSTC_MARKNUM_FOLDEROPENMID, grey);
    MarkerSetBackground (wxSTC_MARKNUM_FOLDEROPENMID, _T("WHITE"));

    MarkerDefine (wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY);
    MarkerSetForeground (wxSTC_MARKNUM_FOLDERMIDTAIL, grey);
    MarkerSetBackground (wxSTC_MARKNUM_FOLDERMIDTAIL, grey);

    MarkerDefine (wxSTC_MARKNUM_FOLDERTAIL,    wxSTC_MARK_EMPTY);
    MarkerSetForeground (wxSTC_MARKNUM_FOLDERTAIL, grey);
    MarkerSetBackground (wxSTC_MARKNUM_FOLDERTAIL, grey);
    // ---- End of code folding part

        // markers
    MarkerDefine (wxSTC_MARKNUM_FOLDER,        wxSTC_MARK_DOTDOTDOT, wxT("BLACK"), wxT("BLACK"));
    MarkerDefine (wxSTC_MARKNUM_FOLDEROPEN,    wxSTC_MARK_ARROWDOWN, wxT("BLACK"), wxT("BLACK"));
    MarkerDefine (wxSTC_MARKNUM_FOLDERSUB,     wxSTC_MARK_EMPTY,     wxT("BLACK"), wxT("BLACK"));
    MarkerDefine (wxSTC_MARKNUM_FOLDEREND,     wxSTC_MARK_DOTDOTDOT, wxT("BLACK"), wxT("WHITE"));
    MarkerDefine (wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_ARROWDOWN, wxT("BLACK"), wxT("WHITE"));
    MarkerDefine (wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY,     wxT("BLACK"), wxT("BLACK"));
    MarkerDefine (wxSTC_MARKNUM_FOLDERTAIL,    wxSTC_MARK_EMPTY,     wxT("BLACK"), wxT("BLACK"));

    //SetFoldFlags(wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED);
    SetWrapMode (wxSTC_WRAP_WORD); // other choice is wxSCI_WRAP_NONE

    for (int Nr = 0; Nr < wxSTC_STYLE_MAX; Nr++)
    {
        StyleSetForeground (Nr,  wxColour(225,225,225));
        StyleSetBackground (Nr, wxColour(50, 50, 50));
    }

    StyleSetForeground (wxSTC_STYLE_LINENUMBER, wxColour (150, 150, 150) );
    StyleSetBackground (wxSTC_STYLE_LINENUMBER, wxColour (25, 25, 25));
}

