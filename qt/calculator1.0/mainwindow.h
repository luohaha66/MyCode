#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <iostream>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool isoperator(char op);                         // 判断是否为运算符
    int priority(char op);                            // 求运算符优先级
    int postfix(char* pre, char* post);    // 把中缀表达式转换为后缀表达式
    double read_number(char* str,int i);            // 将数字字符串转变成相应的数字
    int read_counter(char* str,int i);
    double postfix_value(char* post, int n);                // 由后缀表达式字符串计算相应的中值表达式的值


private slots:
    void on_pb0_clicked();
    void on_pb1_clicked();
    void on_pb2_clicked();
    void on_pb3_clicked();
    void on_pb4_clicked();
    void on_pb5_clicked();
    void on_pb6_clicked();
    void on_pb7_clicked();
    void on_pb8_clicked();
    void on_pb9_clicked();

    void on_pb_add_clicked();
    void on_pb_sub_clicked();
    void on_pb_mul_clicked();
    void on_pb_div_clicked();
    void on_pb_ace_clicked();
    void on_pb_dii_clicked();

    void on_pb_le_clicked();
    void on_pb_ri_clicked();
    void on_pb_del_clicked();

    void on_pb_equ_clicked();

private:
    Ui::MainWindow *ui;
    QStack<double> stack;
    QStack<char> symb;
    QByteArray b;
    QString    s;
    char*   count   = NULL;
    char*   p       = NULL;
    double  value   = 0.0;
    int     n       = 0;
};

#endif // MAINWINDOW_H
