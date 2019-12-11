#include "mytimer.h"
#include <QThread>
#include <QDebug>

MyTimer::MyTimer(QObject *parent) : QObject(parent)
{

}

void MyTimer::setFlag(bool flag)
{
    this->flag = flag;
}

void MyTimer::setInterval(ulong interval)
{
    this->interval = interval;
}

void MyTimer::myTimer()
{
    while (flag) {
        qDebug() << QThread::currentThread();
        QThread::msleep(interval);
        emit myTimeout();
    }
}
