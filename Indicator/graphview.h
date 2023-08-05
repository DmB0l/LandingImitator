#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include "graphscene.h"

#include <QGraphicsView>
#include <QKeyEvent>
#include <QObject>
#include <QWheelEvent>
#include <QtCore>

class GraphView : public QGraphicsView {
    Q_OBJECT

  public:
    explicit GraphView(QWidget *parent = nullptr);

  protected:
    //    void wheelEvent(QWheelEvent *event) override;

  private:
    //    void zoom(qreal factor);
    QPointF m_lastPos;
};

#endif // GRAPHVIEW_H
