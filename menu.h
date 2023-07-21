#pragma once

#include <wx/wx.h>
#include <iostream>
#include <wx/menu.h>
#include "window.h"

class MenuBar {
 private:
   wxMenuBar *menubar;
  
 public:
   MenuBar();
   int AddItem(wxMenu *menu,wxString name);
   wxMenuBar *GetItem(void);
};

class Menu {
 private:
  wxMenu *menu;

 public:
  Menu();
  int AddItem(int id,wxString name);
  wxMenu *GetMenu(void);
};

