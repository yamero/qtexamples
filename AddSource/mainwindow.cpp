#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->actionnew->setIcon(QIcon("E:/QtProject/AddSource/images/1.png"));
    ui->actionnew->setIcon(QIcon(":/icon/images/1.png"));
    ui->actionopen->setIcon(QIcon(":/icon/images/3.png"));
    ui->actionsave->setIcon(QIcon(":/icon/images/2.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
