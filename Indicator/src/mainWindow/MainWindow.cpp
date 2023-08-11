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

    m_scene1 = new MyScene(m_view1, ui->LV_1);
    m_scene2 = new MyScene(m_view2, ui->LV_2);

    m_view1->setScene(m_scene1);
    m_view2->setScene(m_scene2);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::onReadyRead() {
    QByteArray buffer;
    buffer.resize(m_socket->pendingDatagramSize());

    m_socket->readDatagram(buffer.data(), buffer.size());

    QDataStream stream(&buffer, QIODevice::ReadOnly);
    message mess;
    stream >> mess.x >> mess.y >> mess.z >> mess.trackNumber;
    qDebug() << mess.x << mess.y << mess.z << mess.trackNumber;

    int x = mess.x;
    int y = mess.y;

    qDebug() << x << y;

    m_scene1->drawTrack(MyScene::SIZE_SQUARE + x - 2, MyScene::SIZE_SQUARE + y - 2, 4, 4, mess.trackNumber);
}
