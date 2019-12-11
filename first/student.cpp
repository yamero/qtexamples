#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::doHomework()
{
    qDebug() << "学生开始做作业了";
}

void Student::doHomework(QString name)
{
    // QString打印出来的字符串会自动加上双引号，使用QString的toUtf8()将其转为QByteArray，再使用QByteArray的data()将其转为char *
    qDebug() << "学生开始做" << name.toUtf8().data();
}
