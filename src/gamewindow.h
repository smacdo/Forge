#ifndef FORGE_GAMEWINDOW_H
#define FORGE_GAMEWINDOW_H

#include <QMainWindow>

class QString;
class ClientView;
class ChatWidget;

class GameWindow : public QMainWindow
{
    Q_OBJECT;

public:
    GameWindow();
    virtual ~GameWindow();

private slots:
    void build();

private:
    ClientView *m_view;
    ChatWidget *m_chat;
};

#endif
