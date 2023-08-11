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
#include <QColor>
//#include "scene/MyScene.h"

class ItemEllipse : public QGraphicsItem {
public:
    ItemEllipse(qreal x, qreal y, qreal w, qreal h, int numberEllipse, int numberAirplane,
                QGraphicsScene *parent = nullptr);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void setColor(const QColor &color);

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

private:
    int m_numberAirplane = 0;
    int m_numberEllipse = 0;
    QColor m_color;

    QGraphicsScene *parent = nullptr;
    qreal m_x = 0;
    qreal m_y = 0;
    qreal m_w = 0;
    qreal m_h = 0;
};


#endif //INDICATOR_ITEMELLIPSE_H
