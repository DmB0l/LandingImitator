#ifndef GRAPHSCENE_H
#define GRAPHSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include <QGraphicsItem>
#include "graphitem.h"

class GraphScene :public QGraphicsScene
{
    Q_OBJECT

public:
    explicit GraphScene(QObject *parent = nullptr);

};

#endif // GRAPHSCENE_H
