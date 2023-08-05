#ifndef GRIDITEM_H
#define GRIDITEM_H

#include <QGraphicsItem>
#include <QPainter>

class GridItem : public QGraphicsItem {
  public:
    GridItem(int gridSize, int row, int col, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void setSize(int size);

  private:
    int m_gridSize;
    int m_row;
    int m_col;
};

#endif // GRIDITEM_H
