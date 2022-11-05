QT += core xml sql network gui xmlpatterns widgets websockets concurrent

TARGET = LoginServer

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEFINES += QT_DEPRECATED_WARNINGS

win32 {
    QMAKE_LFLAGS_WINDOWS += "advapi32.lib"

    # debug build (using msvcrtd.lib)
    CONFIG(debug, debug|release): QMAKE_LFLAGS_WINDOWS += /NODEFAULTLIB:msvcrt.lib /NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:libcmtd.lib

    # release build (using msvcrt.lib)
    CONFIG(release, debug|release): QMAKE_LFLAGS_WINDOWS += /NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcrtd.lib
}

CONFIG += qt thread c++17 precompile_header warn_off

PRECOMPILED_HEADER  = pch/pch.h

include(app/app.pri)
include(ui/ui.pri)

SOURCES += \
    main.cpp \

HEADERS += \
    pch/pch.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
