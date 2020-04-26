#include "mylabel.h"
#include <QDebug>

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    //设定 初始鼠标追踪
    this->setMouseTracking(true);
}

void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QString text;
    text = QString("<center><h1>Mouse Move: (%1, %2)</h1></center>").arg(ev->x()).arg(ev->y());
    //this->setText(text);
}

void myLabel::mousePressEvent(QMouseEvent *ev)
{
    int i = ev->x();
    int j = ev->y();
    //%1.%2为参数占位符
    QString text;

    if (ev->button() == Qt::LeftButton) {
        qDebug() << "left" <<endl;
        text = QString("<center><h1>Mouse LeftButton Press: (%1, %2)</h1></center>").arg(i).arg(j);
    } else if (ev->button() == Qt::RightButton) {
        qDebug() << "right" <<endl;
        text = QString("<center><h1>Mouse RightButton Press: (%1, %2)</h1></center>").arg(i).arg(j);
    } else if (ev->button() == Qt::MiddleButton) {
        qDebug() << "middle" <<endl;
        text = QString("<center><h1>Mouse MiddleButton Press: (%1, %2)</h1></center>").arg(i).arg(j);
    }

    this->setText(text);
}

void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QString text;
    text = QString("<center><h1>Mouse Release: (%1, %2)</h1></center>").arg(ev->x()).arg(ev->y());
    this->setText(text);
}

void myLabel::enterEvent(QEvent *e)
{
    QString text;
    text = QString("<center><h1>EnterEvent</h1></center>");
    this->setText(text);
}

void myLabel::leaveEvent(QEvent *e)
{
    QString text;
    text = QString("<center><h1>LeaveEvent</h1></center>");
    this->setText(text);
}
