#include "Settings.h"
#include <wx/filename.h>
#include <wx/dir.h>
#include <iostream>
using namespace std;

Settings::Settings()
{
   	setClassName("Settings");
	Register("FontName", &FontName);
	Register("FontSize", &FontSize);
	Register("CurColSchm", &CurColSchm);
    
	Register("Setting4", &Setting4);
	Register("Setting5", &Setting5);
	Register("Setting6", &Setting6);
	Register("Setting7", &Setting7);
	setVersion("1.0");
    
    FILENAME = wxT("config/settings.xml");
    
    //Set Default Values incase Load() does not find the file
    FontName = "Calibri";
    FontSize = 9;
}

Settings::~Settings()
{
}

void Settings::Load()
{
    //Check if File Exits
    if(wxFileName::Exists(FILENAME))
    {
        cout<<"Loading Settings...";
        file.Open(FILENAME);
        
        string tempFile = "";
        
        for(int i = 0; i < file.GetLineCount(); i++)
        {
            tempFile += file.GetLine(i);
        }
        
     if (Serializable::fromXML(tempFile, this))
	{
        cout<<"Done!"<<endl;
//	cout << "Result:" << endl;
//	cout << this->toXML() << endl << endl;
    }
        file.Close();
    }
    else
    {
        //Check to see if the config Directory exists
        if(wxDir::Exists("config") == false)
        {
            wxDir::Make("config");
        }
        
        //Alert in the debug which file was not found
        cout<<"File '"<<FILENAME<<"' Not Found!"<<endl;
        
        //Now create the settings xml file in the config directory
        cout<<"Creating Settings File...";
        file.Create(FILENAME);
        cout<<"Done!"<<endl;
        
        Save();
        Load();
    }
}

void Settings::Save()
{    
    cout<<"Saving Settings File...";
        file.Open(FILENAME);
        
        //first clear it so that it's a clean save file we're dealing with
        file.Clear();
        
        //Add XML in
        file.AddLine(this->toXML());
        
        //Write the contents to the file
        file.Write();
        
        //Close the file writer
        file.Close();   
        
    cout<<"Done!"<<endl;
}

