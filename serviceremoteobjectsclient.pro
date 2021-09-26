QT += qml quick androidextras remoteobjects

CONFIG += c++11

SOURCES += main.cpp

include(./common/common.pri)

REPC_REPLICA += ./common/amneziaandroidservice.rep

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

target.path = $$PWD
INSTALLS += target

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

DISTFILES += \
    android/AndroidManifest.xml \
    android/src/org/amnezia/amneziavpn/AmneziaAndroidService.java

ANDROID_EXTRA_LIBS = C:/Users/nikita.rozov/Documents/AmneziaVPN/Anroid-service/../amnezia-library/libamnezianl.so C:/Users/nikita.rozov/Documents/AmneziaVPN/Anroid-service/../amnezia-library/deps/openvpn/liblz4.so $$PWD/../amnezia-library/deps/openvpn/liblzo.so
