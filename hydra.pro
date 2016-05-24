TEMPLATE = app
SOURCES = main.cpp
HEADERS = assets.h os.h main.h
TARGET = HYDRA
CONFIG = debug c++11
LIBS = -lQt5Core -lQt5Gui -lQt5Widgets
QT = widgets gui core
message($$QMAKESPEC)
win32-g++ {
    CONFIG += windows
    LIBS += -LSFML-2.3.2/lib/ -lsfml-audio-d
    LIBS += -LC:/Qt/5.6/mingw49_32/lib/
    INCLUDEPATH += "C:/Qt/5.6/mingw49_32/include/"
    INCLUDEPATH += "SFML-2.3.2/include/"
    SOURCES += os_win.cpp
    HEADERS += mingw.thread.h
}
linux-g++ {
    LIBS += -lsfml-audio -pthread
    INCLUDEPATH = /usr/include/qt
    SOURCES += os_nix.cpp
}
