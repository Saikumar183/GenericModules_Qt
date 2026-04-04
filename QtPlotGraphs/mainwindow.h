
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QCheckBox>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTimer>

#include "DataManager.h"
#include "PlotManager.h"
#include "ExportManager.h"
#include "Logger.h"

class MainWindow: public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget* p=nullptr);

private:
    QCustomPlot* plot;
    DataManager dm;
    PlotManager* pm;
    ExportManager* ex;
    Logger log;
};
#endif
