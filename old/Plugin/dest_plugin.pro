#HEADERS +=     ../../pattern/abstractfactory.h

QT       += widgets network sql xml xmlpatterns gui core

win32:CONFIG(release, debug|release): DESTDIR += ../../application/release/Plugin
else:win32:CONFIG(debug, debug|release): DESTDIR += ../../application/debug/Plugin

win32:CONFIG(release, debug|release){
 LIBS += -L$$OUT_PWD/../../application/release/ -lmodel_lib -lvue_lib -lcontrolleur_lib
INCLUDEPATH += $$OUT_PWD/../../application/release
DEPENDPATH += $$OUT_PWD/../../application/release
}
else:win32:CONFIG(debug, debug|release){
 LIBS += -L$$OUT_PWD/../../application/debug/ -lmodel_lib -lvue_lib -lcontrolleur_lib
INCLUDEPATH += ../../Controlleur ../../Model ../../Vue
DEPENDPATH += $$OUT_PWD/../../application/debug
}

QMAKE_CXXFLAGS += -std=c++11
