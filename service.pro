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

#LIBS += -lopenvnp3
#INCLUDEPATH

HEADERS += \
    openvpnandroidprotocol.h \
    ovpncli.hpp
