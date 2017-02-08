#-------------------------------------------------
#
# Project created by QtCreator 2013-07-15T10:25:08
#
#-------------------------------------------------

QT       += widgets network sql webkit xml xmlpatterns

TARGET = plugin_film
TEMPLATE = lib

DEFINES += FILM_LIBRARY

SOURCES += film.cpp \
    pluginfilm.cpp \
    controlleurfilm.cpp \
    fenetrefilm.cpp \
    wizardpagefilm.cpp

HEADERS += film.h\
        film_global.h \
    pluginfilm.h \
    controlleurfilm.h \
    fenetrefilm.h \
    wizardpagefilm.h

FORMS += \
    fenetrefilm.ui \
    wizardpagefilm.ui

include(../dest_plugin.pro)
