#include "mywidget.h"
//应用程序类
#include <QApplication>

int main(int argc, char *argv[])
{
    //有且只有一个应用程序类的对象
    QApplication a(argc, argv);

    //继承与QWidget窗口基类
    MyWidget w;

    //显示窗口（默认不显示）
    w.show();

    //a.exec()等待事件发生 让程序一致执行
    return a.exec();
}
