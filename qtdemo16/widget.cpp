#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    mytimer = new QTimer(this);

    connect(mytimer, &QTimer::timeout,[=](){
        static int i = 0;
        i++;
        ui->lcdNumber->display(i);
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonstart_clicked()
{
    if (mytimer->isActive())
        return;
    //每隔1000毫秒自动触发timeout信号
    mytimer->start(500);
}

void Widget::on_pushButtonstop_clicked()
{
    if (mytimer->isActive()) {
        mytimer->stop();
    }
}
