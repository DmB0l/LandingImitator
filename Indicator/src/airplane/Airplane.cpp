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

Airplane::~Airplane() {
    eraseDataVec();

    delete m_label;
    delete m_itemWidget;
}

void Airplane::eraseDataVec() {
    for(auto iterator = m_ellipseVec.begin(); iterator < m_ellipseVec.end(); iterator++) {
        delete (*iterator);
    }

    for(auto iterator = m_textVec.begin(); iterator < m_textVec.end(); iterator++) {
        delete (*iterator);
    }

    m_ellipseVec.clear();
    m_textVec.clear();
}

QLabel *Airplane::getLabel() const {
    return m_label;
}

void Airplane::setLabel(QLabel *label) {
    Airplane::m_label = label;
}

void Airplane::eraseLabel() {
    delete m_label;
    m_label = nullptr;
}

void Airplane::eraseWidget() {
    delete m_itemWidget;
    m_itemWidget = nullptr;
}

QListWidgetItem *Airplane::getItemWidget() const {
    return m_itemWidget;
}

void Airplane::setItemWidget(QListWidgetItem *itemWidget) {
    Airplane::m_itemWidget = itemWidget;
}
