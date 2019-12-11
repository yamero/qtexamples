#include "myudponewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyUdpOneWidget w;
    w.show();

    return a.exec();
}
