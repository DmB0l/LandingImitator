#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QVector>
#include <QListWidget>
#include <QStandardItem>
#include <QGraphicsView>
#include <QPushButton>
#include <QMenu>


#include "src/itemEllipse/ItemEllipse.h"
#include "src/itemText/ItemText.h"
#include "src/airplane/Airplane.h"
#include "src/modalInfoWindow/ModalInfoWindow.h"

class MyScene : public QGraphicsScene {
   public:
    static const int ROW_COUNT = 50;
    static const int COLUMN_COUNT = 50;
    static const int FIELD_SIZE = 10;
    static const int SIZE_SQUARE = ROW_COUNT * FIELD_SIZE;;
    QString colors[5] {"blue", "red", "gray", "green", "yellow"};

    explicit MyScene(QObject *parent = nullptr, QListWidget *listWidget = nullptr, quint8 mod = 0);

    ~MyScene() override;

    void createGrid();
    void drawTrack(qreal x, qreal y, qreal w, qreal h, quint8 numberAirplane);

    const QVector<Airplane *> &getMAirplanes() const;

private:
    quint8 m_mod = 0;
    QListWidget *m_listWidget = nullptr;
    int m_numberItem = 0;
    int m_prevNumberAirplane = 0;
    int m_numberChoose = 0;

    QList<int> m_prevNumberList;
    QVector<Airplane*> m_airplanes;

private slots:
    void hideTravel();
    void showTravel();
    void deleteTravel();
    void showInfo();
    void showContextMenu(QPoint pos);
};

#endif  // MYSCENE_H
