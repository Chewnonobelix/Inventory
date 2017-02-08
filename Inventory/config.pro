CONFIG += c++14

win32:CONFIG(release, debug|release): DEPENDPATH += $$OUT_PWD/../Application/release
else:win32:CONFIG(release, debug|release): DEPENDPATH += $$OUT_PWD/../Application/debug
else:unix:!macx: DEPENDPATH = $$OUT_PWD/../Application

INCLUDEPATH += $$PWD/Expression
INCLUDEPATH += $$PWD/controller $$PWD/Model $$PWD/View

win32:CONFIG(release, debug|release): DESTDIR = ../Application/release
else:win32:CONFIG(debug, debug|release): DESTDIR = ../Application/debug
else:unix:!macx: DESTDIR = ../Application

unix {
    target.path = /usr/lib
    INSTALLS += target
}
