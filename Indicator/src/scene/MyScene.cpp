#include <QLabel>
#include "MyScene.h"

MyScene::MyScene(QObject *parent, QListWidget *listWidget, quint8 mod) : QGraphicsScene(parent),
                                                                         m_listWidget(listWidget), m_mod(mod) {
    createGrid();
    m_airplanes.reserve(256);
    for (int i = 0; i < 256; i++) {
        m_airplanes.push_back(new Airplane(i));
    }
    m_prevNumberList.push_back(0);
}

MyScene::~MyScene() {
    m_airplanes.clear();
//    delete m_listWidget;
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
    Airplane *airplane = m_airplanes.at(numberAirplane);

    if (m_prevNumberList.last() != numberAirplane) {
        airplane = m_airplanes.at(numberAirplane);
        airplane->eraseDataVec();
        m_prevNumberList.push_back(numberAirplane);
        m_numberItem = 0;

        if (airplane->getLabel() == nullptr && airplane->getItemWidget() == nullptr) {
            QLabel *label = new QLabel("track number: " + QString::number(numberAirplane), m_listWidget);
            label->setStyleSheet("color: " + colors[numberAirplane % 5]);
            label->setContextMenuPolicy(Qt::CustomContextMenu);
            connect(label, &QWidget::customContextMenuRequested, this, &MyScene::showContextMenu);

            QListWidgetItem *itemWidget = new QListWidgetItem(m_listWidget);
            m_listWidget->setItemWidget(itemWidget, label);

            // Сортируем элементы в алфавитном порядке
            m_listWidget->setSortingEnabled(true);
            m_listWidget->sortItems();

            airplane->setLabel(label);
            airplane->setItemWidget(itemWidget);
        }
        update();
    }


    ItemEllipse *ellipse = new ItemEllipse(x, y, w, h, m_numberItem, numberAirplane, this);
    ellipse->setColor(color);
    airplane->getMEllipseVec().push_back(ellipse);

    ItemText *textItem = new ItemText(x, y, 0, 0, numberAirplane, m_mod);
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
    connect(showInfo, &QAction::triggered, this, &MyScene::showInfo);

    QAction *hide = new QAction(tr("Скрыть"), this);
    connect(hide, &QAction::triggered, this, &MyScene::hideTravel);

    QAction *show = new QAction(tr("Показать"), this);
    connect(show, &QAction::triggered, this, &MyScene::showTravel);

    QAction *del = new QAction(tr("Удалить"), this);
    connect(del, &QAction::triggered, this, &MyScene::deleteTravel);
    /* Подключаем СЛОТы обработчики для действий контекстного меню */
    /* Устанавливаем действия в меню */
    menu->addAction(showInfo);
    menu->addAction(hide);
    menu->addAction(show);
    menu->addAction(del);
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

void MyScene::deleteTravel() {
    qDebug() << "зашла в удалить";
    Airplane *airplane = m_airplanes.at(m_numberChoose);
    airplane->eraseDataVec();
    airplane->eraseLabel();

    m_listWidget->removeItemWidget(airplane->getItemWidget());
    airplane->eraseWidget();

    if (m_prevNumberList.last() == m_numberChoose) {
        m_prevNumberList.pop_back();
    }

    m_listWidget->sortItems();
}

void MyScene::showInfo() {
    ModalInfoWindow *modalInfoWindow = new ModalInfoWindow(m_airplanes.at(m_numberChoose));
    modalInfoWindow->show();
}

