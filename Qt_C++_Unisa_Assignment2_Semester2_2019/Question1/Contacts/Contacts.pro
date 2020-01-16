#-------------------------------------------------
#
# Project created by QtCreator 2016-07-26T12:04:06
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += -L$$(CPPLIBS) -ldataobjects
INCLUDEPATH	+= $$(CPPLIBS)/dataobjects

TARGET = Contacts
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    contact.cpp \
    contactlist.cpp \
    contactreader.cpp

HEADERS  += mainwindow.h \
    contact.h \
    contactlist.h \
    contactreader.h

FORMS    += mainwindow.ui
