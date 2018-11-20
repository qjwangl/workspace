TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ../../baidu/adu/apollo-v2x/app/policies/traffic_light/v2x_traffic_light.cpp

HEADERS += \
    ../../baidu/adu/apollo-v2x/app/policies/traffic_light/v2x_traffic_light.h
