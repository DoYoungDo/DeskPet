#ifndef TRAYICON_H
#define TRAYICON_H

#include <QSystemTrayIcon>

class TrayIcon : public QSystemTrayIcon
{
    Q_OBJECT
public:
    explicit TrayIcon(QObject *parent = nullptr);

private:
    void setup();
};

#endif // TRAYICON_H
