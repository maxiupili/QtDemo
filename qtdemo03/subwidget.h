#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    void SendSignToW1();
signals:
    //信号关键字 无返回值,只需申明，无需定义
    void mySignal();
    void mySignal(int, QString);

private:
    QPushButton b4;

};

#endif // SUBWIDGET_H
