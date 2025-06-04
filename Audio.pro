#-------------------------------------------------
#
# Project created by QtCreator 2025-05-16T08:48:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Audio
TEMPLATE = app

HEADERS  += Window.hpp \
    SoundPlayer.hpp \
    Utils.hpp \
    Visualize.hpp

INCLUDEPATH += "include"

SOURCES += main.cpp\
        Window.cpp \
    SoundPlayer.cpp \
    Utils.cpp \
    Visualize.cpp

LIBS += -L"lib" -lSDL3 -lSDL3_mixer

FORMS    += Window.ui

RESOURCES += \
    Ressources.qrc

RC_ICONS = icons/icon.ico
