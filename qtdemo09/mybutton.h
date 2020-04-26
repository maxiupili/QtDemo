#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class myButton : public QPushButton
{
    Q_OBJECT
public:
    explicit myButton(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event);

signals:

};

#endif // MYBUTTON_H
