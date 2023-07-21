#pragma once

#include <wx/wx.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/menu.h>
#include <string>
#include <wx/string.h>
using namespace std;

#include "defs.h"
#include "main.h"
#include "menu.h"
#include "table.h"
#include "window.h"
#include "collection.h"
#include <iostream>

// constructor

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(NULL, wxID_ANY, "Collection Manager") {

// Create menus

  Menu *FileMenu=new Menu;				// add file menu
  FileMenu->AddItem(NEW_FILE,"New");
  FileMenu->AddItem(OPEN_FILE,"&Open");
  FileMenu->AddItem(SAVE_FILE,"&Save");
  FileMenu->AddItem(SAVE_FILE_AS,"Save &As");
  FileMenu->AddItem(QUIT_APP,"&Quit");

  Menu *ItemMenu=new Menu;					// add item menu
  ItemMenu->AddItem(ADD_ITEM,"&Add item");
  ItemMenu->AddItem(DELETE_ITEM,"&Delete item");

  Menu *HelpMenu=new Menu;					// add help menu
  HelpMenu->AddItem(HELP_CONTENTS,"&Contents");
  HelpMenu->AddItem(HELP_ABOUT,"&About");

  MenuBar *CMMenuBar=new MenuBar;				// create menu bar

  CMMenuBar->AddItem(FileMenu->GetMenu(),"&File");				// add menus to menubar
  CMMenuBar->AddItem(ItemMenu->GetMenu(),"&Item");
  CMMenuBar->AddItem(HelpMenu->GetMenu(),"&Help");
  AddMenuBarToWindow(CMMenuBar->GetItem());			// add menubar to MyFrame
}

int MainFrame::AddMenuBarToWindow(wxMenuBar *MenuBar) {
 SetMenuBar(MenuBar);
}
