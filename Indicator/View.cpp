#include "View.h"

View::View(QWidget *parent) : QGraphicsView(parent) {}

bool View::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::Wheel) {
        // QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        //        qDebug() << "Прокрутка";
        return true;
    } else {
        // вызов стандартного сигнала
        return QObject::eventFilter(obj, event);
    }
}
