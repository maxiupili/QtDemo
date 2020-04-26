#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QBitmap>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    x = 100;
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::paintEvent(QPaintEvent *event)
{
    //QPainter p(this);
    QPainter p;
    p.begin(this);

    //p.drawPixmap(0, 0, width(), height(), QPixmap("../Image/Frame.jpg"));
    p.drawPixmap(rect(), QPixmap("../Image/Frame.jpg"));

    QPen pen;
    pen.setWidth(5);
    pen.setStyle(Qt::DashLine);
    p.setPen(pen);

    p.drawLine(50, 50, 250, 50);
    p.drawLine(50, 50, 50, 250);

    QBrush br;
    br.setStyle(Qt::Dense1Pattern);
    p.setBrush(br);
    p.drawRect(100,100,200,200);

    p.drawPixmap(x, 180, 80, 80, QPixmap("../Image/up.png"));
    p.drawPixmap(x+200, 180, 80, 80, QBitmap("../Image/up.png"));
    p.end();
}


void MyWidget::on_pushButton_clicked()
{
    x += 50;
    if (x > width()) {
        x = 0;
    }
    //刷新窗口 重绘图
    update();
}
