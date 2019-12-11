#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals: // 信号只定义，不实现
    void homework(); // 老师无参作业信号
    void homework(QString name); // 老师有参作业信号

public slots:
};

#endif // TEACHER_H
