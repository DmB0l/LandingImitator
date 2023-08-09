#include "MyScene.h"

MyScene::MyScene(QObject *parent) : QGraphicsScene(parent) { createGrid(); }

void MyScene::createGrid() {
    QPen pen(QBrush(Qt::GlobalColor::black), 1.0, Qt::PenStyle::SolidLine);
    int sizeSquare = ROW_COUNT * FIELD_SIZE;
    for (int i = -sizeSquare; i < sizeSquare; i += FIELD_SIZE) {
        if (i == 0) {
            pen.setWidthF(3.0);
            this->addLine(i, -sizeSquare, i, sizeSquare, pen);
            this->addLine(-sizeSquare, i, sizeSquare, i, pen);
            pen.setWidth(1);
        }
        this->addLine(i, -sizeSquare, i, sizeSquare, pen);
        this->addLine(-sizeSquare, i, sizeSquare, i, pen);
    }
}
