#include "graphitem.h"

GraphItem::GraphItem()
{

}

GraphItem::GraphItem(QString icao24, QColor color, bool isSelectedUser)
{
    m_icao24 = icao24;
    m_color = color;
    m_isSelectedUser = isSelectedUser;
}

GraphItem::GraphItem(const GraphItem& other)
{
    m_icao24 = other.m_icao24;
    m_color = other.m_color;
    m_isSelectedUser = other.m_isSelectedUser;
}

QRectF GraphItem::boundingRect() const
{
    return QRectF(-5, -6, 10, 12);
}

void GraphItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));

    painter->drawLine(-1000, 0, 1000, 0);
    painter->drawLine(0, -1000, 0, 1000);
}

bool GraphItem::operator ==(const GraphItem& other)
{
    return (m_icao24 == other.m_icao24);
}

void GraphItem::operator =(const GraphItem& other)
{
    m_icao24 = other.m_icao24;
    m_color = other.m_color;
    m_isSelectedUser = other.m_isSelectedUser;
}

const QString &GraphItem::icao24() const
{
    return m_icao24;
}

const QColor &GraphItem::color() const
{
    return m_color;
}

void GraphItem::setColor(const QColor &newColor)
{
    m_color = newColor;
}

bool GraphItem::isSelectedUser() const
{
    return m_isSelectedUser;
}

void GraphItem::setIsSelectedUser(bool newIsSelectedUser)
{
    m_isSelectedUser = newIsSelectedUser;
}


