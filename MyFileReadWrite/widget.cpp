#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QString path = QFileDialog::getOpenFileName(this, "选择文件", "E:\\", "Txt (*.txt)");
        ui->lineEdit->setText(path);
        QFile f(path);
        f.open(QIODevice::ReadOnly);
        //ui->textEdit->setText(f.readAll());
        QByteArray a;
        while (!f.atEnd()) {
            a += f.readLine();
        }
        ui->textEdit->setText(a);
        f.close();
        f.open(QIODevice::Append);
        f.write("我完事了，你们呢？");
        f.close();
    });
}

Widget::~Widget()
{
    delete ui;
}
