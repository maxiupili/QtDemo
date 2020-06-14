#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class myThread : public QThread
{
    Q_OBJECT
public:
    explicit myThread(QObject *parent = nullptr);

signals:
    void isDone();
protected:
    //线程处理 start调用
    void run() override;
};

#endif // MYTHREAD_H
