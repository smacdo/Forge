#include "gamewindow.h"
#include "clientview.h"
#include "chatwidget.h"

#include <QMainWindow>
#include <QtGui>

GameWindow::GameWindow()
    : QMainWindow(),
      m_view( NULL ),
      m_chat( new ChatWidget(this) ),
      m_fileMenu( NULL ),
      m_helpMenu( NULL ),
      m_connectAction( NULL ),
      m_quitAction( NULL ),
      m_aboutAction( NULL )
{
    build();
    statusBar()->showMessage(tr("Hi there"));

    configureActions();
    configureMenus();
}

GameWindow::~GameWindow()
{
}

void GameWindow::showlogin()
{
    qDebug() << "connect";
}

void GameWindow::close()
{
    qDebug() << "quit";
}

void GameWindow::about()
{
    qDebug() << "about";
}

void GameWindow::configureActions()
{
    m_connectAction = new QAction( tr("&Connect to server..."), this );
    m_connectAction->setShortcuts( QKeySequence::Open );
    m_connectAction->setStatusTip( tr("Connects to a forge server") );
    connect( m_connectAction, SIGNAL(triggered()), this, SLOT(showlogin()) );

    m_quitAction = new QAction( tr("&Quit"), this );
    m_quitAction->setShortcuts( QKeySequence::Quit );
    m_quitAction->setStatusTip( tr("Quits the game") );
    connect( m_quitAction, SIGNAL(triggered()), this, SLOT(close()) );

    m_aboutAction = new QAction( tr("&About"), this );
    m_aboutAction->setStatusTip( tr("Shows information about this forge client") );
    connect( m_aboutAction, SIGNAL(triggered()), this, SLOT(about()) );
}

void GameWindow::configureMenus()
{
    m_fileMenu = menuBar()->addMenu( tr("&File") );
    m_fileMenu->addAction( m_connectAction );
    m_fileMenu->addSeparator();
    m_fileMenu->addAction( m_quitAction );

    m_helpMenu = menuBar()->addMenu( tr("&Help") );
    m_helpMenu->addAction( m_aboutAction );
}

void GameWindow::build()
{
    m_view = new ClientView( this );
    setCentralWidget( m_view );

    QDockWidget *dock = new QDockWidget( tr("Chat Window"), this );
    dock->setAllowedAreas( Qt::BottomDockWidgetArea );
    dock->setWidget( m_chat );

    addDockWidget( Qt::BottomDockWidgetArea, dock );
    resize( 800, 600 );
}
