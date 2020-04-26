#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("w2");
    b4.setParent(this);
    b4.setText("切换到主窗口");

    connect(&b4, &QPushButton::released, this, &SubWidget::SendSignToW1);

    resize(400, 300);
}

void SubWidget::SendSignToW1()
{
    emit mySignal(); // 广播发送信号
    emit mySignal(100, "hello龚红杰");
}
