#ifndef OBJEKT_H
#define OBJEKT_H
#include <QGraphicsEllipseItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>


class Enemy: public QObject,public QGraphicsEllipseItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
public slots:
    void move();
};
#endif // OBJEKT_H
