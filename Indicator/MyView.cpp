#include "MyView.h"

MyView::MyView(QWidget *parent) : QGraphicsView(parent) {
    setTransformationAnchor(QGraphicsView::NoAnchor);
    setDragMode(QGraphicsView::ScrollHandDrag);
}

void MyView::wheelEvent(QWheelEvent *event) {
    // Масштабирование сцены при прокрутке колесика мыши
    int delta = event->delta();
    double scaleFactor = 1.15;

    //    QGraphicsView *view = this->views().first();

    double currentScale = this->transform().m11();

    if (delta > 0) {
        if (currentScale >= 2.0)  // Ограничение масштаба сверху
            return;

        this->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
        this->scale(scaleFactor, scaleFactor);

    } else if (delta < 0) {
        if (currentScale <= 0.5)  // Ограничение масштаба снизу
            return;

        this->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
        this->scale(1 / scaleFactor, 1 / scaleFactor);
    }
}
