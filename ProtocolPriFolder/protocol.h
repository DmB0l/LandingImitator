#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QtCore>

struct message
{
    quint64 x = 0;
    quint64 y = 0;
    quint64 z = 0;

    quint8 trackNumber = 0;
};

void printMessage(QString message);

#endif // PROTOCOL_H
