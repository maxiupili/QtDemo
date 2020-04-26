#include "chesswidget.h"
#include "ui_chesswidget.h"

chessWidget::chessWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chessWidget)
{
    ui->setupUi(this);
}

chessWidget::~chessWidget()
{
    delete ui;
}

