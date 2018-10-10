#include "meinwidget.h"
#include <iostream>
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

zeichenFeld * meinZeichenFeld;

int main(int argc, char *argv[])
{
    //Erstellung des Widgets, auf dem sich das Spielfeld und alles andere befindet
    QApplication app(argc, argv);
    meinWidget widget;
    widget.setGeometry(100, 100, 500, 355);
    widget.show();
    return app.exec();
}
