#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPalette>
#include <QPixmap>
#include <QFont>

#include "car.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void show_car_control();

private slots:
    void on_out_clicked();

private:
    Ui::Widget *ui;
    QString net_ip;
    unsigned int net_port;
};

#endif // WIDGET_H
