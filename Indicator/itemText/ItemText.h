//
// Created by alex on 10.08.2023.
//

#ifndef INDICATOR_ITEMTEXT_H
#define INDICATOR_ITEMTEXT_H


#include <QGraphicsTextItem>
#include <QPainter>

class ItemText : public QGraphicsTextItem {
public:
    ItemText(qreal x, qreal y, qreal w, qreal h);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
//    QString m_text = "";

    qreal m_x = 0;
    qreal m_y = 0;
    qreal m_w = 0;
    qreal m_h = 0;
};


#endif //INDICATOR_ITEMTEXT_H
