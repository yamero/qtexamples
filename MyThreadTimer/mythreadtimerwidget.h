#ifndef MYTHREADTIMERWIDGET_H
#define MYTHREADTIMERWIDGET_H

#include <QWidget>
#include <mytimer.h>

namespace Ui {
class MyThreadTimerWidget;
}

class MyThreadTimerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyThreadTimerWidget(QWidget *parent = nullptr);
    ~MyThreadTimerWidget();
    MyTimer *myTimer;

signals:
    void startThreadTask(); // 开始执行已投递到子线程中的任务（这里是定时器任务）

private:
    Ui::MyThreadTimerWidget *ui;

};

#endif // MYTHREADTIMERWIDGET_H
