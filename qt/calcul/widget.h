#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVboxLayout>
#include <QHBoxLayout>
#include <QIcon>
#include <QImage>
#include <QPalette>
#include <QPixmap>
#include <QStack>
#include <QString>
#include <qmath.h>
#include <QRegExp>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    bool isoperator(char op);                 // 判断是否为运算符
    int priority(char op);                    // 求运算符优先级
    int postfix(char* pre, char* post);       // 把中缀表达式转换为后缀表达式
    double read_number(char* str,int i);      // 将数字字符串转变成相应的数字
    int read_counter(char* str,int i);
    double postfix_value(char* post, int n);   // 由后缀表达式字符串计算相应的中值表达式的值

public slots:
    void b0_clicked();
    void b1_clicked();
    void b2_clicked();
    void b3_clicked();
    void b4_clicked();
    void b5_clicked();
    void b6_clicked();
    void b7_clicked();
    void b8_clicked();
    void b9_clicked();
    void badd_clicked();
    void bmun_clicked();
    void bmul_clicked();
    void bdiv_clicked();
    void bequ_clicked();
    void bdel_clicked();
    void bleft_clicked();
    void bright_clicked();
    void bdd_clicked();
    void bace_clicked();

private:
    Ui::Widget *ui;
    QPushButton* button0;
    QPushButton* button1;
    QPushButton* button2;
    QPushButton* button3;
    QPushButton* button4;
    QPushButton* button5;
    QPushButton* button6;
    QPushButton* button7;
    QPushButton* button8;
    QPushButton* button9;
    QPushButton* buttonleft;
    QPushButton* buttondd;
    QPushButton* buttonright;
    QPushButton* buttonace;
    QPushButton* buttonadd;
    QPushButton* buttonmul;
    QPushButton* buttondiv;
    QPushButton* buttonmun;
    QPushButton* buttonequ;
    QPushButton* buttondel;
    QLabel* la1;
    QLabel* la2;
    QStack<double> stack;
    QStack<char> symb;
    QByteArray b;
    QString    s;
    char*   count   = NULL;
    char*   p       = NULL;
    double  value   = 0.0;
    int     value1  = 0;
    int     n       = 0;
};

#endif // WIDGET_H
