#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    m_socket = new QUdpSocket(this);
    m_socket->bind(QHostAddress::LocalHost, 5678);
    connect(m_socket, &QUdpSocket::readyRead, this, &MainWindow::onReadyRead);

    m_graphScene = new GraphScene(this);

    QPen pen(Qt::black, 0.5, Qt::SolidLine, Qt::RoundCap);
    message mess;
    mess.x = 2;
    mess.y = 2;

    //    graphScene->addLine(mess.x-0.5,mess.y-0.5, mess.x+0.5,mess.y+0.5,
    //    pen); graphScene->addLine(mess.x-0.5,mess.y+0.5,
    //    mess.x+0.5,mess.y-0.5, pen);

    m_graphScene->addItem(new GraphItemNet());

    m_graphView = ui->GV_1;
    m_graphView->setScene(m_graphScene);
    m_graphView->show();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::onReadyRead() {
    QByteArray buffer;
    buffer.resize(m_socket->pendingDatagramSize());
    qDebug() << m_socket->pendingDatagramSize();

    m_socket->readDatagram(buffer.data(), buffer.size());
}
