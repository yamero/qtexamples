#ifndef MYTHREADDRAWWIDGET_H
#define MYTHREADDRAWWIDGET_H

#include <QWidget>
#include <QImage>
#include <QThread>
#include "mydraw.h"

namespace Ui {
class MyThreadDrawWidget;
}

class MyThreadDrawWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyThreadDrawWidget(QWidget *parent = nullptr);
    ~MyThreadDrawWidget();
    void paintEvent(QPaintEvent *ev); // 重写绘图事件

signals:
    void startDrawThread();

private:
    Ui::MyThreadDrawWidget *ui;
    MyDraw *myDraw;
    QImage img;
    QThread *thread;
    void drawDone(QImage img); // 图画好了，进行更新
};

#endif // MYTHREADDRAWWIDGET_H
