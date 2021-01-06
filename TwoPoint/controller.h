#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QtCore/QRandomGenerator>

#include "graphic.h"

class Controller : public QThread
{
    Q_OBJECT

public:
    Controller();
    ~Controller();

    void run() override;
    void stopSystem();

signals:
    void newPoint(qreal pointA, qreal pointB);

private:
    bool m_stop;

};

#endif // CONTROLLER_H
