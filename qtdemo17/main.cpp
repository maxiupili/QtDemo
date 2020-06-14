#include "serverwidget.h"
#include "clientwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    serverWidget w;
    w.show();
    clientWidget cw;
    cw.show();
    return a.exec();
}
