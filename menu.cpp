#include <wx/wx.h>
#include <wx/menu.h>
#include <iostream>
#include <string>
using namespace std;

#include "menu.h"

//*************
// menu functions
//

// constructor for MenuBar
MenuBar::MenuBar() {
    menubar = new wxMenuBar;
}

int MenuBar::AddItem(wxMenu *menu,wxString name) {
   menubar->Append(menu, name);				// add menu bar item
}

wxMenuBar *MenuBar::GetItem(void) {
 return(menubar);
}

// constructor for Menu

Menu::Menu()  {
  menu = new wxMenu;
}


int Menu::AddItem(int id,wxString name) {	
  menu->Append(id, name);				// add menuitem
}

wxMenu *Menu::GetMenu(void) {
 return(menu);
}
