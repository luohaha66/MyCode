#include "led_con.h"
#include "ui_led_con.h"

led_con::led_con(QString ip1, int port1, QWidget *parent) :
    ip(ip1), port(port1), QDialog(parent),
    ui(new Ui::led_con)
{
    ui->setupUi(this);
    this->setWindowTitle("Led Client"); //设置界面标题
    this->setWindowIcon(QIcon(":/image/LED.png")); //设置界面图标
    QString ledstyle =
            "QRadioButton{spacing: 10px;border:0;background-color:#ffffff;color:#aa00ff;}"
            "QRadioButton::indicator {width: 65px;height: 35px;}"
            "QRadioButton::indicator:unchecked {image: url(:/image/off1.png);}"
            "QRadioButton::indicator:unchecked:hover {image: url(:/image/c2.png);}"
            "QRadioButton::indicator:unchecked:pressed {image: url(:/image/off1.png);}"
            "QRadioButton::indicator:checked {image: url(:/image/on1.png);}"
            "QRadioButton::indicator:checked:hover {image: url(:/image/c6.png);}"
            "QRadioButton::indicator:checked:pressed {image: url(:/image/on1.png);}";
    ui->status->hide();
    ui->ld1->setStyleSheet(ledstyle);
    ui->ld2->setStyleSheet(ledstyle);
    ui->ld3->setStyleSheet(ledstyle);
    ui->ld4->setStyleSheet(ledstyle);
    ui->ldr->setStyleSheet(ledstyle);
    ui->pwm->setStyleSheet(ledstyle);


    socket = new QTcpSocket();
    socket->connectToHost(ip, port);

    connect(socket, SIGNAL(connected()), this, SLOT(new_connect()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(messge_error()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(discon_from_host()));

}

led_con::~led_con()
{
    delete ui;
}

void led_con::new_connect()
{
    ui->status->show();
    ui->status->setText("                          Connect Successful");
    flag = true;
}

void led_con::discon_from_host()
{
    ui->status->show();
    ui->status->setText("                           Connect is Interrupt");
    flag = false;
}

void led_con::messge_error()
{
    ui->status->show();
    ui->status->setText("                               " + socket->errorString());
    flag = false;
}

void led_con::on_ld_clicked()
{
    if(!flag)
        return;
    unsigned char id = '5';
    QRadioButton* radio = static_cast<QRadioButton*>(sender());
    std::string str= radio->objectName().toStdString();
    const char* name = str.c_str();
    if (qstrcmp(name, "ld1") == 0)
        id = '0';
    if (qstrcmp(name, "ld2") == 0)
        id = '1';
    if (qstrcmp(name, "ld3") == 0)
        id = '2';
    if (qstrcmp(name, "ld4") == 0)
        id = '3';
    if (qstrcmp(name, "ldr") == 0)
        id = '4';
    if (qstrcmp(name, "pwm") == 0)
        id = '5';
    memset(cmd, 0, 10);
    if(radio->isChecked())
    {
        strcpy(cmd, "on");
        socket->putChar(id);
        socket->write((const char*)cmd, 10);
    }
    else
    {
        strcpy(cmd, "off");
        socket->putChar(id);
        socket->write((const char*)cmd, 10);
    }
}
