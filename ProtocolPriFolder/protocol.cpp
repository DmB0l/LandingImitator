#include "protocol.h"

void printMessage(QString message) { qDebug() << message; }

// QDataStream &operator<<(QDataStream &in, message const &mess) {
//     return in << mess.x << mess.y << mess.z << mess.trackNumber;
// }

// QDataStream &operator>>(QDataStream &out, message &mess) {
//     return out >> mess.x >> mess.y >> mess.z >> mess.trackNumber;
// }
