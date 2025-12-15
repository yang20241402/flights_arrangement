#include "PersonCenterWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    PersonCenterWindow w;
    w.show();
    return a.exec();
}
