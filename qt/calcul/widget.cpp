#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Calculator"); //设置界面标题
    this->setWindowIcon(QIcon(":/计算器.png")); //设置界面图标
    //this->setWindowOpacity(0.9); //设置窗体整体半透明
    this->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");//设置控件为圆角
    this->setAutoFillBackground(true);

    QPalette uipa;
    QPixmap pix(":/e.jpg");
    uipa.setBrush(QPalette::Window, QBrush(pix));
    this->setPalette(uipa); //设置窗体背景图片

    p     = new char[100];
    count = new char[100];

    button0 = new QPushButton("0", this);
    button1 = new QPushButton("1", this);
    button2 = new QPushButton("2", this);
    button3 = new QPushButton("3", this);
    button4 = new QPushButton("4", this);
    button5 = new QPushButton("5", this);
    button6 = new QPushButton("6", this);
    button7 = new QPushButton("7", this);
    button8 = new QPushButton("8", this);
    button9 = new QPushButton("9", this);
    buttonadd = new QPushButton("+", this);
    buttonmul = new QPushButton("-", this);
    buttondiv = new QPushButton("/", this);
    buttonmun = new QPushButton("*", this);
    buttonequ = new QPushButton("=", this);
    buttondel = new QPushButton(".", this);
    buttondd = new QPushButton("←", this);
    buttonace = new QPushButton("AC", this);
    buttonleft = new QPushButton("(", this);
    buttonright = new QPushButton(")", this);
    la1 = new QLabel(this);
    la2 = new QLabel(this);

    la1->setFixedSize(380, 30);
    la2->setFixedSize(380, 30);
    button0->setFixedSize(60, 40);
    button1->setFixedSize(60, 40);
    button2->setFixedSize(60, 40);
    button3->setFixedSize(60, 40);
    button4->setFixedSize(60, 40);
    button5->setFixedSize(60, 40);
    button6->setFixedSize(60, 40);
    button7->setFixedSize(60, 40);
    button8->setFixedSize(60, 40);
    button9->setFixedSize(60, 40);
    buttonadd->setFixedSize(60, 40);
    buttonmul->setFixedSize(60, 40);
    buttonmun->setFixedSize(60, 40);
    buttonequ->setFixedSize(60, 40);
    buttondel->setFixedSize(60, 40);
    buttondiv->setFixedSize(60, 40);
    buttondd->setFixedSize(60, 40);
    buttonleft->setFixedSize(60, 40);
    buttonright->setFixedSize(60, 40);
    buttonace->setFixedSize(60, 40);

    QString buttonstyle =
                         "QPushButton{color:#55ffff;border:0;}"
                         "QPushButton:!hover:!pressed{border-image:url(:/2.png)}"
                         "QPushButton:hover{border-image:url(:/1.png)}"
                         "QPushButton:pressed{border-image:url(:/2.png)}";
    QFont style_ft("Comic Sans MS", 18, 87);
    button0->setStyleSheet(buttonstyle);
    button0->setFont(style_ft);

    button1->setStyleSheet(buttonstyle);
    button1->setFont(style_ft);

    button2->setStyleSheet(buttonstyle);
    button2->setFont(style_ft);

    button3->setStyleSheet(buttonstyle);
    button3->setFont(style_ft);

    button4->setStyleSheet(buttonstyle);
    button4->setFont(style_ft);

    button5->setStyleSheet(buttonstyle);
    button5->setFont(style_ft);

    button6->setStyleSheet(buttonstyle);
    button6->setFont(style_ft);

    button7->setStyleSheet(buttonstyle);
    button7->setFont(style_ft);

    button8->setStyleSheet(buttonstyle);
    button8->setFont(style_ft);

    button9->setStyleSheet(buttonstyle);
    button9->setFont(style_ft);

    buttonadd->setStyleSheet(buttonstyle);
    buttonadd->setFont(style_ft);

    buttonmul->setStyleSheet(buttonstyle);
    buttonmul->setFont(style_ft);

    buttonmun->setStyleSheet(buttonstyle);
    buttonmun->setFont(style_ft);

    buttondiv->setStyleSheet(buttonstyle);
    buttondiv->setFont(style_ft);

    buttondel->setStyleSheet(buttonstyle);
    buttondel->setFont(style_ft);

    buttonequ->setStyleSheet(buttonstyle);
    buttonequ->setFont(style_ft);

    buttondd->setStyleSheet(buttonstyle);
    buttondd->setFont(style_ft);

    buttonleft->setStyleSheet(buttonstyle);
    buttonleft->setFont(style_ft);

    buttonright->setStyleSheet(buttonstyle);
    buttonright->setFont(style_ft);

    buttonace->setStyleSheet(buttonstyle);
    buttonace->setFont(style_ft);

    QString lastyle =
                   "QLabel{background-color:#54547d;color:#00ffff;border:0;}";
    QFont idft("Comic Sans MS", 22, 87);
    la1->setStyleSheet(lastyle);
    la1->setFont(idft); //设置字体

    QString la1style =
                   "QLabel{background-color:#553855;color:#00ffff;border:0;}";
    la2->setStyleSheet(la1style);
    la2->setFont(idft); //设置字体

    QVBoxLayout* vl = new QVBoxLayout;
    vl->addWidget(la1);
    vl->addWidget(la2);

    QHBoxLayout* hb = new QHBoxLayout;
    hb->addWidget(buttonace);
    hb->addWidget(buttonleft);
    hb->addWidget(buttonright);
    hb->addWidget(buttondd);

    QHBoxLayout* hb1 = new QHBoxLayout;
    hb1->addWidget(button7);
    hb1->addWidget(button8);
    hb1->addWidget(button9);
    hb1->addWidget(buttonmun);

    QHBoxLayout* hb2 = new QHBoxLayout;
    hb2->addWidget(button4);
    hb2->addWidget(button5);
    hb2->addWidget(button6);
    hb2->addWidget(buttondiv);

    QHBoxLayout* hb3 = new QHBoxLayout;
    hb3->addWidget(button1);
    hb3->addWidget(button2);
    hb3->addWidget(button3);
    hb3->addWidget(buttonadd);

    QHBoxLayout* hb4 = new QHBoxLayout;
    hb4->addWidget(buttondel);
    hb4->addWidget(button0);
    hb4->addWidget(buttonequ);
    hb4->addWidget(buttonmul);

    QVBoxLayout* vl1 = new QVBoxLayout;
    vl1->addLayout(vl);
    vl1->addLayout(hb);
    vl1->addLayout(hb1);
    vl1->addLayout(hb2);
    vl1->addLayout(hb3);
    vl1->addLayout(hb4);

    setLayout(vl1);
    connect(button0, SIGNAL(clicked()), this, SLOT(b0_clicked()));
    connect(button1, SIGNAL(clicked()), this, SLOT(b1_clicked()));
    connect(button2, SIGNAL(clicked()), this, SLOT(b2_clicked()));
    connect(button3, SIGNAL(clicked()), this, SLOT(b3_clicked()));
    connect(button4, SIGNAL(clicked()), this, SLOT(b4_clicked()));
    connect(button5, SIGNAL(clicked()), this, SLOT(b5_clicked()));
    connect(button6, SIGNAL(clicked()), this, SLOT(b6_clicked()));
    connect(button7, SIGNAL(clicked()), this, SLOT(b7_clicked()));
    connect(button8, SIGNAL(clicked()), this, SLOT(b8_clicked()));
    connect(button9, SIGNAL(clicked()), this, SLOT(b9_clicked()));
    connect(buttonadd, SIGNAL(clicked()), this, SLOT(badd_clicked()));
    connect(buttondiv, SIGNAL(clicked()), this, SLOT(bdiv_clicked()));
    connect(buttonequ, SIGNAL(clicked()), this, SLOT(bequ_clicked()));
    connect(buttonmun, SIGNAL(clicked()), this, SLOT(bmun_clicked()));
    connect(buttonmul, SIGNAL(clicked()), this, SLOT(bmul_clicked()));
    connect(buttondel, SIGNAL(clicked()), this, SLOT(bdel_clicked()));
    connect(buttonace, SIGNAL(clicked()), this, SLOT(bace_clicked()));
    connect(buttonleft, SIGNAL(clicked()), this, SLOT(bleft_clicked()));
    connect(buttonright, SIGNAL(clicked()), this, SLOT(bright_clicked()));
    connect(buttondd, SIGNAL(clicked()), this, SLOT(bdd_clicked()));
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

