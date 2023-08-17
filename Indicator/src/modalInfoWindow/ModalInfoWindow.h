//
// Created by alex on 17.08.2023.
//

#ifndef INDICATOR_MODALINFOWINDOW_H
#define INDICATOR_MODALINFOWINDOW_H

#include <QWidget>

#include "../airplane/Airplane.h"
#include "src/scene/MyScene.h"


QT_BEGIN_NAMESPACE
namespace Ui { class ModalInfoWindow; }
QT_END_NAMESPACE

class ModalInfoWindow : public QWidget {
Q_OBJECT

public:
    explicit ModalInfoWindow(Airplane *airplane = nullptr, QWidget *parent = nullptr);

    ~ModalInfoWindow() override;

private:
    Ui::ModalInfoWindow *ui;

    Airplane *m_airplane = nullptr;
};


#endif //INDICATOR_MODALINFOWINDOW_H
