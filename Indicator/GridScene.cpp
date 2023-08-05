#include "GridScene.h"

GridScene::GridScene(QObject *parent) : QGraphicsScene(parent) { createGrid(); }

void GridScene::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        move(-10, 0);
    } else if (event->key() == Qt::Key_Right) {
        move(10, 0);
    } else if (event->key() == Qt::Key_Up) {
        move(0, -10);
    } else if (event->key() == Qt::Key_Down) {
        move(0, 10);
    }
}

void GridScene::wheelEvent(QGraphicsSceneWheelEvent *event) {
    // Масштабирование сцены при прокрутке колесика мыши
    int delta = event->delta();
    double scaleFactor = 1.15;
    this->views().first()->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
    if (delta > 0) {
        this->views().first()->scale(scaleFactor, scaleFactor);

    } else if (delta < 0) {
        this->views().first()->scale(1 / scaleFactor, 1 / scaleFactor);
    }
}

void GridScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        isMousePressed = true;
        lastMousePos = event->scenePos();
        event->accept();
    } else {
        QGraphicsScene::mousePressEvent(event);
    }
}

void GridScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (isMousePressed) {
        QPointF delta = event->scenePos() - lastMousePos;
        // Перемещаем каждый элемент сцены на delta
        foreach (QGraphicsItem *item, items()) {
            item->setPos(item->pos() + delta);
        }
        lastMousePos = event->scenePos();
        event->accept();
    } else {
        QGraphicsScene::mouseMoveEvent(event);
    }
}

void GridScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        isMousePressed = false;
        event->accept();
    } else {
        QGraphicsScene::mouseReleaseEvent(event);
    }
}

void GridScene::createGrid() {
    const int rows = 10;     // Количество строк сетки
    const int cols = 10;     // Количество столбцов сетки
    const int gridSize = 50; // Размер ячейки сетки

    // Создание ячеек сетки и добавление их на сцену
    for (int row = -rows; row <= rows; ++row) {
        for (int col = -cols; col <= cols; ++col) {
            GridItem *gridItem = new GridItem(gridSize, row, col);
            addItem(gridItem);
            gridItem->setPos(col * gridSize, row * gridSize);
        }
    }
}

void GridScene::move(int dx, int dy) {
    // Перемещение сцены на указанное смещение
    setSceneRect(sceneRect().translated(dx, dy));
}
