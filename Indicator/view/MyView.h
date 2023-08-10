#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
#include <QScrollBar>

class MyView : public QGraphicsView {
   public:
    explicit MyView(QWidget *parent);

   protected:
    void wheelEvent(QWheelEvent *event) override;

};

#endif  // MYVIEW_H
