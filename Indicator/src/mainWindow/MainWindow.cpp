#include "MainWindow.h"

#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    m_socket = new QUdpSocket(this);
    m_socket->bind(QHostAddress::LocalHost, 5678);

    connect(m_socket, &QUdpSocket::readyRead, this, &MainWindow::onReadyRead);

    m_view1 = ui->GV_1;
    m_view2 = ui->GV_2;

    m_view1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_view1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_view2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_view2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_scene1 = new MyScene(m_view1, ui->LW_1, 0);
    m_scene2 = new MyScene(m_view2, ui->LW_2, 1);

    m_view1->setScene(m_scene1);
    m_view2->setScene(m_scene2);
}

MainWindow::~MainWindow() {
    delete ui;
    delete m_view1;
    delete m_scene1;
    delete m_view2;
    delete m_scene2;
    delete m_socket;
}

void MainWindow::onReadyRead() {
    QByteArray buffer;
    buffer.resize(m_socket->pendingDatagramSize());

    m_socket->readDatagram(buffer.data(), buffer.size());

    QDataStream stream(&buffer, QIODevice::ReadOnly);
    message mess;
    stream >> mess.x >> mess.y >> mess.z >> mess.trackNumber;
    qDebug() << "x: " << mess.x << "y: " << mess.y << "z: " << mess.z << "num track: " << mess.trackNumber;

    qreal coord = qSqrt(qPow(mess.x, 2) + qPow(mess.y, 2));
    qDebug() << "coord: " << coord;

    m_scene1->drawTrack(MyScene::SIZE_SQUARE + mess.x - 2, MyScene::SIZE_SQUARE - mess.y - 2, 4, 4, mess.trackNumber);
    m_scene2->drawTrack(MyScene::SIZE_SQUARE + coord, MyScene::SIZE_SQUARE - mess.z - 2, 4, 4, mess.trackNumber);
}
