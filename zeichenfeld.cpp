#include <QtGui>
#include "zeichenFeld.h"
#include "avatar.h"
#include "punkte.h"
#include "objekt.h"
#include "objekt2.h"
#include <QMessageBox>
#include <QTimer>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFormLayout>
#include <QProgressBar>
#include <QKeyEvent>
#include <QPainter>
#include <QWidget>
#include <QDebug>
#include <QObject>
#include <QTabWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QList>
#include <QFile>
#include <QBrush>
#include <QGraphicsItem>
#include <QDebug>
#include <QFont>
#include <QPen>
#include <QTextStream>
#include <QTime>
#include <QGraphicsTextItem>
#include <QTextStream>
#include <QtGui>
#include <iostream>


zeichenFeld::zeichenFeld(QWidget *parent) {
    //spielfeld eigenschaften
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setPalette(QPalette(QColor(250, 250, 200)));
    setFixedSize(700,600);
    setAutoFillBackground(true);
    setMouseTracking(false);

    //GraphicsScene erstellen + Eigenschaften um GraphicsItems zu verwenden

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,700,600);
    setScene(scene);
    scene->setBackgroundBrush(Qt::black);
    QGraphicsView * view = new QGraphicsView(scene);

//Spieler/Avatar erstellen + Eigenschaften (Position, Form, Farbe etc.)
    MyRect * avatar = new MyRect();
    avatar->setRect(0,0,100,100);
    QBrush brush(Qt::lightGray, Qt::BDiagPattern);
    avatar->setBrush(brush);
    QPen pen(Qt::blue);
    avatar->setPen(pen);

    avatar->setFlag(QGraphicsItem::ItemIsFocusable);
    avatar->setFocus();
    scene->addItem(avatar);
    avatar->setPos(scene->width()/2,scene->height() - avatar->rect().height());

   //Timer für die Funktion spawn(Lässt die objekte auf dem Bildschirm erscheinen und generiert neue Objekte)
    increment=0;
    phase=0;
    timer=new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),avatar,SLOT(spawn()));
    //Erstellung des Scores
    score = new Score();
    scene->addItem(score);

    timern = new QTimer(this);
    QObject::connect(timern,SIGNAL(timeout()),avatar,SLOT(spawny()));


    //die drei Leben
    ellipse = new QGraphicsEllipseItem();
    ellipse->setBrush(Qt::darkMagenta);
    ellipse->setRect(600, 20, 20, 20);
    scene->addItem(ellipse);

    ellipse2 = new QGraphicsEllipseItem();
    ellipse2->setBrush(Qt::darkMagenta);
    ellipse2->setRect(630, 20, 20, 20);
    scene->addItem(ellipse2);

    ellipse3 = new QGraphicsEllipseItem();
    ellipse3->setBrush(Qt::darkMagenta);
    ellipse3->setRect(660, 20, 20, 20);
    scene->addItem(ellipse3);


//GraphcicsScene zeigen

    show();
}

zeichenFeld::~zeichenFeld(){
}


void zeichenFeld::serialize(QFile &file)
{
    QTextStream out(&file);
    //Score als QString speichern ->mit getScore erstellung des integers newScore

    out << "Mein Zeichnungsformat" << endl;
    out << "score: " << QString::number(score->getScore());

}

void zeichenFeld::deserialize(QFile & file)
{

    QTextStream in(&file);
    //Lesen des gespeicherten QStrings
    int lineNumber = 0;
    while (in.atEnd() == false){
        QString line = in.readLine();
        if(lineNumber == 0){
            //Überprüfung des Strings
            if(line!= QString("Mein Zeichnungsformat")){
                QMessageBox::warning(this,tr("Fehler"), tr("kein Zeichnugsformat"), QMessageBox::Ok);
                return;
            }
        }
        else{
            //Suche des gespeicherten Strings und diesen als QStringList array aufspliten, erster Teil des Arrays
            // ist array[0] und entspricht "score" zweiter Teil ist array [1] und gibt den Integerwert des Scores an
            //also die Zahl des Scores
            if(line.startsWith(QString("score: "))){
                QStringList array = line.split(QString(" "));

                int newScore = array[1].toInt();
                //Score wird erstellt und geladen
                //im Spielfeld kann nun mit dem gespeicherten Score weitergespielt werden
                score->setScore(newScore);
                score->update();
            }
        }
        lineNumber++;
            }
        }

