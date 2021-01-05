#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QObject>
#include <QDebug>
#include <QDate>
#include <QMutex>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QAbstractAxis>
#include <QtCore/QRandomGenerator>

#include <QtCore/QTimer>
#include <QtCore/QDateTime>
#include <QtCore/QDebug>

#include "controller.h"

class Controller;

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class Graphic : public QChart
{
    Q_OBJECT

public:
    Graphic(QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = {});
    ~Graphic();

public slots:
    void addPoint(qreal newPoint);

private:
    QSplineSeries *m_series;
    QDateTimeAxis *m_axisX;
    QValueAxis *m_axisY;   
    QDateTime *m_timeActu;
    Controller *m_controller;
    QMutex *m_mutex;
    qreal m_x;
    qreal m_y;
};

#endif // GRAPHIC_H
