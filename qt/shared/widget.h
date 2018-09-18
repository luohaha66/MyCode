#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QSharedMemory>
#include <QDir>
#include <QImage>
#include <QBuffer>
#include <QPixmap>
#include <QDataStream>


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

    void on_load_clicked();

    void on_show_clicked();

private:
    Ui::Widget     *ui;
    QString        filename;
    QSharedMemory* memory;
};

#endif // WIDGET_H
