#-------------------------------------------------
#
# Project created by QtCreator 2015-05-15T20:11:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    AI.cpp \
    Player.cpp \
    Field.cpp \
    GameLogic.cpp

HEADERS  += mainwindow.h \
    AI.h \
    Player.h \
    Types.h \
    Field.h \
    GameLogic.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
