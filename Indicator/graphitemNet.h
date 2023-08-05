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

    void setRect(double left, double top, double width, double height);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *,
               QWidget *) override;

  private:
    QRect m_rect;
};

#endif // GRAPHITEM_H
