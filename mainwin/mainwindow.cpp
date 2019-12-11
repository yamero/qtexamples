#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QLabel>
#include <QStatusBar>
#include <QTextEdit>
#include <QDockWidget>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800, 600);

    // 菜单栏，只能有一个
    QMenuBar *bar = menuBar();
    setMenuBar(bar); // 将菜单栏添加到当前窗口中

    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");
    bar->addMenu("构建");

    fileMenu->addAction("新建");
    fileMenu->addAction("打开");
    fileMenu->addSeparator(); // 分割线
    fileMenu->addAction("另存为");

    editMenu->addAction("复制");
    editMenu->addAction("粘贴");

    // 工具栏，可以有多个
    QToolBar *toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, toolBar); // 将工具栏添加到当前窗口中，并设置默认停靠在左侧
    //toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea); // 只允许工具栏停靠在左侧和右侧
    toolBar->setFloatable(true); // 设置工具栏是否可以浮动
    toolBar->setMovable(true); // 设置工具栏是否可以移动
    toolBar->addAction("裁剪");
    QPushButton *scaleBtn = new QPushButton(this);
    scaleBtn->setText("缩放");
    toolBar->addWidget(scaleBtn);

    // 状态栏，只能有一个
    QStatusBar *staBar = statusBar();
    setStatusBar(staBar);
    QLabel *leftLab = new QLabel(this);
    leftLab->setText("显示在左边");
    staBar->addWidget(leftLab);
    QLabel *rightLab = new QLabel(this);
    rightLab->setText("显示在右边");
    staBar->addPermanentWidget(rightLab);

    // 浮动窗口，可以有多个，浮动窗口是相对于中心部件进行浮动的
    QDockWidget *dockWidget = new QDockWidget("浮动窗口", this);
    addDockWidget(Qt::BottomDockWidgetArea, dockWidget);

    // 中心部件，只能有一个
    QTextEdit *textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);
}

MainWindow::~MainWindow()
{

}
