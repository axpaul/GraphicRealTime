#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>

#include "graphic.h"

Graphic::Graphic(QGraphicsItem *parent, Qt::WindowFlags wFlags)
    : QChart(QChart::ChartTypeCartesian, parent, wFlags),
      m_series(0),
      m_axisX(new QValueAxis()),
      m_axisY(new QValueAxis()),
      m_step(0),
      m_x(0),
      m_y(0),
      m_controller(new Controller)
{
    m_series = new QSplineSeries(this);

    QPen red(Qt::red);
    colorLine(red);

    m_series->append(m_x, m_y);


    addSeries(m_series);

    addAxis(m_axisX,Qt::AlignBottom);
    addAxis(m_axisY,Qt::AlignLeft);
    m_series->attachAxis(m_axisX);
    m_series->attachAxis(m_axisY);
    m_axisX->setTickCount(5);
    m_axisX->setRange(-5, 10);
    m_axisY->setRange(-5, 10);

    this->legend()->hide();
    this->setAnimationOptions(QChart::AllAnimations);

    connect(m_controller, &Controller::newPoint, this, &Graphic::addPoint);
    m_controller->start();


}

Graphic::~Graphic(){
    m_controller->stopSystem();
    while(m_controller->isRunning()){};
    delete m_controller;
}

void Graphic::addPoint(){
    qreal x = plotArea().width() / m_axisX->tickCount();
    qreal y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();
    m_x += y;
    m_y = QRandomGenerator::global()->bounded(5) - 2.5;
    m_series->append(m_x, m_y);
    scroll(x, 0);

}

/*void Graphic::nameTitleLegend(QString title, QString axeX, QString axeY){
    this->setTitle(title);

}*/

void Graphic::colorLine(QPen color)
{
    color.setWidth(3);
    m_series->setPen(color);
}

