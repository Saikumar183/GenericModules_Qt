#-------------------------------------------------
#
# Project created by QtCreator 2025-12-05T19:54:44
#
#-------------------------------------------------

QT       += core gui serialport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UDPSerialApp
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
    globalclass.cpp \
    serialportwidget.cpp \
    modbusscreen.cpp \
    endianregistergridwidget.cpp \
    appversiondialog.cpp \
    setup_ip.cpp \
    udpcommunication.cpp

HEADERS  += mainwindow.h \
    globalclass.h \
    serialportwidget.h \
    qtheaderfiles.h \
    modbusscreen.h \
    endianregistergridwidget.h \
    appversiondialog.h \
    appinfo.h \
    setup_ip.h \
    udpcommunication.h

FORMS    += mainwindow.ui \
    modbusscreen.ui \
    setup_ip.ui

RESOURCES += \
    mediafiles.qrc
