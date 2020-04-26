#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //去边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //背景透明
    //setAttribute(Qt::WA_TranslucentBackground);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p;
    p.begin(this);
    p.drawPixmap(0, 0, QPixmap("../Image/sunny.png"));
    p.end();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        close();
    } else if (event->button() == Qt::LeftButton) {
        //
        po = this->frameGeometry().topLeft() - event->globalPos();
    }
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() & Qt::LeftButton) {
        move(event->globalPos() + po);
    } else if (event->button() == Qt::RightButton) {
        close();
    }
}
