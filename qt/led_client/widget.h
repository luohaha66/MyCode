#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QIcon>
#include <QMessageBox>
#include <QString>

#include "led_con.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_log_clicked();

    void on_out_clicked();

private:
    Ui::Widget *ui;
    QString cli_ip;
    int cli_port;
};

#endif // WIDGET_H
