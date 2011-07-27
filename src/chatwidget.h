#ifndef FORGE_CHAT_WIDGET_H
#define FORGE_CHAT_WIDGET_H

#include <QWidget>

class QTextEdit;
class QLineEdit;
class QPushButton;
class QListWidget;

class ChatWidget : public QWidget
{
    Q_OBJECT;

public:
    ChatWidget( QWidget *parent );
    virtual ~ChatWidget();


public slots:
    void addChat( const QString& from, const QString& message );

private slots:
    void returnPressed();
    void newPlayer( const QString& username );
    void playerLeft( const QString& username );

private:
    QTextEdit   *m_chatbox;
    QLineEdit   *m_inputbox;
    QPushButton *m_sendChatButton;
    QListWidget *m_userList;
};

#endif
