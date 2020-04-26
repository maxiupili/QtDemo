#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(400,300);
    //菜单栏
    QMenuBar *mb = menuBar();
    //添加菜单
    QMenu *pFile = mb->addMenu("File");
    //添加菜单项
    QAction *pNew = pFile->addAction("new");
    connect(pNew, &QAction::triggered,
           [=]()
    {
        qDebug() << "new被按下";
    });
    pFile->addSeparator(); //添加分割线
    QAction *pOpen = pFile->addAction("open");
    //工具栏
    QToolBar *toolBar = addToolBar("toolBar");
    toolBar->addAction(pNew);

    QPushButton *b = new QPushButton(this);
    b->setText("^_^");
    toolBar->addWidget(b);

    connect(b, &QPushButton::released, [=](){
        b->setText("@_@");
    });


    //状态栏
    QStatusBar *stBar = statusBar();
    QLabel *la = new QLabel(this);
    la->setText(" Normal Test File");
    //从状态栏左往右
    stBar->addWidget(la);
    stBar->addWidget(new QLabel("xxxx", this));
    //从右往左
    stBar->addPermanentWidget(new QLabel("right", this));


    //核心控件
    QTextEdit *tEdit = new QTextEdit(this);
    setCentralWidget(tEdit);


    //浮动窗口
    QDockWidget *dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    QTextEdit *tEdit1 = new QTextEdit(this);
    dock->setWidget(tEdit1);
}

MainWindow::~MainWindow()
{
}

