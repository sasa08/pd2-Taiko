#-------------------------------------------------
#
# Project created by QtCreator 2016-05-15T04:47:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pd2-Taiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    face.cpp

HEADERS  += mainwindow.h \
    scene.h \
    face.h

FORMS    += mainwindow.ui

RESOURCES += \
    pics.qrc
