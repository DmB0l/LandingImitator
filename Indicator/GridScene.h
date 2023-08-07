#ifndef GRIDSCENE_H
#define GRIDSCENE_H

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QMouseEvent>

#include "GridItem.h"

class GridScene : public QGraphicsScene {
  public:
    GridScene(QObject *parent = nullptr);

  protected:
    void keyPressEvent(QKeyEvent *event) override;
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

  private:
    bool isMousePressed = false;
    QPointF lastMousePos;

    QGraphicsView *view = nullptr;

    void createGrid();
    void move(int dx, int dy);
};

#endif // GRIDSCENE_H
