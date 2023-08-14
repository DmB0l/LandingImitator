#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../../../ProtocolPriFolder/protocol.h"
#include <QMainWindow>
#include <QUdpSocket>

#include "../TravelAirplane.h"


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
    double m_startX = 0;
    double m_startY = 0;
    double m_startZ = 0;

    double m_finishX = 0;
    double m_finishY = 0;
    double m_finishZ = 0;

    double m_period = 0;
    double m_speed = 0;
    double m_distance = 0;
    quint8 m_trackNumber = 0;

    double m_timeToTravel = 0;


    QUdpSocket *m_socket = nullptr;
    QTimer *m_timer = nullptr;
    Ui::MainWindow *ui;

    double calcDistance(double fX, double fY, double fZ, double sX, double sY, double sZ);
};
#endif // MAINWINDOW_H
