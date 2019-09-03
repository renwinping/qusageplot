# QUsagePlot [![Build Status](https://travis-ci.com/yxwangcs/qusageplot.svg?branch=master)](https://travis-ci.com/yxwangcs/qusageplot)

Real-time Usage Plotting Tool For `Qt` Based On `QCustomPlot` Library.

It was originally built for [taskmanager](https://github.com/yxwangcs/taskmanager/tree/v1.0-qt-based), and I split it out to be used in other projects.

Add more useful methods in `QCustomPlot` to fit in the need to plot real-time usage graph.

### How to start
Since the class `QUsagePlot` is the subclass of `QCustomPlot`, it has the same way to set up and use `QUsagePlot`.

Follow up the tutorial of `QCustomPlot` [here](http://www.qcustomplot.com/index.php/tutorials/settingup),
however instead of promoting your own widget to `QCustomPlot`, promote it to `QUsagePlot`, remember to add `printsupport` to your `.pro` file,
If you're using `Visual Studio`, remember to check the `Print Support` checkbox in `Qt Project Settings -> Qt Modules`.

Now you're free to use anything that `QCustomPlot` provides you with, `QUsagePlot` is simply adding more methods to
help you set up and draw real-time usage graph easilier.

### Set up the widget

<img src="https://github.com/yxwangcs/qusageplot/raw/master/screenshots/1.png" width="50%" />

Basically there are four labels at the cornors:

- Use `QUsagePlot::setPlotName` to set the top-left label.

- Use `QUsagePlot::setMaximumTime` to set maximum time the bottom-left label.

- Use `QUsagePlot::setUsageUnit` and `QUsagePlot::setMaximumUsage` to set the maximum usage the top-right label,
The bottom-right label is always set to `0`.

- Use `QUsagePlot::setTimeUnit` to set the unit, by default, "Sec" is used.

Label's font and color can be set via `QUsagePlot::setLabelFont` and `QUsagePlot::setLbaelColor`, by default, the four labels
are set to be gray and `Arial` is used.

`QCustomPlot::toPixmap` is re-designed to leave out grid and bolden the borders when taking a snapshot,
thus making it easy to make out when used to be icons.

`QUsagePlot::setThemeColor` is used to set the theme color, the input should be the color of the border,
the rest of everything will be handled automatically to match the border color.

### Add real-time data
Data is added via `QUsagePlot::addData(double data)`, by calling this method, `data` is added to
the tail of the real-time data sequence, the head of the sequence is removed, if the size of it
is larger than what we previously set via `QUsagePlot::setMaximumTime`.

You can simply call this method multiple times to add a set of data but the common use of it
is to call it repeatedly, like, connect a slot to `QTimer::timeout` signal, in the slot, do some
data processing and call `QUsagePlot::addData`, thus making it a real-time plotting tool.

### Sample code for setting up

Following the code below

```cpp
// setup cpu usage plot
ui.widget->setPlotName("CPU Utilization %");
ui.widget->setMaximumTime(60);
ui.widget->setMaximumUsage(100);
ui.widget->setUsageUnit("%");
ui.widget->setThemeColor(QColor(17, 125, 187));

// simulate data
for (int i = 0; i < 60; i++)
  ui.widget->addData(qrand() % 99);
```

Gives us output like

<img src="https://github.com/yxwangcs/qusageplot/raw/master/screenshots/2.png" width="50%" />

### Screenshots for [taskmanager](https://github.com/yxwangcs/taskmanager/tree/v1.0-qt-based)
<img src="https://github.com/yxwangcs/taskmanager/blob/v1.0-qt-based/screenshots/2.png?raw=true" width="50%" />

### License
[GPLv3](https://github.com/yxwangcs/qusageplot/blob/master/LICENSE).
