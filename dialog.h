#include <string>
using namespace std;

class Dialog {
 
 public:
  Dialog();
  int MessageBox(wxString title,wxString message);
  int yes_no_dialog(string title,string message);
  wxString OpenFileDialog(void);
  wxString SaveFileDialog(void);
  wxString SaveFileAsDialog(void);
};

