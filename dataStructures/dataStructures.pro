TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    parameter.cpp \
    sort.cpp \
    kmp.cpp \
    kmp2.cpp \
    childtree.cpp \
    fathertree.cpp \
    brothertree.cpp \
    threadtree.cpp \
    binarythreadtree.cpp

HEADERS += \
    tree.h
