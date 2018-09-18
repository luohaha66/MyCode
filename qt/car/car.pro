#-------------------------------------------------
#
# Project created by QtCreator 2018-02-05T14:32:37
#
#-------------------------------------------------

QT       += core gui network  webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = car
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    car.cpp

HEADERS  += widget.h \
    car.h

FORMS    += widget.ui \
    car.ui

RESOURCES += \
    res.qrc
