#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->label->setStyleSheet("QLabel{color:rgb(0, 255, 255);"
                             "background-color:red}");
    ui->pushButton->setStyleSheet("QPushbutton{"
                                  "background-color:red}"
                                  "QPushButton:hover{"
                                  "background-color:green}"
                                  "QPushButton:pressed{"
                                  "background-color:black}");
    //全局QLabel样式
    //this->setStyleSheet("QLabel{color:rgb(0, 255, 255);"
    //                         "background-color:red;}");





}

Widget::~Widget()
{
    delete ui;
}

