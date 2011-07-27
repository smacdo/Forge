#ifndef FORGE_GAME_CLIENT_H
#define FORGE_GAME_CLIENT_H

#include <QObject>

class GameClient : public QObject
{
    Q_OBJECT;

public slots:
    void start();
    void stop();

signals:
    void stopping();
};

#endif
