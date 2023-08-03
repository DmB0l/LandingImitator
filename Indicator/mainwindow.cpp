#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    graphScene = new GraphScene(this);
    graphScene->addItem(new GraphItem());

    graphView = ui->GV_1;
    graphView->setScene(graphScene);

    graphView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

