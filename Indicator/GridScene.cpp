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
            QPointF newPos = item->pos() + delta;

            if (newPos.x() <= m_minX || newPos.x() >= m_maxX || newPos.y() <= m_minY || newPos.y() >= m_maxY) {
                lastMousePos = event->scenePos();
                event->accept();
                return;
            }
        }

        m_coordZeroX += delta.x();
        m_coordZeroX += delta.y();

        foreach (QGraphicsItem *item, items()) {
            QPointF newPos = item->pos() + delta;
            item->setPos(newPos);
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

double GridScene::coordZeroX() const { return m_coordZeroX; }

double GridScene::coordZeroY() const { return m_coordZeroY; }

void GridScene::createGrid() {
    const int rows = 20;            // Количество строк сетки
    const int cols = 20;            // Количество столбцов сетки
    const int gridSize = 50;        // Размер ячейки сетки
    const int delta = gridSize / 2; //

    m_maxX = cols * gridSize * 1.5;
    m_maxY = rows * gridSize * 1.5;
    m_minX = -cols * gridSize * 1.5;
    m_minY = -rows * gridSize * 1.5;

    // Создание ячеек сетки и добавление их на сцену
    for (int row = -rows; row <= rows; ++row) {
        for (int col = -cols; col <= cols + 1; ++col) {
            GridItem *gridItem = new GridItem(gridSize, row, col);
            addItem(gridItem);
            gridItem->setPos(col * gridSize + delta, row * gridSize);
        }
    }

    QPen pen(QBrush(Qt::GlobalColor::black), 8.0, Qt::PenStyle::SolidLine);
    addLine(0, -gridSize * (rows), 0, gridSize * (rows + 1), pen);
    addLine(-gridSize * (cols - 0.5), 0, gridSize * (cols + 2.5), 0, pen);

    //    QGraphicsView *view = this->views().first();
}

void GridScene::move(int dx, int dy) {
    // Перемещение сцены на указанное смещение
    setSceneRect(sceneRect().translated(dx, dy));
}
