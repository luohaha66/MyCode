#-------------------------------------------------
#
# Project created by QtCreator 2018-02-06T15:37:51
#
#-------------------------------------------------

QT       += core gui network webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = farm_client
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    show_pic.cpp \
    control.cpp

HEADERS  += widget.h \
    show_pic.h \
    control.h

RESOURCES += \
    res.qrc

FORMS += \
    show_pic.ui \
    control.ui
