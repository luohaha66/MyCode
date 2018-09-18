#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    this->setFixedSize(400, 155);
    ui->setupUi(this);
    connect(ui->cmd, SIGNAL(returnPressed()), this, SLOT(on_p1_clicked()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_p1_clicked()
{
    QProcess* process = new QProcess;
    QString   startp   = ui->cmd->text();
    process->start(startp.trimmed());//最后为去空格
}

void Widget::on_p2_clicked()
{
    this->close();
}
