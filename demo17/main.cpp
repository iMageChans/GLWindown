#include "glwindown.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLWindown w;
    w.show();

    return a.exec();
}
