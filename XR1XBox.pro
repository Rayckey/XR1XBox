#-------------------------------------------------
#
# Project created by QtCreator 2018-08-22T12:01:40
#
#-------------------------------------------------

QT       -= gui

CONFIG += plugin

TARGET = XR1XBox
TEMPLATE = lib

DEFINES += XR1XBOX_LIBRARY

SOURCES += xr1xbox.cpp

HEADERS += xr1xbox.h\
        xr1xbox_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}



INCLUDEPATH += $$PWD/../Eigen3

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-QXboxController-Desktop_Qt_5_7_1_GCC_64bit-Debug/release/ -lQXboxController
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-QXboxController-Desktop_Qt_5_7_1_GCC_64bit-Debug/debug/ -lQXboxController
else:unix: LIBS += -L$$PWD/../build-QXboxController-Desktop_Qt_5_7_1_GCC_64bit-Debug/ -lQXboxController

INCLUDEPATH += $$PWD/../QXBoxController
DEPENDPATH += $$PWD/../QXBoxController
