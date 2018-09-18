#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
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

    ip      = new QLabel(this);
    port    = new QLabel(this);
    edt_ip  = new QLineEdit(this);
    edt_po  = new QLineEdit(this);
    log     = new QPushButton(this);
    quit    = new QPushButton(this);
    pic     = new QLabel(this);

    QString buttonstyle =
                      "QPushButton{color:#55ffff;border:0;}"
                      "QPushButton:!hover:!pressed{border-image:url(:/image/2.png)}"
                      "QPushButton:hover{border-image:url(:/image/1.png)}"
                      "QPushButton:pressed{border-image:url(:/image/2.png)}";
    QFont styleft("Century Schoolbook L", 16, 87);
    log->setStyleSheet(buttonstyle);
    log->setFont(styleft);
    log->setText("Login");
    log->setShortcut(QKeySequence(QLatin1String("Return")));
    log->setFixedSize(200,45); //调整大小

    quit->setStyleSheet(buttonstyle);
    quit->setFont(styleft); //设置字体
    quit->setText("Quit ");
    quit->setShortcut(QKeySequence(QLatin1String("Esc")));
    quit->setFixedSize(200,45); //调整大小

    QString labelstyle =
                      "QLabel{color:#ff5500;background-color:#424263;border:0;}";
    ip->setStyleSheet(labelstyle);
    QFont labelft("Century Schoolbook L", 16, 87);
    ip->setFont(labelft); //设置字体
    ip->setText("IP    ");

    port->setStyleSheet(labelstyle);
    port->setFont(labelft); //设置字体
    port->setText("Port");

    QString editstyle =
                      "QLineEdit{color:#ff557f;background-color:#390056;border:0;}";
    QFont editft("Century Schoolbook L", 16, 87);
    edt_ip->setStyleSheet(editstyle);
    edt_ip->setFont(editft); //设置字体
    edt_ip->setText("192.168.");

    edt_po->setStyleSheet(editstyle);
    edt_po->setFont(editft); //设置字体
    edt_po->setText("8888");

    pic->setScaledContents(true);
    pic->setStyleSheet("border:0;");//去除边框
    pic->setFixedSize(200,100);
    pic->setPixmap(QPixmap(":/image/4.png"));

    QHBoxLayout* hbox = new QHBoxLayout;
    hbox->addStretch();
    hbox->addWidget(ip);
    hbox->addWidget(edt_ip);

    QHBoxLayout* hbox1 = new QHBoxLayout;
    hbox1->addStretch();
    hbox1->addWidget(port);
    hbox1->addWidget(edt_po);

    QVBoxLayout* vbox1 = new QVBoxLayout;
    vbox1->addLayout(hbox);
    vbox1->addLayout(hbox1);

    QHBoxLayout* hbox3 = new QHBoxLayout;
    hbox3->addWidget(pic);
    hbox3->addLayout(vbox1);

    QHBoxLayout* hbox2 = new QHBoxLayout;
    hbox2->addWidget(log);
    hbox2->addStretch();
    hbox2->addWidget(quit);

    QVBoxLayout* vbox = new QVBoxLayout;
    vbox->addLayout(hbox3);
    vbox->addLayout(hbox2);

    setLayout(vbox);
    layout()->setMargin(0);

    connect(quit,SIGNAL(clicked()),this,SLOT(closeapp()));
    connect(log,SIGNAL(clicked()),this,SLOT(show_window2()));
}

void Widget::show_window2()
{
    nip     = edt_ip->text();
    nport   = edt_po->text().toInt();
    this->close();
    show_pic *s = new show_pic(nip, nport);
    s->show(); //界面跳转

}

void Widget::closeapp()
{
    this->close();
}

Widget::~Widget()
{

}

