#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QThread>
#include <QDebug>

#include "graphic.h"

class Controller : public QThread
{
    Q_OBJECT

public:
    Controller();
    ~Controller();

    void run() override;

public slots:

signals:

};

#endif // CONTROLLER_H
