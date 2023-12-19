#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LittleFibo *win = new LittleFibo;
    win -> show();
    return a.exec();
}
