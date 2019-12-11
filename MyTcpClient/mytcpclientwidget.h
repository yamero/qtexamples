#ifndef MYTCPCLIENTWIDGET_H
#define MYTCPCLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class MyTcpClientWidget;
}

class MyTcpClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyTcpClientWidget(QWidget *parent = nullptr);
    ~MyTcpClientWidget();
    QTcpSocket *tcpSocket;

private:
    Ui::MyTcpClientWidget *ui;
};

#endif // MYTCPCLIENTWIDGET_H
