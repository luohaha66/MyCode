#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    memory = new QSharedMemory();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_load_clicked()
{
    if (memory->isAttached())
        memory->detach();

    filename = QFileDialog::getOpenFileName(this,
                                    tr("Open Image"), QDir::currentPath(), tr("Images(*.jpg *.png)"));
    QImage image;
    if (!(image.load(filename)))
    {
        ui->lineEdit->setText(tr("You have to chose a image"));
        return;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
    QBuffer buf;
    buf.open(QBuffer::ReadWrite);
    QDataStream out(&buf);
    out << image;
    int size = buf.size();
    memory->setKey("luohaha");
    if (!(memory->create(size)))
    {
        ui->lineEdit->setText(memory->errorString());
        return;
    }
    memory->lock();
    char* to   = (char*)memory->data();
    const char* from = buf.data().data();
    memcpy(to, from, qMin(memory->size(), size));
    memory->unlock();
    ui->lineEdit->setText(tr("Load Image into Shared Memory Success"));
}

void Widget::on_show_clicked()
{
    ui->label->clear();
    if (memory->isAttached())
        memory->detach();

    if (!(memory->attach()))
    {
         ui->lineEdit->setText("Can't attach to Shared Memory");
         return;
    }
    QBuffer buff;
    QDataStream in(&buff);
    QImage  img;
    memory->lock();
    buff.setData((char*)memory->data(), memory->size());
    buff.open(QBuffer::ReadOnly);
    in >> img;
    memory->unlock();

    ui->lineEdit->setText(tr("Load Image into Shared Memory Success"));
    memory->detach();
    ui->label->setPixmap(QPixmap::fromImage(img));
}
