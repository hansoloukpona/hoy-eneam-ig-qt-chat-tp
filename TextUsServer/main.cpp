#include "textusserver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextUsServer w;
    w.show();

    return a.exec();
}
