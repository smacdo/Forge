#include "client/gameclient.h"

#include <QDebug>
#include <QtNetwork>

void GameClient::start()
    : m_timer( new QTimer(this) ),
      m_socket( new QUdpSocket(this) )
{
    qDebug() << "GameClient::start()";

    connectToServer( QHostAddress::LocalHost );
    QByteArray datagram = "Hello there!";
    m_socket->writeDatagram( datagram.data(), datagram.size(), QHostAddress::LocalHost, 42000 );
    m_socket->close();
}

/**
 * Instructs the game client to connect to the requested server. Returns false if
 * impossible
 */
bool GameClient::connectToServer( const QHostAddress& server )
{
    return isConnected();
}

/**
 * Checks if the game client is connected to a game server
 */
bool GameClient::isConnected() const
{
    return m_socket->isValid();
}

void GameClient::stop()
{
    qDebug() << "GameClient::stop()";
    emit stopping();
}
