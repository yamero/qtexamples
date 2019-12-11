#include "mytcpclientwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyTcpClientWidget w;
    w.show();

    return a.exec();
}
