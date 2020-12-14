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

    void stopSystem();

signals:
    void newPoint();

private:
    int m_cout;
    bool m_stop;

};

#endif // CONTROLLER_H
