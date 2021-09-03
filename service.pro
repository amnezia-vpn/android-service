TEMPLATE = lib
TARGET = service
CONFIG += dll
QT += core androidextras remoteobjects

SOURCES += service_main.cpp \
    openvpnandroidprotocol.cpp

include(./common/common_ro.pri)

REPC_SOURCE += ./common/qtandroidservice.rep

target.path = $$PWD
INSTALLS += target

INCLUDEPATH += $PWD/ovpncli.hpp
LIBS += -lamnezianl

HEADERS += \
    openvpnandroidprotocol.h \
    ovpncli.hpp
