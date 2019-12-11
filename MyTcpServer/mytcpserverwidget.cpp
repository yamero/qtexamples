#include "mytcpserverwidget.h"
#include "ui_mytcpserverwidget.h"

MyTcpServerWidget::MyTcpServerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyTcpServerWidget)
{
    ui->setupUi(this);

    this->setWindowTitle("tcp服务端");
    tcpServer = nullptr;
    tcpSocket = nullptr;

    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any, 8200);

    // 监听客户端连接
    connect(tcpServer, &QTcpServer::newConnection, [=](){

        tcpSocket = tcpServer->nextPendingConnection();
        QString ip = tcpSocket->peerAddress().toString();
        quint16 port = tcpSocket->peerPort();
        QString str = QString("客户端：%1 端口：%2 已连接进来").arg(ip).arg(port);
        ui->receiveTextBox->append(str);

        // 读消息
        connect(tcpSocket, &QTcpSocket::readyRead, [=](){
            if (tcpSocket == nullptr) {
                return;
            }
            QByteArray recvMsg = tcpSocket->readAll();
            ui->receiveTextBox->append(recvMsg);
        });

    });

    // 发消息
    connect(ui->sendBtn, &QPushButton::clicked, [=](){
        if (tcpSocket == nullptr) {
            return;
        }
        QString sendMsg = ui->sendTextBox->toPlainText();
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

MyTcpServerWidget::~MyTcpServerWidget()
{
    delete ui;
}
