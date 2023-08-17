#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QtCore>

struct message {
    qint64 x = 0;
    qint64 y = 0;
    qint64 z = 0;

    quint8 trackNumber = 0;
};

void printMessage(QString message);

// QDataStream &operator<<(QDataStream &in, message const &mess);

// QDataStream &operator>>(QDataStream &out, message &mess);

#endif // PROTOCOL_H
