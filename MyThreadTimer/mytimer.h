#ifndef MYTIMER_H
#define MYTIMER_H

#include <QObject>

class MyTimer : public QObject
{
    Q_OBJECT
public:
    explicit MyTimer(QObject *parent = nullptr);
    void myTimer();
    void setFlag(bool flag);
    void setInterval(ulong interval);

signals:
    void myTimeout();

public slots:

private:
    bool flag;
    ulong interval;
};

#endif // MYTIMER_H
