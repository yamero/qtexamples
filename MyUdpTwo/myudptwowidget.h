#ifndef MYUDPTWOWIDGET_H
#define MYUDPTWOWIDGET_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class MyUdpTwoWidget;
}

class MyUdpTwoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyUdpTwoWidget(QWidget *parent = nullptr);
    ~MyUdpTwoWidget();
    QUdpSocket *udpSocket;

private:
    Ui::MyUdpTwoWidget *ui;
};

#endif // MYUDPTWOWIDGET_H
