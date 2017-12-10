QT += qml quick

CONFIG += c++11

SOURCES += main.cpp \
    mazzo.cpp \
    cartaobject.cpp \
    labelobject.cpp \
    qmlstring.cpp \
    qmlint.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    mazzo.h \
    cartaobject.h \
    labelobject.h \
    qmlstring.h \
    qmlint.h

DISTFILES +=
