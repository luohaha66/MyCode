#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QDir>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QFileInfo>
#include <QUrl>
#include <QDebug>

#include "info.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void show_info();

    void on_openbutton_clicked();

    void on_deletebutton_clicked();

private:
    Ui::Widget *ui;
    QString     fipath;
    QString     filepath;
};

#endif // WIDGET_H
