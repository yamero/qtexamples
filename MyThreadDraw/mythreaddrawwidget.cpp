#include "mythreaddrawwidget.h"
#include "ui_mythreaddrawwidget.h"
#include <QPainter>

MyThreadDrawWidget::MyThreadDrawWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyThreadDrawWidget)
{
    ui->setupUi(this);

    myDraw = new MyDraw;
    thread = new QThread(this);
    myDraw->moveToThread(thread);

    connect(ui->drawPushButton, &QPushButton::clicked, myDraw, &MyDraw::drawImage);

    connect(myDraw, &MyDraw::drawImageDone, this, &MyThreadDrawWidget::drawDone);

    connect(this, &QWidget::destroyed, [=](){
        if (!thread->isRunning()) {
            return;
        }
        thread->quit();
        thread->wait();
        delete myDraw; // 这个对象没有指定父对象，手动释放一下
    });

    thread->start();
}

void MyThreadDrawWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawImage(50, 50, img);
}

void MyThreadDrawWidget::drawDone(QImage img)
{
    this->img = img;
    update();
}

MyThreadDrawWidget::~MyThreadDrawWidget()
{
    delete ui;
}
