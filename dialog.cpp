#include <wx/wx.h>
#include <wx/dialog.h>
#include <wx/filedlg.h>
#include <string>
using namespace std;
#include "dialog.h"

//**************
// dialog functions

// contructor for Dialog

Dialog::Dialog() {
}

// message box
int Dialog::MessageBox(wxString title,wxString message) {
 wxMessageBox(message,title);
}

// Yes/No messagebox
int Dialog::yes_no_dialog(string title,string message) {
  int result;

  result=wxMessageBox(message,title,wxYES_NO);			// display yes no messagebox
   
   if(result == wxYES) {		// click yes
	return(true);
   }
   else
   {
 	return(false);
   }

}

 wxString Dialog::OpenFileDialog(void) {
  int count;
  int row;
  int column;
  wxString filename;

  wxFileDialog *openfiledialog=new wxFileDialog(NULL, _("Open collection"), "", "","CSV files (*.csv)|*.csv", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
  if(openfiledialog->ShowModal() == wxID_CANCEL) return("");		// user pressed cancel
  
  filename=openfiledialog->GetFilename();			// get filenames selected

  openfiledialog->Destroy();		// clean up dialog

  return(filename);
 }

 wxString Dialog::SaveFileDialog(void) {
  wxString filename;
  wxFileDialog *savefiledialog=new wxFileDialog(NULL, _("Save collection"), "", "","CSV files (*.csv)|*.csv", wxFD_SAVE);

  if(savefiledialog->ShowModal() == wxID_CANCEL) return("");		// user pressed cancel

  filename=savefiledialog->GetFilename();			// get filenames selected

  savefiledialog->Destroy();		// clean up dialog
  return(filename);
 }
 
wxString Dialog::SaveFileAsDialog(void) {
 wxString filename;
 wxFileDialog *savefiledialog=new wxFileDialog(NULL, _("Save collection"), "", "","CSV files (*.csv)|*.csv", wxFD_SAVE);
 
 if(savefiledialog->ShowModal() == wxID_CANCEL) return("");		// user pressed cancel

 filename=savefiledialog->GetFilename();			// get filenames selected

 savefiledialog->Destroy();		// clean up dialog
 return(filename); 
}

