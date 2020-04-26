#include "udpwidget.h"
#include "ui_udpwidget.h"
#include <QHostAddress>

udpWidget::udpWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::udpWidget)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);

    //绑定bind
    udpSocket->bind(8888);

    setWindowTitle("Port:8888");

    connect(udpSocket, &QUdpSocket::readyRead, this, &udpWidget::dealMsg);
}

void udpWidget::dealMsg()
{
    char buf[1024] = {0};
    QHostAddress addr;
    quint16 port;
    qint64 len =
        udpSocket->readDatagram(buf, sizeof(buf), &addr, &port);
    if (len > 0) {
        QString str = QString("[%1:%2] %3").arg(addr.toString()).arg(port).arg(buf);
        ui->textEdit->setText(str);
    }
}

udpWidget::~udpWidget()
{
    delete ui;
}




void udpWidget::on_pushButtonsend_clicked()
{
    //获取目标机信息
    QString ip = ui->lineEditIP->text();
    quint16 port = ui->lineEditPort->text().toUInt();

    QString str2 = ui->textEdit->toPlainText();

    udpSocket->writeDatagram(str2.toUtf8(),QHostAddress(ip), port);
}
