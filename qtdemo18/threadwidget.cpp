#include "threadwidget.h"
#include "ui_threadwidget.h"

threadWidget::threadWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::threadWidget)
{
    ui->setupUi(this);
    myTimer = new QTimer(this);

    connect(myTimer, &QTimer::timeout, [=](){
        static int i = 0; //可重入
        ++i;
        ui->lcdNumber->display(i);
    });

    mmth = new myThread(this);

    connect(mmth, &myThread::isDone, this, &threadWidget::dealDone);

    connect(this, &threadWidget::destroyed, this, &threadWidget::stopThread);
}

threadWidget::~threadWidget()
{
    delete ui;
}


void threadWidget::on_pushButton_clicked()
{
    if (myTimer->isActive()) {
        return;
    }
    //QThread::sleep(5);
    mmth->start();

    myTimer->start(100);
}

void threadWidget::dealDone()
{
    qDebug() << "done";
    myTimer->stop();

}

void threadWidget::stopThread()
{
    qDebug() << "quit thread";
    mmth->quit();

    mmth->wait();
}
