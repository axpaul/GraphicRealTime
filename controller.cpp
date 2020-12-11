#include "controller.h"

Controller::Controller(){}

Controller::~Controller(){}

void Controller::run(){


    for(m_cout = 0 ; m_cout < 1000 ; m_cout++)
    {
        emit newPoint();
        QThread::sleep(1);
    }

}
