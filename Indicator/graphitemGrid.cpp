#include "graphitemGrid.h"

GraphItemGrid::GraphItemGrid() {}

QRectF GraphItemGrid::boundingRect() const { return QRectF(0, 0, 0, 0); }

void GraphItemGrid::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                         QWidget *) {
    painter->setPen(QPen(Qt::black, 0.5, Qt::SolidLine, Qt::RoundCap));

    for (int i = -MAX_SIZE_FIELD; i < MAX_SIZE_FIELD; i += MAX_SIZE_SQUARE) {
        if (i != 0) {
            painter->drawLine(i, -MAX_SIZE_FIELD, i, MAX_SIZE_FIELD);
            painter->drawLine(-MAX_SIZE_FIELD, i, MAX_SIZE_FIELD, i);
        } else {
            painter->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
            painter->drawLine(i, -MAX_SIZE_FIELD, i, MAX_SIZE_FIELD);
            painter->drawLine(-MAX_SIZE_FIELD, i, MAX_SIZE_FIELD, i);
            painter->setPen(QPen(Qt::black, 0.5, Qt::SolidLine, Qt::RoundCap));
        }
    }
}
