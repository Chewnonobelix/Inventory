#-------------------------------------------------
#
# Project created by QtCreator 2013-05-16T15:27:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gestionnaire_de_media
TEMPLATE = app


SOURCES += main.cpp

HEADERS  +=

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/release/ -lcontrolleur_lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/debug/ -lcontrolleur_lib

INCLUDEPATH += $$PWD/../Controlleur
DEPENDPATH += $$PWD/../Controlleur

OTHER_FILES +=
