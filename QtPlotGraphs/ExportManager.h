
#ifndef EXPORTMANAGER_H
#define EXPORTMANAGER_H
#include <QObject>
#include ".././QCustomPlot/qcustomplot/qcustomplot.h"

class ExportManager: public QObject
{
    Q_OBJECT
public:
    ExportManager(QCustomPlot*,QObject* p=nullptr);
    void pdf(QString);
    void png(QString);

private:
    QCustomPlot* plot;
};
#endif
