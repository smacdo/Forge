#include "gamewindow.h"
#include "clientview.h"
#include "chatwidget.h"

#include <QMainWindow>
#include <QtGui>

GameWindow::GameWindow()
    : QMainWindow(),
      m_view( NULL ),
      m_chat( new ChatWidget(this) )
{
    build();
    statusBar()->showMessage(tr("Hi there"));
}

GameWindow::~GameWindow()
{
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
