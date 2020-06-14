#include "widget.h"
#include "ui_widget.h"
#include <QPainter>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    myT = new MyThread;

    thread = new QThread(this);
    //添加到子线程
    myT->moveToThread(thread);

    thread->start();

    connect(ui->pushButton, &QPushButton::pressed, myT, &MyThread::drawImage);
    connect(myT, &MyThread::updateImage, this, &Widget::getImage);
    connect(this, &Widget::destroyed, this, &Widget::dealClose);
}

void Widget::dealClose()
{
    thread->quit();

    thread->wait();
    //未指定父对象，手动释放
    delete myT;

}

void Widget::getImage(QImage temp)
{
    image = temp;
    update();
    //repaint();
//    QPainter p(this);

//    p.drawImage(50, 50, image);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    p.drawImage(50, 50, image);
}
