#-------------------------------------------------
#
# Project created by QtCreator 2013-05-16T15:39:04
#
#-------------------------------------------------

QT       += widgets sql xml

TARGET = vue_lib
TEMPLATE = lib

DEFINES += VUE_LIBRARY

SOURCES += \
    mainwindow.cpp \
    option.cpp

HEADERS +=\
        vue_global.h \
    mainwindow.h \
    option.h

FORMS += \
    mainwindow.ui \
    option.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../application/release/ -lmodel_lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../application/debug/ -lmodel_lib

INCLUDEPATH += $$OUT_PWD/../application
DEPENDPATH += $$OUT_PWD/../application

include(../compilation.pro)

