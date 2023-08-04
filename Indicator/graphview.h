#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QWheelEvent>
#include <QtCore>

class GraphView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GraphView(QWidget* parent = nullptr);

protected:
    void wheelEvent(QWheelEvent* event) override;

    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    void zoom(qreal factor);

};

#endif // GRAPHVIEW_H
