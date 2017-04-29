#-------------------------------------------------
#
# Project created by QtCreator 2016-06-20T21:38:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = BControl
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    IMUfilter.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
        macrodefs.h \
        IMUfilter.h \
    qcustomplot.h

FORMS    += mainwindow.ui

QT += serialport
