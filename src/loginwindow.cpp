#include "loginwindow.h"
#include <QtGui>

LoginWindow::LoginWindow( QWidget *parent )
    : m_usernameLabel( new QLabel(tr("Username"), parent) ),
      m_passwordLabel( new QLabel(tr("Password"), parent) ),
      m_serverLabel( new QLabel(tr("Server"), parent) ),
      m_username( new QLineEdit( parent ) ),
      m_password( new QLineEdit( parent ) ),
      m_server( new QLineEdit( tr("Localhost"), parent ) ),
      m_loginButton( new QPushButton(tr("&Login")) ),
      m_registerButton( new QPushButton(tr("&Register")) )
{
    // Create and hook up dialog buttons
    connect( m_loginButton, SIGNAL(clicked()), this, SLOT(login()) );
    connect( m_registerButton, SIGNAL(clicked()), this, SLOT(newaccount()) );

    // Now layout all of our widgets on the dialog
    QGridLayout *layout = new QGridLayout;

    layout->addWidget( m_usernameLabel, 0, 0 );
    layout->addWidget( m_username, 0, 1, 1, 3 );
    layout->addWidget( m_passwordLabel, 1, 0 );
    layout->addWidget( m_password, 1, 1, 1, 3 );
    layout->addWidget( m_serverLabel, 2, 0 );
    layout->addWidget( m_server, 2, 1, 1, 3 );

    layout->addWidget( m_registerButton, 3, 2 );
    layout->addWidget( m_loginButton, 3, 3 );

    setLayout( layout );

    // Finish up and pretty ourselves up
    setWindowTitle( tr("Account Login") );
    resize( 300, 150 );
}

void LoginWindow::login()
{
    qDebug() << "Login clicked";
}

void LoginWindow::newaccount()
{
    qDebug() << "New account clicked";
}
