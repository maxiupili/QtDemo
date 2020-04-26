#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("^_^");
    //ui->label_2->setPixmap("C:/Users/林森俊/Pictures/毕业照/新建文件夹/9BFB4F3DEAA4E52330D2AD11A7EEF150.png");
}

MainWindow::~MainWindow()
{
    delete ui;
}

