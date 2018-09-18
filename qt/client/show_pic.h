#ifndef SHOW_PIC_H
#define SHOW_PIC_H

#include <QWidget>
#include <QTcpSocket>
#include <QPushButton>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QRadioButton>
#include <QImageReader>
#include <QDataStream>
#include <QButtonGroup>
#include <QSpinBox>
#include <QBuffer>
#include <QtWebKitWidgets/QWebView>
#include <QDir>
#include <QTimer>
#include <QApplication>

#include "widget.h"
#include "control.h"

class show_pic : public QWidget
{
    Q_OBJECT
public:
    explicit show_pic(QString ip1, int port1, QWidget *parent = NULL);

public slots:
    void new_connect();
    void returnapp();
    void messge_error();
    void discon_from_host();
    void hide_ledcon();
    void playcontrol();
    void replaycontrol();

public:
    QSpinBox*     temp_z;
    QSpinBox*     light_z;
    QRadioButton* play;
    QRadioButton* led;
    QRadioButton* led1;
    QRadioButton* led_7;
    QRadioButton* beep;
    QRadioButton* fan;
    QRadioButton* z_light;
    QRadioButton* z_temp;
    QButtonGroup* mgroup;
    QPushButton*  re_pl;
    QPushButton*  re_tur;
    QPushButton*  set_temp;
    QPushButton*  set_light;
    QWebView*     view;
    QLabel*       c_temp;
    QLabel*       c_light;
    QLabel*       pic1;
    QLabel*       pic2;
    QLabel*       light;
    QLabel*       temp;
    QLabel*       adc;
    QLabel*       acc;
    QLabel*       d_id;
    QLabel*       status;
    QTcpSocket*   socket;
    QString       nip;
    int           nport;
};

#endif // SHOW_PIC_H
