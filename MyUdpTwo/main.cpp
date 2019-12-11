#include "myudptwowidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyUdpTwoWidget w;
    w.show();

    return a.exec();
}
