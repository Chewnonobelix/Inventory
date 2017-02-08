#-------------------------------------------------
#
# Project created by QtCreator 2016-01-08T15:00:59
#
#-------------------------------------------------

QT       += xml gui widgets core

TARGET = Model
TEMPLATE = lib

DEFINES += MODEL_LIBRARY

SOURCES += media.cpp \
    category.cpp \
    attribute.cpp \
    user.cpp \
    research.cpp \
    searchclaus.cpp

HEADERS += media.h\
        model_global.h \
    category.h \
    attribute.h \
    user.h \
    research.h \
    searchclaus.h


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Application/release/ -lExpression
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Application/debug/ -lExpression
else:unix:!macx: LIBS += -L$$OUT_PWD/../Application -lExpression

include(../config.pro)
