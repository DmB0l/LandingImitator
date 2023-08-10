//
// Created by alex on 10.08.2023.
//

#include "ItemText.h"

ItemText::ItemText(qreal x, qreal y, qreal w, qreal h) : m_x(x), m_y(y), m_w(w), m_h(h) {}


QRectF ItemText::boundingRect() const {
    return QRectF(m_x, m_y, m_w, m_h);
}

void ItemText::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawText(m_x + m_w + 10, m_y + 10, "m_x: " + QString::number(m_x) + "\n m_y: " + QString::number(m_y));
    QGraphicsTextItem::paint(painter, option, widget);
}


