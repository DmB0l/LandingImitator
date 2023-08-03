#include "graphview.h"

GraphView::GraphView(QWidget* parent) : QGraphicsView(parent)
{
    setTransformationAnchor(QGraphicsView::NoAnchor);
}
