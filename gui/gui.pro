#-------------------------------------------------
#
# Project created by QtCreator 2017-12-07T21:06:41
#
#-------------------------------------------------

QT       += core gui

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += widgets

CONFIG += c++14

TARGET = gui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main/main.cpp \
        main/mainwindow.cpp \
    main/scheme.cpp \
    elements/style.cpp \
    elements/graphElement.cpp \
    elements/graphLayer.cpp \
    elements/graphPin.cpp \
    main/styleselect.cpp \
    elements/pblockstyle.cpp


HEADERS += \
    main/mainwindow.h \
    main/scheme.h \
    elements/style.h \
    main/styleselect.h \
    elements/graphElement.h \
    elements/graphLayer.h \
    elements/graphPin.h \
    elements/pblockstyle.h \
    settings.hpp


FORMS += \
        user_interface/mainwindow.ui \
    user_interface/scheme.ui \
    user_interface/styleselect.ui

LIBS += -lqjson

DISTFILES += \
    main/test.json \
    styles/DefaultStyle.json \
    styles/myStyle.json
