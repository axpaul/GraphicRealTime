#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QObject>

#include "graphic.h"


QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow window;

    Graphic *graphic = new Graphic;

    QChartView chartView(graphic);
    chartView.setRenderHint(QPainter::Antialiasing);
    window.setCentralWidget(&chartView);
    window.resize(600, 300);
    window.show();


    return a.exec();
}
