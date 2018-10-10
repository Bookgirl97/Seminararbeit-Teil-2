#include "objekt2.h"
#include "zeichenfeld.h"
#include <QTimer>
#include <QPushButton>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QList>
#include <QFont>
#include <QDebug>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>

//siehe objekt.cpp
extern zeichenFeld * meinZeichenFeld;

Enemyy::Enemyy(QGraphicsItem *parent): QObject(), QGraphicsRectItem(){



    int random_number = rand() % 700;
    setPos(random_number,0);


    setRect(0,0,50,50);
    setBrush(Qt::darkGreen);


    QTimer * timerm = new QTimer(this);
    QObject::connect(timerm,SIGNAL(timeout()),this,SLOT(movey()));
    timerm->start(40);


}

void Enemyy::movey(){

     QList<QGraphicsItem *> colliding_items = collidingItems();
    // collisionCounter=0;

     for (int i = 0, n = colliding_items.size(); i < n; ++i){
         if (typeid(*(colliding_items[i])) == typeid(MyRect)){

             scene()->removeItem(this);
             delete this;

             QPen pen(Qt::darkMagenta);
             meinZeichenFeld->ellipse->setPen(pen);
             meinZeichenFeld->ellipse->setBrush(Qt::black);

             QTime dieTime= QTime::currentTime().addSecs(1); //Verzögert um 1 Sekundehare
             while (QTime::currentTime() < dieTime){ //bisherige Zeit ist kleiner als die neue Zeit->dehnt die Zeit
                 QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
             }
            // ++collisionCounter;

             return;


             }


     }


     setPos(x(),y()+5);
     if (pos().y() + rect().height() < 0){
         scene()->removeItem(this);
         delete this;

     }


}





