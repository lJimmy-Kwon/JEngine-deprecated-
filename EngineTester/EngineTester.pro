QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    clock_test.cpp \
    main_test.cpp \
    vector2d_test.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Engine/release/ -lEngine
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Engine/debug/ -lEngine
else:unix: LIBS += -L$$OUT_PWD/../Engine/ -lEngine

INCLUDEPATH += $$PWD/../Engine
DEPENDPATH += $$PWD/../Engine

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Engine/release/libEngine.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Engine/debug/libEngine.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Engine/release/Engine.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Engine/debug/Engine.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Engine/libEngine.a

HEADERS += \
    clock_test.h \
    vector2d_test.h
