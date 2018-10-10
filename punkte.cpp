#include "punkte.h"
#include "objekt.h"
#include "objekt2.h"
#include "meinwidget.h"
#include <QFont>


Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // anfangs Score ist null
    score = 0;

    // Score als Textelement
    setPlainText(QString("score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(){
    //score immer um eins hochsetzen
        score++;
        update();



}
void Score::update(){
    //score erneuern/laden
    setPlainText(QString("score: ") + QString::number(score));} // Score: 1}


int Score::getScore(){
    //score zurückgeben
    return score;
}

void Score::setScore(int newScore){
    //für deserialize
    score = newScore;
}
