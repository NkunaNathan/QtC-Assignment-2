LIBS += -L$$(CPPLIBS) -ldataobjects
INCLUDEPATH += $$(CPPLIBS)/dataobjects

QT       += core

QT       -= gui

TARGET = Contacts
CONFIG   += console
CONFIG   -= app_bundle


TEMPLATE = app


SOURCES += main.cpp \
    contact.cpp \
    contactlist.cpp \
    contactfactory.cpp

HEADERS += \
    contact.h \
    contactlist.h \
    contactfactory.h

