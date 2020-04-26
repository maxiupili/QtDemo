#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTimerEvent>
#include <QEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class myWidget; }
QT_END_NAMESPACE

class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = nullptr);
    ~myWidget();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void timerEvent(QTimerEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event) override;
    //bool event(QEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::myWidget *ui;

    int timeID;
    int timeID2;
};
#endif // MYWIDGET_H
