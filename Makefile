INCLUDE = -I/usr/include/qt
OPTIONS = -fpic -Wall -Wextra
LIBS = -lQt5Core -lQt5Gui -lQt5Widgets

all:
	g++ $(OPTIONS) $(INCLUDE) ./main.cpp $(LIBS)
