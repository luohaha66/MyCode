#ifndef LED_CON_H
#define LED_CON_H

#include <QDialog>
#include <QTcpSocket>
#include <QByteArray>
#include <QString>
#include <QDebug>

#include "widget.h"

namespace Ui {
class led_con;
}

class led_con : public QDialog
{
    Q_OBJECT

public:
    explicit led_con(QString ip1, int port1, QWidget *parent = 0);
    ~led_con();

public slots:
    void new_connect();
    void discon_from_host();
    void messge_error();

private slots:
    void on_ld_clicked();

private:
    Ui::led_con *ui;
    QString ip;
    int port;
    QTcpSocket* socket;
    char cmd[10];
    bool flag;
};

#endif // LED_CON_H
