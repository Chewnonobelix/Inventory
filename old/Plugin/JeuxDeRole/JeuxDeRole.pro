#-------------------------------------------------
#
# Project created by QtCreator 2013-07-15T16:24:11
#
#-------------------------------------------------

QT       += widgets network webkit webkitwidgets xml xmlpatterns

TARGET = plugin_jeuxderole
TEMPLATE = lib

DEFINES += JEUXDEROLE_LIBRARY

SOURCES += jeuxderole.cpp \
    fenetrejdr.cpp \
    wizardpagejdr.cpp \
    controlleurjdr.cpp \
    pluginjdr.cpp \
    wizardsupplement.cpp \
    supplement.cpp \
    fenetresupplement.cpp

HEADERS += jeuxderole.h\
        jeuxderole_global.h \
    fenetrejdr.h \
    wizardpagejdr.h \
    controlleurjdr.h \
    pluginjdr.h \
    wizardsupplement.h \
    supplement.h \
    fenetresupplement.h

include(../dest_plugin.pro)

FORMS += \
    fenetrejdr.ui \
    wizardpagejdr.ui \
    wizardsupplement.ui \
    fenetresupplement.ui
