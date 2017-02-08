#-------------------------------------------------
#
# Project created by QtCreator 2016-01-08T15:01:32
#
#-------------------------------------------------

QT       += widgets gui xml

TARGET = View
TEMPLATE = lib

DEFINES += VIEW_LIBRARY

SOURCES += \
    mainwindow.cpp \
    mediaview.cpp \
    mediawidget.cpp \
    categoryedit.cpp \
    categoryeditpage.cpp \
    uichoice.cpp \
    usersetting.cpp \
    researchview.cpp \
    groupclaus.cpp \
    claus.cpp \
    search.cpp \
    subcomponent.cpp \
    settings.cpp

HEADERS +=\
        view_global.h \
    mainwindow.h \
    mediaview.h \
    mediawidget.h \
    categoryedit.h \
    categoryeditpage.h \
    uichoice.h \
    usersetting.h \
    researchview.h \
    groupclaus.h \
    claus.h \
    search.h \
    subcomponent.h \
    settings.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Application/release/ -lExpression -lModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Application/debug/ -lExpression -lModel
else:unix:!macx: LIBS += -L$$OUT_PWD/../Application/ -lExpression -lModel

FORMS += \
    mainwindow.ui \
    mediaview.ui \
    mediawidget.ui \
    categoryedit.ui \
    categoryeditpage.ui \
    uichoice.ui \
    usersetting.ui \
    researchview.ui \
    groupclaus.ui \
    claus.ui \
    settings.ui

include(../config.pro)
