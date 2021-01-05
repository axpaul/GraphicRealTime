

#include <QtCharts/QValueAxis>

#include <QtCore/QDebug>

#include "graphic.h"

Graphic::Graphic(QGraphicsItem *parent, Qt::WindowFlags wFlags)
    : QChart(QChart::ChartTypeCartesian, parent, wFlags),
      m_series(0),
      m_axisX(new QDateTimeAxis),
      m_axisY(new QValueAxis()),
      m_timeActu(new QDateTime),
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

    addSeries(m_series);

        // 1.Format axe X

    m_axisX->setTickCount(10);
    m_axisX->setFormat("hh:mm:ss");
    m_axisX->setTitleText("Date");
    addAxis(m_axisX,Qt::AlignBottom);
    m_series->attachAxis(m_axisX);

    m_axisX->setMin(QDateTime::currentDateTime().addSecs(0));
    m_axisX->setMax(QDateTime::currentDateTime().addSecs(60));

        // 2.Format axe Y

    m_axisY->setLabelFormat("%i");
    m_axisY->setTitleText("Point");
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

    delete m_timeActu;
}

void Graphic::addPoint(){

    m_mutex->lock();

    //Récupération de l'heure
    *m_timeActu = QDateTime::currentDateTime();

    //Generate random Numbers as test data
    m_y = QRandomGenerator::global()->bounded(5) - 2.5;

    m_series->append(m_timeActu->toMSecsSinceEpoch(),m_y);

    if (m_timeActu->currentDateTime() >= m_axisX->max())
    {
        scroll(60,0);
    }

    m_mutex->unlock();

}



