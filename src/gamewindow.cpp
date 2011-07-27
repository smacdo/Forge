#include "gamewindow.h"
#include "clientview.h"

#include <QMainWindow>
#include <QtGui>

GameWindow::GameWindow()
    : QMainWindow(),
      m_view( NULL ),
      m_chatbox( NULL ),
      m_inputbox( NULL ),
      m_sendChatButton( NULL ),
      m_userList( NULL )
{
    build();
    statusBar()->showMessage(tr("Hi there"));
}

GameWindow::~GameWindow()
{
}

void GameWindow::addChat( const QString& from, const QString& message )
{
    qDebug() << "chat from " << from << " saying: " << message;
}

void GameWindow::returnPressed()
{

}

void GameWindow::newPlayer( const QString& username )
{
    qDebug() << "new player logged in: " << username;
}

void GameWindow::playerLeft( const QString& username )
{
    qDebug() << "player left: " << username;
}

void GameWindow::build()
{
    m_view = new ClientView( this );
    m_chatbox = new QTextEdit( this );

    setCentralWidget( m_view );

   // QGridLayout *layout = new QGridLayout;

    QDockWidget *dock = new QDockWidget( tr("Chat Window"), this );
    dock->setAllowedAreas( Qt::BottomDockWidgetArea );
    dock->setWidget( m_chatbox );

    addDockWidget( Qt::BottomDockWidgetArea, dock );
 //   layout->addWidget( m_view, 0, 0, 3, 5 );
    // layout->addWidget( m_chatbox, 3, 0, 1, 3 );
    // layout->addWidget( m_inputbox, 4, 0, 1, 3 );

    // setLayout( layout );
    resize( 800, 600 );
}
