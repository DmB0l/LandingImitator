#include "graphitemNet.h"

GraphItemNet::GraphItemNet()
{

}

GraphItemNet::GraphItemNet(QString icao24, QColor color, bool isSelectedUser)
{
    m_icao24 = icao24;
    m_color = color;
    m_isSelectedUser = isSelectedUser;
}

GraphItemNet::GraphItemNet(const GraphItemNet& other)
{
    m_icao24 = other.m_icao24;
    m_color = other.m_color;
    m_isSelectedUser = other.m_isSelectedUser;
}

QRectF GraphItemNet::boundingRect() const
{
    return QRectF(-5, -6, 10, 12);
}

void GraphItemNet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(QPen(Qt::black, 0.5, Qt::SolidLine, Qt::RoundCap));

    for(int i = -MAX_SIZE_FIELD; i < MAX_SIZE_FIELD; i += MAX_SIZE_SQUARE)
    {
        painter->drawLine(i, -MAX_SIZE_FIELD, i, MAX_SIZE_FIELD);
        painter->drawLine(-MAX_SIZE_FIELD, i, MAX_SIZE_FIELD, i);
    }

//    painter->drawLine(-MAX_SIZE_FIELD, 0, MAX_SIZE_FIELD, 0);
//    painter->drawLine(0, -MAX_SIZE_FIELD, 0, MAX_SIZE_FIELD);

//    painter->drawLine(-100, 0, 100, 0);
}

bool GraphItemNet::operator ==(const GraphItemNet& other)
{
    return (m_icao24 == other.m_icao24);
}

void GraphItemNet::operator =(const GraphItemNet& other)
{
    m_icao24 = other.m_icao24;
    m_color = other.m_color;
    m_isSelectedUser = other.m_isSelectedUser;
}

const QString &GraphItemNet::icao24() const
{
    return m_icao24;
}

const QColor &GraphItemNet::color() const
{
    return m_color;
}

void GraphItemNet::setColor(const QColor &newColor)
{
    m_color = newColor;
}

bool GraphItemNet::isSelectedUser() const
{
    return m_isSelectedUser;
}

void GraphItemNet::setIsSelectedUser(bool newIsSelectedUser)
{
    m_isSelectedUser = newIsSelectedUser;
}


