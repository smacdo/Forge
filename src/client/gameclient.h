#ifndef FORGE_GAME_CLIENT_H
#define FORGE_GAME_CLIENT_H

#include <QObject>

class QTimer;
class QUdpSocket;
class QHostAddress;

class GameClient : public QObject
{
    Q_OBJECT;

public:
    GameClient();
    ~GameClient();
    bool isConnected() const;

public slots:
    void start();
    void stop();
    bool connectToServer( const QHostAddress& server );

private slots:
    void processDatagrams();

signals:
    void stopping();

private:
    QTimer *m_timer;
    QUdpSocket *m_socket;
};

#endif
