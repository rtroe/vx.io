void vxTextCtrl::SetLexarAsCPP(wxStyledTextCtrl* text)
{

    SetLexarBase(text);
    text->SetLexer(wxSTC_LEX_CPP);

    text->StyleSetForeground (wxSTC_C_STRING,                       m_settings->CurColSchm.Col_C_StringDouble.TowxColour());
    text->StyleSetForeground (wxSTC_C_PREPROCESSOR,      m_settings->CurColSchm.Col_C_Preprocessor.TowxColour());
    //text->StyleSetForeground (wxSTC_C_IDENTIFIER,             wxColour(40,0,60));
    text->StyleSetForeground (wxSTC_C_NUMBER,                     m_settings->CurColSchm.Col_C_Number.TowxColour());
    text->StyleSetForeground (wxSTC_C_CHARACTER,              m_settings->CurColSchm.Col_C_StringSingle.TowxColour());
    text->StyleSetForeground (wxSTC_C_WORD,                         m_settings->CurColSchm.Col_Main_Word.TowxColour());
    text->StyleSetForeground (wxSTC_C_WORD2,                       m_settings->CurColSchm.Col_Main_Word2.TowxColour());
    text->StyleSetForeground (wxSTC_C_COMMENT,                  m_settings->CurColSchm.Col_C_Comment.TowxColour());
    text->StyleSetForeground (wxSTC_C_COMMENTLINE,         m_settings->CurColSchm.Col_C_CommentLine.TowxColour());
    text->StyleSetForeground (wxSTC_C_COMMENTDOC,        m_settings->CurColSchm.Col_C_CommentDoc.TowxColour());
    text->StyleSetForeground (wxSTC_C_COMMENTDOCKEYWORD, m_settings->CurColSchm.Col_C_CommentDocKeyword.TowxColour());
    text->StyleSetForeground (wxSTC_C_COMMENTDOCKEYWORDERROR, m_settings->CurColSchm.Col_C_CommentDocKeywordError.TowxColour());
    text->StyleSetBold(wxSTC_C_WORD, true);
    text->StyleSetBold(wxSTC_C_WORD2, true);
    text->StyleSetBold(wxSTC_C_COMMENTDOCKEYWORD, true);

    wxString CppWordlist1 = wxT("int if float asm auto bool break case catch char class const const_cast continue default delete do double dynamic_cast else enum explicit mutable namespace new operator private protected public register reinterpret_cast return short signed sizeof static static_cast struct switch template this throw true try typedef typeid typename union unsigned using virtual void extern volatile wchar_t DECLARE_EVENT_TABLE EVT_MENU EVT_UPDATE_UI EVT_MENU_RANGE BEGIN_EVENT_TABLE while");

    wxString CppWordlist2 =
    wxT("std cout endl wxArtProvider wxAuiNotebook wxAuiToolBarItem wxAuiToolBarItemArray wxAuiPaneInfoArray wxBitmap wxCommandEvent wxDefaultPosition wxDefaultSize wxGrid wxHtmlWindow wxMenuBar wxMenu wxPoint wxT wxTextCtrl wxTreeCtrl vxTextCtrl wxSize wxString wxWindow wxSizeEvent wxEraseEvent wxUpdateUIEvent wxStyledTextCtrl wxAuiManagerEvent wxAuiManager wxArrayString wxAuiToolBar");


    // a sample list of keywords, I haven't included them all to keep it short...
    text->SetKeyWords(0, CppWordlist1);
    text->SetKeyWords(1, CppWordlist2);
}


void vxTextCtrl::SetLexarAsC(wxStyledTextCtrl* text)
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

    wxString CppWordlist1 = wxT("break	else long switch case enum	register typedef char extern	return	union const float short unsigned continue for signed void default goto	sizeof	volatile do if static while");

    //wxString CppWordlist2 = wxT("wxArtProvider wxAuiNotebook wxAuiToolBarItem wxAuiToolBarItemArray wxAuiPaneInfoArray wxBitmap wxCommandEvent wxDefaultPosition wxDefaultSize wxGrid wxHtmlWindow wxMenuBar wxMenu wxPoint wxT wxTextCtrl wxTreeCtrl vxTextCtrl wxSize wxString wxWindow wxSizeEvent wxEraseEvent wxUpdateUIEvent wxStyledTextCtrl wxAuiManagerEvent wxAuiManager wxArrayString wxAuiToolBar");


    // a sample list of keywords, I haven't included them all to keep it short...
    text->SetKeyWords(0, CppWordlist1);
    //text->SetKeyWords(1, CppWordlist2);
}





void vxTextCtrl::SetLexarAsCS(wxStyledTextCtrl* text)
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

    wxString CppWordlist1 = wxT("abstract	as	base	bool	break byte	case	catch	char	checked class	const	continue	decimal	default delegate	do	double	else	enum event	explicit	extern	false	finally fixed	float	for	foreach goto	if	implicit in	int interface	internal	is	lock	long namespace	new	null	object	operator out	override	params	private	protected public	readonly	ref	return	sbyte sealed	short	sizeof	stackalloc static	string	struct	switch	this throw	true	try	typeof	uint ulong	unchecked	unsafe	ushort	using var	virtual	void	volatile	while");

    wxString CppWordlist2 = wxT("Program Console");


    // a sample list of keywords, I haven't included them all to keep it short...
    text->SetKeyWords(0, CppWordlist1);
    text->SetKeyWords(1, CppWordlist2);
}