//
// Created by alex on 10.08.2023.
//

#include "ItemEllipse.h"
#include "scene/MyScene.h"
ItemEllipse::ItemEllipse() {}

ItemEllipse::ItemEllipse(qreal x, qreal y, qreal w, qreal h, QGraphicsScene *parent) : parent(parent), m_x(x), m_y(y), m_w(w), m_h(h) {
    setAcceptHoverEvents(true);
}

QRectF ItemEllipse::boundingRect() const {
    return QRectF(m_x, m_y, m_w, m_h);
}

void ItemEllipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(QPen(QBrush(Qt::GlobalColor::red), 1.0, Qt::PenStyle::SolidLine));
    painter->setBrush(QBrush(Qt::red));
    painter->drawEllipse(m_x, m_y, m_w, m_h);

//    painter->drawText(m_x + m_w + 10, m_y + 10);
}

void ItemEllipse::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    qDebug() << m_x << m_y;
    QGraphicsItem::hoverEnterEvent(event);
}
