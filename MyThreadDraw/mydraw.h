#ifndef MYDRAW_H
#define MYDRAW_H

#include <QObject>
#include <QImage>

class MyDraw : public QObject
{
    Q_OBJECT
public:
    explicit MyDraw(QObject *parent = nullptr);
    void drawImage(); // 画图

signals:
    void drawImageDone(QImage img); // 图画好了

public slots:
};

#endif // MYDRAW_H
