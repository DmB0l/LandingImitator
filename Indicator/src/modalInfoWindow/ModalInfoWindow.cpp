//
// Created by alex on 17.08.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ModalInfoWindow.h" resolved

#include "ModalInfoWindow.h"
#include "ui_ModalInfoWindow.h"


ModalInfoWindow::ModalInfoWindow(Airplane *airplane, QWidget *parent) :
        QWidget(parent), ui(new Ui::ModalInfoWindow), m_airplane(airplane) {
    ui->setupUi(this);
    if (m_airplane != nullptr) {
        ui->L_trackNumber->setText("Track number: " + QString::number(m_airplane->getNumber()));

        QStringList horizontalHeaders;
        horizontalHeaders << "number track" << "Coords (x,y)";
        ui->TW->setHorizontalHeaderLabels(horizontalHeaders);
        ui->TW->verticalHeader()->setVisible(false);

        ui->TW->setRowCount(airplane->getMEllipseVec().size());
        ui->TW->setColumnCount(2);

        ui->TW->setColumnWidth(0, this->width() / 2 - 5);
        ui->TW->setColumnWidth(1, this->width() / 2 - 5);

        int row = 0;
        for (auto it = airplane->getMEllipseVec().begin(); it < airplane->getMEllipseVec().end(); it++) {
            if (row == 0)
                ui->TW->setItem(row, 0, new QTableWidgetItem("Начальна позиция"));
            else if (row == airplane->getMEllipseVec().size() - 1)
                ui->TW->setItem(row, 0, new QTableWidgetItem("Конечная позиция"));
            else
                ui->TW->setItem(row, 0, new QTableWidgetItem(QString::number(row)));

            ui->TW->setItem(row, 1, new QTableWidgetItem(
                    "(" + QString::number((*it)->getMX() - MyScene::SIZE_SQUARE + 2) + "; " +
                    QString::number(-((*it)->getMY() - MyScene::SIZE_SQUARE + 2)) + ")"));
            row++;
        }
    }
    ui->TW->update();
}

ModalInfoWindow::~ModalInfoWindow() {
//    delete m_airplane;
    delete ui;
}
