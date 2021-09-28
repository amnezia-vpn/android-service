TEMPLATE = lib
TARGET = service
CONFIG += dll
QT += core androidextras remoteobjects

SOURCES += service_main.cpp

include(./common/common_ro.pri)

REPC_SOURCE += ./common/amneziaandroidservice.rep

target.path = $PWD
INSTALLS += target

android {
    assets.files = config/osinit.ovpn
    assets.path = /assets/config/
    INSTALLS += assets
}

INCLUDEPATH += \
            . \
            ../amnezia-library \
            ../amnezia-library/src \
            ../amnezia-library/deps/openvpn/openvpn3 \



LIBS += -L../amnezia-library -lamnezianl
LIBS += -L../amnezia-library\deps\openvpn -llz4
LIBS += -L../amnezia-library\deps\openvpn -llzo
