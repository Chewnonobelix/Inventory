#-------------------------------------------------
#
# Project created by QtCreator 2013-05-16T15:29:10
#
#-------------------------------------------------



QT       += widgets network sql xml

TARGET = controlleur_lib
TEMPLATE = lib

DEFINES += CONTROLLEUR_LIBRARY

SOURCES += abstractcontrolleur.cpp \
    controlleurmainwindow.cpp \
    controlleurchargement.cpp \
    wizardpagechoix.cpp \
    controlleursauvegarde.cpp \
    controlleurplugin.cpp

HEADERS += abstractcontrolleur.h\
        controlleur_global.h \
    controlleurmainwindow.h \
    controlleurchargement.h \
    wizardpagechoix.h \
    controlleursauvegarde.h \
    InterfacePlugin.h \
    controlleurplugin.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../application/release/ -lmodel_lib -lvue_lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../application/debug/ -lmodel_lib -lvue_lib

INCLUDEPATH += $$OUT_PWD/../application
DEPENDPATH += $$OUT_PWD/../application



FORMS += \
    wizardpagechoix.ui

include(../compilation.pro)

QMAKE_CXXFLAGS += -std=c++11
