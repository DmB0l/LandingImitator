#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "./ProtocolPriFolder/protocol.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private slots:
    void goStart();
    void calcTravel();

  private:
    double m_distanceTraveled;
    double m_period;
    double m_speed;
    double m_distance;
    QTimer *timer = nullptr;
    quint8 m_trackNumber;
    Ui::MainWindow *ui;
    double calcDistance(double fX, double fY, double fZ, double sX, double sY,
                        double sZ);
};
#endif // MAINWINDOW_H
