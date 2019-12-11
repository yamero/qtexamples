#include "mywidget.h"
#include "ui_mywidget.h"
#include <QEvent>
#include <QMouseEvent>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    setMouseTracking(true);

    ui->setupUi(this);

    // 由于QSpinBox的valueChanged信号有重载，所以要明确指出连接哪个信号
    void (QSpinBox:: *spinBoxValueChange) (int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, spinBoxValueChange, ui->horizontalSlider, &QSlider::setValue);

    // 由于QSlider的valueChanged信号只有一个，没有重载，所以直接连接就可以
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

void MyWidget::setNum(int n)
{
    ui->spinBox->setValue(n);
}

int MyWidget::getNum()
{
    return ui->spinBox->value();
}

void MyWidget::enterEvent(QEvent *)
{
    qDebug() << "鼠标插进来了，啊，好疼！";
}

void MyWidget::leaveEvent(QEvent *)
{
    qDebug() << "鼠标拔出去了，啊，好失落!";
}

void MyWidget::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton) {
        qDebug() << "鼠标左键插进来了，啊，好棒！";
    } else if (ev->button() == Qt::RightButton) {
        qDebug() << "鼠标右键插进来了，啊，好痒！";
    }
}

void MyWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton) {
        qDebug() << "鼠标左键拔出来了，啊，好棒！";
    } else if (ev->button() == Qt::RightButton) {
        qDebug() << "鼠标右键拔出来了，啊，好痒！";
    }
}

void MyWidget::mouseMoveEvent(QMouseEvent *ev)
{
    QString str = QString("X:%1 Y:%2").arg(ev->x()).arg(ev->y());
    qDebug() << str.toUtf8().data();
}

bool MyWidget::event(QEvent *e)
{
    if (e->type() == QEvent::MouseButtonPress) { // 处理鼠标按下事件
        QMouseEvent *ev = static_cast<QMouseEvent *>(e);
        if (ev->button() == Qt::LeftButton) {
            qDebug() << "分发器鼠标左键插进来了，啊，好棒！";
        } else if (ev->button() == Qt::RightButton) {
            qDebug() << "分发器鼠标右键插进来了，啊，好痒！";
        }
        return true;
    }
    return QWidget::event(e); // 其他事件交给父类去处理
}

MyWidget::~MyWidget()
{
    delete ui;
}
