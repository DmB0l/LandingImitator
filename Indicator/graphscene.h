#ifndef GRAPHSCENE_H
#define GRAPHSCENE_H

#include "graphitemGrid.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QList>
#include <QThread>

class GraphScene : public QGraphicsScene {
    Q_OBJECT

  public:
    const static int MAX_SIZE_FIELD = 500;
    const static int MAX_SIZE_SQUARE = 10;

    explicit GraphScene(QObject *parent = nullptr);

    void keyPressEvent(QKeyEvent *event) override {
        // Передвижение по сцене влево при нажатии клавиши влево
        if (event->key() == Qt::Key_Left) {
            // Получаем текущую позицию
            QPointF currentPosition =
                views().first()->mapToScene(views().first()->viewport()->rect()).boundingRect().center();

            // Смещаем позицию на 10 пикселей влево
            QPointF newPosition = QPointF(currentPosition.x() - 10, currentPosition.y());

            // Устанавливаем новую позицию
            views().first()->centerOn(newPosition);
        }

        // Передвижение по сцене вправо при нажатии клавиши вправо
        if (event->key() == Qt::Key_Right) {
            // Получаем текущую позицию
            QPointF currentPosition =
                views().first()->mapToScene(views().first()->viewport()->rect()).boundingRect().center();

            // Смещаем позицию на 10 пикселей вправо
            QPointF newPosition = QPointF(currentPosition.x() + 10, currentPosition.y());

            // Устанавливаем новую позицию
            views().first()->centerOn(newPosition);
        }

        // Передвижение по сцене вверх при нажатии клавиши вверх
        if (event->key() == Qt::Key_Up) {
            // Получаем текущую позицию
            QPointF currentPosition =
                views().first()->mapToScene(views().first()->viewport()->rect()).boundingRect().center();

            // Смещаем позицию на 10 пикселей вверх
            QPointF newPosition = QPointF(currentPosition.x(), currentPosition.y() - 10);

            // Устанавливаем новую позицию
            views().first()->centerOn(newPosition);
        }

        // Передвижение по сцене вниз при нажатии клавиши вниз
        if (event->key() == Qt::Key_Down) {
            // Получаем текущую позицию
            QPointF currentPosition =
                views().first()->mapToScene(views().first()->viewport()->rect()).boundingRect().center();

            // Смещаем позицию на 10 пикселей вниз
            QPointF newPosition = QPointF(currentPosition.x(), currentPosition.y() + 10);

            // Устанавливаем новую позицию
            views().first()->centerOn(newPosition);
        }
    }

  protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;
};

#endif // GRAPHSCENE_H
