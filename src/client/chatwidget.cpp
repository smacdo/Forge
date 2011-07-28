#include "client/chatwidget.h"

#include <QtGui>

ChatWidget::ChatWidget( QWidget *parent )
    : QWidget( parent ),
      m_chatbox( new QTextEdit(this) ),
      m_inputbox( new QLineEdit(this) ),
      m_sendChatButton( new QPushButton( tr("Send"), this ) ),
      m_userList( new QListWidget(this) )
{
    QGridLayout *layout = new QGridLayout;

    layout->addWidget( m_chatbox, 0, 0, 1, 8 );
    layout->addWidget( m_userList, 0, 8, 1, 1 );
    layout->addWidget( m_inputbox, 3, 0, 1, 8 );
    layout->addWidget( m_sendChatButton, 3, 8, 1, 1 );

    //m_chatbox->setMinimumSize( 300, 175 );
    m_userList->setMaximumSize( 200, 800 );

    setLayout( layout );
    setMinimumSize( 400, 200 );
}

ChatWidget::~ChatWidget()
{
}

void ChatWidget::addChat( const QString& from, const QString& message )
{
    qDebug() << "chat from " << from << " saying: " << message;
}

void ChatWidget::returnPressed()
{
    qDebug() << "return was pressed";
}

void ChatWidget::newPlayer( const QString& username )
{
    qDebug() << "new player logged in: " << username;
}

void ChatWidget::playerLeft( const QString& username )
{
    qDebug() << "player left: " << username;
}

