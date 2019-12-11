#include "mywidget.h"
#include "mypushbutton.h"
#include <QPushButton>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    this->tch = new Teacher(this);
    this->stu = new Student(this);

    QPushButton *pushBtn1 = new QPushButton;
    pushBtn1->setText("发送无参信号");
    pushBtn1->setParent(this);

    QPushButton *pushBtn2 = new QPushButton;
    pushBtn2->setText("发送有参信号");
    pushBtn2->move(10, 50);
    pushBtn2->resize(100, 30);
    pushBtn2->setParent(this);

    MyPushButton *myPushBtn = new MyPushButton;
    myPushBtn->setText("点我关闭窗口");
    myPushBtn->move(200, 100);
    myPushBtn->setParent(this);

    connect(myPushBtn, &MyPushButton::clicked, this, &QWidget::close);

    // 无参信号
    void (Teacher:: *tHomework1) (void) = &Teacher::homework;
    void (Student:: *sDoHomework1) (void) = &Student::doHomework;
    connect(this->tch, tHomework1, this->stu, sDoHomework1);
//    connect(pushBtn1, &QPushButton::clicked, this, [&](){
//        emit this->tch->homework();
//    });
    // 如果connect第3个参数为当前对象(this)，槽为lambda表达式，则第三个参数可以省略
    connect(pushBtn1, &QPushButton::clicked, [=](){
        pushBtn1->setText("嘿嘿");
        emit this->tch->homework();
    });

    // 有参信号
    void (Teacher:: *tHomework2) (QString) = &Teacher::homework;
    void (Student:: *sDoHomework2) (QString) = &Student::doHomework;
    connect(this->tch, tHomework2, this->stu, sDoHomework2);
//    connect(pushBtn2, &QPushButton::clicked, this, [&](){
//        this->tch->homework("数学作业");
//    });
    connect(pushBtn2, &QPushButton::clicked, [=](){
        pushBtn2->setText("我变大了");
        pushBtn2->resize(150, 50);
        this->tch->homework("数学作业");
    });

    resize(800, 600);
    setWindowTitle("小黄片");
    //move(800, 100);
}

MyWidget::~MyWidget()
{

}
