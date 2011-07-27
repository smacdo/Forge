#include "gameserver.h"
#include "gameclient.h"

#include "gamewindow.h"

#include <QApplication>
#include <QTimer>

int main( int argc, char* argv[] )
{
    QApplication app( argc, argv );

    GameServer server;
    GameClient client;

//    QTimer::singleShot( 0, &server, SLOT(start()) );
//    QTimer::singleShot( 0, &client, SLOT(start()) );

    QObject::connect( &server, SIGNAL(stopping()), &app, SLOT(quit()) );

    GameWindow window;
    window.show();

    app.exec();
    client.stop();
}
