#ifndef FORGE_GAME_CLIENT_H
#define FORGE_GAME_CLIENT_H

#include <QObject>
#include <stdint.h>

class QTimer;
class QUdpSocket;
class QHostAddress;
class QString;

enum ConnectionStatus
{
    CONNECT_NONE,
    CONNECT_AUTHENTICATED,
    CONNECT_REJECTED
};

class GameClient : public QObject
{
    Q_OBJECT;

public:
    GameClient();
    ~GameClient();
    bool isConnected() const;
    bool started() const;

public slots:
    void start();
    void stop();
    bool connectToServer( const QHostAddress& server, uint16_t port );
    bool sendMessageToServer();

    void demoLogin();

private slots:
    void processDatagrams();

private:
    bool sendLoginRequest( const QHostAddress& server,
                           uint16_t severPort,
                           const QString& username,
                           const QString& password );

    bool waitForServerConnection();

signals:
    void stopping();

private:
    QTimer *m_timer;
    QUdpSocket *m_socket;
    ConnectionStatus m_connectionStatus;
    uint16_t m_clientPort;
};

#endif
