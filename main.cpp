#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

#include "graphic.h"
#include "controller.h"

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow window;

    window.resize(400, 300);
    window.show();
    return a.exec();
}
