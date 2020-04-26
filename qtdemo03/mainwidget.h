#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"  //子窗口头文件
#include <QDebug>
#include "mybutton.h"
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void DealSign();
    void DealSlot(int, QString);

private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;
    void mySlot();

    SubWidget sw;
};
#endif // MAINWIDGET_H
