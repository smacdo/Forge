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
    qDebug() << "GameServer::start";

    m_socket->bind( 42000, QUdpSocket::ShareAddress );
    connect( m_socket, SIGNAL(readyRead()), this, SLOT(processDatagrams()) );

    connect( m_timer, SIGNAL(timeout()), this, SLOT(runTimeslice()) );
    m_timer->start( 1000 );
}

void GameServer::processDatagrams()
{
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

        // deal with it
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
