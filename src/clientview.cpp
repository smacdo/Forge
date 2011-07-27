#include "clientview.h"
#include <QtGui>

ClientView::ClientView( QWidget *parent )
    : QWidget( parent ),
      m_scene( 0, 0, 640, 480 ),
      m_view( &m_scene, this )
{
    m_view.setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    m_view.setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    m_view.setCacheMode(QGraphicsView::CacheBackground);
    m_view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    m_view.setOptimizationFlags(QGraphicsView::DontClipPainter
                            | QGraphicsView::DontSavePainterState
                            | QGraphicsView::DontAdjustForAntialiasing);

    m_view.viewport()->setFocusProxy( this );
}

ClientView::~ClientView()
{
}
