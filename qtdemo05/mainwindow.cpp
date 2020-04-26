#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(400, 300);

    QMenuBar *mBar = menuBar();

    setMenuBar(mBar);
    QMenu *mu = mBar->addMenu("对话框");

    QAction *ac1 = mu->addAction("模态框");
    connect(ac1, &QAction::triggered, [=](){
        QDialog dlg;
        dlg.exec();
        qDebug() << "close dialog";
    });

    QAction *ac2 = mu->addAction("非模态框");
    connect(ac2, &QAction::triggered, [=](){

        dlg.show();
        qDebug() << "close dialog";
    });

    QAction *ac3 = mu->addAction("关于框");
    connect(ac3, &QAction::triggered, [=](){

//        dlg.show();
//        qDebug() << "close dialog";
        QMessageBox::about(this, "about", "关于QT");
    });

    QAction *ac4 = mu->addAction("问题框");
    connect(ac4, &QAction::triggered, [=](){

//        dlg.show();
//        qDebug() << "close dialog";
        int ret = QMessageBox::question(this, "question", "are you ok?",
                                        QMessageBox::Ok | QMessageBox::Cancel);
        switch (ret) {
        case QMessageBox::Yes:
            qDebug() <<"Yes";
            break;
        case QMessageBox::No:
            qDebug() <<"No";
            break;
        default:
            break;
        }
    });

    QAction *ac5 = mu->addAction("文件对话框");
    connect(ac5, &QAction::triggered, [=](){
        QString path = QFileDialog::getOpenFileName(
                    this, "open", "../",
                    "Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml);;all(*.*)");
        qDebug()<<path;

    });

}

MainWindow::~MainWindow()
{
}

