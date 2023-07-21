#include "wx/wx.h"
#include <wx/toolbar.h>
#include <string>
using namespace std;

class Toolbar {
 private:
  wxToolBar *tb;

 public:
  Toolbar(wxFrame *frame);
  int AddItem(int id,wxBitmap bitmap,wxString tooltip);
};


