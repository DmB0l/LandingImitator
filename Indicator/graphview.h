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
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            // запоминаем текущую позицию мыши
            m_lastPos = event->pos();
        }
    }

    void mouseMoveEvent(QMouseEvent *event) override {
        if (event->buttons() & Qt::LeftButton) {
            // вычисляем разницу между текущей позицией мыши и запомненной
            // позицией
            QPoint p((int)m_lastPos.x(), (int)m_lastPos.y());
            QPointF delta = mapToScene(event->pos()) - mapToScene(p);

            // перемещаем видимую область на эту разницу
            QPointF center = mapToScene(viewport()->rect().center());
            center -= delta;
            centerOn(center);

            // запоминаем текущую позицию мыши
            m_lastPos = event->pos();
        }
    }

    //    void mousePressEvent(QMouseEvent *event) override;

  private:
    //    void zoom(qreal factor);
    QPointF m_lastPos;
};

#endif // GRAPHVIEW_H
