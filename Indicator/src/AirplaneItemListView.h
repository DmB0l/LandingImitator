//
// Created by alex on 14.08.2023.
//

#ifndef INDICATOR_AIRPLANEITEMLISTVIEW_H
#define INDICATOR_AIRPLANEITEMLISTVIEW_H


#include <QStandardItem>
#include <QMenu>
#include <QContextMenuEvent>
#include <QDebug>

class AirplaneItemListView : public QObject, public QStandardItem {
Q_OBJECT

public:
    AirplaneItemListView(const QString &text, QObject *obj = nullptr);

//    bool event(QEvent *event) override;

    bool eventFilter(QObject *obj, QEvent *event) override;

    bool event(QEvent *event) override;
};




#endif //INDICATOR_AIRPLANEITEMLISTVIEW_H
