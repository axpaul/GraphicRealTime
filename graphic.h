#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QObject>
#include <QtCharts/QChart>
#include <QtCore/QTimer>
#include <QDebug>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class Graphic : public QChart
{
    Q_OBJECT

public:
    explicit Graphic(QChart *parent = nullptr);


signals:


};

#endif // GRAPHIC_H
