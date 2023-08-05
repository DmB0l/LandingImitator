#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    m_socket = new QUdpSocket(this);
    m_socket->bind(QHostAddress::LocalHost, 5678);
    connect(m_socket, &QUdpSocket::readyRead, this, &MainWindow::onReadyRead);

    m_graphScene = new GridScene(this);

    message mess;
    mess.x = 2;
    mess.y = 2;

    ui->GV_1->setScene(m_graphScene);
    ui->GV_1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->GV_1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::onReadyRead() {
    QByteArray buffer;
    buffer.resize(m_socket->pendingDatagramSize());
    //    qDebug() << m_socket->pendingDatagramSize();

    m_socket->readDatagram(buffer.data(), buffer.size());

    QDataStream stream(&buffer, QIODevice::ReadOnly);
    message mess;
    stream >> mess.x >> mess.y >> mess.z >> mess.trackNumber;
    qDebug() << mess.x << mess.y << mess.z << mess.trackNumber;

    QPen pen(Qt::red, 0.5, Qt::SolidLine, Qt::RoundCap);
    m_graphScene->addLine(mess.x - 0.7, mess.y - 0.7, mess.x + 0.7, mess.y + 0.7, pen);
    m_graphScene->addLine(mess.x - 0.7, mess.y + 0.7, mess.x + 0.7, mess.y - 0.7, pen);
}
