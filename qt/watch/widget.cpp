#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Time");
    this->setWindowIcon(QIcon(":/pic/im-time.png")); //设置界面图标
    this->setWindowOpacity(0.9); //设置窗体整体半透明
    this->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");//设置控件为圆角
    this->setAutoFillBackground(true);

    lcd = new QLCDNumber(this);
    t = new QTimer(this);

    QString style = "QLCDNumber{background-color:#54547d;color:#00ffff;border:0;}";
    QFont idft("Comic Sans MS", 22, 87);
    lcd ->setDigitCount(19);
    lcd->setMode(QLCDNumber::Dec);
    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->setFont(idft);
    lcd->setStyleSheet(style);
    lcd->setFixedSize(200, 40);

    t->setInterval(1000);
    connect(t, SIGNAL(timeout()), this, SLOT(showtime()));
    t->start();

}

Widget::~Widget()
{

}

void Widget::showtime()
{
    // 获取系统当前时间
    QDateTime dateTime = QDateTime::currentDateTime();
    // 显示的内容
    lcd->display(dateTime.toString("yyyy-MM-dd HH:mm:ss"));
}
