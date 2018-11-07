TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    D:\source\linux-4.9.88\linux-4.9.88\include \
    D:\source\linux-4.9.88\linux-4.9.88\include\uapi


SOURCES += \
    ../../source/linux-4.9.88/linux-4.9.88/tools/gpio/gpio-event-mon.c \
    ../../source/linux-4.9.88/linux-4.9.88/tools/gpio/gpio-hammer.c \
    ../../source/linux-4.9.88/linux-4.9.88/tools/gpio/gpio-utils.c \
    ../../source/linux-4.9.88/linux-4.9.88/tools/gpio/lsgpio.c

HEADERS += \
    ../../source/linux-4.9.88/linux-4.9.88/tools/gpio/gpio-utils.h

DISTFILES += \
    ../../source/linux-4.9.88/linux-4.9.88/tools/gpio/Makefile
