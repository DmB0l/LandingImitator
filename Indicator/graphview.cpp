#include "graphview.h"

GraphView::GraphView(QWidget *parent) : QGraphicsView(parent) {
    setTransformationAnchor(QGraphicsView::NoAnchor);
}

void GraphView::wheelEvent(QWheelEvent *event) {
    qreal zoomFactor = qPow(1.0015, event->angleDelta().y());
    if (transform().m22() * zoomFactor >= 0.1 &&
        transform().m22() * zoomFactor <= 7.5) {
        scale(zoomFactor, zoomFactor);
    }
}
