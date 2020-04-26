#include "tcpwidget.h"
#include "ui_tcpwidget.h"

tcpWidget::tcpWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::tcpWidget)
{
    ui->setupUi(this);

    tcpServer = NULL;
    tcpSocket = NULL;
    //指定父对象 自动释放
    tcpServer = new QTcpServer(this);
    //监听任何地址发来的连接请求，服务器端口号8888
    tcpServer->listen(QHostAddress::Any, 8888);
    setWindowTitle("Server : 8888");
    //触发连接信号对应的槽方法
    connect(tcpServer, &QTcpServer::newConnection, [=](){
        //取出建立好连接的套接字
        tcpSocket = tcpServer->nextPendingConnection();
        //获取客户端信息
        QString ip = tcpSocket->peerAddress().toString();

        qint16 port = tcpSocket->peerPort();

        QString tmp = QString("[%1:%2]:连接成功").arg(ip).arg(port);

        ui->textEditread->setText(tmp);

        connect(tcpSocket, &QTcpSocket::readyRead, [=]() {
            //从通信套接字中取出客户端发来的信息
            QByteArray data = tcpSocket->readAll();
            ui->textEditread->append(data);
        });

    });


}

tcpWidget::~tcpWidget()
{
    delete ui;
}


void tcpWidget::on_send_clicked()
{
    if (tcpSocket == NULL) {
        return;
    }
    QString str = ui->textEditwrite->toPlainText();
    //QString  ->
    tcpSocket->write(str.toUtf8().data());
}

void tcpWidget::on_close_clicked()
{
    if (tcpSocket == NULL) {
        return;
    }
    //先断开通信连接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpSocket = NULL;
}
