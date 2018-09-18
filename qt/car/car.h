#ifndef CAR_H
#define CAR_H

#include <QDialog>
#include <QTcpSocket>
#include <QByteArray>
#include <stdio.h>

#include "widget.h"

namespace Ui {
class car;
}

class car : public QDialog
{
    Q_OBJECT

public:
    explicit car(QString n_ip, unsigned int n_port, QWidget *parent = 0);
    ~car();

public slots:
    void control_car();
    void new_connect();
    void messge_error();
    void discon_from_host();
    void on_button_clicked();
    void on_spinbox_changed();
    void on_radio_clicked();

private slots:
    void on_camera_clicked();

private:
    Ui::car *ui;
    QString ip;
    unsigned int port;
    unsigned int dis;
    unsigned int view;
    unsigned int power;
    unsigned int hum;
    unsigned int tem;
    unsigned int radiate;
    bool flag;
    QString sdis;
    QString sview;
    QString spower;
    QString shum;
    QString stem;
    QString sradiate;
    unsigned char buff[5];
    unsigned char buffer[5] = {0xFF, 0x00, 0x00, 0x00, 0xFF};
    QTcpSocket* socket;
};

#endif // CAR_H
