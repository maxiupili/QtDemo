#include "sqlwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SQLWidget w;
    w.show();
    return a.exec();
}
