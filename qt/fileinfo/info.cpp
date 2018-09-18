#include "info.h"
#include "ui_info.h"

info::info(QString myfile, QWidget *parent) :
    nfilepath(myfile), QDialog(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);
    this->setWindowTitle("FileInfo");
    if (nfilepath.isEmpty())
       {
           QMessageBox::warning(this, "Error", "OPen Error");
           return;
       }
       QFileInfo info(nfilepath);
       ui->lineEdit->setText(QString::number(info.size()));

       QDateTime create = info.created();
       ui->lineEdit_2->setText(create.toString("yyyy-MM-dd hh:mm:ss"));

       QDateTime last = info.lastModified();
       ui->lineEdit_3->setText(last.toString("yyyy-MM-dd hh:mm:ss"));
}

info::~info()
{
    delete ui;
}
