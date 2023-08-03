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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goStart()
{
    if (timer != nullptr)
    {
        timer->stop();
    }

    m_distanceTraveled = 0;
    m_trackNumber++;

    ui->L_trackNumberCounter->setText(QString::number(m_trackNumber));

    double firstX = ui->DSB_firstX->value();
    double firstY = ui->DSB_firstY->value();
    double firstZ = ui->DSB_firstZ->value();

    double secondX = ui->DSB_secondX->value();
    double secondY = ui->DSB_secondY->value();
    double secondZ = ui->DSB_secondZ->value();

    m_speed = ui->DSB_speed->value();
    m_period = static_cast<int>(ui->DSB_period->value());

    m_distance =
        calcDistance(firstX, firstY, firstZ, secondX, secondY, secondZ);
    ui->progB->setMaximum(m_distance);

    qDebug() << "distance: " << m_distance;

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::calcTravel);
    timer->start(m_period * 1000);
}

void MainWindow::calcTravel()
{
    m_distanceTraveled += m_speed * m_period;
    ui->progB->setValue(m_distanceTraveled >= m_distance ? m_distance
                        : m_distanceTraveled);
    qDebug() << "distance traveled: " << m_distanceTraveled;

    if (m_distanceTraveled >= m_distance)
    {
        timer->stop();
    }
}

double MainWindow::calcDistance(double fX, double fY, double fZ, double sX,
                                double sY, double sZ)
{
    return sqrt(pow(sX - fX, 2) + pow(sY - fY, 2) + pow(sZ - fZ, 2));
}
