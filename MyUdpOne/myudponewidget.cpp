#include "myudponewidget.h"
#include "ui_myudponewidget.h"

MyUdpOneWidget::MyUdpOneWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyUdpOneWidget)
{
    ui->setupUi(this);
    setWindowTitle("udp应用8300");

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(8300);

    connect(udpSocket, &QUdpSocket::readyRead, [=](){
        char buf[1024] = {0};
        QHostAddress addr;
        quint16 port;
        qint64 len = udpSocket->readDatagram(buf, sizeof(buf), &addr, &port);
        if (len > 0) {
            QString recvMsg = QString("[%1:%2] %3").arg(addr.toString()).arg(port).arg(buf);
            ui->recvTextEdit->append(recvMsg);
        }
    });

    connect(ui->sendBtn, &QPushButton::clicked, [=](){
        QString sendMsg = ui->sendTextEdit->toPlainText();
        QHostAddress addr(ui->ipLineEdit->text());
        quint16 port = ui->portLineEdit->text().toUShort();
        udpSocket->writeDatagram(sendMsg.toUtf8(), addr, port);
    });
}

MyUdpOneWidget::~MyUdpOneWidget()
{
    delete ui;
}
