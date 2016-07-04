#ifndef SETTINGS_H
#define SETTINGS_H
#include <wx/textfile.h>

#include "../lib/xmls/XMLSerialization.h"

using namespace xmls;

class Settings : public Serializable
{
public:
    Settings();
    ~Settings();
    
    wxTextFile file;
    
    xString FontName;
	xInt FontSize;
	xString Setting3;
	xInt Setting4;
	xInt Setting5;
	xBool Setting6;
	xBool Setting7;
    
    void Load();
    void Save();

protected:
    wxString FILENAME;
};

#endif // SETTINGS_H
