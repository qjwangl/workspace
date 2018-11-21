TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ../../baidu/adu/apollo-v2x/app/policies/traffic_light/v2x_traffic_light.cpp

HEADERS += \
    ../../baidu/adu/apollo-v2x/app/policies/traffic_light/v2x_traffic_light.h

DISTFILES += \
    ../../baidu/adu/apollo-v2x/app/proto/v2x_carstatus.proto \
    ../../baidu/adu/apollo-v2x/app/proto/v2x_traffic_light.proto \
    ../../baidu/adu/apollo-v2x/app/proto/v2x_trafficlight_policy.proto \
    ../../baidu/adu/apollo-v2x/app/proto/chassis_detail.proto \
    ../../baidu/adu/apollo-v2x/app/proto/localization.proto
