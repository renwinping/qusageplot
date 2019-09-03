TEMPLATE = app
TARGET = demo
QT += core gui widgets printsupport
INCLUDEPATH += ../ ../qcustomplot

HEADERS += ../qcustomplot/qcustomplot.h ../usageplot.h mainwindow.h
SOURCES += ../qcustomplot/qcustomplot.cpp ../usageplot.cpp main.cpp mainwindow.cpp

FORMS += \
    mainwindow.ui
