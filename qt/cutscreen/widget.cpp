#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    menu = new QMenu(this);
    ac1  = new QAction(this);
    ac2  = new QAction(this);
    ac3  = new QAction(this);
    ac1->setText("save");
    ac2->setText("copy");
    ac3->setText("delete");
    ac1->setIcon(QIcon(":/imag/img/save.png"));
    ac2->setIcon(QIcon(":/imag/img/copy.png"));
    ac3->setIcon(QIcon(":/imag/img/delete.png"));
    menu->addAction(ac1);
    menu->addAction(ac2);
    menu->addAction(ac3);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    this->hide();
    time = new QTimer;
    connect(time, SIGNAL(timeout()), this, SLOT(new_screencut()));
    time->start(500);
}

void Widget::new_screencut()
{
    pixcut = QPixmap::grabWindow(QApplication::desktop()->winId());
    ui->label->setPixmap(pixcut.scaled(ui->label->size()));
    time->stop();
    this->show();
}

void Widget::save_pic()
{
    filename = QFileDialog::getSaveFileName(this, "Save File",
               QStandardPaths::writableLocation(QStandardPaths::PicturesLocation), tr("*.*"));
    pixcut.save(filename);
}

void Widget::copy_pic()
{
    QClipboard* clip = QApplication::clipboard();
    clip->setPixmap(pixcut);
}

void Widget::del_pic()
{
    ui->label->clear();
}

void Widget::on_pushButton_2_clicked()
{
    filename = QFileDialog::getSaveFileName(this, "Save File",
               QStandardPaths::writableLocation(QStandardPaths::PicturesLocation), tr("*.*"));
    pixcut.save(filename);
}

void Widget::contextMenuEvent(QContextMenuEvent* event)
{
   connect(ac1, SIGNAL(triggered()), this, SLOT(save_pic()));
   connect(ac2, SIGNAL(triggered()), this, SLOT(copy_pic()));
   connect(ac3, SIGNAL(triggered()), this, SLOT(del_pic()));
   menu->exec(QCursor::pos());
}
