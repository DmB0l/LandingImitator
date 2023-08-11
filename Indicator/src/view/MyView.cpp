#include "MyView.h"

MyView::MyView(QWidget *parent) : QGraphicsView(parent), widget(parent) {
    setTransformationAnchor(QGraphicsView::AnchorViewCenter);
    setDragMode(QGraphicsView::ScrollHandDrag);
}

void MyView::wheelEvent(QWheelEvent *event) {
    // Масштабирование сцены при прокрутке колесика мыши
    int delta = event->delta();
    double scaleFactor = 1.15;

    QPointF pos = mapToScene(event->pos());

    double currentScale = this->transform().m11();

    if (delta > 0) {
        if (currentScale >= 2.5)  // Ограничение масштаба сверху
            return;

        this->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
        this->scale(scaleFactor, scaleFactor);

//        centerOn(pos);

    } else if (delta < 0) {
        if (currentScale <= 0.5)  // Ограничение масштаба снизу
            return;

        this->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
        this->scale(1 / scaleFactor, 1 / scaleFactor);
    }


    event->accept();
}

//void MyView::mousePressEvent(QMouseEvent *event) {
//    if (event->button() == Qt::LeftButton) {
//        widget->setCursor(Qt::OpenHandCursor);
//    }
//    QGraphicsView::mousePressEvent(event);
//}
//
//void MyView::mouseReleaseEvent(QMouseEvent *event) {
//    widget->setCursor(Qt::OpenHandCursor);
//    QGraphicsView::mouseReleaseEvent(event);
//}
