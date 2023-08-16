#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "src/travelAirplane/TravelAirplane.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->PB_start, &QPushButton::clicked, this, &MainWindow::goStart);
    connect(ui->PB_deleteTrackNumber, &QPushButton::clicked, this, &MainWindow::onDeleteTrackNumber);
    connect(ui->PB_deleteAll, &QPushButton::clicked, this, &MainWindow::onDeleteAll);


    ui->progB->setValue(0);
    ui->PB_stop->setEnabled(false);

//    m_socket = new QUdpSocket();
//    m_socket->bind(QHostAddress::LocalHost, 1234);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::goStart() {
    if (m_timer != nullptr) {
        m_timer->stop();
    }

    ui->PB_stop->setEnabled(true);
    ui->PB_deleteAll->setEnabled(false);
    ui->PB_deleteTrackNumber->setEnabled(false);
    ui->PB_start->setEnabled(false);

    ui->progB->setValue(0);

//    m_timeTraveled = 0;
//    m_distanceTraveled = 0;
//    m_persentageTraveled = 0;

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

    TravelAirplane *travelAirplane = new TravelAirplane(m_startX, m_startY, m_startZ, m_finishX, m_finishY,
                                                        m_finishZ, m_distance, m_timeToTravel, m_speed, m_period, m_trackNumber);

    connect(ui->PB_stop, &QPushButton::clicked, travelAirplane, &TravelAirplane::stop);

    QThread *thread = new QThread();
    travelAirplane->moveToThread(thread);

    connect(thread, &QThread::started, travelAirplane, &TravelAirplane::initTimer);

    connect(travelAirplane, &TravelAirplane::changeProgBar, this, &MainWindow::changeProgBar);

    // При излучении сигнала finished получаем флаг успешности
    connect(travelAirplane, &TravelAirplane::finished, this, &MainWindow::unlockButtons);
    // Также, по сигналу finished отправляем команду на завершение потока
    connect(travelAirplane, &TravelAirplane::finished, thread, &QThread::quit);
    // А потом удаляем экземпляр обработчика
    connect(travelAirplane, &TravelAirplane::finished, travelAirplane, &QObject::deleteLater);
    // И наконец, когда закончит работу поток, удаляем и его
    connect(thread, &QThread::finished, thread, &QObject::deleteLater);

    thread->start();
}

double MainWindow::calcDistance(double fX, double fY, double fZ, double sX, double sY, double sZ) {
    return sqrt(pow(sX - fX, 2) + pow(sY - fY, 2) + pow(sZ - fZ, 2));
}

void MainWindow::onDeleteAll() {
    ui->DSB_firstX->setValue(0.0);
    ui->DSB_firstY->setValue(0.0);
    ui->DSB_firstZ->setValue(0.0);

    ui->DSB_secondX->setValue(0.0);
    ui->DSB_secondY->setValue(0.0);
    ui->DSB_secondZ->setValue(0.0);

    ui->DSB_speed->setValue(1.0);
    ui->DSB_period->setValue(1.0);

    ui->progB->setValue(0);

    ui->L_trackNumberCounter->setText("0");
    m_trackNumber = 0;
}

void MainWindow::onDeleteTrackNumber() {
    ui->progB->setValue(0);

    ui->L_trackNumberCounter->setText("0");
    m_trackNumber = 0;
}

void MainWindow::unlockButtons() {
//    m_timer->stop();
    ui->PB_stop->setEnabled(false);
    ui->PB_start->setEnabled(true);
    ui->PB_deleteAll->setEnabled(true);
    ui->PB_deleteTrackNumber->setEnabled(true);
}

void MainWindow::changeProgBar(double newVal) {
    ui->progB->setValue(newVal);
}
