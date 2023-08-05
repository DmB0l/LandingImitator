#ifndef GRAPHITEM_H
#define GRAPHITEM_H

#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>

class GraphItemNet : public QGraphicsItem {

  public:
    const static int MAX_SIZE_FIELD = 10000;
    const static int MAX_SIZE_SQUARE = 50;

    GraphItemNet();

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *,
               QWidget *) override;
};

#endif // GRAPHITEM_H
