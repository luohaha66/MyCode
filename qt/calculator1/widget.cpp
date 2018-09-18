#include "widget.h"
#include "ui_widget.h"

using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Calculator");
    this->setWindowIcon(QIcon(":/计算器.png")); //设置界面图标
    //this->setWindowOpacity(0.9); //设置窗体整体半透明
    this->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");//设置控件为圆角
    this->setAutoFillBackground(true);

    QPalette uipa;
    QPixmap pix(":/e.jpg");
    uipa.setBrush(QPalette::Window, QBrush(pix));
    this->setPalette(uipa); //设置窗体背景图片

    l1 = new QLineEdit(this);
    l2 = new QLineEdit(this);
    lay = new QGridLayout(this);

    QString lastyle =
                   "QLineEdit{background-color:#54547d;color:#00ffff;border:0;}";
    QFont idft("Comic Sans MS", 22, 87);
    l1->setStyleSheet(lastyle);
    l1->setFont(idft); //设置字体
    l1->setReadOnly(true);
    l1->setAlignment(Qt::AlignRight);

    QString la1style =
                   "QLineEdit{background-color:#553855;color:#00ffff;border:0;}";
    l2->setStyleSheet(la1style);
    l2->setFont(idft); //设置字体
    l2->setReadOnly(true);
    l2->setAlignment(Qt::AlignRight);

    QString buttonstyle =
                         "QPushButton{color:#55ffff;border:0;}"
                         "QPushButton:!hover:!pressed{border-image:url(:/2.png)}"
                         "QPushButton:hover{border-image:url(:/1.png)}"
                         "QPushButton:pressed{border-image:url(:/2.png)}";
    QFont style_ft("Comic Sans MS", 18, 87);

    lay->addWidget(l1, 0, 0, 1, 4);
    lay->addWidget(l2, 1, 0, 1, 4);
    
    vector<vector<QString>> key{{"AC", "(", ")", "←"},
                                {"7", "8", "9", "*"},
                                {"4", "5", "6", "/"},
                                {"1", "2", "3", "+"},
                                {".", "0", "=", "-"}};
    
    for(unsigned int i = 0; i < key.size(); i++)
    {
        vector<QPushButton*> temp;
        for(unsigned int j = 0; j < key[i].size(); j++)
        {
            temp.push_back(new QPushButton(key[i][j], this));
            temp.back()->setFont(style_ft);
            temp.back()->setStyleSheet(buttonstyle);
            lay->addWidget(temp.back(), i + 2, j);
            connect(temp.back(), SIGNAL(clicked()), this, SLOT(count()));
        }
        button.push_back(temp);
    }
    setLayout(lay);
}

void Widget::count()
{
    QPushButton* bu = static_cast<QPushButton*>(sender());
    QString butext(bu->text());
    if(butext == "*" || butext == "/" || butext == "+" || butext == "-" || butext == "(" ||
            butext == ")" || butext == "0" || butext == "1" || butext == "2" || butext == "3" ||
            butext == "4" || butext == "5" || butext == "6" || butext == "7" || butext == "8" ||
            butext == "9" || butext == ".")
    {
        l1->setText(l1->text() + bu->text());
    }
    if(butext == "AC")
    {
        l1->clear();
        l2->clear();
        stack.clear();
        symb.clear();
    }
    if(butext == "←")
    {
        QString s;
        s = l1->text();
        s = s.left(s.length() - 1);
        l1->setText(s);
    }

    if(butext == "=")
    {
        int i = 0;
        string s = l1->text().toStdString();
        while(1)
        {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
                break;
            i++;
        }
        i++;
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            l2->setText("Wrong Expression");
            return;
        }
        else
        {
            string sss = l1->text().toStdString();
            string q;
            int n = 0;
            n = postfix(sss, q);
            double value = calculator(q, n);
            QRegExp rx;
            rx.setPattern("(\\.){0,1}0+$");
            QString ss = QString("%1").arg(value,0,'f',-1).replace(rx,"");
            l2->setText(ss);
        }
    }
}

bool Widget::isoperator(char op)
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

int Widget::priority(char op)
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

int Widget::read_counter(string& str,int i)
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

double Widget::read_number(string& str,int i)
{
    double x = 0.0;
    int k    = 0;
    while(str[i] >= '0' && str[i] <= '9')  // 处理整数部分
    {
        x = x * 10.0 + (double)(str[i] - '0');
        i++;
    }

    if(str[i] == '.') // 处理小数部分
    {
        i++;
        while(str[i] >= '0' && str[i] <='9')
        {
            x = x * 10.0 + (double)(str[i]-'0');
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

int Widget::postfix(string& pre, string& post)
{
    int i   = 0;
    int j   = 0;
    int len = 0;
    int n   = 0;

    len = pre.size();
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


double Widget::calculator(string& post, int n)
{
    int    i  = 0 ;
    double x1 = 0.0;
    double x2 = 0.0;
    int    co = 0;
    while(i < n)
    {
        if(post[i] >='0' && post[i] <='9')
        {
            stack.push((double)read_number(post, i));
            co = read_counter(post, i);
            i = co;
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

Widget::~Widget()
{
    delete ui;
}
