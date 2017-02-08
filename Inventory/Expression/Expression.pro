#-------------------------------------------------
#
# Project created by QtCreator 2016-02-08T09:28:14
#
#-------------------------------------------------

QT       -= gui

TARGET = Expression
TEMPLATE = lib

DEFINES += EXPRESSION_LIBRARY

SOURCES += \
    equivalentexpression.cpp \
    andexpression.cpp \
    orexpression.cpp \
    noexpression.cpp \
    impliedexpression.cpp

HEADERS += expression.h\
        expression_global.h \
    binaryexpression.h \
    additionexpression.h \
    divisionexpression.h \
    minusexpression.h \
    multiplicationexpression.h \
    andexpression.h \
    unaryexpression.h \
    valueexpression.h \
    equivalentexpression.h \
    impliedexpression.h \
    orexpression.h \
    noexpression.h \
    constantexpression.h

include(../config.pro)
