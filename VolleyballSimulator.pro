TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    receiver.cpp \
    player.cpp \
    game.cpp \
    oppositespiker.cpp \
    middleblocker.cpp \
    setter.cpp

HEADERS += \
    receiver.h \
    player.h \
    game.h \
    oppositespiker.h \
    middleblocker.h \
    setter.h

QMAKE_CXXFLAGS += -std=c++11
