#ifndef FORGE_CLIENT_VIEW_H
#define FORGE_CLIENT_VIEW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

class ClientView : public QWidget
{
    Q_OBJECT;

public:
    ClientView( QWidget *parent );
    virtual ~ClientView();

private:
    QGraphicsScene m_scene;
    QGraphicsView  m_view;
};

#endif
