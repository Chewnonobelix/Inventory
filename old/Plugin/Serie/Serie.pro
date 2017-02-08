#-------------------------------------------------
#
# Project created by QtCreator 2013-07-09T10:03:32
#
#-------------------------------------------------

QT       += widgets sql xml xmlpatterns

TARGET = plugin_serie
TEMPLATE = lib

CONFIG += plugin

DEFINES += SERIE_LIBRARY

SOURCES += pluginserie.cpp \
    wizardpageserie.cpp \
    Serie.cpp \
    fenetreserie.cpp \
    controlleurserie.cpp

HEADERS += pluginserie.h\
        serie_global.h \
    wizardpageserie.h \
    Serie.h \
    fenetreserie.h \
    controlleurserie.h \

FORMS += \
    wizardpageserie.ui \
    fenetreserie.ui

include(../dest_plugin.pro)
