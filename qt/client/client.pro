#-------------------------------------------------
#
# Project created by QtCreator 2017-10-24T15:16:12
#
#-------------------------------------------------

QT       += core gui network webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    show_pic.cpp \
    control.cpp

HEADERS  += widget.h \
    show_pic.h \
    control.h

RESOURCES += \
    resource.qrc

DISTFILES +=
