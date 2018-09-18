#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("User Client"); //设置界面标题
    this->setWindowIcon(QIcon(":/image/client.png")); //设置界面图标
    this->setWindowOpacity(0.9); //设置窗体整体半透明
    this->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");//设置控件为圆角

    this->setFixedSize(480,280);
    this->setAutoFillBackground(true);
    QPalette uipa;
    QPixmap pix(":/image/5.png");
    uipa.setBrush(QPalette::Window, QBrush(pix));
    this->setPalette(uipa); //设置窗体背景图片

    QString buttonstyle =
                      "QPushButton{color:#55ffff;border:0;}"
                      "QPushButton:!hover:!pressed{border-image:url(:/image/2.png)}"
                      "QPushButton:hover{border-image:url(:/image/1.png)}"
                      "QPushButton:pressed{border-image:url(:/image/2.png)}";
    QFont buttonfont("Century Schoolbook L", 16, 75);
    ui->in->setStyleSheet(buttonstyle);
    ui->out->setStyleSheet(buttonstyle);
    ui->in->setFont(buttonfont);
    ui->out->setFont(buttonfont);
    ui->in->setFixedSize(200,45);
    ui->out->setFixedSize(200,45);
    ui->ip->setText("192.168.");
    ui->port->setText("8888");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::show_car_control()
{
    net_ip = ui->ip->text();
    net_port = ui->port->text().toInt();
    car* my_car = new car(net_ip, net_port);
    my_car->show();
    this->close();
}

void Widget::on_out_clicked()
{
    this->close();
}
