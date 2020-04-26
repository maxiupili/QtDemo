#include <QApplication>
#include <QWidget>
#include <QPushButton>


int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget w;
    w.setWindowTitle("Hello QT");

    QPushButton b;
    b.setText("button");
    b.setParent(&w);

    QPushButton b1(&w);
    b1.setText("b1");
    b1.move(100,100);

    w.show();



    app.exec();
    return 0;
}
