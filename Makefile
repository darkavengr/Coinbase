CC=g++
CCOPTS=`wx-config --cxxflags --libs` -w -o CollectionManager
CCFILES=collection.cpp dialog.cpp main.cpp menu.cpp table.cpp window.cpp toolbar.cpp help.cpp

all:
	$(CC) $(CCFILES) $(CCOPTS)


