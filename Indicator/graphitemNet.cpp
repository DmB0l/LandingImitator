#include "graphitemNet.h"

GraphItemNet::GraphItemNet() {
    //    this->m_rect.setRect(-5, -6, 10, 12);
}

void GraphItemNet::setRect(double left, double top, double width,
                           double height) {
    this->m_rect.setRect(left, top, width, height);
}

QRectF GraphItemNet::boundingRect() const { return m_rect; }

void GraphItemNet::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
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
