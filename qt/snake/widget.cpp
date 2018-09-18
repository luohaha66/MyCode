#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Hungry Snake");
    this->setWindowIcon(QIcon(":/pic/ff.png"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    snake* ss = new snake;
    this->close();
    ss->show();
}

void Widget::on_pushButton_2_clicked()
{
    this->close();
}
