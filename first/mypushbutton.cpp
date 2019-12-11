#include "mypushbutton.h"
#include <QPushButton>
#include <QDebug>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug() << "MyPushButton的构造函数被调用了";
}

MyPushButton::~MyPushButton()
{
    qDebug() << "MyPushButton的析构函数被调用了";
}
