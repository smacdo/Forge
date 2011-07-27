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

public slots:
    void showlogin();
    void close();
    void about();

private:
    void build();
    void configureActions();
    void configureMenus();

private:
    ClientView *m_view;
    ChatWidget *m_chat;
    QMenu      *m_fileMenu;
    QMenu      *m_helpMenu;
    QAction    *m_connectAction;
    QAction    *m_quitAction;
    QAction    *m_aboutAction;
};

#endif
