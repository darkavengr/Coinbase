#include <wx/wx.h>
#include <wx/dialog.h>
#include <wx/menu.h>
#include <wx/grid.h>
#include <wx/toolbar.h>
#include <wx/frame.h>
#include <string>
using namespace std;

#include "main.h"
#include "window.h"
#include "collection.h"
#include "dialog.h"
#include "toolbar.h"
#include "help.h"

// macro to connect the menus to events

   wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)
    EVT_MENU(NEW_FILE,CollectionManager::FileNew)
    EVT_MENU(OPEN_FILE,CollectionManager::FileOpen)
    EVT_MENU(SAVE_FILE,CollectionManager::FileSave)
    EVT_MENU(SAVE_FILE_AS,CollectionManager::FileSaveAs) 
    EVT_MENU(ADD_ITEM,CollectionManager::ItemAdd) 
    EVT_MENU(DELETE_ITEM,CollectionManager::ItemDelete)
    EVT_MENU(HELP_CONTENTS,CollectionManager::HelpContents) 
    EVT_MENU(HELP_ABOUT,CollectionManager::HelpAbout)

  wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(CollectionManager);		// main function

Collection *collection;

bool CollectionManager::OnInit(void) {
 MainFrame *frame=new MainFrame("Collection Manager", wxPoint(50, 50), wxSize(1000,1000));

 frame->Maximize();
 frame->Show(1);

 collection=new Collection(frame);
 collection->NewCollection();			// start new collection
}


// misc functions
 void CollectionManager::QuitApp(wxCommandEvent& event) {
  Dialog *dia=new Dialog;

  if(collection->IsSaved() == FALSE) {		// collection not saved
   if(dia->yes_no_dialog("Save now?","Collection has not been saved. Save now?") == true) {
    collection->SaveCollection();					// save current collection
    exit(0);
   } 
  }

  exit(0);
 }

// event handlers

 void CollectionManager:: FileNew(wxCommandEvent& event) {
  collection->NewCollection();
 }

 void CollectionManager:: FileOpen(wxCommandEvent& event) {
  collection->OpenCollection();
 }

 void CollectionManager:: FileSave(wxCommandEvent& event) {
  collection->SaveCollection();
 }

 void CollectionManager:: FileSaveAs(wxCommandEvent& event) {
  collection->SaveCollectionAs();
 }

 void CollectionManager:: ItemAdd(wxCommandEvent& event) {
  collection->AddItem();
 }

 void CollectionManager:: ItemDelete(wxCommandEvent& event) {
  collection->DeleteItem();
 }

 void CollectionManager:: HelpContents(wxCommandEvent& event) {
  Help *help=new Help;

  help->HelpContents();
  delete(help);
 }

 void CollectionManager:: HelpAbout(wxCommandEvent& event) {
  Help *help=new Help;

  help->About();
  delete(help);
 }
