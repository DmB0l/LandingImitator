#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QScrollBar>

class MyView : public QGraphicsView {
   public:
    explicit MyView(QWidget *parent);

   protected:
    void wheelEvent(QWheelEvent *event) override;

//    void mouseReleaseEvent(QMouseEvent *event) override;
//    void mousePressEvent(QMouseEvent *event) override;

private:
    QWidget *widget = nullptr;

};

#endif  // MYVIEW_H
