#include "mytcpclientwidget.h"
#include "ui_mytcpclientwidget.h"

MyTcpClientWidget::MyTcpClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyTcpClientWidget)
{
    ui->setupUi(this);
    setWindowTitle("tcp客户端");
    tcpSocket = nullptr;

    tcpSocket = new QTcpSocket(this);

    connect(ui->connectBtn, &QPushButton::clicked, [=](){

        QString ip = ui->IpLineEdit->text();
        quint16 port = ui->portLineEdit->text().toUShort();
        tcpSocket->connectToHost(ip, port);

        // 监听是否连接成功
        connect(tcpSocket, &QTcpSocket::connected, [=](){
            ui->recvTextEdit->append("连接成功");
        });

        // 读消息
        connect(tcpSocket, &QTcpSocket::readyRead, [=](){
            if (tcpSocket == nullptr) {
                return;
            }
            QByteArray recvMsg = tcpSocket->readAll();
            ui->recvTextEdit->append(recvMsg);
        });

    });

    // 发消息
    connect(ui->sendBtn, &QPushButton::clicked, [=](){
        if (tcpSocket == nullptr) {
            return;
        }
        QString sendMsg = ui->sendTextEdit->toPlainText();
        tcpSocket->write(sendMsg.toUtf8().data());
    });

    // 断开并关闭连接
    connect(ui->closeBtn, &QPushButton::clicked, [=](){
        if (tcpSocket == nullptr) {
            return;
        }
        tcpSocket->disconnectFromHost();
        tcpSocket->close();
    });
}

MyTcpClientWidget::~MyTcpClientWidget()
{
    delete ui;
}
