#include "mythread.h"

myThread::myThread(QObject *parent) : QThread(parent)
{

}

void myThread::run()
{
    //复杂耗时的数据处理
    sleep(5);
    emit isDone();
}
