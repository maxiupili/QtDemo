#ifndef CHESSWIDGET_H
#define CHESSWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class chessWidget; }
QT_END_NAMESPACE

class chessWidget : public QWidget
{
    Q_OBJECT

public:
    chessWidget(QWidget *parent = nullptr);
    ~chessWidget();

private:
    Ui::chessWidget *ui;
};
#endif // CHESSWIDGET_H
