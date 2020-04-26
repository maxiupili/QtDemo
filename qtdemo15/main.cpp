#include "udpwidget.h"
#include "udpform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    udpWidget w;
    w.show();

    udpForm f;
    f.show();
    return a.exec();
}
