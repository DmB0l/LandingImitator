//
// Created by alex on 10.08.2023.
//

#include "ItemEllipse.h"
#include "src/scene/MyScene.h"
#include "src/view/MyView.h"

ItemEllipse::ItemEllipse(qreal x, qreal y, qreal w, qreal h, int numberEllipse, int numberAirplane,
                         QGraphicsScene *parent) : parent(parent),
                                                   m_x(x), m_y(y),
                                                   m_w(w), m_h(h),
                                                   m_numberEllipse(numberEllipse), m_numberAirplane(numberAirplane) {
    setAcceptHoverEvents(true);
}

QRectF ItemEllipse::boundingRect() const {
    return QRectF(m_x, m_y, m_w, m_h);
}

void ItemEllipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(QPen(QBrush(m_color), 1.0, Qt::PenStyle::SolidLine));
    painter->setBrush(QBrush(Qt::red));
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawEllipse(m_x, m_y, m_w, m_h);
//    MyScene *scene = (MyScene *) parent;
//    MyView *view = (MyView *) scene->getMParent();
//    view->setDragMode(QGraphicsView::NoDrag); // отключаем режим перетаскивания
//    view->centerOn(m_x, m_y);
//    view->setDragMode(QGraphicsView::ScrollHandDrag); // включаем обратно режим перетаскивания
}

void ItemEllipse::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    MyScene *scene = (MyScene *) parent;

    ItemText *itemText = scene->getMAirplanes().at(m_numberAirplane)->getMTextVec().at(m_numberEllipse);
    itemText->setVisible(true);
    scene->update();

    QGraphicsItem::hoverEnterEvent(event);
}

void ItemEllipse::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    MyScene *scene = (MyScene *) parent;

    ItemText *itemText = scene->getMAirplanes().at(m_numberAirplane)->getMTextVec().at(m_numberEllipse);
    itemText->setVisible(false);
    scene->update();

    QGraphicsItem::hoverLeaveEvent(event);
}

void ItemEllipse::setColor(const QColor &color) {
    ItemEllipse::m_color = color;
}
