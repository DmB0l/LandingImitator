#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../ProtocolPriFolder/protocol.h"
#include "GridScene.h"

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
    //    bool eventFilter(QObject *obj, QEvent *event) override;
    QUdpSocket *m_socket;
    GridScene *m_graphScene;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
