#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    graphScene = new GraphScene(this);



    QVector<QPointF> points;
    points << QPointF(0,0) << QPointF(100,100) << QPointF(200,50) << QPointF(300,200);

    QPolygonF polygon(points);
    QGraphicsPolygonItem *polyItem = new QGraphicsPolygonItem(polygon);

    QLine line();
    QPen pen(Qt::black, 0.5, Qt::SolidLine, Qt::RoundCap);
    message mess;
    mess.x = 2;
    mess.y = 2;

    graphScene->addLine(mess.x-0.5,mess.y-0.5, mess.x+0.5,mess.y+0.5, pen);
    graphScene->addLine(mess.x-0.5,mess.y+0.5, mess.x+0.5,mess.y-0.5, pen);

    graphScene->addItem(new GraphItem());
    graphScene->addItem(polyItem);

    graphView = ui->GV_1;
    graphView->setScene(graphScene);
    graphView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

