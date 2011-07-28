#include "client/gameclient.h"

#include <QDebug>
#include <QtNetwork>

#include <cassert>

/**
 * Constructor. Initializes member variables, doesn't start anything up though
 */
GameClient::GameClient()
    : m_timer( new QTimer(this) ),
      m_socket( new QUdpSocket(this) ),
      m_connectionStatus( CONNECT_NONE ),
      m_clientPort( 20000 )
{
}

/**
 * Its a destructor... yay!!!!
 */
GameClient::~GameClient()
{
    // If we're not disconnected, do so
    if ( m_socket->isValid() )
    {
        m_socket->close();
    }
}

/**
 * Startsthe game client up. Must connect to a game server to proceed further
 */
void GameClient::start()
{
    qDebug() << "GameClient::start()";
}

/**
 * Checks if the game client is running
 */
bool GameClient::started() const
{
    return true;
}

/**
 * Instructs the game client to connect to the requested server. Returns false if
 * impossible
 */
bool GameClient::connectToServer( const QHostAddress& server, uint16_t serverPort )
{
    assert( started() );
    m_socket->bind( QHostAddress::LocalHost, m_clientPort );

    qDebug() << "[CLIENT] Established socket on " << m_clientPort;

    connect( m_socket, SIGNAL(readyRead()), this, SLOT(processDatagrams()) );

    //
    // Now try to connect to the server and see if it all works. This is pretty nasty
    // at the moment, we can sort it out later.
    //
    // Essentially we're waiting for a reply back from the network, so we're going to
    // loop for a finite amount of time to see if we succeeded in connecting and
    // authenticating to the game server.
    //
    if (! sendLoginRequest( server, serverPort, "admin", "password" ) )
    {
        qDebug() << "[CLIENT] Failed to establish connection to server";
        return false;
    }

    QFuture<bool> future =
        QtConcurrent::run( this, &GameClient::waitForServerConnection );

    if (! future.result() )
    {
        qDebug() << "[CLIENT] Failed to connect to server";
        return false;
    }

    qDebug() << "[CLIENT] Connected to server";
    return true;
}

/**
 * Sends a login request to the game server
 */
bool GameClient::sendLoginRequest( const QHostAddress& server,
                                   uint16_t serverPort,
                                   const QString& username,
                                   const QString& password )
{
    assert( m_socket->isValid() );
    assert( username.length() < 64 );
    assert( password.length() < 64 );

    QByteArray packetdata;

    // Format login request packet
    uint8_t messageType = 1;    // login request
    uint8_t usernameLen = username.length();
    uint8_t passwordLen = password.length();

    packetdata.append( reinterpret_cast<const char *>( &messageType ), sizeof(uint8_t) );
    packetdata.append( reinterpret_cast<const char *>( &m_clientPort ), sizeof(uint16_t) );
    packetdata.append( reinterpret_cast<const char *>( &usernameLen ), sizeof(uint8_t) );
    packetdata.append( username );
    packetdata.append( reinterpret_cast<const char *>( &passwordLen ), sizeof(uint8_t) );
    packetdata.append( passwordLen );

    // Now send it!
    qDebug() << "[CLIENT] sending to " << (int) serverPort;

    qint64 r = m_socket->writeDatagram( packetdata, server, serverPort );
    return ( r > 0 );
}

/**
 * Waits for the server to make reply back that we are connected and authenticated
 */
bool GameClient::waitForServerConnection()
{
    // this REALLY could be improved
    qDebug() << "[CLIENT] Waiting for server response...";

    while ( m_connectionStatus == CONNECT_NONE )
    {
        usleep( 50 );
        return false;
    }

    return m_connectionStatus == CONNECT_AUTHENTICATED;
}

/**
 * Checks if the game client is connected to a game server
 */
bool GameClient::isConnected() const
{
    return m_socket->isValid();
}

/**
 * Sends the requested message over to the server
 */
bool GameClient::sendMessageToServer()
{
    if ( started() == false || isConnected() == false )
    {
        qDebug() << "[CLIENT] Failed sending message! Not connected";
        return false;
    }

    QByteArray datagram = "Hello there!";
    m_socket->writeDatagram( datagram.data(), datagram.size(), QHostAddress::LocalHost, 42000 );

    // I hope it worked...
    return true;
}

/**
 * Deals with an incoming set of udp packets
 */
void GameClient::processDatagrams()
{
    while ( m_socket->hasPendingDatagrams() )
    {
        // read in the data packet
        QByteArray datagram;
        datagram.resize( m_socket->pendingDatagramSize() );

        m_socket->readDatagram( datagram.data(), datagram.size() );

        // now try to make heads and tails of the packet header

        // deal with it
        qDebug() << "[CLIENT] Got: " << datagram;
    }
}

void GameClient::demoLogin()
{
    connectToServer( QHostAddress::LocalHost, 42000 );
    sendMessageToServer();
}

/**
 * Stopping code
 */
void GameClient::stop()
{
    qDebug() << "GameClient::stop()";
    emit stopping();
}
