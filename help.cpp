#include <wx/wx.h>
#include <wx/dialog.h>
#include <wx/mimetype.h>

using namespace std;

#include "dialog.h"
#include "help.h"

// constructor

Help::Help() {
}

int Help::HelpContents(void) {
wxMimeTypesManager *mtm=new wxMimeTypesManager;
wxFileType *filetype;
wxString executecommand;

filetype=mtm->GetFileTypeFromExtension(wxT("html"));		// get file type information

executecommand=filetype->GetOpenCommand("./help.html");		// get command to open html file

cout << executecommand << endl;

if(executecommand != "") {				// has command
 executecommand += " ./help.html";			// add parameter

 wxExecute(executecommand);				// open file
}

 delete(filetype);
}

int Help::About(void) {
 Dialog *dia=new Dialog;

 dia->MessageBox("About","Collection Manager Version 1.0. (c) Matthew Boote 2021");
}

