#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../ProtocolPriFolder/protocol.h"
#include "GridScene.h"
#include "graphitemGrid.h"
#include "graphscene.h"
#include "graphview.h"

#include <QByteArray>
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

  public slots:
    void onReadyRead();

  private:
    //    GraphItem *graphItem;
    QUdpSocket *m_socket;
    GridScene *m_graphScene;
    GraphView *m_graphView;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
