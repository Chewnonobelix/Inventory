#-------------------------------------------------
#
# Project created by QtCreator 2013-07-09T10:04:14
#
#-------------------------------------------------

QT       += widgets network sql xml xmlpatterns

TARGET = plugin_jeuxvideo
TEMPLATE = lib

CONFIG += plugin

DEFINES += JEUXVIDEO_LIBRARY

SOURCES += pluginjeuxvideo.cpp \
    wizardpagejv.cpp \
    JeuxVideo.cpp \
    fenetrejeuxvideo.cpp \
    controlleurjeuxvideo.cpp

HEADERS += pluginjeuxvideo.h\
        jeuxvideo_global.h \
    wizardpagejv.h \
    JeuxVideo.h \
    fenetrejeuxvideo.h \
    controlleurjeuxvideo.h

FORMS += \
    wizardpagejv.ui \
    fenetrejeuxvideo.ui

include(../dest_plugin.pro)
