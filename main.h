#pragma once
#include <wx/wx.h>

#define NEW_FILE	1
#define OPEN_FILE 	2
#define	SAVE_FILE	3
#define	SAVE_FILE_AS	4
#define ADD_ITEM	5
#define DELETE_ITEM	6
#define QUIT_APP	9
#define	HELP_CONTENTS	10
#define HELP_ABOUT	11

class CollectionManager : public wxApp {
 public:
  virtual bool OnInit();
  void FileNew(wxCommandEvent& event);
  void FileOpen(wxCommandEvent& event);
  void FileSave(wxCommandEvent& event);
  void FileSaveAs(wxCommandEvent& event);
  void ItemAdd(wxCommandEvent& event);
  void ItemDelete(wxCommandEvent& event);
  void QuitApp(wxCommandEvent& event);
  void HelpContents(wxCommandEvent& event);
  void HelpAbout(wxCommandEvent& event);
};

