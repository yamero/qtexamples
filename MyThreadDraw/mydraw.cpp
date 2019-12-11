#include "mydraw.h"
#include <QPainter>
#include <QPen>
#include <QBrush>

MyDraw::MyDraw(QObject *parent) : QObject(parent)
{

}

void MyDraw::drawImage()
{
    QImage img(300, 300, QImage::Format_ARGB32); // 创建绘图设备
    QPainter p(&img); // 创建画家
    QPen pen; // 创建画笔
    pen.setStyle(Qt::SolidLine); // 设置画笔样式
    pen.setColor(Qt::green); // 设置画笔颜色
    p.setPen(pen);
    QPoint points[5] = { // 创建5个点
        QPoint(qrand() % 300, qrand() % 300),
        QPoint(qrand() % 300, qrand() % 300),
        QPoint(qrand() % 300, qrand() % 300),
        QPoint(qrand() % 300, qrand() % 300),
        QPoint(qrand() % 300, qrand() % 300)
    };
    p.drawPolygon(points, 5);
    emit drawImageDone(img);
}
