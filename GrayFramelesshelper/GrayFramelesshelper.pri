qtHaveModule(widgets): SUBDIRS += widget mainwindow
qtHaveModule(quick): SUBDIRS += quick
CONFIG -= ordered

QT += core gui
QT += core-private gui-private

CONFIG += c++17 strict_c++ utf8_source warn_on

HEADERS += \
    $$PWD/framelesshelper_global.h \
    $$PWD/framelesshelper.h \
    $$PWD/framelesswindowsmanager.h \
    $$PWD/utilities.h
SOURCES += \
    $$PWD/framelesshelper.cpp \
    $$PWD/framelesswindowsmanager.cpp \
    $$PWD/utilities.cpp
qtHaveModule(quick) {
    QT += quick
    HEADERS += $$PWD/framelessquickhelper.h
    SOURCES += $$PWD/framelessquickhelper.cpp
}
win32 {
    HEADERS += \
        $$PWD/framelesshelper_windows.h \
        $$PWD/framelesshelper_win32.h \
        $$PWD/qwinregistry_p.h
    SOURCES += \
        $$PWD/utilities_win32.cpp \
        $$PWD/framelesshelper_win32.cpp \
        $$PWD/qwinregistry.cpp
    LIBS += -luser32 -lshell32 -ladvapi32
}
linux* {
    QT += x11extras
    SOURCES += $$PWD/utilities_linux.cpp
}

macx {
    OBJECTIVE_HEADERS += \
        $$PWD/nswindow_proxy.h \
        $$PWD/scoped_nsobject.h \
        $$PWD/window_buttons_proxy.h
    OBJECTIVE_SOURCES += \
        $$PWD/utilities_macos.mm \
        $$PWD/nswindow_proxy.mm \
        $$PWD/window_buttons_proxy.mm
    LIBS += -framework CoreServices
    LIBS += -framework Foundation
    LIBS += -framework CoreFoundation
    LIBS += -framework Carbon
    LIBS += -lobjc
    LIBS += -framework AppKit
    DEFINES += OBJC_OLD_DISPATCH_PROTOTYPES
}

INCLUDEPATH += $$PWD
