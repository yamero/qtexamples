#ifndef MYTCPSERVERWIDGET_H
#define MYTCPSERVERWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class MyTcpServerWidget;
}

class MyTcpServerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyTcpServerWidget(QWidget *parent = nullptr);
    ~MyTcpServerWidget();
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;

private:
    Ui::MyTcpServerWidget *ui;
};

#endif // MYTCPSERVERWIDGET_H
