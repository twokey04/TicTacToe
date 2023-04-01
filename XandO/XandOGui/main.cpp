#include "XandOGui.h"
#include "XandODifficultyWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XandODifficultyWindow w;
    w.show();
    return a.exec();
}
