#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QHostAddress>
#include <QDebug>
#include <QFileDevice>
#include <QFileInfo>

serverWidget::serverWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::serverWidget)
{
    ui->setupUi(this);

    ui->pushButton_send->setEnabled(false);
    ui->pushButton_choose->setEnabled(false);

    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any, 8888);
    setWindowTitle("服务器端口：8888");

    connect(tcpServer, &QTcpServer::newConnection,[=](){
        tcpSocket = tcpServer->nextPendingConnection();

        QString ip = tcpSocket->peerAddress().toString();
        quint16 port = tcpSocket->peerPort();

        QString str = QString("[%1:%2] 连接成功").arg(ip).arg(port);
        ui->textEdit->setText(str);

        ui->pushButton_choose->setEnabled(true);

    });

    connect(&timer, &QTimer::timeout, [=](){
        timer.stop();
        sendData();
    });
}

serverWidget::~serverWidget()
{
    delete ui;
}


void serverWidget::on_pushButton_choose_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this, "open", "../");
    if (filepath.isEmpty()) {
        qDebug() << "打开文件出错";
    } else {
        fileName.clear();
        fileSize = 0;

        QFileInfo info(filepath);
        fileName = info.fileName();
        fileSize = info.size();

        sendSize = 0;

        file.setFileName(filepath);

        if (file.open(QIODevice::ReadOnly) == false) {
            qDebug() << "只读打开文件失败";
        }

        ui->textEdit->append(filepath);
        ui->pushButton_send->setEnabled(true);
        ui->pushButton_choose->setEnabled(false);
    }
}

void serverWidget::on_pushButton_send_clicked()
{
    QString head = QString("%1##%2").arg(fileName).arg(fileSize);

    qint64 len = tcpSocket->write(head.toUtf8());
    if (len > 0) {
        timer.start(20);
    } else {
        qDebug() << "头部发送失败";
        file.close();
        ui->pushButton_send->setEnabled(false);
        ui->pushButton_choose->setEnabled(true);
    }

}

void serverWidget::sendData()
{
    qint64 len;
    do {
        char buf[4 * 1024] = {0};
        len = 0;
        len = file.read(buf, sizeof(buf));
        len = tcpSocket->write(buf, len);
        sendSize += len;
    } while (len > 0);

    if (sendSize == fileSize) {
        ui->textEdit->append("文件发送成功");
        file.close();
        tcpSocket->disconnectFromHost();
        tcpSocket->close();
    }
}

