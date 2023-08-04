#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "graphitemNet.h"
#include "graphscene.h"
#include "graphview.h"
#include "graphitemNet.h"
#include "../ProtocolPriFolder/protocol.h"

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

private:
//    GraphItem *graphItem;
    GraphScene *graphScene;
    GraphView *graphView;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
