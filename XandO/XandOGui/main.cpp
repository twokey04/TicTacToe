#include "XandOGui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XandOGui w;
    w.show();
    return a.exec();
}
