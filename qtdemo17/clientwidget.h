#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QFile>

namespace Ui {
class clientWidget;
}

class clientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit clientWidget(QWidget *parent = nullptr);
    ~clientWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::clientWidget *ui;
    QTcpSocket *tcpSocket;
    QFile file;
    QString fileName;
    qint64 fileSize;
    qint64 recvSize;
    bool flag;
};

#endif // CLIENTWIDGET_H
