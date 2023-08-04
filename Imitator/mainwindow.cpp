#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->PB_start, &QPushButton::clicked, this, &MainWindow::goStart);

    ui->progB->setValue(0);
    m_speed = ui->DSB_speed->value();
    m_period = static_cast<int>(ui->DSB_period->value());

    double firstX = ui->DSB_firstX->value();
    double firstY = ui->DSB_firstY->value();
    double firstZ = ui->DSB_firstZ->value();

    double secondX = ui->DSB_secondX->value();
    double secondY = ui->DSB_secondY->value();
    double secondZ = ui->DSB_secondZ->value();

    m_distance =
        calcDistance(firstX, firstY, firstZ, secondX, secondY, secondZ);
    ui->progB->setMaximum(m_distance);

    m_timer = new QTimer(this);

    m_socket = new QUdpSocket();
    m_socket->bind(QHostAddress::LocalHost, 1234);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goStart()
{
    if (m_timer != nullptr)
    {
        m_timer->stop();
    }

    m_distanceTraveled = 0;
    m_trackNumber++;

    ui->L_trackNumberCounter->setText(QString::number(m_trackNumber));


    qDebug() << "distance: " << m_distance;


    connect(m_timer, &QTimer::timeout, this, &MainWindow::calcTravel);
    m_timer->start(m_period * 1000);
}

void MainWindow::calcTravel()
{
    m_distanceTraveled += m_speed * m_period;
    ui->progB->setValue(m_distanceTraveled >= m_distance ? m_distance
                        : m_distanceTraveled);
    qDebug() << "distance traveled: " << m_distanceTraveled;

//    QByteArray *arr = new QByteArray();
//    arr->append("hello");

    QByteArray arr;
    arr.append("qwe");
    m_socket->writeDatagram(arr, QHostAddress::LocalHost, 5678);

    if (m_distanceTraveled >= m_distance)
    {
        m_timer->stop();
    }
}

double MainWindow::calcDistance(double fX, double fY, double fZ, double sX,
                                double sY, double sZ)
{
    return sqrt(pow(sX - fX, 2) + pow(sY - fY, 2) + pow(sZ - fZ, 2));
}
