#-------------------------------------------------
#
# Project created by QtCreator 2013-07-09T10:04:54
#
#-------------------------------------------------


QT       += widgets sql xml xmlpatterns

TARGET = plugin_bandedessine
TEMPLATE = lib

CONFIG += plugin

DEFINES += BANDEDESSINE_LIBRARY

SOURCES += pluginbandedessine.cpp \
    controlleurbd.cpp \
    wizardpagebd.cpp \
    bandedessine.cpp \
    fenetrebd.cpp \
    ajout.cpp

HEADERS += pluginbandedessine.h\
        bandedessine_global.h \
    controlleurbd.h \
    wizardpagebd.h \
    bandedessine.h \
    fenetrebd.h \
    ajout.h

FORMS += \
    wizardpagebd.ui \
    fenetrebd.ui \
    ajout.ui

include(../dest_plugin.pro)

