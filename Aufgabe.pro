TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += widgets
QT +=core

SOURCES += main.cpp \
    meinwidget.cpp \
    zeichenfeld.cpp \
    avatar.cpp \
    objekt.cpp \
    punkte.cpp \
    objekt2.cpp

HEADERS += \
    meinwidget.h \
    zeichenfeld.h \
    avatar.h \
    objekt.h \
    punkte.h \
    objekt2.h
