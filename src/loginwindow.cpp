#include "loginwindow.h"
#include <QtGui>

LoginWindow::LoginWindow( QWidget *parent )
    : m_usernameLabel( new QLabel(tr("Username"), parent) ),
      m_passwordLabel( new QLabel(tr("Password"), parent) ),
      m_serverLabel( new QLabel(tr("Server"), parent) ),
      m_username( new QLineEdit( parent ) ),
      m_password( new QLineEdit( parent ) ),
      m_server( new QLineEdit( tr("localhost"), parent ) ),
      m_loginButton( new QPushButton(tr("&Login")) ),
      m_registerButton( new QPushButton(tr("&Register")) ),
      m_registerRequested( false ),
      m_serverAddress( QHostAddress::LocalHost )
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
    m_loginButton->setDefault( true );

    setWindowTitle( tr("Account Login") );
    resize( 300, 150 );
}

void LoginWindow::login()
{
    // Make sure they provided a username and password
    if ( m_username->text().length() == 0 ||
         m_password->text().length() == 0 ||
         m_server->text().length()   == 0 )
    {
        QMessageBox::warning( this, tr("Account Login"),
                              tr("You must provide account details to log in") );
        return;
    }

    // Is this a valid hostname? Recogonize localhost as a special name
    if ( m_server->text() == "localhost" )
    {
        m_serverAddress = QHostAddress( QHostAddress::LocalHost );
    }
    else if (! m_serverAddress.setAddress( m_server->text() ) )
    {
        QMessageBox::warning( this, tr("Account Login"),
                              tr("The server address is invalid") );
        return;
    }

    // Looks good!
    accept();
}

void LoginWindow::newaccount()
{
    m_registerRequested = true;
    reject();
}

bool LoginWindow::wasRegisterRequested() const
{
    return m_registerRequested;
}

QString LoginWindow::username() const
{
    return m_username->text();
}

QString LoginWindow::password() const
{
    return m_password->text();
}

QHostAddress LoginWindow::server() const
{
    return m_serverAddress;
}
