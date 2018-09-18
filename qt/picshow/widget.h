#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void left_show();
    void right_show();
    void open_pic();

private:
    QPushButton* go;
    QPushButton* back;
    QPushButton* now;
    QLabel*      showpic;
    QStringList  filename;
    unsigned int len = 0;
    unsigned int i   = 0;
};

#endif // WIDGET_H
