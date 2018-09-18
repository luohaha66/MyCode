#include "widget.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QTextEdit>
#include <QMessageBox>
#include <QTextStream>
#include <QStringList>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(1280,800);
        open      = new QPushButton(this);
        close     = new QPushButton(this);
        save      = new QPushButton(this);
        resave    = new QPushButton(this);
        edit      = new QTextEdit(this);

        edit->setFixedSize(1280,720); //设置图标

        open->setIcon(QIcon("open.png"));
        open->setIconSize(QSize(30,30));

        save->setIcon(QIcon("save.png"));
        save->setIconSize(QSize(30,30));

        resave->setIcon(QIcon("resave.png"));
        resave->setIconSize(QSize(30,30));

        close->setIcon(QIcon("close.png"));
        close->setIconSize(QSize(30,30));



        QHBoxLayout* hbox = new QHBoxLayout();
        hbox->addWidget(open);
        hbox->addWidget(save);
        hbox->addWidget(resave);
        hbox->addWidget(close);
        hbox->addStretch();

        QVBoxLayout* vbox = new QVBoxLayout();
        vbox->addLayout(hbox);
        vbox->addWidget(edit);

        setLayout(vbox);

        connect(open,   SIGNAL(clicked()), this, SLOT(edit_open()));
        connect(save,   SIGNAL(clicked()), this, SLOT(edit_save()));
        connect(close,  SIGNAL(clicked()), this, SLOT(edit_close()));
        connect(resave, SIGNAL(clicked()), this, SLOT(edit_resave()));
}

void Widget::edit_open()
{
    filename = QFileDialog::getOpenFileName(this, tr("Open Image"),
                           "./", tr("ALL files(*.*)"));

    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite))
           return;
    QTextStream out(&file);
    out.setCodec("UTF-8");
    while(!file.atEnd())
    {
     edit->setText(out.readAll());
    }
    file.close();
}

void Widget::edit_close()
{
    edit->setText(NULL);
}


void Widget::edit_save()
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
          return;
    QString text = edit->toPlainText();
    QTextStream out(&file);
    out.setCodec("UTF-8");
    out << text;
    file.close();
}

void Widget::edit_resave()
{
        QString filena = QFileDialog::getSaveFileName(this,
                                         tr("Resave File"), "./", tr("Text files (*.*)"));
        QString data = edit->toPlainText();
        QFile file(filena);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);
        out.setCodec("UTF-8");
        out << data;
        file.close();
}

Widget::~Widget()
{

}
