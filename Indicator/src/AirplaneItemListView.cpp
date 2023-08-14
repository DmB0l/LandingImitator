//
// Created by alex on 14.08.2023.
//

#include "AirplaneItemListView.h"

AirplaneItemListView::AirplaneItemListView(const QString &text, QObject *obj) : QStandardItem(text), QObject(obj) {
}

bool AirplaneItemListView::eventFilter(QObject *obj, QEvent *event) {
    qDebug() << "зашла";
    if (event->type() == QEvent::MouseButtonPress) {
        // QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
                qDebug() << "Прокрутка";
        return true;
    } else {
        // вызов стандартного сигнала
        return QObject::eventFilter(obj, event);
    }
}

bool AirplaneItemListView::event(QEvent *event) {
    qDebug() << "зашла";
    return QObject::event(event);
}
