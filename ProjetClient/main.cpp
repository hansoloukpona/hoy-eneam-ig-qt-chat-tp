#include <QApplication>
#include "textusconnection.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TextUsConnection Oconnect;
    Oconnect.show();

    return app.exec();
}
