void vxTextCtrl::SetLexarAsJS(wxStyledTextCtrl* text)
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

    wxString CppWordlist1 = wxT("abstract	arguments	boolean	break	byte case	catch	char	class*	const continue	debugger	default	delete	do double	else	enum*	eval	export* extends*	false	final	finally	float for	function	goto	if	implements import*	in	instanceof	int	interface let	long	native	new	null package	private	protected	public	return short	static	super*	switch	synchronized this	throw	throws	transient	true try	typeof	var	void	volatile while	with	yield");


    // a sample list of keywords, I haven't included them all to keep it short...
    text->SetKeyWords(0, CppWordlist1);
    //text->SetKeyWords(1, CppWordlist2);
}


void vxTextCtrl::SetLexarAsCSS(wxStyledTextCtrl* text)
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

    wxString CppWordlist1 = wxT("content uppercase center url after before visibility block right bottom top left repeat text align clear display overflow font weight family size hidden both background padding padding-left padding-right padding-top margin margin-block-end margin-block-start margin-bottom margin-inline-end margin-inline-start margin-left margin-right margin-top color column-count column-fill column-gap column-rule column-rule-color column-rule-style column-rule-width column-span column-width columns widows width height font-family top bottom");

    wxString CppWordlist2 = wxT("body h1 h2 h3 h4 h5 h6 h7 h8 h9 p a hover li ul active src img");

    // a sample list of keywords, I haven't included them all to keep it short...
    text->SetKeyWords(0, CppWordlist1);
    text->SetKeyWords(1, CppWordlist2);
}

void vxTextCtrl::SetLexarAsPHP(wxStyledTextCtrl* text)
{

    SetLexarBase(text);
    text->SetLexer(wxSTC_LEX_PHPSCRIPT);

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

    wxString CppWordlist1 = wxT("abstract and array() as	break case	catch 	cfunction 	class	clone  const	continue	declare	default	do else	elseif	enddeclare	endfor	endforeach endif	endswitch	endwhile	extends final  for	foreach	function	global	goto  if	implements 	interface 	instanceof  namespace 	new	old_function 	or	private  protected 	public 	static	switch	throw  try 	use	var	while	xor");


    // a sample list of keywords, I haven't included them all to keep it short...
    text->SetKeyWords(0, CppWordlist1);
    //text->SetKeyWords(1, CppWordlist2);
}
