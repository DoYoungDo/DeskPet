#include "trayicon.h"

#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TrayIcon icon;
    icon.show();

    return a.exec();
}
