#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>

class MyView : public QGraphicsView {
   public:
    MyView(QWidget *parent);

   protected:
    void wheelEvent(QWheelEvent *event) override;
};

#endif  // MYVIEW_H
