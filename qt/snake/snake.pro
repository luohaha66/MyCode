#-------------------------------------------------
#
# Project created by QtCreator 2018-01-04T14:25:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = snake
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    snake.cpp

HEADERS  += widget.h \
    snake.h

FORMS    += widget.ui \
    snake.ui

RESOURCES += \
    res.qrc

RC_FILE = myapp.rc
