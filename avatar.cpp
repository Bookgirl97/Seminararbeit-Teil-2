#include "avatar.h"
#include "objekt.h"
#include "objekt2.h"
#include "zeichenfeld.h"
#include "punkte.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QPushButton>
#include <QApplication>
#include <QPainter>
#include <QDebug>
extern zeichenFeld * meinZeichenFeld;

void MyRect::keyPressEvent(QKeyEvent *event){
    //Bewegung des Avatars mit den Tastaturpfeilen um die angegebenen Werte/Positionen
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
}

void MyRect::spawn(){
    // Objekt erstellen und anzeigen, Score wird erhöht wenn objekt erstellt wird und auf dem Bildschirm erscheint
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
    //Score wird mit increase() um 1 erhöht wenn ein objekt(enemy) erscheint
    if(enemy->collidesWithItem(enemy)){
        meinZeichenFeld->score->increase();
       }

}

void MyRect::spawny(){
    Enemyy * enemyy = new Enemyy();
    scene()->addItem(enemyy);
    if(enemyy->collidesWithItem(enemyy)){
        meinZeichenFeld->score->increase();
       }

 }








