#include "udpform.h"
#include "ui_udpform.h"

udpForm::udpForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::udpForm)
{
    ui->setupUi(this);
    udpSocket = new QUdpSocket(this);
    //QString str = "192.168.1.3";

    //QHostAddress addr = new QHostAddress(127.100.100.100);
    udpSocket->bind(QHostAddress::AnyIPv4,9999);

    setWindowTitle("Port:9999");



    connect(udpSocket, &QUdpSocket::readyRead, [=](){
        char buf[2048] = {0}; //不初始化为0 传中文时可能会出现末尾多字符的情况
        QHostAddress addr;
        quint16 port;
        qint64 len = udpSocket->readDatagram(buf, sizeof(buf), &addr, &port);

        if (len > 0) {
            ui->textEdit->setText(QString("[%1:%2] %3").arg(addr.toString()).arg(port).arg(buf));
        }
    });
}

udpForm::~udpForm()
{
    delete ui;
}

void udpForm::on_pushButton_clicked()
{
    QString ip = ui->lineEdit->text();

    quint16 port = ui->lineEdit_2->text().toUInt();

    QByteArray arr = ui->textEdit->toPlainText().toUtf8();
    udpSocket->writeDatagram(arr, QHostAddress(ip), port);
}
