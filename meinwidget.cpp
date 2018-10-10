#include <QtGui>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
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
#include <QFont>

#include "meinWidget.h"

extern zeichenFeld * meinZeichenFeld;

meinWidget::meinWidget(QWidget *parent):QWidget(parent)
{
  //Buttons fürs Speichern, Laden, Starten und Stoppen
  //Erscheinen auf dem Widget und haben Auswirkungen auf das zeichenfeld/spielfeld
    QPushButton *saver = new QPushButton(tr("Sichern"));
    saver->setFont(QFont("Times", 18, QFont::Bold));
    connect(saver, SIGNAL(clicked()), this, SLOT(saveFile()));

    QPushButton *loader = new QPushButton(tr("Laden"));
    loader->setFont(QFont("Times", 18, QFont::Bold));
    connect(loader, SIGNAL(clicked()), this, SLOT(loadFile()));

    QPushButton *startButton = new QPushButton(tr("Start"));
    startButton->setFont(QFont("Times", 18, QFont::Bold));
    connect(startButton, SIGNAL(clicked()), this, SLOT(start()));

    QPushButton *stopButton = new QPushButton(tr("Stop"));
    stopButton->setFont(QFont("Times", 18, QFont::Bold));
    connect(stopButton, SIGNAL(clicked()), this, SLOT(stop()));

//erstellung es spielfelds
    meinZeichenFeld = new zeichenFeld;
    meinZeichenFeld->show();

    QGridLayout *gridLayout = new QGridLayout;
     //Layout für das Widget, an welcher Stelle was angeordnet wird
    gridLayout->addWidget(loader, 0, 0);
    gridLayout->addWidget(saver, 1, 0);
    gridLayout->addWidget(stopButton, 2, 0);
    gridLayout->addWidget(startButton, 3, 0);
    gridLayout->addWidget(meinZeichenFeld, 0, 1, 3, 1);
    gridLayout->setColumnStretch(1, 10);
    setLayout(gridLayout);
}
//Funktionen für start und stop->die auf dem zeichenfeld stattfinden
void meinWidget::start(void)
{
meinZeichenFeld->start();
}
void meinWidget::stop(void)
{
meinZeichenFeld->stop();
}

//durch saveFile kann man den Spielstand an einer bestimmten Stelle unter einem gewählten Namen speichern
// ->Dialog mit dem User und Hinweise
void meinWidget::saveFile(void){
    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getSaveFileName(this,
                                      tr("Speichern als"), ".", tr("Position (*.pos"));

    if (fileName.isNull()==false)
    {
        file.setFileName(fileName);
        if (!file.open(QIODevice::ReadWrite))
        {
            QMessageBox::warning(this, tr("Dateifehler"),
                                 tr("Folgende Datei kann nicht verwendet werden: ") + fileName,QMessageBox::Ok);
        }

        meinZeichenFeld->serialize(file);
        file.close();
        return;
    }
}
//durch loadFile kann man den Spielstand aus einem Ordner laden ->Dialog mit dem User und Hinweise

void meinWidget::loadFile(void){
    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getOpenFileName(this,
                                      tr("Speichern als"), ".", tr("Position (*.pos)"));

    if (fileName.isNull()==false)
    {
        file.setFileName(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Dateifehler"),
                                 tr("Folgende Datei kann nicht geöffnet werden: ") + fileName,QMessageBox::Ok);
        }

        meinZeichenFeld->deserialize(file);
        file.close();
        return;
    }
}



