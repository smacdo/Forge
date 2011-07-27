#include "gameclient.h"

#include <QDebug>
#include <QtNetwork>

void GameClient::start()
{
    qDebug() << "GameClient::start()";

    QUdpSocket *m_socket = new QUdpSocket(this);

    QByteArray datagram = "Hello there!";
    m_socket->writeDatagram( datagram.data(), datagram.size(), QHostAddress::LocalHost, 42000 );
    m_socket->close();
}

void GameClient::stop()
{
    qDebug() << "GameClient::stop()";
    emit stopping();
}
