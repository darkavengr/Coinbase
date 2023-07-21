#pragma once

#include <wx/wx.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <iostream>

class MainFrame: public wxFrame {
 private:
  wxDECLARE_EVENT_TABLE();

 public:
   MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
   int AddMenuBarToWindow(wxMenuBar *MenuBar);

};


