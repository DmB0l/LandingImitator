//
// Created by alex on 14.08.2023.
//

#include "TravelAirplane.h"

TravelAirplane::TravelAirplane(double startX, double startY, double startZ, double finishX,
                               double finishY, double finishZ, double distance,
                               double timeToTravel, double speed, double period, quint8 trackNumber) : m_startX(startX),
                                                                                   m_startY(startY), m_startZ(startZ),
                                                                                   m_finishX(finishX),
                                                                                   m_finishY(finishY),
                                                                                   m_finishZ(finishZ),
                                                                                   m_distance(distance),
                                                                                   m_timeToTravel(timeToTravel),
                                                                                   m_speed(speed), m_period(period),
                                                                                   m_trackNumber(trackNumber){


}

TravelAirplane::~TravelAirplane() {
    delete m_socket;
    delete m_timer;
}

void TravelAirplane::initTimer() {
    m_timer = new QTimer(this);

    m_socket = new QUdpSocket();
    m_socket->bind(QHostAddress::LocalHost, 1234);

    message mess;
    mess.x = m_startX;
    mess.y = m_startY;
    mess.z = m_startZ;
    mess.trackNumber = m_trackNumber;

    QByteArray arr;
    QDataStream stream(&arr, QIODevice::WriteOnly);
    stream << mess.x << mess.y << mess.z << mess.trackNumber;
    m_socket->writeDatagram(arr, QHostAddress::LocalHost, 5678);

    connect(m_timer, &QTimer::timeout, this, &TravelAirplane::calc);

    if (m_distance != 0)
        m_timer->start(m_period * 1000);
}

void TravelAirplane::calc() {
    m_timeTraveled += m_period;
    m_distanceTraveled += m_speed * m_period;

    m_persentageTraveled = m_timeTraveled / m_timeToTravel;
    qDebug() << "distance traveled: " << m_distanceTraveled;
    qDebug() << "percent traveled: " << m_persentageTraveled << '\n';

    emit changeProgBar(m_distanceTraveled >= m_distance ? m_distance : m_distanceTraveled);

    message mess;
    mess.x = m_startX * (1 - m_persentageTraveled) + m_finishX * m_persentageTraveled;
    mess.y = m_startY * (1 - m_persentageTraveled) + m_finishY * m_persentageTraveled;
    mess.z = m_startZ * (1 - m_persentageTraveled) + m_finishZ * m_persentageTraveled;
    mess.trackNumber = m_trackNumber;

    QByteArray arr;
    QDataStream stream(&arr, QIODevice::WriteOnly);
    stream << mess.x << mess.y << mess.z << mess.trackNumber;
    m_socket->writeDatagram(arr, QHostAddress::LocalHost, 5678);

    if (m_distanceTraveled >= m_distance) {
        m_timer->stop();
        emit finished(true);
    }
}

void TravelAirplane::stop() {
    m_timer->stop();
    emit finished(true);
}


