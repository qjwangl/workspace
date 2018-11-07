TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += D:\source\linux-4.9.88\linux-4.9.88\include

SOURCES += \
    getopt.cpp \
    hello.cpp \
    gpio.cpp

DISTFILES += \
    Makefile \
    Makefile_arm-linux-

HEADERS += \
    hello.h
