TEMPLATE = app
CONFIG -= console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

unix:!macx: LIBS += -L/usr/local/lib/ -lsfml-graphics
unix:!macx: LIBS += -L/usr/local/lib/ -lsfml-window
unix:!macx: LIBS += -L/usr/local/lib/ -lsfml-system

INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include

SOURCES += main.cpp \
    windowsmanager.cpp \
    gamewindow.cpp \
    player.cpp \
    texturesmanager.cpp \
    animatedsprite.cpp \
    basemap.cpp \
    basictile.cpp \
    infotile.cpp \
    basemapbuilder.cpp \
    richobject.cpp

HEADERS += \
    windowsmanager.h \
    gamewindow.h \
    player.h \
    texturesmanager.h \
    animatedsprite.h \
    basemap.h \
    basictile.h \
    infotile.h \
    basemapbuilder.h \
    richobject.h

OTHER_FILES += \
    ../test.map \
    ../test.link \
    ../test2.map

