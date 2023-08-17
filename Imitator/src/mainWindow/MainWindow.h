#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QTime>
#include <QTimer>
#include <QtMath>

#include "../../../ProtocolPriFolder/protocol.h"
#include "src/travelAirplane/TravelAirplane.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private slots:
    void onDeleteTrackNumber();
    void onDeleteAll();
    void goStart();
    void changeProgBar(double newVal);
    void unlockButtons();

  private:
    quint8 m_trackNumber = 0;

    Ui::MainWindow *ui;

    double calcDistance(double fX, double fY, double fZ, double sX, double sY, double sZ);
};
#endif // MAINWINDOW_H
