#ifndef GRAPHITEM_H
#define GRAPHITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class GraphItemNet : public QGraphicsItem
{

public:
    const static int MAX_SIZE_FIELD = 10000;
    const static int MAX_SIZE_SQUARE = 50;

    GraphItemNet();

    GraphItemNet(QString icao24, QColor color, bool isSelectedUser);

    GraphItemNet(const GraphItemNet& other);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget* ) override;

    bool operator ==(const GraphItemNet& other);

    void operator =(const GraphItemNet& other);


    const QString &icao24() const;

    const QColor &color() const;

    void setColor(const QColor &newColor);



    bool isSelectedUser() const;
    void setIsSelectedUser(bool newIsSelectedUser);

private:
    QString m_icao24;
    QColor m_color;
    bool m_isSelectedUser = false;
};

#endif // GRAPHITEM_H
