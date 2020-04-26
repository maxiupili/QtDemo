#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    //相对于左上角
    move(0, 0);

    b1.setParent(this);
    b1.setText("close");
    b1.move(100, 100);

    b2 = new QPushButton(this);
    b2->setText("b2 butten");

    connect(&b1, &QPushButton::pressed, this, &MainWidget::close);

    //自定义槽函数
    connect(b2, &QPushButton::released, this, &MainWidget::mySlot);
    connect(b2, &QPushButton::released, &b1, &QPushButton::hide);

    setWindowTitle("w1");
    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(50, 50);

    connect(&b3, &QPushButton::released, this, &MainWidget::hide);
    connect(&b3, &QPushButton::released, &sw, &SubWidget::show);

    //connect(&b4, &QPushButton::released, this, &MainWidget::show);
    //sw.show();

    //信号重载，使用函数指针
    void (SubWidget::*funSignal)() = &SubWidget::mySignal;
    connect(&sw, funSignal, this, &MainWidget::DealSign);
    void (SubWidget::*funSignalWithStr)(int, QString) = &SubWidget::mySignal;
    connect(&sw, funSignalWithStr, this, &MainWidget::DealSlot);

    //qt4信号连接 不推荐使用
    //SIGNAL SLOT 宏将函数名转化为字符串 不进行错误检查

    //Lamda表达式 C++11
    QPushButton *b5 = new QPushButton(this);
    b5->setText("LamdaBT");
    b5->move(150,150);
    b5->resize(100, 100);

    myButton *b6 = new myButton(b5);
    b6->setText("^_^");
    b6->move(10, 10);

    connect(b5, &QPushButton::clicked,  //clicked带参数 可在[](此处传递信号方法的参数)
            [=](bool isCheck) mutable //关键字mutable 允许修改传进来的变量 不再只读
            { // []中可写具体外部变量如b5  [=] 把外部所有局部变量，类中所有成员以值传递(只读)
              // [this] 类中所有成员传进来
              // [&] 把外部变量不包括类中成员传进来，容易出错
              b5->setText("LamdaBTchange");
              //qDebeg()使用相当于cout
              qDebug() << "lamdalamda" << endl;
              qDebug() << isCheck;
             });



    resize(400, 300);
}

void MainWidget::DealSign()
{
    this->show();
    sw.hide();
}

void MainWidget::DealSlot(int a, QString str)
{
    qDebug() << a << str.toUtf8().data();  //打印中文
}

void MainWidget::mySlot()
{
    b2->setText("ccccchange");
}

MainWidget::~MainWidget()
{
}
//qt对象树系统自动回收动态申请空间（只要指定了父对象，并直接或间接继承于QObject）
