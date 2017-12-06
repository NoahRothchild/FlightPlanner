TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    String.cpp \
    test.cpp \
    flight.cpp \
    filemanager.cpp \
    airport.cpp \
    flightoptions.cpp \
    rflights.cpp

HEADERS += \
    catch.hpp \
    DSString.h \
    test.h \
    linkednode.h \
    linkedlist.h \
    stack.h \
    flight.h \
    filemanager.h \
    airport.h \
    DSVector.h \
    flightoptions.h \
    rflights.h
