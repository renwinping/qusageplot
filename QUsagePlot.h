#ifndef USAGEPLOT_H
#define USAGEPLOT_H

#include "qcustomplot.h"

class QUsagePlot : public QCustomPlot
{
    Q_OBJECT
private:
    enum Position
    {
        TopLeft, TopRight, BottomLeft, BottomRight
    };
    bool isReplotBlocked;
    QVector<double> time, usage;
    QList<QLabel *> cornorLabel;
protected:
    virtual void resizeEvent(QResizeEvent *event);
public:
    QUsagePlot(QWidget * parent = nullptr);
    void setMaximumTime(unsigned int max);
    void setPlotName(const QString & name);
    void setMaximumUsage(double max);
    void setThemeColor(const QColor & themeColor, unsigned int scale = 1);
    void setUsageUnit(const QString & unit);
    void setLabelFont(const QFont & font);
    void setLabelColor(const QColor & color);
    void addData(double data);
    QPixmap toPixmap(int width = 0, int height = 0, double scale = 1.0);
    void replot();
};

#endif // QUSAGEPLOT_H
