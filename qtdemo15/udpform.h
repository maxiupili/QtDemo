#ifndef UDPFORM_H
#define UDPFORM_H
#include <QUdpSocket>
#include <QHostAddress>

#include <QWidget>

namespace Ui {
class udpForm;
}

class udpForm : public QWidget
{
    Q_OBJECT

public:
    explicit udpForm(QWidget *parent = nullptr);
    ~udpForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::udpForm *ui;
    QUdpSocket *udpSocket;
};

#endif // UDPFORM_H
