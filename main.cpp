#include <QApplication>
#include "connectdatabase.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connectdatabase w;
    w.show();
    //Widget w;
   // w.show();
    return a.exec();
}
