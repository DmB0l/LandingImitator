#include "MainWindow.h"

#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    m_socket = new QUdpSocket(this);
    m_socket->bind(QHostAddress::LocalHost, 5678);

    connect(m_socket, &QUdpSocket::readyRead, this, &MainWindow::onReadyRead);

    int size = 500;

    m_view = new MyView(this);
    m_view->setMaximumWidth(size);
    m_view->setMaximumHeight(size);
    m_view->setMinimumWidth(size);
    m_view->setMinimumHeight(size);

    //    m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //    m_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_scene = new MyScene(m_view);

    m_view->setScene(m_scene);
    m_view->show();
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

    m_scene->drawRedEllipse(x - 2, y - 2, 4, 4);
}
