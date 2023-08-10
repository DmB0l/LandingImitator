#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QVector>

#include "itemEllipse/ItemEllipse.h"
#include "itemText/ItemText.h"

class MyScene : public QGraphicsScene {
   public:
    static const int ROW_COUNT = 50;
    static const int COLUMN_COUNT = 50;
    static const int FIELD_SIZE = 10;
    static const int SIZE_SQUARE = ROW_COUNT * FIELD_SIZE;;

    explicit MyScene(QObject *parent = nullptr);

    void createGrid();
    void drawRedEllipse(qreal x, qreal y, qreal w, qreal h);

private:
    QVector<ItemEllipse*> m_ellipseVec;
    QVector<ItemText*> m_textVec;
};

#endif  // MYSCENE_H
