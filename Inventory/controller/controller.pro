#-------------------------------------------------
#
# Project created by QtCreator 2016-01-08T15:00:01
#
#-------------------------------------------------

QT       += xml core gui widgets


TARGET = Controller
TEMPLATE = lib

DEFINES += CONTROLLER_LIBRARY

SOURCES += abstractcontroller.cpp \
    maincontroller.cpp \
    savecontroller.cpp \
    loadcontroller.cpp \
    categorycontroller.cpp \
    mediacontroller.cpp \
    usercontroller.cpp \
    languagecontroller.cpp \
    researchcontroller.cpp \
    settingscontroller.cpp

HEADERS += abstractcontroller.h\
        controller_global.h \
    maincontroller.h \
    savecontroller.h \
    loadcontroller.h \
    categorycontroller.h \
    mediacontroller.h \
    usercontroller.h \
    languagecontroller.h \
    researchcontroller.h \
    settingscontroller.h


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Application/release/ -lExpression -lModel -lView
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Application/debug/ -lExpression -lModel -lView
else:unix:!macx: LIBS += -L$$OUT_PWD/../Application -lExpression -lView -lModel

include(../config.pro)

STATECHARTS += \
    hj.scxml
