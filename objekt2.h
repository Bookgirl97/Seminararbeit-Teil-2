#ifndef OBJEKT2_H
#define OBJEKT2_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>


class Enemyy: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Enemyy(QGraphicsItem * parent=0);
public slots:
    void movey();
};
#endif // OBJEKT2_H
