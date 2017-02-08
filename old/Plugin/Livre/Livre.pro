#-------------------------------------------------
#
# Project created by QtCreator 2013-07-15T11:31:57
#
#-------------------------------------------------

QT       += widgets network sql xml xmlpatterns gui core

TARGET = plugin_livre
TEMPLATE = lib

DEFINES += LIVRE_LIBRARY

SOURCES += livre.cpp \
    controlleurlivre.cpp \
    pluginlivre.cpp \
    wizardpagelivre.cpp \
    fenetrelivre.cpp

HEADERS += livre.h\
        livre_global.h \
    controlleurlivre.h \
    pluginlivre.h \
    wizardpagelivre.h \
    fenetrelivre.h

include(../dest_plugin.pro)

FORMS += \
    wizardpagelivre.ui \
    fenetrelivre.ui
