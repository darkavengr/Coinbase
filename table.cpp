#include <wx/wx.h>
#include <wx/grid.h>
#include <wx/gdicmn.h>
#include <iostream>
#include <fstream>
#include <string>
#include "defs.h"

using namespace std;

#include "table.h"
 
//************************
// table functions

// Table constructor
Table::Table(wxFrame *frame) {
 int colcount=0;
 int *width=new int;
 int *height=new int;
 int w;

 string column_headers[] = { "Image" , "Description" , "Year" , "Condition" , "Weight" , "Height" , "Width","" };

 frame->GetSize(width,height);		// get frame size
 wxSize GridSize(*width,*height);

 w=*width;					// get width
 
 gui_coin_table=new wxGrid(frame,wxID_ANY, wxDefaultPosition, GridSize,wxEXPAND);		// create new table

 gui_coin_table->CreateGrid(1,NUM_COLUMNS);		// create table
// gui_coin_table->Fit();

  while(column_headers[colcount].compare("") != 0) {
   gui_coin_table->SetColLabelValue(colcount,column_headers[colcount]);		// set column header
   gui_coin_table->SetColSize(colcount,w/(NUM_COLUMNS/4));
 
  colcount++;
 }

 rowcount=1;
 currentrow=1;
}

// add item to table at currently selected row

 void Table::add_item(void) {
  if(currentrow == gui_coin_table->GetNumberRows()) {			// if at end
          gui_coin_table->AppendRows(1);	// add new row
  }
  else
  {
   gui_coin_table->InsertRows(currentrow);
 }
  
  rowcount++;
}
  
// edit item in table
 void Table::edit_item(void) {
 }

// delete item at currently row

 void Table::delete_item(void) {
  gui_coin_table->DeleteRows(currentrow,1);
  rowcount--;
 }

void Table::select_row(int row,int col) {
 gui_coin_table->GoToCell(row,col);

}

 
// Load database from CSV file

int Table::LoadTableFromFile(string filename) {
 ifstream myfile;
 int count;
 string line;
 string tokens[MAX_NAME_SIZE];
 int tokencount;

 rowcount=0;

 myfile.open(filename,std::ifstream::in);
 if(!myfile) return(-1);

 do {

 getline(myfile,line);			// read line from file

 if(line == "") return(0);			// ignore blank lines

// tokenize line

  tokencount=0;

// clear tokens
  for(count=0;count < MAX_NAME_SIZE-1;count++) {
   tokens[count]="";
  }

  for(count=0;count<line.length();count++) {
   if(line[count] == ',') {				// if at end

    tokencount++;					// point to next token
   }
   else
   {
    tokens[tokencount] += line[count];			// add to current token
   }

  }

  for(count=0;count< NUM_COLUMNS;count++) {
   gui_coin_table->SetCellValue(rowcount,count,tokens[count]);		// add data
  }

  gui_coin_table->AppendRows(1);	// add new row
     
  rowcount++;

 } while(!myfile.eof());			// until end of file

 myfile.close();

}

int Table::SaveTableToFile(string filename) {
 ofstream myfile;
 int colcount;
 string line;
 int count;

// add csv extension if there is no extension

 for(count=filename.length();count > 0;count--) {
  if(filename[count] == '.') break;			// found extension
 }

 if(count == 0)  filename += ".csv";		// no extension found , add extension
 
 myfile.open(filename,std::ofstream::out);			// open file
 line="";

 for(count=0;count<rowcount+1;count++) { 
  line="";

  for(colcount=0;colcount<NUM_COLUMNS;colcount++) {
  	line += gui_coin_table->GetCellValue(count,colcount);	// add to line
	
	if(colcount < NUM_COLUMNS-1) line += ",";	
   }

   line += "\n";

   myfile << line;		// write line
 }
myfile.close();
}
