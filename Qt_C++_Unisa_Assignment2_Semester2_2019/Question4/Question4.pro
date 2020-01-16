#-------------------------------------------------
#
# Project created by QtCreator 2019-08-16T22:26:33
#
#-------------------------------------------------

QT       += core gui webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += webkitwidgets

TARGET = Question4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    investmentview.cpp\
    investmentpluginfactory.cpp\
    investmentcalculator.cpp

HEADERS  += mainwindow.h \
    investmentview.h\
    investmentpluginfactory.h\
    investmentcalculator.h
