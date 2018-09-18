#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <map>
#include <set>
#include <QStack>
#include <QPushButton>
#include <QLineEdit>
#include <vector>
#include <QGridLayout>
#include <QPalette>
#include <QString>
#include <QImage>
#include <QPixmap>
#include <QDebug>

using namespace std;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void count();
    bool isoperator(char op);
    int priority(char op);
    int read_counter(string& str,int i);
    double read_number(string& str,int i);
    int postfix(string& pre, string& post);
    double calculator(string& post, int n);

private:
    Ui::Widget *ui;
    QLineEdit* l1;
    QLineEdit* l2;
    QGridLayout* lay;
    vector<vector<QPushButton*>> button;
    QStack<char> symb;
    QStack<double> stack;
};

#endif // WIDGET_H
