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
    setter.cpp \
    statistics.cpp \
    vposition.cpp \
    ball.cpp \
    court.cpp

HEADERS += \
    receiver.h \
    player.h \
    game.h \
    oppositespiker.h \
    middleblocker.h \
    setter.h \
    statistics.h \
    vposition.h \
    ball.h \
    court.h

QMAKE_CXXFLAGS += -std=c++11
