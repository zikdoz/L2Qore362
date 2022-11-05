QT -= gui
QT += core xml sql network xmlpatterns websockets concurrent

TARGET = common
TEMPLATE = lib

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += COMMON_LIBRARY qt thread c++17 precompile_header warn_off

PRECOMPILED_HEADER  = pch/pch.h

include(database/database.pri)
include(enum/enum.pri)
include(interface/interface.pri)
include(type/type.pri)
include(util/util.pri)

HEADERS += \
    pch/pch.h       \
    Common_global.h \

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
