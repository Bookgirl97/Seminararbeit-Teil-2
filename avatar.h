#ifndef AVATAR_H
#define AVATAR_H
#include <QGraphicsRectItem>
#include <QObject>

class MyRect:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);

public slots:
    void spawn();
    void spawny();

};
#endif // AVATAR_H
