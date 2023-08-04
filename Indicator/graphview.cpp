#include "graphview.h"

GraphView::GraphView(QWidget* parent) : QGraphicsView(parent)
{
    setTransformationAnchor(QGraphicsView::NoAnchor);
}

void GraphView::wheelEvent(QWheelEvent* event)
{
    qreal zoomFactor = qPow(1.0015, event->angleDelta().y());
    zoom(zoomFactor);

    QPointF mousePos = mapToScene(mapFromGlobal(event->globalPos()));
    QPointF centerPos = mapToScene(viewport()->rect().center());
    QPointF delta = (mousePos - centerPos) / 4;

    translate(-delta.x(), -delta.y());
}

void GraphView::zoom(qreal factor)
{
    QPointF oldPos = mapToScene(viewport()->rect().center());

    if (transform().m22() * factor >= 0.25 && transform().m22() * factor <= 70.5)
    {
        scale(factor, factor);
    }

    QPointF newPos = mapToScene(viewport()->rect().center());

    QPointF delta = newPos - oldPos;
    translate(delta.x(), delta.y());
}

void GraphView::mouseReleaseEvent(QMouseEvent* event)
{
    QGraphicsView::mouseReleaseEvent(event);

    QPointF clickPos = mapToScene(event->pos());

//    emit clickOnField(m_zoomLevel, clickPos.x(), clickPos.y());
}
