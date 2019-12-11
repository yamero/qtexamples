#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/1.png"));
    this->setWindowTitle("找美女");
    this->setFixedSize(700, 700);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/images/1.jpg");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}
