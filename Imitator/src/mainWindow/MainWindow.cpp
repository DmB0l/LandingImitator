#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "src/travelAirplane/TravelAirplane.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->PB_start, &QPushButton::clicked, this, &MainWindow::goStart);
    connect(ui->PB_deleteTrackNumber, &QPushButton::clicked, this,&MainWindow::onDeleteTrackNumber);
    connect(ui->PB_deleteAll, &QPushButton::clicked, this, &MainWindow::onDeleteAll);

    ui->progB->setValue(0);
    ui->PB_stop->setEnabled(false);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::goStart() {
    ui->PB_stop->setEnabled(true);
    ui->PB_deleteAll->setEnabled(false);
    ui->PB_deleteTrackNumber->setEnabled(false);
    ui->PB_start->setEnabled(false);

    ui->progB->setValue(0);

    m_trackNumber++;

    ui->L_trackNumberCounter->setText(QString::number(m_trackNumber));

    double speed = ui->DSB_speed->value();
    double period = ui->DSB_period->value();

    double startX = ui->DSB_firstX->value();
    double startY = ui->DSB_firstY->value();
    double startZ = ui->DSB_firstZ->value();

    double finishX = ui->DSB_secondX->value();
    double finishY = ui->DSB_secondY->value();
    double finishZ = ui->DSB_secondZ->value();

    double distance = calcDistance(startX, startY, startZ, finishX, finishY, finishZ);

    if (distance != 0) {
        ui->progB->setMaximum(distance);
    }

    double timeToTravel = 0;
    if (speed != 0) {
        timeToTravel = distance / speed;
    }

    qDebug() << "distance: " << distance;
    qDebug() << "time to travel: " << distance << '\n';

    TravelAirplane *travelAirplane = new TravelAirplane(startX, startY, startZ, finishX, finishY,
                                                        finishZ, distance,
                                                        timeToTravel, speed, period, m_trackNumber);

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
    ui->PB_stop->setEnabled(false);
    ui->PB_start->setEnabled(true);
    ui->PB_deleteAll->setEnabled(true);
    ui->PB_deleteTrackNumber->setEnabled(true);
}

void MainWindow::changeProgBar(double newVal) {
    ui->progB->setValue(newVal);
}
