#include "graphscene.h"

GraphScene::GraphScene(QObject *parent) : QGraphicsScene{parent} {}

void GraphScene::drawBackground(QPainter *painter, const QRectF &rect) {
    painter->setPen(QPen(Qt::black, 0.5, Qt::SolidLine, Qt::RoundCap));
    QThread::sleep(1);
    for (int i = -MAX_SIZE_FIELD; i < MAX_SIZE_FIELD; i += MAX_SIZE_SQUARE) {
        if (i != 0) {
            painter->drawLine(i, -MAX_SIZE_FIELD, i, MAX_SIZE_FIELD);
            painter->drawLine(-MAX_SIZE_FIELD, i, MAX_SIZE_FIELD, i);
        } else {
            painter->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
            painter->drawLine(i, -MAX_SIZE_FIELD, i, MAX_SIZE_FIELD);
            painter->drawLine(-MAX_SIZE_FIELD, i, MAX_SIZE_FIELD, i);
            painter->setPen(QPen(Qt::black, 0.5, Qt::SolidLine, Qt::RoundCap));
        }
    }
}
