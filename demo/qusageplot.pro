TEMPLATE = app
TARGET = demo
QT += core gui widgets printsupport
INCLUDEPATH += ../

HEADERS += qcustomplot.h ../usageplot.h mainwindow.h
SOURCES += qcustomplot.cpp ../usageplot.cpp main.cpp mainwindow.cpp

FORMS += \
    mainwindow.ui
