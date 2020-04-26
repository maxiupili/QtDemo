#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QIODevice>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_readButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "打开文件", "../../");

    if (!path.isEmpty()) {
        QFile file(path);

        bool isOK = file.open(QIODevice::ReadOnly);

        if (isOK) {
            //默认utf8
            QByteArray arr;
            while (file.atEnd() == false) {
                arr += file.readLine();
            }
            //显示
            ui->textEdit->setText(arr);
        }
        //关闭文件对象
        file.close();

        QFileInfo info(path);

        qDebug() <<info.fileName().toUtf8().data();
        qDebug() <<info.suffix();
        qDebug() <<info.created().toString("yyyy-MM-dd hh:mm:ss");

    }

}

void Widget::on_writeButton_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, "save", "../../", "TXT(*txt)");
    if (!path.isEmpty()) {
        QFile file(path);
        bool isOK = file.open(QIODevice::WriteOnly);

        if (isOK) {
            QString str = ui->textEdit->toPlainText();
            //QString -> QByteArray
            file.write(str.toUtf8());
        }
        file.close();
    }

}
