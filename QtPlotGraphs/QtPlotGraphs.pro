#-------------------------------------------------
#
# Project created by QtCreator 2026-03-17T20:25:37
#
#-------------------------------------------------

QT += core gui widgets printsupport
#CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtPlotGraphs
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    DataManager.cpp \
    PlotManager.cpp \
    ../QCustomPlot/qcustomplot/qcustomplot.cpp \
    ExportManager.cpp \
    Logger.cpp

HEADERS  += mainwindow.h \
    DataManager.h \
    Global.h \
    PlotManager.h \
    ../QCustomPlot/qcustomplot/qcustomplot.h \
    ExportManager.h \
    Logger.h \
    channels.h \
    ringbuffer.h

FORMS    += mainwindow.ui

DISTFILES += \
    QtPlotGraphs.pro.user
