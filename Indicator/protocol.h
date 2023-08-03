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

quint64 toUINT64(double val) { return static_cast<quint64>(val); }

#endif // PROTOCOL_H
