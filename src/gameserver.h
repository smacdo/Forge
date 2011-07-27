#ifndef FORGE_GAME_SERVER_H
#define FORGE_GAME_SERVER_H

#include <QObject>
class QTimer;
class QUdpSocket;

class GameServer : public QObject
{
    Q_OBJECT;

public:
    GameServer();
    ~GameServer();

public slots:
    void start();
    void stop();
    void runTimeslice();

private slots:
    void processDatagrams();

signals:
    void stopping();

private:
    QTimer *m_timer;
    QUdpSocket *m_socket;
    unsigned int m_slices;
};

#endif
