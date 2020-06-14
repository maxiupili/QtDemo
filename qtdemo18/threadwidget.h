#ifndef THREADWIDGET_H
#define THREADWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QThread>
#include "mythread.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class threadWidget; }
QT_END_NAMESPACE

class threadWidget : public QWidget
{
    Q_OBJECT

public:
    threadWidget(QWidget *parent = nullptr);
    ~threadWidget();
    void dealDone();
    void stopThread();

private slots:
    void on_pushButton_clicked();

private:
    Ui::threadWidget *ui;

    QTimer *myTimer;

    myThread *mmth;
};
#endif // THREADWIDGET_H
