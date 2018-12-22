#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "usageplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->usageplot->setPlotName("CPU Utilization");
    ui->usageplot->setMaximumTime(60);
    ui->usageplot->setUsageUnit("%");
    ui->usageplot->setMaximumUsage(100);
    ui->usageplot->setThemeColor(QColor(17, 125, 187));

    // simulate data
    for (int i = 0; i < 60; i++)
      ui->usageplot->addData(qrand() % 99);
}

MainWindow::~MainWindow()
{
    delete ui;
}
