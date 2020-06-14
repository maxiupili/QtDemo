#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QDebug>
#include <QMessageBox>
#include <QHostAddress>

clientWidget::clientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientWidget)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    tcpSocket = new QTcpSocket(this);
    flag = true;
    connect(tcpSocket, &QTcpSocket::readyRead, [=](){

        QByteArray buf = tcpSocket->readAll();
        if (flag == true) {
            fileName = QString(buf).section("##", 0, 0);
            fileSize = QString(buf).section("##", 1, 1).toInt();
            recvSize = 0;
            ui->progressBar->setMinimum(0);

            ui->progressBar->setMaximum(fileSize / 1024);
            file.setFileName(fileName);
            if (file.open(QIODevice::WriteOnly) == false) {
                qDebug() << "打开只写文件失败";
            }
            flag = false;
        } else {
            qint64 len = file.write(buf);
            recvSize += len;
            ui->progressBar->setValue(recvSize / 1024);
            if (recvSize == fileSize) {
                file.close();
                QMessageBox::information(this, "完成", "文件接收完成");
                flag = true;
                tcpSocket->disconnectFromHost();
                tcpSocket->close();

            }
        }
    });
}

clientWidget::~clientWidget()
{
    delete ui;
}

void clientWidget::on_pushButton_clicked()
{
    QString ip = ui->lineEdit->text();
    quint16 port = ui->lineEdit_2->text().toUInt();

    tcpSocket->connectToHost(QHostAddress(ip), port);
}
