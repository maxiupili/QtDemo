#ifndef TCPWIDGET_H
#define TCPWIDGET_H

#include <QWidget>
#include <QTcpServer>  //监听套接字
#include <QTcpSocket>  //通信套接字

QT_BEGIN_NAMESPACE
namespace Ui { class tcpWidget; }
QT_END_NAMESPACE

class tcpWidget : public QWidget
{
    Q_OBJECT

public:
    tcpWidget(QWidget *parent = nullptr);
    ~tcpWidget();

private slots:
    void on_send_clicked();

    void on_close_clicked();

private:
    Ui::tcpWidget *ui;

    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;

};
#endif // TCPWIDGET_H
