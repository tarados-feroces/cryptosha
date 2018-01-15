#-------------------------------------------------
#
# Project created by QtCreator 2017-12-07T21:06:41
#
#-------------------------------------------------

QT       += core gui

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += widgets

CONFIG += c++11

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
        elements/graph_pin.cpp \
#        elements/graph_scene.cpp \
    elements/graph_element.cpp \
    elements/graph_layer.cpp \
    main/scheme.cpp
#    elements/graph_scene.cpp \


HEADERS += \
    main/mainwindow.h \
    elements/graph_pin.h \
    elements/graph_element.h \
    elements/graph_layer.h \
    main/scheme.h
#    elements/graph_scene.h \

FORMS += \
        user_interface/mainwindow.ui \
    user_interface/scheme.ui

LIBS += -lqjson

DISTFILES += \
    main/test.json