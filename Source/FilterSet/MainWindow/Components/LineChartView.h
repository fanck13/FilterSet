#pragma once

#include <QDockWidget>

#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>


class LineChartView : public QDockWidget
{
    Q_OBJECT

public:
    LineChartView(QWidget *parent = Q_NULLPTR);
    ~LineChartView();
};
