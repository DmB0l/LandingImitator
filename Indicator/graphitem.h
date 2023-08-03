#ifndef GRAPHITEM_H
#define GRAPHITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class GraphItem : public QGraphicsItem
{
public:
    GraphItem();

    GraphItem(QString icao24, QColor color, bool isSelectedUser);

    GraphItem(const GraphItem& other);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget* ) override;

    bool operator ==(const GraphItem& other);

    void operator =(const GraphItem& other);


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
