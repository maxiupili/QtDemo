#include "sqlwidget.h"
#include "ui_sqlwidget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>

SQLWidget::SQLWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SQLWidget)
{
    ui->setupUi(this);

    qDebug() << QSqlDatabase::drivers();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("192.168.1.2");
    db.setUserName("root");
    db.setPassword("kankin");
    db.setDatabaseName("ncre");

    if (!db.open()) {
        QMessageBox::warning(this, "error", db.lastError().text());
        return;
    }


}

SQLWidget::~SQLWidget()
{
    delete ui;
}

