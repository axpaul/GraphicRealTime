#include "controller.h"

Controller::Controller(){}

Controller::~Controller(){}

void Controller::run(){

    m_stop = false;

    while(m_stop != true)
    {
        emit newPoint();
        QThread::sleep(1);
    }

}

void Controller::stopSystem()
{
    m_stop = true;
}
