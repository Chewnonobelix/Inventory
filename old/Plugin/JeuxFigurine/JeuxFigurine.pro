#-------------------------------------------------
#
# Project created by QtCreator 2013-07-15T16:22:40
#
#-------------------------------------------------

QT       += widgets sql webkit xml xmlpatterns

TARGET = plugin_jeuxfigurine
TEMPLATE = lib

DEFINES += JEUXFIGURINE_LIBRARY

SOURCES += jeuxfigurine.cpp \
    controlleurjeuxfigurine.cpp \
    pluginjeuxfigurine.cpp \
    wizardpagejeuxfigurine.cpp \
    fenetrejeuxfigurine.cpp \
    livre.cpp \
    figurines.cpp \
    ajoutlivre.cpp \
    controlleurlivre.cpp \
    ajoutfigurine.cpp \
    controlleurfigurine.cpp

HEADERS += jeuxfigurine.h\
        jeuxfigurine_global.h \
    controlleurjeuxfigurine.h \
    pluginjeuxfigurine.h \
    wizardpagejeuxfigurine.h \
    fenetrejeuxfigurine.h \
    livre.h \
    figurines.h \
    ajoutlivre.h \
    controlleurlivre.h \
    ajoutfigurine.h \
    controlleurfigurine.h

include(../dest_plugin.pro)

FORMS += \
    wizardpagejeuxfigurine.ui \
    fenetrejeuxfigurine.ui \
    ajoutlivre.ui \
    ajoutfigurine.ui


