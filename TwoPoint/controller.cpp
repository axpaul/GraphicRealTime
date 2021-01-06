#include "controller.h"

Controller::Controller(){}

Controller::~Controller(){}

void Controller::run(){

    m_stop = false;
    int x = 0;

    while(m_stop != true)
    {
        x = x + 1;
        emit newPoint(QRandomGenerator::global()->bounded(5) - 2.5, x);
        //QThread::sleep(QRandomGenerator::global()->bounded(1,1));
        QThread::sleep(1);
    }
}

void Controller::stopSystem()
{
    m_stop = true;
}
