#include "snake.h"
#include "ui_snake.h"

snake::snake(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::snake)
{
    ui->setupUi(this);
    this->setFixedSize(1000, 1000);
    this->setWindowTitle("Hungry Snake");
    this->setWindowIcon(QIcon(":/pic/ff.png"));
    this->setAutoFillBackground(true);
    QPalette style;
    QPixmap pix(":/pic/abc.jpg");
    style.setBrush(QPalette::Window, QBrush(pix));
    this->setPalette(style);
    initcolor();
    createhead();
    createfood();
    timer = new QTimer(this);
    timer->start(200);
    connect(timer, SIGNAL(timeout()), this, SLOT(snakerun()));
}

snake::~snake()
{
    delete ui;
}

void snake::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);//绘制的图像反锯齿
    painter.fillRect(QRect(body[0][0], body[0][1], 20, 20), my_color[0]);
    painter.fillRect(QRect(food[0], food[1], 20, 20), my_color[1]);
    for(int i = 1; i < bodycount; i++) {
       if (i == 1)
           painter.fillRect(QRect(body[i][0], body[i][1], 20, 20), my_color[2]);
       else if (i % 2 == 0 || i % 6 == 0)
           painter.fillRect(QRect(body[i][0], body[i][1], 20, 20), my_color[3]);
       else if (i % 3 == 0 || i % 7 == 0)
           painter.fillRect(QRect(body[i][0], body[i][1], 20, 20), my_color[4]);
       else if (i % 4 == 0 || i % 8 == 0)
           painter.fillRect(QRect(body[i][0], body[i][1], 20, 20), my_color[5]);
       else if (i % 5 == 0 || i % 9 == 0)
           painter.fillRect(QRect(body[i][0], body[i][1], 20, 20), my_color[6]);
       else
           painter.fillRect(QRect(body[i][0], body[i][1], 20, 20), my_color[0]);
   }
}

void snake::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Up) {
        if (bodycount > 1 && direction == 1) {
             direction = 1;
        }
        else
            direction = 0;
    }
    if (event->key() == Qt::Key_Down) {
        if (bodycount > 1 && direction == 0) {
             direction = 0;
        }
        else
            direction = 1;
    }
    if (event->key() == Qt::Key_Left) {
        if (bodycount > 1 && direction == 3) {
             direction = 3;
        }
        else
            direction = 2;
    }
    if (event->key() == Qt::Key_Right) {
        if (bodycount > 1 && direction == 2) {
             direction = 2;
        }
        else
            direction = 3;
    }
}

void snake::initcolor()
{
    QColor c1(0x00, 0xff, 0xff);
    QColor c2(0xaa, 0x55, 0xff);
    QColor c3(0xff, 0x00, 0xff);
    QColor c4(0xaa, 0xff, 0x7f);
    QColor c5(0x00, 0xff, 0x7f);
    QColor c6(0xff, 0x7f, 0xbf);
    QColor c7(0xab, 0xab, 0xff);
    my_color.push_back(c1);
    my_color.push_back(c2);
    my_color.push_back(c3);
    my_color.push_back(c4);
    my_color.push_back(c5);
    my_color.push_back(c6);
    my_color.push_back(c7);
}

void snake::snakeheadrun()
{
    switch (direction) {
    case 0:
        body[0][1] -= 20;
        break;
    case 1:
        body[0][1] += 20;
        break;
    case 2:
        body[0][0] -= 20;
        break;
    case 3:
        body[0][0] += 20;
        break;
    default:
        break;
    }
}


void snake::createhead()
{
    body[0][0] = (qrand() % 30) * 20;
    body[0][1] = (qrand() % 20) * 20;
    bodycount = 1;
    direction = qrand() % 4;
}

void snake::createfood()
{
    food[0] = (qrand() % 20) * 20;
    food[1] = (qrand() % 15) * 20;
    for(int i = 0; i < bodycount; i++) {
        if(food[0] == body[i][0] && food[1] == body[i][1]) {
            food[0] = (qrand() % 20) * 20 - 20;
            food[1] = (qrand() % 15) * 20 - 20;
        }
    }
}

void snake::checkfood()
{
    if (body[0][0] == food[0] && body[0][1] == food[1]) {
        bodycount++;
        createfood();
    }
    for(int i = bodycount; i > 0; i--) {
        body[i][0] = body[i - 1][0];
        body[i][1] = body[i - 1][1];
    }
    snakeheadrun();
}

bool snake::game()
{
    if(body[0][0] > this->width() || body[0][0] < 0 ||
            body[0][1] > this->height() || body[0][1] == 0) {
        gameover();
        return true;
    }

    for(int i = 1; i < bodycount; i++) {
        if (body[0][0] == body[i][0] && body[0][1] == body[i][1]) {
            gameover();
            return true;
        }
    }
    return false;
}

void snake::gameover()
{
    timer->stop();
    QMessageBox msgBox;
    msgBox.setText("The Game is Over.");
    msgBox.setInformativeText("Do you want to return?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::No:
        this->close();
        break;
    case QMessageBox::Yes:
        this->close();
        Widget* w = new Widget;
        w->show();
        break;
    }
}

void snake::snakerun()
{
    if (game())
        return;
    checkfood();
    update();
}
