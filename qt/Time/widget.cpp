#include "widget.h"
#include "ui_widget.h"

//下面三个数组用来定义表针的三个顶点，以便后面的填充
const QPoint Widget::hourHand[3] = {
    QPoint(3, 8),
    QPoint(-3, 8),
    QPoint(0, -40)
};

const QPoint Widget::minuteHand[3] = {
     QPoint(3, 8),
     QPoint(-3, 8),
     QPoint(0, -70)
};

const QPoint Widget::secondHand[3] = {
     QPoint(3, 8),
     QPoint(-3, 8),
     QPoint(0, -90)
};

const QVector<QString> Widget::my_num = {{"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"}, {"9"},
                                         {"10"}, {"11"}, {"12"}, {"1"}, {"2"}};

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("System Clock");
    this->resize(300, 300);
    this->setWindowOpacity(0.9);
    this->setAttribute(Qt::WA_TranslucentBackground); //设置窗体整体透明
    this->setWindowFlags(Qt::FramelessWindowHint);
    my_timer = new QTimer(this);
    connect(my_timer, SIGNAL(timeout()), this, SLOT(update()));
    my_timer->start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
     //填充表针的颜色
     QColor hourColor(0x64, 0x32, 0x4b);  //分针颜色(第四个表示不透明度)
     QColor minuteColor(0x55, 0xaa, 0xff);
     QColor secondColor(0x00, 0xff, 0xff);

     int side = qMin(width(), height());  //绘制的范围(宽、高中最小值)
     QTime time = QTime::currentTime();   //获取当前的时间
     QPainter painter(this);              //声明用来绘图用的painter
     QFont f("Microsoft YaHei", 12, 87);
     painter.setFont(f);

     painter.setRenderHint(QPainter::Antialiasing, true);//绘制的图像反锯齿
     painter.translate(width() / 2, height() / 2);//重新定位坐标起始点，把坐标原点放到窗体的中央
     painter.scale(side / 300.0, side / 300.0);//设定画布的边界,用窗体宽高的最小值来计算时钟的大小，防止窗体拉伸导致的时钟变形以及显示不全

     painter.setPen(QColor(0xaa, 0xaa, 0xff));
     QString timeStr= QTime::currentTime().toString();     //绘制当前的时间
     painter.drawText(QRectF(-40,30,80,30), Qt::AlignHCenter | Qt::AlignTop, timeStr);

     painter.setPen(Qt::NoPen);   //填充时针，不需要边线所以NoPen
     painter.setBrush(hourColor);  //画刷颜色设定
     painter.save();  //保存painter的状态，保存的是当前的坐标状态，如果不保存，画完之后坐标以改变不方便画下一个
     painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0))); //将painter（的”视角“）根据时间参数转移(30° * (小时 + 分钟 / 60))
     painter.drawConvexPolygon(hourHand, 3);  //填充时针的区域
     painter.restore();

     painter.setPen(Qt::NoPen);
     painter.setBrush(minuteColor);
     painter.save();
     painter.rotate(6.0 * (time.minute() + time.second() / 60.0));  //设旋转(角度 = 6° * (分钟 + 秒 / 60))
     painter.drawConvexPolygon(minuteHand, 3);  //填充分针部分
     painter.restore();

     painter.setPen(Qt::NoPen);
     painter.setBrush(secondColor);
     painter.save();
     painter.rotate(6.0 * time.second());  //设置旋转(6° * 秒)
     painter.drawConvexPolygon(secondHand, 3);  //设置填充
     painter.restore();

     QPen mypen;
     mypen.setColor(QColor(0xab, 0xab, 0xff));
     mypen.setWidth(2);
     painter.setPen(mypen);
     for (int j = 0; j < 60; ++j) {  //循环60次，绘制表盘（其实可以从1开始，到59，提高一点效率）
         if ((j % 5) == 0)           //判断是否能被5整除(能被5整除表示是正点刻度，暂不绘制)
             painter.drawLine(0, -88, 0, -96);
         else {
             painter.drawLine(0, -92, 0, -96);  //不是正点刻度，绘制长4个像素的直线
         }
         painter.rotate(6.0);   //循环60次，每次旋转6度，所以不用save和restore
     }

     painter.setPen(QColor(0xff, 0x7f, 0xbf));
     float r = 75.0;
     float x1;
     float y1;
     for (int i = 0; i < my_num.size(); ++i) {
         //写上刻度数字
         x1 = r * qCos(30 * i * 3.14 / 180);
         y1 = r * qSin(30 * i * 3.14 / 180);
         if (i == 0)
             painter.drawText(QPointF(x1, y1 + 7), my_num.at(i));
         if (i < 3 && i > 0)
             painter.drawText(QPointF(x1 - 2, y1 + 9), my_num.at(i));
         if (i == 3)
             painter.drawText(QPointF(x1 - 6, y1 + 7), my_num.at(i));
         if (i > 3 && i <= 6)
             painter.drawText(QPointF(x1 - 7, y1 + 7), my_num.at(i));
         if (i > 6 && i < 10)
             painter.drawText(QPointF(x1 - 8, y1 + 4), my_num.at(i));
         if (i == 10 || i == 11)
             painter.drawText(QPointF(x1 - 2, y1 + 5), my_num.at(i));
     }

     painter.setBrush(Qt::black);
     painter.drawEllipse(QPoint(0,0),2,2);

     painter.setBrush(Qt::NoBrush);
     painter.setPen(Qt::black);
     painter.drawEllipse(QPoint(0,0),97,97);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    wind = this->pos();
    mous = event->globalPos();
    posit = mous - wind;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - posit);
}
