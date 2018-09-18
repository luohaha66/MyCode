#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QColor>
#include <QFont>
#include <QRectF>
#include <qmath.h>
#include <QVector>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QPoint wind;
    QPoint mous;
    QPoint posit;
    QTimer* my_timer;
    static const QVector<QString> my_num;
    static const QPoint hourHand[3];
    static const QPoint minuteHand[3];
    static const QPoint secondHand[3];
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
};

#endif // WIDGET_H
