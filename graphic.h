#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QObject>
#include <QtCharts/QChart>
#include <QtCore/QTimer>
#include <QDebug>

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

    void nameTitleLegend(QString title, QString axeX, QString axeY);

public slots:
    void addPoint();

private:
    QSplineSeries *m_series;
    QStringList m_titles;
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;
    qreal m_step;
    qreal m_x;
    qreal m_y;

    Controller *m_controller;


};

#endif // GRAPHIC_H
