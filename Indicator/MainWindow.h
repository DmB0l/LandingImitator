#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QDesktopWidget>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QLine>
#include <QMainWindow>
#include <QPen>
#include <QUdpSocket>

#include "../ProtocolPriFolder/protocol.h"
#include "MyScene.h"
#include "MyView.h"

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
    void onReadyRead();

   private:
    Ui::MainWindow *ui;

    MyView *m_view = nullptr;
    MyScene *m_scene = nullptr;
    QGraphicsItem *m_item = nullptr;

    QUdpSocket *m_socket = nullptr;
};
#endif  // MAINWINDOW_H
