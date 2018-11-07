TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    rs485_t.cpp

INCLUDEPATH += ../../source/linux-4.9.88/linux-4.9.88/include \
               ../../source/include
