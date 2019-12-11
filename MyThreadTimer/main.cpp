#include "mythreadtimerwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyThreadTimerWidget w;
    w.show();

    return a.exec();
}
