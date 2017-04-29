#-------------------------------------------------
#
# Project created by QtCreator 2017-01-04T12:59:34
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = mindwave
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Loop.cpp

QT += serialport

HEADERS += \
    Loop.h
