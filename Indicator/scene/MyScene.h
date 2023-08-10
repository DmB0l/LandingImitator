#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>


class MyScene : public QGraphicsScene {
   public:
    static const int ROW_COUNT = 50;
    static const int COLUMN_COUNT = 50;
    static const int FIELD_SIZE = 10;
    static const int SIZE_SQUARE = ROW_COUNT * FIELD_SIZE;;

    MyScene(QObject *parent = nullptr);

    void createGrid();
    void drawRedEllipse(qreal x, qreal y, qreal w, qreal h);
};

#endif  // MYSCENE_H
