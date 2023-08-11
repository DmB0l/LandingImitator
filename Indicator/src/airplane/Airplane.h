//
// Created by alex on 11.08.2023.
//

#ifndef INDICATOR_AIRPLANE_H
#define INDICATOR_AIRPLANE_H


#include "src/itemEllipse/ItemEllipse.h"
#include "src/itemText/ItemText.h"

class Airplane {
public:
    Airplane(quint8 number);

    quint8 getNumber() const;

     QVector<ItemEllipse*> &getMEllipseVec();

     QVector<ItemText*> &getMTextVec();


private:
    quint8 number = 0;
    QVector<ItemEllipse*> m_ellipseVec;
    QVector<ItemText*> m_textVec;
};


#endif //INDICATOR_AIRPLANE_H
