#include <wx/wx.h>
#include <wx/toolbar.h>
#include <iostream>
#include <string>
using namespace std;

#include "toolbar.h"

// constructor

Toolbar::Toolbar(wxFrame *frame) {
 tb=new wxToolBar(frame,wxID_ANY,wxDefaultPosition, wxDefaultSize);
 tb->Show(true);
 tb->Realize();
}

// add item to toolbar

int Toolbar::AddItem(int id,wxBitmap bitmap,wxString tooltip) {
 tb->AddTool(id,"",bitmap,tooltip,wxITEM_NORMAL);

 tb->Realize();
}

