TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Player.cpp \
    Game.cpp

HEADERS += \
    Player.h \
    Game.h

QMAKE_CXXFLAGS += -std=c++11
