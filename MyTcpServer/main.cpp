#include "mytcpserverwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyTcpServerWidget w;
    w.show();

    return a.exec();
}
