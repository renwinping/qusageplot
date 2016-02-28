# QUsagePlot
###### By : Ryan Wang @ HUST
###### Email : wangyuxin@hust.edu.cn
Real-time Usage Plotting Tool For `Qt` Based On `QCustomPlot` Library.

It was originally built for [TaskManager](https://github.com/RyanWangGit/TaskManager), and I split it out to use in other projects.

Add more useful methods in `QCustomPlot` to fit in the need to plot real-time usage graph.

### How to start
Since the class `QUsagePlot` is the subclass of `QCustomPlot`, it has the same way to set up and use `QUsagePlot`.

Follow up the tutorial of `QCustomPlot` [here](http://www.qcustomplot.com/index.php/tutorials/settingup), 
however instead of promoting your own widget to `QCustomPlot`, promote it to `QUsagePlot`, remember to add `printsupport` to your `.pro` file,
If you're using `Visual Studio`, remember to check the `Print Support` checkbox in `Qt Project Settings -> Qt Modules`.

Now you're free to use anything that `QCustomPlot` provides you with, `QUsagePlot` is simply adding more methods to 
help you set up and draw real-time usage graph easilier.

![#1](https://github.com/RyanWangGit/QUsagePlot/raw/master/Screenshots/1.png)

Basically there are four labels at the cornors, 
Use `QUsagePlot::setPlotName` to set the top-left label,
Use `QUsagePlot::setMaximumTime` to set maximum time the bottom-left label,
use `QUsagePlot::setUsageUnit` and `QUsagePlot::setMaximumUsage` to set the maximum usage the top-right label,
The bottom-right label is always set to `0`

Label's font and color can be set via `QUsagePlot::setLabelFont` and `QUsagePlot::setLbaelColor`, by default, the four labels
are set to be gray and `Arial` is used.

`QCustomPlot::toPixmap` is re-designed to leave out grid and bolden the borders when taking a snapshot,
thus making it easy to make out when used to be icons.

`QUsagePlot::setThemeColor` is used to set the theme color, the input should be the color of the border,
the rest of everything will be hanled automatically to match the border color.

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
![#2](https://github.com/RyanWangGit/QUsagePlot/raw/master/Screenshots/2.png)

### Screenshots
![#1]

![#3](https://github.com/RyanWangGit/TaskManager/raw/master/Screenshots/2.png)
Used in [TaskManager](https://github.com/RyanWangGit/TaskManager).

### Libraries
 * `QT 5.5.1 for linux`
 * `QCustomPlot` library.

### License
 GPLv3.