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

    double coordZeroX() const;
    double coordZeroY() const;

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

    double m_coordZeroX = 0;
    double m_coordZeroY = 0;

    int m_maxX = 0;
    int m_maxY = 0;
    int m_minX = 0;
    int m_minY = 0;

    void createGrid();
    void move(int dx, int dy);
};

#endif // GRIDSCENE_H
