#include <QtGui/QApplication>
#include "qcalculadora.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCalculadora w;
    w.show();
    
    return a.exec();
}
