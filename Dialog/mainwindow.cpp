#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionnew, &QAction::triggered, [=](){

//        QDialog dlg(this); // 保存在栈区
//        dlg.resize(200, 100);
//        dlg.exec();
//        qDebug() << "模态对话框弹出了";

//        QDialog *dlg = new QDialog(this); // 保存在堆区
//        dlg->setAttribute(Qt::WA_DeleteOnClose);
//        dlg->resize(200, 100);
//        dlg->show();
//        qDebug() << "非模态对话框弹出了";

//        int ret = QMessageBox::question(this, "那么问题了", "你是同性恋吗？", QMessageBox::Yes | QMessageBox::No);
//        if (ret == QMessageBox::Yes) {
//            QMessageBox::information(this, "提示一下", "好吧，请与我保持距离");
//        } else {
//            QMessageBox::information(this, "拥抱一下", "お前、本当は変態だろう");
//        }

//        QColor color = QColorDialog::getColor(QColor(0, 255, 0), this);
//        qDebug() << color.red() << color.green() << color.blue();

//        QString fileName = QFileDialog::getOpenFileName(this, "选择文件吧", "e:\\", "Image (*.jpg *.png *.gif);;Header (*.h);;Source (*.cpp)");
//        qDebug() << fileName;

        bool ok;
        QFont font = QFontDialog::getFont(&ok, QFont("Arial", 20), this);
        if (ok) {
            qDebug() << font.family() << font.pointSize() << font.weight() << font.italic();
        } else { // 点了取消或选择了初始QFont

        }

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
