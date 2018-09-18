#ifndef SNAKE_H
#define SNAKE_H

#include <QDialog>
#include <QKeyEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QColor>
#include <QTime>
#include <QTimer>
#include <QVector>
#include <QRect>
#include <QMessageBox>
#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QIcon>

#include "widget.h"

namespace Ui {
class snake;
}

class snake : public QDialog
{
    Q_OBJECT

public:
    explicit snake(QWidget *parent = 0);
    ~snake();
    void paintEvent(QPaintEvent* event);
    void keyPressEvent(QKeyEvent* event);
    void initcolor();
    void snakeheadrun();
    void createhead();
    void createfood();
    void checkfood();
    bool game();
    void gameover();

public slots:
     void snakerun();

private:
    Ui::snake *ui;
    QPixmap pic;
    int body[100][2];
    QVector<QColor> my_color;
    QTimer* timer;
    int food[2];
    int bodycount;
    int direction;
};

#endif // SNAKE_H
