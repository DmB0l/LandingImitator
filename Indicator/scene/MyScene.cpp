#include "MyScene.h"

MyScene::MyScene(QObject *parent) : QGraphicsScene(parent) {
    createGrid();
//    this->m_ellipseVec = new QVector<ItemEllipse*>();
//    this->m_textVec = new QVector<ItemText*>();
//    this->setSceneRect(-500, -500, 1000, 1000);
}

void MyScene::createGrid() {
    QPen pen(QBrush(QColor(0, 0, 0, 50)), 0.5, Qt::PenStyle::SolidLine);
    int sizeSquare = ROW_COUNT * FIELD_SIZE;

//    for (int i = -sizeSquare; i <= sizeSquare; i += FIELD_SIZE) {
//        if (i == 0) {
//            pen.setWidthF(3.0);
//            this->addLine(i, -sizeSquare, i, sizeSquare, pen);
//            this->addLine(-sizeSquare, i, sizeSquare, i, pen);
//            pen.setWidth(1);
//        } else {
//            this->addLine(i, -sizeSquare, i, sizeSquare, pen);
//            this->addLine(-sizeSquare, i, sizeSquare, i, pen);
//        }
//    }

    for (int i = 0; i < sizeSquare * 2; i += FIELD_SIZE) {
        if (i == sizeSquare) {
            pen.setWidthF(3.0);
            pen.setColor(QColor(0, 0, 0, 255));
            this->addLine(i, 0, i, sizeSquare * 2, pen);
            this->addLine(0, i, sizeSquare * 2, i, pen);
            pen.setColor(QColor(0, 0, 0, 50));
            pen.setWidthF(0.5);
        } else {
            this->addLine(i, 0, i, sizeSquare * 2, pen);
            this->addLine(0, i, sizeSquare * 2, i, pen);
        }
    }
}

void MyScene::drawRedEllipse(qreal x, qreal y, qreal w, qreal h) {
//    QPen pen2(QBrush(Qt::GlobalColor::red), 1.0, Qt::PenStyle::SolidLine);
//    auto *ellipse = new QGraphicsEllipseItem(m_x, m_y, m_w, m_h);
//    ellipse->setBrush(QBrush(Qt::red));
//    ellipse->setPen(pen2);
//    this->addItem(ellipse);
    ItemEllipse *ellipse = new ItemEllipse(x, y, w, h, this);
    this->m_ellipseVec.push_back(ellipse);

    ItemText *textItem = new ItemText(x+5, y, 50, 10);
    this->m_textVec.push_back(textItem);

    this->addItem(ellipse);
    this->addItem(textItem);
//    this->items().first()->setVisible(false);
}

