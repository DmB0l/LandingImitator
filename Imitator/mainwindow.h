#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

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
    void goStart();
    void calcTravel();

  private:
    double m_distanceTraveled = 0;
    double m_period = 0;
    double m_speed = 0;
    double m_distance = 0;
    QUdpSocket *m_socket = nullptr;
    QTimer *m_timer = nullptr;
    quint8 m_trackNumber = 0;
    Ui::MainWindow *ui;
    double calcDistance(double fX, double fY, double fZ, double sX, double sY,
                        double sZ);
};
#endif // MAINWINDOW_H
