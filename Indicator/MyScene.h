#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>

class MyScene : public QGraphicsScene {
   public:
    static const int ROW_COUNT = 50;
    static const int COLUMN_COUNT = 50;
    static const int FIELD_SIZE = 10;

    MyScene(QObject *parent = nullptr);

    void createGrid();
};

#endif  // MYSCENE_H
