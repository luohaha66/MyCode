#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("FileWatch");
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(show_info()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_openbutton_clicked()
{
    QString filename = QFileDialog::getExistingDirectory(this, tr("Open Dir"), QDir::currentPath());
    if (filename.size() == 0)
    {
        QMessageBox::warning(this ,"Error", "Open Error");
        return;
    }
        QDir d(filename);
        d.setFilter(QDir::Files | QDir::AllDirs);
        //列出文件,列出隐藏文件（在Unix下就是以.开始的为文件）,不列出符号链接（不支持符号连接的操作系统会忽略）
        d.setSorting(QDir::Size | QDir::Reversed);//按文件大小排序，相反的排序顺序
        const QFileInfoList list = d.entryInfoList();//返回这个目录中所有目录和文件的QFileInfo对象的列表
        QFileInfoList::const_iterator iterator = list.begin();
        while(iterator != list.end()){
            if((*iterator).fileName() == "." || (*iterator).fileName() == "..")
            {
                iterator++;
                continue;
            }
            QListWidgetItem* item = new QListWidgetItem;
            QFileInfo info((*iterator));
            fipath = info.path();
            if(info.isDir())
            {
                item->setIcon(QIcon(":/imag/img/文件夹.png"));
            }
            else
            {
                item->setIcon(QIcon(":/imag/img/文件.png"));
            }
            item->setText((*iterator).fileName());
            ui->listWidget->addItem(item);
            iterator++;
        }
}

void Widget::on_deletebutton_clicked()
{
    int count = 0;
    while (1)
    {
        QListWidgetItem* item = ui->listWidget->takeItem(count);
        if (item != NULL)
        {
            delete  item;
        }
        else
            break;

    }
}

void Widget::show_info()
{
    filepath = fipath + "/" + ui->listWidget->currentItem()->text();
    info* fiinfo = new info(filepath);
    fiinfo->show();
}
