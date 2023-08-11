//
// Created by alex on 11.08.2023.
//

#include "Airplane.h"

Airplane::Airplane(quint8 number) : number(number) {}

 QVector<ItemEllipse *> &Airplane::getMEllipseVec() {
    return m_ellipseVec;
}

 QVector<ItemText *> &Airplane::getMTextVec() {
    return m_textVec;
}

quint8 Airplane::getNumber() const {
    return number;
}
