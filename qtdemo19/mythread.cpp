#include "mythread.h"
#include <QPainter>
#include <QPen>
#include <QBrush>

MyThread::MyThread(QObject *parent) : QObject(parent)
{

}

void MyThread::drawImage()
{
    QImage image(500, 500, QImage::Format_ARGB32);

    QPainter p(&image);

    QPoint a[] = {
        QPoint(qrand()%500, qrand()%500),
        QPoint(qrand()%500, qrand()%500),
        QPoint(qrand()%500, qrand()%500),
        QPoint(qrand()%500, qrand()%500),
        QPoint(qrand()%500, qrand()%500)
    };

    QPen pen;
    pen.setWidth(5);

    p.setPen(pen);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);

    p.setBrush(brush);

    p.drawPolygon(a, 5);

    //通过信号发送图片
    emit updateImage(image);



}
