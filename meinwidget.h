#include <QWidget>
#include "zeichenFeld.h"
#include "objekt.h"

class meinWidget : public QWidget{

    Q_OBJECT

public:
    meinWidget(QWidget *parent = 0);


private slots:
    void saveFile(void);
    void loadFile(void);
    void start(void);
    void stop(void);
};
