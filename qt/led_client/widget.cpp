#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Led Client"); //设置界面标题
    this->setWindowIcon(QIcon(":/image/LED.png")); //设置界面图标
    this->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");//设置控件为圆角
    QString buttonstyle =
                      "QPushButton{color:#55ffff;border:0;}"
                      "QPushButton:!hover:!pressed{border-image:url(:/image/2.png)}"
                      "QPushButton:hover{border-image:url(:/image/1.png)}"
                      "QPushButton:pressed{border-image:url(:/image/2.png)}";
    ui->log->setStyleSheet(buttonstyle);
    ui->out->setStyleSheet(buttonstyle);
    ui->ip->setText("192.168.");
    ui->port->setText("8888");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_log_clicked()
{
    cli_ip = ui->ip->text();
    cli_port = ui->port->text().toInt();
    led_con* led = new led_con(cli_ip, cli_port);
    led->show();
    this->close();
}

void Widget::on_out_clicked()
{
    this->close();
}
