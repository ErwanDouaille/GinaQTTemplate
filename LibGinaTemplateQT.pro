TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/release/ -lGina
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/debug/ -lGina
else:unix: LIBS += -L$$PWD/lib/ -lGina

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/release/libGina.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/debug/libGina.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/release/Gina.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/debug/Gina.lib
else:unix: PRE_TARGETDEPS += $$PWD/lib/libGina.a

HEADERS += \
    Leap.h \
    LeapMath.h \
    LgData.h \
    LgDataTemplate.h \
    LgEnvironment.h \
    LgFunctions.h \
    LgGenerator.h \
    LgGroupTemplate.h \
    LgHistoricTemplate.h \
    LgMetaData.h \
    LgNode.h \
    LgNodeFactory.h \
    LgObserver.h \
    LgPoint2D.h \
    LgPoint3D.h \
    LgProcessor.h \
    LgSwitch.h \
    LgTimer.h
