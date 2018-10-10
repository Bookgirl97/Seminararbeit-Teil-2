#include <vector>
#include <QWidget>
#include <QFile>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include "punkte.h"
#include "avatar.h"
#include "objekt.h"
#include "objekt2.h"


class zeichenFeld : public QGraphicsView{
 Q_OBJECT
public:
    //Definitionen der Items
    zeichenFeld(QWidget *parent = 0);
    QGraphicsScene* scene;
    Score * score;
    QGraphicsEllipseItem *ellipse;
    QGraphicsEllipseItem *ellipse2;
    QGraphicsEllipseItem *ellipse3;
    ~zeichenFeld();



public slots:
    //Funktionen
    void serialize(QFile & file);
    void deserialize(QFile & file);
    //Timer werden bei Klick auf des Startbutton gestartet
    void start(void) {
        timer->start(1000); timern->start(1000);  increment=1; };
     //Timer werden bei Klick auf des Stopbutton gestoppt
    void stop(void) {
        timer->stop();  timern->stop();  increment=0;};
    private:
    QTimer *timer;
    QTimer *timern;
    int increment;
    int phase;
    int x;
};


