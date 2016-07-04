#include "ColourScheme.h"

vxColour::vxColour()
{
    R = 255;
    G = 255;
    B = 255;
    A = 255;
    
   	setClassName("vxColour");
	Register("R", &R);
	Register("G", &G);
	Register("B", &B);
	Register("A", &A);
	setVersion("1.0");
}

void vxColour::SetColour(float r, float g, float b, float a)
{
    R = r;
    G = g;
    B = b;
    A = a;
}

vxColour::~vxColour()
{
    
}


ColourScheme::ColourScheme()
{    
   	setClassName("ColourScheme");
	Register("Name", &Name);
	Register("ColStringSingle", &ColStringSingle);
	Register("ColStringDouble", &ColStringDouble);
	Register("ColPreprocessor", &ColPreprocessor);
	Register("ColNumber", &ColNumber);
	Register("ColChar", &ColChar);
	Register("ColComment", &ColComment);
	Register("ColCommentLine", &ColCommentLine);
	Register("ColCommentDoc", &ColCommentDoc);
	Register("ColCommentDocKeyword", &ColCommentDocKeyword);
	Register("ColCommentDocKeywordError", &ColCommentDocKeywordError);
	Register("ColWord", &ColWord);
	Register("ColWord2", &ColWord2);
	setVersion("1.0");
}

ColourScheme::~ColourScheme()
{
    
}

