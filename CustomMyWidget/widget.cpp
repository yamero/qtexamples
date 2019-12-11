#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->getNumBtn, &QPushButton::clicked, [=](){
        int n = ui->spinSlider->getNum();
        qDebug() << n;
    });
    connect(ui->setNumBtn, &QPushButton::clicked, [=](){
        ui->spinSlider->setNum(44);
    });

    QTimer *timer = new QTimer(this);
    timer->start(1000);
    connect(timer, &QTimer::timeout, [=](){
        static int s = 1;
        ui->secondLab->setText(QString::number(s++));
    });

}

Widget::~Widget()
{
    delete ui;
}
