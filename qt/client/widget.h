#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>
#include <QApplication>
#include <QtNetwork/QTcpSocket>
#include <QMessageBox>


#include "show_pic.h"

class Widget : public QWidget
{
    Q_OBJECT

private slots:
    void show_window2();
    void closeapp();

private:
    QApplication* app;
    QLabel*       ip;
    QLabel*       port;
    QLineEdit*    edt_ip;
    QLineEdit*    edt_po;
    QPushButton*  log;
    QPushButton*  quit;
    QLabel*       pic;
    QString       nip;
    int           nport;

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
