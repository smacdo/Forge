#include "server/gameserver.h"

#include <QTimer>
#include <QDebug>
#include <QtNetwork>

GameServer::GameServer()
    : m_timer( new QTimer(this) ),
      m_socket( new QUdpSocket(this) ),
      m_slices( 0 )
{
}

GameServer::~GameServer()
{
    delete m_timer;
    delete m_socket;
}

void GameServer::start()
{
    int m_port = 42000;
    qDebug() << "GameServer::start";

    m_socket->bind( QHostAddress::LocalHost, m_port );
    connect( m_socket, SIGNAL(readyRead()), this, SLOT(processDatagrams()) );

    qDebug() << "[SERVER] Established socket on " << m_port;

    connect( m_timer, SIGNAL(timeout()), this, SLOT(runTimeslice()) );

    qDebug() << "[SERVER] Ready and waiting";
}

void GameServer::processDatagrams()
{
    qDebug() << "[SERVER] got stuff";

    //
    // process ALL the datagrams!!!!!!
    //
    while ( m_socket->hasPendingDatagrams() )
    {
        // read in the data packet
        QByteArray datagram;
        datagram.resize( m_socket->pendingDatagramSize() );

        m_socket->readDatagram( datagram.data(), datagram.size() );

        // now try to make heads and tails of the packet header
        const char* data = datagram.data();
        uint8_t messageType = *( reinterpret_cast<const uint8_t*>( &data[0] ) );

        qDebug() << "[SERVER] id was " << (int) messageType;

        // deal with it
        qDebug() << "[SERVER] Got: " << datagram;
    }
}

void GameServer::runTimeslice()
{
    qDebug() << "GameServer::slice()";

    if ( m_slices > 3 )
    {
        stop();
    }
    else
    {
        m_slices++;
    }
}

void GameServer::stop()
{
    qDebug() << "GameServer::stop";
    m_timer->stop();
    m_socket->close();
    emit stopping();
}
