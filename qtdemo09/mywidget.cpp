#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QMouseEvent>
#include <QMessageBox>

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myWidget)
{
    ui->setupUi(this);
    timeID = this->startTimer(1000);
    timeID2 = this->startTimer(500);
    connect(ui->pushButton, &myButton::pressed,[=](){
        qDebug()<<"按钮被按下";
    });



    ui->label_2->installEventFilter(this);
}

myWidget::~myWidget()
{
    delete ui;
}

void myWidget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << (char)event->key();
    if (event->key() == Qt::Key_A) {
        qDebug() << "A";
    }
}

void myWidget::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == this->timeID) {
        static int sec = 0;
        ++sec;
        ui->label->setText(QString("<center><h1>Time : %1</h1></center>").arg(sec));
        if (sec == 10) {
            this->killTimer(this->timeID);
        }
    } else if (event->timerId() == this->timeID2) {
        static int sec = 0;
        ++sec;
        ui->label_2->setText(QString("<center><h1>Time : %1</h1></center>").arg(sec));
    }

}

void myWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "父组件接受子组件忽略鼠标事件";
}

void myWidget::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::question(this,"question","Are you sure to close the window ?");
    if (ret == QMessageBox::Yes) {
        event->accept(); //接受事件不在传递
    } else {
        event->ignore(); //忽略事件 传递
    }
}


bool myWidget::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->label_2) {
        //xxx
        QMouseEvent *env = static_cast<QMouseEvent *>(event);
        if (event->type() == QEvent::MouseMove) {
            ui->label_2->setText(QString("(%1, %2)").arg(env->x()).arg(env->y()));
            return true;
        } else {
            return QWidget::eventFilter(watched, event);
        }

    } else {
        return QWidget::eventFilter(watched, event);
    }

}
