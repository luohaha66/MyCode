#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setReadOnly(true);
    //ui->lineEdit->installEventFilter(this);
    //this->startTimer(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //ui->label->setGeometry(event->x(), event->y(), 100, 20);
    QPoint p = event->pos();
    pos.append(p);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint p = event->pos();
    pos.append(p);
    update();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int y = ui->label->pos().y();
    if (event->key() == Qt::Key_Up ) {
        y -= 5;
        ui->label->setGeometry(ui->label->pos().x(), y, 100, 20);
    }
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    int x = ui->label->pos().x();
    int y = ui->label->pos().y();
    x += 2;
    ui->label->setGeometry(x, y, 100, 20);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->lineEdit) {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent* mevent = static_cast<QMouseEvent*>(event);
            if (mevent->button() == 1)
                ui->lineEdit->setText("皮一下很快乐吗");
            else
                ui->lineEdit->setText("皮一下是很快乐");
        }
    }
    return 0;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    QPen* p = new QPen;
    p->setWidth(8);
    p->setColor(QColor(0xab, 0xab, 0xff));
    pen.setPen(*p);
    for (int i = 0; i < pos.size() - 1; i = i + 2) {
        QPoint p1 = pos.at(i);
        QPoint p2 = pos.at(i + 1);
        pen.drawLine(p1, p2);
    }
}
