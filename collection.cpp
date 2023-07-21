#include "wx/wx.h"
#include <wx/grid.h>

#include <iostream>
#include <string>
using namespace std;
#include "collection.h"
#include "main.h"
#include "dialog.h"

// Constructor for collection

Collection::Collection(wxFrame *frame) {
 table=new Table(frame);
 collection_filename="";
}

// Destructor for collection

Collection::~Collection() {
 delete(table);				// destroy table
}

int Collection::NewCollection(void) {
}

int Collection::OpenCollection(void) {
 int ret;
 Dialog *dia=new Dialog;
 string filename;

 filename=dia->OpenFileDialog();				// get filename from dialog
 
 ret=table->LoadTableFromFile(filename);		// load filename
 if(ret == -1) return(-1);

 collection_filename=filename;
}

int Collection::SaveCollection(void) {
 int ret;
 Dialog *dia=new Dialog;
 string filename;

 if(collection_filename == "") {				// no filename
  filename=dia->SaveFileDialog();				// get filename from dialog
 }
 else
 {
  filename=collection_filename;
 }

 ret=table->SaveTableToFile(filename);		// save database
 if(ret == -1) return(-1);

 is_saved=TRUE;
}

int Collection::SaveCollectionAs(void) {
 int ret;
 Dialog *dia=new Dialog;
 string filename;

 filename=dia->SaveFileAsDialog();				// get filename from dialog

 ret=table->SaveTableToFile(filename);			// save database
 if(ret == -1) return(-1);

 collection_filename=filename;
 is_saved=TRUE;
}

int Collection::AddItem(void) {
  table->add_item();

  is_saved=FALSE;
}

int Collection::DeleteItem(void) {
  table->delete_item();

  is_saved=FALSE;
}

bool Collection::IsSaved(void) {
 return(is_saved);
}

