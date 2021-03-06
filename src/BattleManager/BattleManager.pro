#-------------------------------------------------
#
# Project created by QtCreator 2011-08-29T23:44:58
#
#-------------------------------------------------

QT += declarative
TARGET = battlelib
TEMPLATE = lib
DESTDIR = ../../bin
LIBS += -L../../bin \
    -lutilities \
    -lpokemonlib

DEFINES += BATTLEMANAGER_LIBRARY

SOURCES += \
    battledata.cpp \
    main.cpp \
    testing.cpp \
    teamdata.cpp \
    battleinput.cpp \
    battleclientlog.cpp \
    auxpokebattledata.cpp \
    battlescene.cpp \
    battledataaccessor.cpp

HEADERS +=\
    command.h \
    commandmanager.h \
    commandextracter.h \
    commandflow.h \
    commandinvoke.h \
    battleenum.h \
    battlecommandmanager.h \
    battleextracter.h \
    battlecommandinvoker.h \
    test.h \
    battledata.h \
    teamdata.h \
    battleinput.h \
    battleclientlog.h \
    auxpokebattledata.h \
    defaulttheme.h \
    battlescene.h \
    battledataaccessor.h

QMAKE_CXXFLAGS += "-std=c++0x"

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEEF4D708
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = BattleManager.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

OTHER_FILES += \
    battlescene.qml

RESOURCES += \
    battlemanager.qrc








