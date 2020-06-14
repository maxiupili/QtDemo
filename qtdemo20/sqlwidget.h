#ifndef SQLWIDGET_H
#define SQLWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class SQLWidget; }
QT_END_NAMESPACE

class SQLWidget : public QWidget
{
    Q_OBJECT

public:
    SQLWidget(QWidget *parent = nullptr);
    ~SQLWidget();

private:
    Ui::SQLWidget *ui;
};
#endif // SQLWIDGET_H
