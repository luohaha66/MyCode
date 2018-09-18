#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLCDNumber>
#include <QString>
#include <QDateTime>
#include <QTimer>
#include <QIcon>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void showtime();

private:
    QLCDNumber* lcd;
    QTimer* t;
};

#endif // WIDGET_H
