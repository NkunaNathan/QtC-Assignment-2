#-------------------------------------------------
#
# Project created by QtCreator 2019-08-17T18:28:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Question2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    operations.cpp \
    intoperations.cpp \
    stringoperations.cpp \
    stringlistoperations.cpp \
    iofield.cpp \
    intiofield.cpp \
    stringiofield.cpp \
    stringlistiofield.cpp \
    operationsfactory.cpp \
    iofieldfactory.cpp \
    displaywidget.cpp

HEADERS  += mainwindow.h \
    operations.h \
    intoperations.h \
    stringoperations.h \
    stringlistoperations.h \
    iofield.h \
    intiofield.h \
    stringiofield.h \
    stringlistiofield.h \
    operationsfactory.h \
    iofieldfactory.h \
    displaywidget.h

FORMS    += mainwindow.ui
