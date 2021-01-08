#include <QtCharts/QValueAxis>

#include <QtCore/QDebug>

#include "graphic.h"

Graphic::Graphic(QGraphicsItem *parent, Qt::WindowFlags wFlags)
    : QChart(QChart::ChartTypeCartesian, parent, wFlags),
      m_series(0),
      m_axisX(new QValueAxis()),
      m_axisY(new QValueAxis()),
      m_controller(new Controller),
      m_mutex(new QMutex),
      m_x(0),
      m_y(0)
{
    m_series = new QSplineSeries(this);

    // Propriété graphique
        // 1.Propriétés du graphe

    this->setTitle("Point aléatoire en fonction du temps");
    this->legend()->hide();
    this->setAnimationOptions(QChart::AllAnimations);

        // 2.Propriétés de la courbe

    QPen red(Qt::red);
    red.setWidth(3);
    m_series->setPen(red);

    // Initialisatuion du graphique

    m_series->append(m_x, m_y);
    addSeries(m_series);

        // 1.Format axe X

    m_axisX->setTickCount(5);
    m_axisX->setLabelFormat("%i");
    m_axisX->setTitleText("Point B");
    addAxis(m_axisX,Qt::AlignBottom);
    m_series->attachAxis(m_axisX);
    m_axisX->setRange(0, 50);

        // 2.Format axe Y

    m_axisY->setLabelFormat("%i");
    m_axisY->setTitleText("Point A");
    addAxis(m_axisY,Qt::AlignLeft);
    m_series->attachAxis(m_axisY);
    m_axisY->setRange(-5, 5);

    //  3.Connexion à la simulation thread

    connect(m_controller, &Controller::newPoint, this, &Graphic::addPoint);
    m_controller->start();
}

Graphic::~Graphic()
{
    m_controller->stopSystem();
    while(m_controller->isRunning()){};
    delete m_controller;

    delete m_axisX;
    delete m_axisY;
}

void Graphic::addPoint(qreal pointA, qreal pointB)
{
    m_mutex->lock();

    //qreal x = plotArea().width() / m_axisX->tickCount();

    //qDebug() << "Max :" << m_axisX->max() << " Min : " << m_axisX->min() << Qt::endl;

    m_middlePos = (m_axisX->max() - m_axisX->min())/2;

    if (m_middlePos < (pointB - m_axisX->min()))
    {
        m_recalDist = ((pointB - m_axisX->min()) - m_middlePos);
        m_xDepalce = (plotArea().width() * m_recalDist) / (m_axisX->max() - m_axisX->min());
    }
    else
    {
        m_xDepalce = 0;
    }

    m_series->append(pointB, pointA);

    if (m_xDepalce != 0)
    {
        scroll(m_xDepalce, 0);
    }

    m_mutex->unlock();
}



