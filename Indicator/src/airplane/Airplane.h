//
// Created by alex on 11.08.2023.
//

#ifndef INDICATOR_AIRPLANE_H
#define INDICATOR_AIRPLANE_H


#include <QLabel>
#include <QListWidgetItem>
#include "src/itemEllipse/ItemEllipse.h"
#include "src/itemText/ItemText.h"

class Airplane {
public:
    Airplane(quint8 number);

    virtual ~Airplane();

    quint8 getNumber() const;

    QVector<ItemEllipse *> &getMEllipseVec();

    QVector<ItemText *> &getMTextVec();

    void eraseDataVec();

    void setLabel(QLabel *label);

    QLabel *getLabel() const;

    void eraseLabel();

    void eraseWidget();

    void setItemWidget(QListWidgetItem *itemWidget);

    QListWidgetItem *getItemWidget() const;

private:
    quint8 number = 0;
    QVector<ItemEllipse *> m_ellipseVec;
    QVector<ItemText *> m_textVec;
    QLabel *m_label = nullptr;
    QListWidgetItem *m_itemWidget = nullptr;
};


#endif //INDICATOR_AIRPLANE_H
