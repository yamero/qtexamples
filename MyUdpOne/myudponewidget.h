#ifndef MYUDPONEWIDGET_H
#define MYUDPONEWIDGET_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class MyUdpOneWidget;
}

class MyUdpOneWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyUdpOneWidget(QWidget *parent = nullptr);
    ~MyUdpOneWidget();
    QUdpSocket *udpSocket;

private:
    Ui::MyUdpOneWidget *ui;
};

#endif // MYUDPONEWIDGET_H
