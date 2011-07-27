#ifndef FORGE_GAMEWINDOW_H
#define FORGE_GAMEWINDOW_H

#include <QMainWindow>

class QString;
class QTextEdit;
class QLineEdit;
class QButton;
class QListWidget;
class ClientView;

class GameWindow : public QMainWindow
{
    Q_OBJECT;

public:
    GameWindow();
    virtual ~GameWindow();

public slots:
    void addChat( const QString& from, const QString& message );

private slots:
    void returnPressed();
    void newPlayer( const QString& username );
    void playerLeft( const QString& username );
    void build();

private:
    ClientView *m_view;
    QTextEdit  *m_chatbox;
    QLineEdit  *m_inputbox;
    QButton    *m_sendChatButton;
    QListWidget *m_userList;
};

#endif
