#-------------------------------------------------
#
# Project created by QtCreator 2018-01-27T17:26:26
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = led_client
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    led_con.cpp

HEADERS  += widget.h \
    led_con.h

FORMS    += widget.ui \
    led_con.ui

RESOURCES += \
    res.qrc
