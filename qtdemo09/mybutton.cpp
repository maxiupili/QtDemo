#include "mybutton.h"
#include <QMouseEvent>
#include <QDebug>

myButton::myButton(QWidget *parent) : QPushButton(parent)
{

}

void myButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        qDebug() << "左键";
        event->ignore();  //忽略 事件传递下去给父组件 非基类 这边是qwidget
    } else {
        QPushButton::mousePressEvent(event);
    }
    //QPushButton::mousePressEvent(event);
}
