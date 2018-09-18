#include "widget.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(1280,800);
    go      = new QPushButton(this);
    now     = new QPushButton(this);
    back    = new QPushButton(this);
    showpic = new QLabel(this);

    showpic->setFixedSize(1280,720); //设置图标
    showpic->setScaledContents(true);

    go->setIcon(QIcon("rig.png"));
    go->setIconSize(QSize(30,30));

    now->setIcon(QIcon("open.png"));
    now->setIconSize(QSize(30,30));

    back->setIcon(QIcon("lef.png"));
    back->setIconSize(QSize(30,30));



    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->addStretch();
    hbox->addWidget(back);
    hbox->addWidget(now);
    hbox->addWidget(go);
    hbox->addStretch();

    QVBoxLayout* vbox = new QVBoxLayout();
    vbox->addWidget(showpic);
    vbox->addLayout(hbox);

    setLayout(vbox);

    connect(back, SIGNAL(clicked()), this, SLOT(left_show()));
    connect(now,  SIGNAL(clicked()), this, SLOT(open_pic()));
    connect(go,   SIGNAL(clicked()), this, SLOT(right_show()));
}

void Widget::left_show()
{
    if(len > 0)
    {
        if(i == 0)
        {
            showpic->setPixmap(QPixmap(filename[len - 1]));
            i = len - 1;
        }
        else
        showpic->setPixmap(QPixmap(filename[--i]));
     }
}

void Widget::open_pic()
{
    filename = QFileDialog::getOpenFileNames(this, tr("Open Image"),
                       "./", tr("Image files(*.png *.jpg *.bmp)"));
    len = filename.length();
    if (len > 0)
    {
        showpic->setPixmap(QPixmap(filename[0]));
    }
    else
        return;
}

void Widget::right_show()
{
    if(len > 0)
    {
        if (i == len - 1)
        {
            showpic->setPixmap(QPixmap(filename[i]));
            i = 0;
        }
        else
            showpic->setPixmap(QPixmap(filename[++i]));
    }
}

Widget::~Widget()
{

}
