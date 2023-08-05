#include "GridItem.h"

GridItem::GridItem(int gridSize, int row, int col, QGraphicsItem *parent)
    : QGraphicsItem(parent), m_gridSize(gridSize), m_row(row), m_col(col) {
    setFlags(ItemIsSelectable);
}

QRectF GridItem::boundingRect() const { return QRectF(0, 0, m_gridSize, m_gridSize); }

void GridItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(Qt::black);
    painter->setBrush(Qt::white);
    painter->drawRect(boundingRect());
}

void GridItem::setSize(int size) {
    prepareGeometryChange();
    m_gridSize = size;
}