int Widget::postfix(char* pre,char* post)
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

int Widget::read_counter(char* str,int i)
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

double Widget::read_number(char* str,int i)
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

double Widget::postfix_value(char* post,int n)
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

Widget::~Widget()
{
    delete []p;
    delete []count;
    p     = NULL;
    count = NULL;
    delete ui;
}



void Widget::b0_clicked()
{
    la1->setText(la1->text() + "0");
}

void Widget::b1_clicked()
{
    la1->setText(la1->text() + "1");
}

void Widget::b2_clicked()
{
    la1->setText(la1->text() + "2");
}

void Widget::b3_clicked()
{
    la1->setText(la1->text() + "3");
}

void Widget::b4_clicked()
{
    la1->setText(la1->text() + "4");
}

void Widget::b5_clicked()
{
    la1->setText(la1->text() + "5");
}

void Widget::b6_clicked()
{
    la1->setText(la1->text() + "6");
}

void Widget::b7_clicked()
{
    la1->setText(la1->text() + "7");
}

void Widget::b8_clicked()
{
    la1->setText(la1->text() + "8");
}

void Widget::b9_clicked()
{
    la1->setText(la1->text() + "9");
}

void Widget::badd_clicked()
{
    la1->setText(la1->text() + "+");
}

void Widget::bmul_clicked()
{
    la1->setText(la1->text() + "-");
}

void Widget::bmun_clicked()
{
    la1->setText(la1->text() + "*");
}

void Widget::bdiv_clicked()
{
    la1->setText(la1->text() + "/");
}

void Widget::bdel_clicked()
{
    la1->setText(la1->text() + ".");
}

void Widget::bleft_clicked()
{
    la1->setText(la1->text() + "(");
}

void Widget::bright_clicked()
{
    la1->setText(la1->text() + ")");
}

void Widget::bdd_clicked()
{
    QString s;
    s = la1->text();
    s = s.left(s.length() - 1);
    la1->setText(s);
}

void Widget::bace_clicked()
{
    la1->setText(NULL);
    la2->setText(NULL);
}

void Widget::bequ_clicked()
{
    s = la1->text();
    b = s.toLatin1();
    p = b.data();

    n = postfix(p, count);
    value = postfix_value(count, n);
    QRegExp rx;
    rx.setPattern("(\\.){0,1}0+$");
    QString ss = QString("%1").arg(value,0,'f',-1).replace(rx,"");
    la2->setText(ss);
}





