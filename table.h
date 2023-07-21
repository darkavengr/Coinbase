#pragma once

#include "wx/wx.h"
#include "wx/grid.h"
#include <iostream>

#define LIST_WIDTH	8
#define NUM_COLUMNS	8

#define CSV_IMAGE_FILENAME	0
#define CSV_NAME	1
#define CSV_DESCRIPTION	2
#define CSV_YEAR	3
#define CSV_GRADE	4
#define CSV_WEIGHT	5
#define CSV_HEIGHT	6
#define CSV_WIDTH	7


class Table {
 private:
 wxGrid *gui_coin_table;
 int currentrow=0;
 int rowcount=0;

 public:
  Table(wxFrame *frame);
  int LoadTableFromFile(string filename);
  int SaveTableToFile(string filename);
  void add_item(void);
  void edit_item(void);
  void delete_item(void);
  void select_row(int row,int col);
};

