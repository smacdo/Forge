#include "server/gameserver.h"
#include "client/gameclient.h"

#include "client/gamewindow.h"

#include <QApplication>
#include <QTimer>
#include <QHostAddress>

int main( int argc, char* argv[] )
{
    QApplication app( argc, argv );

    GameServer server;
    GameClient client;

    QTimer::singleShot( 0, &server, SLOT(start()) );
    QTimer::singleShot( 0, &client, SLOT(start()) );
    QTimer::singleShot( 1, &client, SLOT(demoLogin()) );

    QObject::connect( &server, SIGNAL(stopping()), &app, SLOT(quit()) );

    GameWindow window;
    window.show();

    client.connectToServer( QHostAddress::LocalHost, 42000 );
    client.sendMessageToServer();

    app.exec();
    client.stop();
}
