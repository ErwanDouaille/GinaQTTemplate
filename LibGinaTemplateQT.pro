TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    mygenerator.cpp \
    myprocessor.cpp \
    myobserver.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lGinaWin32
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lGinaWin32
else:unix: LIBS += -L$$PWD/lib/ -lGinaUnix

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

# TODO DEBUG VERSION
win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/libGinaWin32.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/libGinaWin32.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/libGina.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/libGina.lib
else:unix: PRE_TARGETDEPS += $$PWD/lib/libGinaUnix.a

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
    LgTimer.h \
    mygenerator.h \
    myprocessor.h \
    myobserver.h
