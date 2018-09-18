#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    p     = new char[100];
    count = new char[100];
}

MainWindow::~MainWindow()
{
    delete []p;
    delete []count;
    p     = NULL;
    count = NULL;
    delete ui;
}

bool MainWindow::isoperator(char op)
{
    switch(op)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return 1;
    default :
        return 0;
    }
}

int MainWindow::priority(char op)
{
    switch(op)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default :
        return -1;
    }
}

int MainWindow::postfix(char* pre,char* post)
{
    int i   = 0;
    int j   = 0;
    int len = 0;
    int n   = 0;

    len = strlen(pre);
    while (i < len)
    {
     if((pre[i] >= '0' && pre[i] <= '9') || pre[i] == '.') // 遇到数字和小数点直接写入后缀表达式
        {
            post[j++] = pre[i];
            n++;
        }
        else if (pre[i] == '(')   // 遇到“（”不用比较直接入栈
            symb.push(pre[i]);
        else if(pre[i] == ')')  // 遇到右括号将其对应左括号后的操作符（操作符栈中的）全部写入后缀表达式
        {
            while(symb.top() != '(')
            {
                post[j++] = symb.pop();
                n++;
            }
            symb.pop(); // 将“（”出栈，后缀表达式中不含小括号
        }
        else if (isoperator(pre[i]))
        {
            post[j++] = ' '; // 用空格分开操作数
            n++;

                while( (!symb.isEmpty()) && (priority(pre[i]) <= priority(symb.top())))
                {
                    // 当前的操作符小于等于栈顶操作符的优先级时，将栈顶操作符写入到后缀表达式，重复此过程
                    post[j++] = symb.pop();
                    n++;
                }
            symb.push(pre[i]); // 当前操作符优先级大于栈顶操作符的优先级，将该操作符入栈
        }
        i++;
    }

    while( !(symb.isEmpty()) ) // 将所有的操作符加入后缀表达式
    {
        post[j++] = symb.pop();
        n++;
    }
  return n;
}

int MainWindow::read_counter(char* str,int i)
{
    while(str[i] >= '0' && str[i] <= '9')  // 处理整数部分
    {
        i++;
    }

    if(str[i] == '.') // 处理小数部分
    {
        i++;
        while(str[i] >= '0' && str[i] <='9')
        {
            i++;
        }
    }
    return i;
}

double MainWindow::read_number(char* str,int i)
{
    double x = 0.0;
    int k    = 0;
    while(str[i] >= '0' && str[i] <= '9')  // 处理整数部分
    {
        x = x * 10 + (str[i] - '0');
        i++;
    }

    if(str[i] == '.') // 处理小数部分
    {
        i++;
        while(str[i] >= '0' && str[i] <='9')
        {
            x = x * 10 + (str[i]-'0');
            i++;
            k++;
        }
    }
    while(k != 0)
    {
        x /= 10.0;
        k--;
    }
    return x;
}

double MainWindow::postfix_value(char* post,int n)
{
    int    i  = 0 ;
    double x1 = 0;
    double x2 = 0;
    int    co = 0;
    while(i < n)
    {
        if(post[i] >='0' && post[i] <='9')
        {
            stack.push(read_number(post, i));
            co = read_counter(post, i);
            i = co;
            /*stack.push(post[i]);
            i++;*/
        }
        else if (post[i] == ' ')
            i++;
        else if (post[i] == '+')
        {
            x2 = stack.pop();
            x1 = stack.pop();
            stack.push(x1 + x2);
            i++;
        }
        else if (post[i] == '-' )
        {
            x2 = stack.pop();
            x1 = stack.pop();
            stack.push(x1 - x2);
            i++;
        }
        else if (post[i] == '*' )
        {
            x2 = stack.pop();
            x1 = stack.pop();
            stack.push(x1 * x2);
            i++;
        }
        else if (post[i] == '/')
        {
            x2 = stack.pop();
            x1 = stack.pop();
            stack.push(x1 / x2);
            i++;
        }
    }
    return stack.top();
}

void MainWindow::on_pb0_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "0");
}

void MainWindow::on_pb1_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "1");
}

void MainWindow::on_pb2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "2");
}

void MainWindow::on_pb3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "3");
}

void MainWindow::on_pb4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "4");
}

void MainWindow::on_pb5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "5");
}

void MainWindow::on_pb6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "6");
}

void MainWindow::on_pb7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "7");
}

void MainWindow::on_pb8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "8");
}

void MainWindow::on_pb9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "9");
}

void MainWindow::on_pb_le_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "(");
}

void MainWindow::on_pb_ri_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ")");
}

void MainWindow::on_pb_dii_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ".");
}

void MainWindow::on_pb_del_clicked()
{
    QString s;
    s = ui->lineEdit->text();
    s = s.left(s.length() - 1);
    ui->lineEdit->setText(s);
}

void MainWindow::on_pb_add_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "+");
}

void MainWindow::on_pb_sub_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "-");
}

void MainWindow::on_pb_mul_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "*");
}

void MainWindow::on_pb_div_clicked()
{
   ui->lineEdit->setText(ui->lineEdit->text() + "/");
}

void MainWindow::on_pb_ace_clicked()
{
    ui->lineEdit->setText(NULL);
    ui->lineEdit_2->setText(NULL);
}

void MainWindow::on_pb_equ_clicked()
{
    s = ui->lineEdit->text();
    b = s.toLatin1();
    p = b.data();

    n = postfix(p, count);
    value = postfix_value(count, n);
    ui->lineEdit_2->setText(QString::number(value, 10.0));
    //ui->lineEdit_2->setText(QString("%1").arg(p));
    //ui->lineEdit_2->setText();
}

