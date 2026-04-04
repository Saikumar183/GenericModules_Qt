
#ifndef PLOTMANAGER_H
#define PLOTMANAGER_H
#include <QObject>
#include <QMap>
#include <QSet>
#include ".././QCustomPlot/qcustomplot/qcustomplot.h"
#include "DataManager.h"
//#include <QCPItemLine>
//#include <QCPItemText>

#include "channels.h"

class PlotManager: public QObject
{
    Q_OBJECT
public:
    PlotManager(QCustomPlot*,DataManager*,QObject* p=nullptr);
    void addChannel(Channels ch, QString name);
    void enable(QString,bool);
    void setWindow(double);
    void pause(bool);

public slots:
    void onMouseClick(QMouseEvent *event);
private:
    QCustomPlot* plot;
    DataManager* data;
    QMap<QString,QCPGraph*> graphs;
    QSet<QString> enabled;

    bool paused=false;
    double window = 5.0; // default 5 sec window
    QCPItemLine *m_cursorLine;
    QCPItemText *m_cursorText;
    std::array<QCPGraph*, (int)Channels::COUNT> m_graphs;

    // 🔥 Dual cursor (Step 4)
    QCPItemLine *m_cursor1;
    QCPItemLine *m_cursor2;

    bool m_useSecondCursor = false;
    double m_cursor1X = 0;
    double m_cursor2X = 0;

        // 🔹 Time per division (display purpose)
        double m_timePerDiv = 1.0;

        // 🔹 Voltage/unit per division (per channel)
        std::array<double, (int)Channels::COUNT> m_voltPerDiv;

        // 🔹 Overlay text (units display)
        QCPItemText *m_scaleText;

    double niceNumber(double value);
public:
    void resetCursor();
    void decimate(const std::vector<double> &inX, const std::vector<double> &inY, QVector<double> &outX, QVector<double> &outY, int factor);
    void updatePlot();
    void enable(Channels ch, bool en);
};
#endif
