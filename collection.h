#pragma once

#include <wx/wx.h>
#include <wx/grid.h>
#include <string>
using namespace std;

#include "defs.h"
#include "table.h"

class Collection {
 private:
  Table *table;
  string collection_filename;
  int currentpos;
  bool is_saved=FALSE;

 public:
  Collection(wxFrame *frame);
  ~Collection();
  int NewCollection(void);
  int SaveCollection(void);
  int SaveCollectionAs(void);
  int OpenCollection(void);
  int AddItem(void);
  int DeleteItem(void);
  bool IsSaved(void);
};



