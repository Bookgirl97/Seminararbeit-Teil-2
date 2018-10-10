#include "objekt.h"
#include "zeichenfeld.h"
#include <QTimer>
#include <QPushButton>
#include <QApplication>
#include <QGraphicsScene>
#include <QList>
#include <QFont>
#include <QDebug>

extern zeichenFeld * meinZeichenFeld;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsEllipseItem(){


    //zufällige Position der Objekte
    int random_number = rand() % 700;
    setPos(random_number,0);

    // Objektform/farbe
    setRect(50,50,50,50);
    setBrush(Qt::darkCyan);


    // Timer für die Bewegung der Objekte
    QTimer * timern = new QTimer(this);
    QObject::connect(timern,SIGNAL(timeout()),this,SLOT(move()));
    //Geschwindigkeit
    timern->start(50);


}

void Enemy::move(){

    QList<QGraphicsItem *> colliding_items = collidingItems();

    // Kollision von Objekt und Avatar
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(MyRect)){


            // objekt bei kollision entfernen

            scene()->removeItem(this);
            delete this;
           //erstes Leben bei Kollision nicht mehr ausgefüllt
           QPen pen(Qt::darkMagenta);
           meinZeichenFeld->ellipse->setPen(pen);
           meinZeichenFeld->ellipse->setBrush(Qt::black);

            return;
        }
    }


    setPos(x(),y()+5);
    // zerstört Objekt wenn es nicht mehr sichtbar ist
    if (pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;

    }

   }





