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
};

#endif // GRAPHVIEW_H
