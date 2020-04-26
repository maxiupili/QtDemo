#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QHostAddress>
#include <QString>

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);

    setWindowTitle("Client");
    tcpSocket = NULL;

    tcpSocket = new QTcpSocket(this);
    //配置通信套接字连接信号对应的槽函数
    connect(tcpSocket, &QTcpSocket::connected, [=](){
        ui->textEditread->setText("成功连接服务器");
    });
    //接受服务器发送消息触发的readyread信号的槽函数
    connect(tcpSocket, &QTcpSocket::readyRead, [=](){
        QByteArray data = tcpSocket->readAll();
        ui->textEditread->append(data);
    });

}

ClientWidget::~ClientWidget()
{
    delete ui;
}
//建立连接
void ClientWidget::on_pushButton_clicked()
{
    //ip and port
    QString ip = ui->lineEditip->text();
    qint16 port = ui->lineEditport->text().toInt();
    //本机ip 目标服务器端口号
    tcpSocket->connectToHost(QHostAddress(ip), port);
}

void ClientWidget::on_pushButtonsend_clicked()
{
    QString str = ui->textEditwrite->toPlainText();
    //将文本通过通信连接套接字传输至服务器
    tcpSocket->write(str.toUtf8().data());
}

void ClientWidget::on_pushButtonclose_clicked()
{
    //断开连接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}
