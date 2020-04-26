#ifndef UDPWIDGET_H
#define UDPWIDGET_H

#include <QWidget>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class udpWidget; }
QT_END_NAMESPACE

class udpWidget : public QWidget
{
    Q_OBJECT

public:
    udpWidget(QWidget *parent = nullptr);
    ~udpWidget();

    void dealMsg();

private slots:
    void on_pushButtonsend_clicked();

private:
    Ui::udpWidget *ui;
    QUdpSocket *udpSocket;
};
#endif // UDPWIDGET_H
