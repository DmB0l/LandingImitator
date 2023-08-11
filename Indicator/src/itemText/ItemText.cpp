//
// Created by alex on 10.08.2023.
//

#include "ItemText.h"
#include "src/scene/MyScene.h"

ItemText::ItemText(qreal x, qreal y, qreal w, qreal h, int numberAirplane) : m_x(x), m_y(y), m_w(w), m_h(h),
                                                                             m_numberAirplane(numberAirplane) {}


QRectF ItemText::boundingRect() const {
    return QRectF(m_x, m_y, m_w, m_h);
}

void ItemText::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setFont(QFont("Arial", 5));
    painter->drawText(m_x + m_w + 10, m_y + 10,
                      "x: " + QString::number(m_x - MyScene::SIZE_SQUARE - 3) + '\n' + "; y: " +
                      QString::number(m_y - MyScene::SIZE_SQUARE + 17) + '\n' + "; num: " +
                      QString::number(m_numberAirplane));
    QGraphicsTextItem::paint(painter, option, widget);
}


