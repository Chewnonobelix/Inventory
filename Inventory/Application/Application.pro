#-------------------------------------------------
#
# Project created by QtCreator 2016-01-11T11:05:20
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Inventory
TEMPLATE = app


SOURCES += main.cpp

HEADERS  +=

FORMS    +=

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/release/ -lExpression -lController  -lView -lModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/debug/ -lExpression -lController -lView -lModel
else:unix:!macx: LIBS += -L$$OUT_PWD/ -lExpression -lController -lView -lModel

include(../config.pro)
