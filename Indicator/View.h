#ifndef VIEW_H
#define VIEW_H

#include <QDebug>
#include <QEvent>
#include <QGraphicsView>

class View : public QGraphicsView {
  public:
    View();
    View(QWidget *parent = nullptr);

    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // VIEW_H
