
win32:CONFIG(release, debug|release): DESTDIR += $$OUT_PWD/../application/release
else:win32:CONFIG(debug, debug|release): DESTDIR += $$OUT_PWD/../application/debug
