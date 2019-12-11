#include "mythreadtimerwidget.h"
#include "ui_mythreadtimerwidget.h"
#include <QThread>
#include <QDebug>

MyThreadTimerWidget::MyThreadTimerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyThreadTimerWidget)
{
    ui->setupUi(this);

    myTimer = new MyTimer; // 实例化自己写的定时器类
    QThread *thread = new QThread(this); // 创建一个子线程
    myTimer->moveToThread(thread); // 将定时器类投递到子线程中，注意，这时子线程还没有启动

    connect(myTimer, &MyTimer::myTimeout, [=](){ // 监听定时器类的myTimeout信号
        static int i = 0;
        ui->lcdNumber->display(i++);
    });

    connect(ui->startPushButton, &QPushButton::clicked, [=](){ // 监听开始按钮点击信号
        if (thread->isRunning()) { // 如果子线程正在运行，则直接返回
            return;
        }
        qDebug() << QThread::currentThread();
        myTimer->setFlag(true);
        myTimer->setInterval(500); // 设置时间间隔，毫秒
        thread->start(); // 启动子线程
        emit startThreadTask(); // 触发自定义的信号
    });

    connect(this, &MyThreadTimerWidget::startThreadTask, myTimer, &MyTimer::myTimer); // 监听自定义信号

    connect(ui->stopPushButton, &QPushButton::clicked, [=](){ // 监听停止按钮点击信号
        if (!thread->isRunning()) { // 如果子线程已停止运行，则直接返回
            return;
        }
        myTimer->setFlag(false);
        thread->quit(); // 平滑结束子线程
        thread->wait(); // 等待子线程任务处理完毕再结束子线程
        delete myTimer; // 这个对象没有指定父对象，手动释放一下
    });

    connect(this, &QWidget::destroyed, [=](){ // 监听窗口销毁信号
        if (!thread->isRunning()) { // 如果子线程已停止运行，则直接返回
            return;
        }
        myTimer->setFlag(false);
        thread->quit(); // 平滑结束子线程
        thread->wait(); // 等待子线程任务处理完毕再结束子线程
        delete myTimer; // 这个对象没有指定父对象，手动释放一下
    });
}

MyThreadTimerWidget::~MyThreadTimerWidget()
{
    delete ui;
}
