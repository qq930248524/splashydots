QT += core
QT -= gui

CONFIG += c++11

TARGET = splashydots
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    splashy.cpp \
    dot.cpp

HEADERS += \
    splashy.h \
    dot.h
