#include "GridScene.h"

GridScene::GridScene(QObject *parent) : QGraphicsScene(parent) {
    view = (QGraphicsView *)parent;
    // Получение текущей позиции просмотра
    QPointF currentViewPos = view->mapToScene(view->viewport()->rect().center());

    // Смещение позиции просмотра
    currentViewPos.setX(currentViewPos.x() - 50);

    // Установка новой позиции просмотра
    view->centerOn(currentViewPos);
    createGrid();
}

void GridScene::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        qDebug() << "Прокрутка";
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

    //    QGraphicsView *view = this->views().first();

    double currentScale = view->transform().m11();

    if (delta > 0) {
        if (currentScale >= 1.0) // Ограничение масштаба сверху
            return;

        view->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
        view->scale(scaleFactor, scaleFactor);

    } else if (delta < 0) {
        if (currentScale <= 0.3) // Ограничение масштаба снизу
            return;

        view->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
        view->scale(1 / scaleFactor, 1 / scaleFactor);
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
    const int rows = 20;            // Количество строк сетки
    const int cols = 20;            // Количество столбцов сетки
    const int gridSize = 50;        // Размер ячейки сетки
    const int delta = gridSize / 2; // Размер ячейки сетки

    // Создание ячеек сетки и добавление их на сцену
    for (int row = -rows; row <= rows; ++row) {
        for (int col = -cols; col <= cols + 1; ++col) {
            GridItem *gridItem = new GridItem(gridSize, row, col);
            addItem(gridItem);
            gridItem->setPos(col * gridSize + delta, row * gridSize);
        }
    }

    QPen pen(QBrush(Qt::GlobalColor::black), 4.0, Qt::PenStyle::SolidLine);
    addLine(delta, -gridSize * (rows + 1), delta, gridSize * (rows + 1), pen);
    addLine(-gridSize * (cols + 1), 0, gridSize * (rows + 1), 0, pen);

    //    QGraphicsView *view = this->views().first();
}

void GridScene::move(int dx, int dy) {
    // Перемещение сцены на указанное смещение
    setSceneRect(sceneRect().translated(dx, dy));
}
