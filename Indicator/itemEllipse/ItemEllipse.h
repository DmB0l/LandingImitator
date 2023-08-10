//
// Created by alex on 10.08.2023.
//

#ifndef INDICATOR_ITEMELLIPSE_H
#define INDICATOR_ITEMELLIPSE_H

#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QTextItem>
#include <QPainter>
#include <QDebug>
//#include "itemText/ItemText.h"

class ItemEllipse : public QGraphicsItem {
public:
    ItemEllipse();
    ItemEllipse(qreal x, qreal y, qreal w, qreal h, QGraphicsScene *parent = nullptr);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

private:
    QGraphicsScene *parent = nullptr;
    QTextItem *m_textItem = nullptr;
    qreal m_x = 0;
    qreal m_y = 0;
    qreal m_w = 0;
    qreal m_h = 0;
};


#endif //INDICATOR_ITEMELLIPSE_H
