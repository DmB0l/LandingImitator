//
// Created by alex on 14.08.2023.
//

#ifndef IMITATOR_TRAVELAIRPLANE_H
#define IMITATOR_TRAVELAIRPLANE_H

#include <QObject>
#include <QUdpSocket>
#include "../../../ProtocolPriFolder/protocol.h"


class TravelAirplane : public QObject {
Q_OBJECT

public:
    explicit TravelAirplane(double startX, double startY, double startZ, double finishX, double finishY, double finishZ,
                            double distance,
                            double timeToTravel, double speed, double period, quint8 trackNumber);

    ~TravelAirplane() override;

public slots:

    void initTimer();

    void stop();

signals:

    void finished(bool);

    void changeProgBar(double);

private:
    void calc();

    double m_startX = 0;
    double m_startY = 0;
    double m_startZ = 0;

    double m_finishX = 0;
    double m_finishY = 0;
    double m_finishZ = 0;

    double m_persentageTraveled = 0;
    double m_distanceTraveled = 0;
    double m_timeTraveled = 0;

    double m_period = 0;
    double m_speed = 0;
    double m_distance = 0;
    quint8 m_trackNumber = 0;

    double m_timeToTravel = 0;

    QUdpSocket *m_socket = nullptr;
    QTimer *m_timer = nullptr;
};


#endif //IMITATOR_TRAVELAIRPLANE_H
