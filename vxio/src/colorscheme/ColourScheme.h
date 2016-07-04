#ifndef COLOURSCHEME_H
#define COLOURSCHEME_H

#include "../../lib/xmls/XMLSerialization.h"

using namespace xmls;

class vxColour : public Serializable
{
public:
    vxColour();
    ~vxColour();
    
   void SetColour(float,float,float,float);
    
    xFloat R;
	xFloat G;
	xFloat B;
	xFloat A;
};

class ColourScheme : public Serializable
{
public:
    ColourScheme();
    ~ColourScheme();
    
    xString Name;
	vxColour ColStringSingle;
	vxColour ColStringDouble;
	vxColour ColPreprocessor;
	vxColour ColNumber;
	vxColour ColChar;
	vxColour ColComment;
	vxColour ColCommentLine;
	vxColour ColCommentDoc;
	vxColour ColCommentDocKeyword;
	vxColour ColCommentDocKeywordError;
	vxColour ColWord;
	vxColour ColWord2;

};

#endif // COLOURSCHEME_H
