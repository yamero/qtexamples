#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

void Widget::mouseMoveEvent(QMouseEvent *ev)
{
    ellipseX = ev->x();
    ellipseY = ev->y();
    update();
}

void Widget::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);

    p.drawLine(QPoint(10, 10), QPoint(200, 200));

    QBrush brush(Qt::Dense3Pattern);
    brush.setColor(Qt::green);
    p.setBrush(brush);
    p.drawEllipse(QPoint(ellipseX, ellipseY), 45, 45);

    QBrush brushRed(Qt::Dense1Pattern);
    brushRed.setColor(Qt::red);
    p.setBrush(brushRed);
    p.drawRect(10, 10, 200, 200);

    QPen textPen(Qt::SolidLine);
    textPen.setColor(QColor(0, 100, 200));
    p.setPen(textPen);
    p.drawText(QPoint(0, 230), QString("我不知道啊"));
}

Widget::~Widget()
{
    delete ui;
}
