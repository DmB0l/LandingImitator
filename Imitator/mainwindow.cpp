#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->PB_start, &QPushButton::clicked, this, &MainWindow::goStart);

    ui->progB->setValue(0);

    m_socket = new QUdpSocket();
    m_socket->bind(QHostAddress::LocalHost, 1234);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::goStart() {
    if (m_timer != nullptr) {
        m_timer->stop();
    }

    m_distanceTraveled = 0;
    m_trackNumber++;

    ui->L_trackNumberCounter->setText(QString::number(m_trackNumber));

    m_speed = ui->DSB_speed->value();
    m_period = static_cast<int>(ui->DSB_period->value());

    m_startX = ui->DSB_firstX->value();
    m_startY = ui->DSB_firstY->value();
    m_startZ = ui->DSB_firstZ->value();

    m_finishX = ui->DSB_secondX->value();
    m_finishY = ui->DSB_secondY->value();
    m_finishZ = ui->DSB_secondZ->value();

    m_distance = calcDistance(m_startX, m_startY, m_startZ, m_finishX, m_finishY, m_finishZ);

    if (m_distance != 0) {
        ui->progB->setMaximum(m_distance);
    }

    if (m_speed != 0) {
        m_timeToTravel = m_distance / m_speed;
    }

    qDebug() << "distance: " << m_distance;
    qDebug() << "time to travel: " << m_distance << '\n';

    m_timer = new QTimer(this);

    connect(m_timer, &QTimer::timeout, this, &MainWindow::calcTravel);

    if (m_distance != 0)
        m_timer->start(m_period * 1000);
}

void MainWindow::calcTravel() {
    m_timeTraveled += m_period;
    m_distanceTraveled += m_speed * m_period;
    m_persentageTraveled = m_timeTraveled / m_timeToTravel;
    qDebug() << "distance traveled: " << m_distanceTraveled;
    qDebug() << "percent traveled: " << m_persentageTraveled << '\n';

    ui->progB->setValue(m_distanceTraveled >= m_distance ? m_distance : m_distanceTraveled);

    message mess;
    //    qDebug() << m_startX * (1 - m_persentageTraveled) + m_finishX * m_persentageTraveled;
    mess.x = m_startX * (1 - m_persentageTraveled) + m_finishX * m_persentageTraveled;
    mess.y = m_startY * (1 - m_persentageTraveled) + m_finishY * m_persentageTraveled;
    mess.z = m_startZ * (1 - m_persentageTraveled) + m_finishZ * m_persentageTraveled;
    mess.trackNumber = m_trackNumber;

    QByteArray arr;
    QDataStream stream(&arr, QIODevice::WriteOnly);

    //    stream << mess;

    stream << mess.x << mess.y << mess.z << mess.trackNumber;

    m_socket->writeDatagram(arr, QHostAddress::LocalHost, 5678);

    if (m_distanceTraveled >= m_distance) {
        m_timer->stop();
    }
}

double MainWindow::calcDistance(double fX, double fY, double fZ, double sX, double sY, double sZ) {
    return sqrt(pow(sX - fX, 2) + pow(sY - fY, 2) + pow(sZ - fZ, 2));
}
