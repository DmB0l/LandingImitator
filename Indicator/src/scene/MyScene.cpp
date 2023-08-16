#include <QLabel>
#include "MyScene.h"

MyScene::MyScene(QObject *parent, QListWidget *listWidget) : QGraphicsScene(parent), m_listWidget(listWidget){
    createGrid();
}

void MyScene::createGrid() {
    QPen pen(QBrush(QColor(0, 0, 0, 50)), 0.5, Qt::PenStyle::SolidLine);
    int sizeSquare = ROW_COUNT * FIELD_SIZE;


    for (int i = 0; i < sizeSquare * 2; i += FIELD_SIZE) {
        if (i == sizeSquare) {
            pen.setWidthF(3.0);
            pen.setColor(QColor(0, 0, 0, 255));
            this->addLine(i, 0, i, sizeSquare * 2, pen);
            this->addLine(0, i, sizeSquare * 2, i, pen);
            pen.setColor(QColor(0, 0, 0, 50));
            pen.setWidthF(0.5);
        } else {
            this->addLine(i, 0, i, sizeSquare * 2, pen);
            this->addLine(0, i, sizeSquare * 2, i, pen);
        }
    }
}

void MyScene::drawTrack(qreal x, qreal y, qreal w, qreal h, quint8 numberAirplane) {
    QColor color(colors[numberAirplane % 5]);
    Airplane *airplane = nullptr;

    // костыль для случая, если имитатор начнет не с первого номера самолета
    // (заполнение вектора пустыми самолетами до номера под которым началось моделирование)
    while (m_numberAirplane < numberAirplane) {
        airplane = new Airplane(m_numberAirplane);
        m_airplanes.push_back(airplane);
        m_numberAirplane++;
    }

    // если в векторе уже окажется самолет под номером, который сейчас моделируется
    // (перезапись существующего самолета из коллекции на моделирующийся)
    if (!m_airplanes.empty()) {
        airplane = m_airplanes.last();
//        for(int i = 0; i < m_airplanes.size(); i++) {
//            if(m_airplanes.at(i)->getNumber() == numberAirplane) {
//                m_airplanes.insert(i, new Airplane(numberAirplane));
//                airplane = m_airplanes.at(i);
//                break;
//            }
//        }
    }

    if (airplane == nullptr || airplane->getNumber() != numberAirplane) {
        airplane = new Airplane(numberAirplane);
        m_airplanes.push_back(airplane);
        m_numberAirplane++;
        m_numberItem = 0;

        QLabel *label = new QLabel("track number: " + QString::number(numberAirplane), m_listWidget);
        label->setStyleSheet("color: " + colors[numberAirplane % 5]);
        label->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(label, &QWidget::customContextMenuRequested, this, &MyScene::showContextMenu);

        m_listWidget->setItemWidget(new QListWidgetItem(m_listWidget), label);
    }

    ItemEllipse *ellipse = new ItemEllipse(x, y, w, h, m_numberItem, numberAirplane, this);
    ellipse->setColor(color);
    airplane->getMEllipseVec().push_back(ellipse);

    ItemText *textItem = new ItemText(x + 5, y - 15, 0, 00, numberAirplane);
    airplane->getMTextVec().push_back(textItem);
    textItem->setVisible(false);

    this->addItem(ellipse);
    this->addItem(textItem);

    m_numberItem++;
}

const QVector<Airplane *> &MyScene::getMAirplanes() const {
    return m_airplanes;
}

void MyScene::showContextMenu(QPoint pos) {
    QLabel *label = dynamic_cast<QLabel *>(sender());
    QString str = label->text();
    QStringList spl = str.split(':');
    m_numberChoose = spl.at(1).toInt();
    qDebug() << m_numberChoose;

    /* Создаем объект контекстного меню */
    QMenu *menu = new QMenu((QWidget *) parent());
    /* Создаём действия для контекстного меню */
    QAction *showInfo = new QAction(tr("Подробнее"), this);

    QAction *hide = new QAction(tr("Скрыть"), this);
    connect(hide, &QAction::triggered, this, &MyScene::hideTravel);

    QAction *show = new QAction(tr("Показать"), this);
    connect(show, &QAction::triggered, this, &MyScene::showTravel);
    /* Подключаем СЛОТы обработчики для действий контекстного меню */
    /* Устанавливаем действия в меню */
    menu->addAction(showInfo);
    menu->addAction(hide);
    menu->addAction(show);
    /* Вызываем контекстное меню */
    menu->popup(m_listWidget->viewport()->mapToGlobal(pos));
}

void MyScene::hideTravel() {
    qDebug() << "зашла в скрыть";
    Airplane *airplane = m_airplanes.at(m_numberChoose);
    QVector<ItemEllipse *> vec = airplane->getMEllipseVec();
    for (int i = 0; i < vec.size(); i++) {
        vec.at(i)->setVisible(false);
    }

//    dynamic_cast<QAction *> (sender())->setEnabled(false);
}

void MyScene::showTravel() {
    qDebug() << "зашла в показать";
    Airplane *airplane = m_airplanes.at(m_numberChoose);
    for (auto iterator1 = airplane->getMEllipseVec().begin();
         iterator1 < airplane->getMEllipseVec().end(); iterator1++) {
        (*iterator1)->setVisible(true);
    }

//    dynamic_cast<QAction *> (sender())->setEnabled(true);
}

