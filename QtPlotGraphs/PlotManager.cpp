
#include "PlotManager.h"
#include <algorithm>

PlotManager::PlotManager(QCustomPlot* p,DataManager* d,QObject* parent)
:QObject(parent),plot(p),data(d)
{
    setWindow(5);
    plot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);
    plot->legend->setVisible(true);

    // Cursor line
    m_cursorLine = new QCPItemLine(plot);
    m_cursorLine->setPen(QPen(Qt::red, 1, Qt::DashLine));

    // Cursor text
    m_cursorText = new QCPItemText(plot);
    m_cursorText->setPositionAlignment(Qt::AlignTop | Qt::AlignLeft);
    m_cursorText->position->setType(QCPItemPosition::ptPlotCoords);

    // Cursor 1
    m_cursor1 = new QCPItemLine(plot);
    m_cursor1->setPen(QPen(Qt::green, 1, Qt::DashLine));

    // Cursor 2
    m_cursor2 = new QCPItemLine(plot);
    m_cursor2->setPen(QPen(Qt::blue, 1, Qt::DashLine));

    connect(plot, &QCustomPlot::mousePress,
            this, &PlotManager::onMouseClick);

    m_scaleText = new QCPItemText(plot);
    m_scaleText->setPositionAlignment(Qt::AlignTop | Qt::AlignLeft);
    m_scaleText->position->setType(QCPItemPosition::ptAxisRectRatio);
    m_scaleText->position->setCoords(0.01, 0.01); // top-left

    m_scaleText->setPen(QPen(Qt::yellow));
    m_scaleText->setBrush(QBrush(QColor(0,0,0,150)));

    for (int var = 0; var < (int)Channels::COUNT; ++var) {
        m_voltPerDiv[var] = 1.0;
    }
}
void PlotManager::addChannel(Channels ch, QString name)
{
    QCPGraph *g = plot->addGraph();
    g->setName(name);

    QColor color = QColor::fromHsv((int)ch * 70 % 360, 255, 200);
    g->setPen(QPen(color, 2));

    m_graphs[(int)ch] = g;
}
void PlotManager::enable(QString n,bool en){
    if(!graphs.contains(n))return;
    graphs[n]->setVisible(en);
    if(en) enabled.insert(n); else enabled.remove(n);
}
void PlotManager::enable(Channels ch, bool en)
{
    if (!m_graphs[(int)ch]) return;

    m_graphs[(int)ch]->setVisible(en);
}

void PlotManager::setWindow(double w){window=w;}
void PlotManager::pause(bool p){paused=p;}
void PlotManager::onMouseClick(QMouseEvent *event)
{
    double x = plot->xAxis->pixelToCoord(event->pos().x());

    // ✅ Make visible again
    m_cursor1->setVisible(true);
    m_cursor2->setVisible(true);
    m_cursorText->setVisible(true);

    if (!m_useSecondCursor)
    {
        m_cursor1X = x;

        m_cursor1->start->setCoords(x, plot->yAxis->range().lower);
        m_cursor1->end->setCoords(x, plot->yAxis->range().upper);

        m_useSecondCursor = true;
    }
    else
    {
        m_cursor2X = x;

        m_cursor2->start->setCoords(x, plot->yAxis->range().lower);
        m_cursor2->end->setCoords(x, plot->yAxis->range().upper);

        m_useSecondCursor = false;
    }

    double delta = qAbs(m_cursor2X - m_cursor1X);

    m_cursorText->setText(QString("Δt = %1 sec").arg(delta, 0, 'f', 3));
    m_cursorText->position->setCoords(x, plot->yAxis->range().upper);

    plot->replot(QCustomPlot::rpQueuedReplot);
}
void PlotManager::decimate(const std::vector<double>& inX,
              const std::vector<double>& inY,
              QVector<double>& outX,
              QVector<double>& outY,
              int factor)
{
    outX.clear();
    outY.clear();

    for (size_t i = 0; i < inX.size(); i += factor)
    {
        outX.append(inX[i]);
        outY.append(inY[i]);
    }
}
void PlotManager::updatePlot()
{
    if(paused)
    {
        return;
    }
    double globalMin = 1e9;
    double globalMax = -1e9;

    double t_now = 0;

    // =========================
    // PASS 1: Get RAW min/max (IMPORTANT)
    // =========================
    for (int i = 0; i < (int)Channels::COUNT; i++)
    {
        Channels ch = (Channels)i;

        auto &buffer = data->getBuffer(ch);

        std::vector<double> rawX, rawY;
        buffer.getData(rawX, rawY);

        if (rawY.empty()) continue;

        auto minmax = std::minmax_element(rawY.begin(), rawY.end());

        globalMin = std::min(globalMin, *minmax.first);
        globalMax = std::max(globalMax, *minmax.second);
    }

    if (globalMin > globalMax) return;

    double range = globalMax - globalMin;
    if (range < 0.0001) range = 1.0;

    // =========================
    // ADD MARGIN (FIX CLIPPING)
    // =========================
    double margin = range * 0.1;
    globalMin -= margin;
    globalMax += margin;

    const int Y_DIV = 8;

    double vPerDiv = range / Y_DIV;
    vPerDiv = niceNumber(vPerDiv);

    // Store per channel
    for (int i = 0; i < (int)Channels::COUNT; i++)
        m_voltPerDiv[i] = vPerDiv;

    // =========================
    // SET Y AXIS (BEFORE PLOTTING)
    // =========================
    plot->yAxis->setRange(globalMin, globalMax);

    // =========================
    // PASS 2: Plot with decimation
    // =========================
    for (int i = 0; i < (int)Channels::COUNT; i++)
    {
        Channels ch = (Channels)i;

        if (!m_graphs[i]) continue;

        auto &buffer = data->getBuffer(ch);

        std::vector<double> rawX, rawY;
        buffer.getData(rawX, rawY);

        if (rawX.empty()) continue;

        QVector<double> plotX, plotY;

        int factor = rawX.size() / 500;
        if (factor < 1) factor = 1;

        for (size_t k = 0; k < rawX.size(); k += factor)
        {
            plotX.append(rawX[k]);
            plotY.append(rawY[k]);
        }

        m_graphs[i]->setData(plotX, plotY);

        t_now = plotX.last();
    }

    // =========================
    // X AXIS (TIME WINDOW)
    // =========================
    plot->xAxis->setRange(t_now - window, t_now);

    // =========================
    // SCALE TEXT (UNITS/DIV)
    // =========================
    QString text;
    text += QString("Time: %1 sec/div\n").arg(m_timePerDiv);

    for (int i = 0; i < (int)Channels::COUNT; i++)
    {
        text += QString("CH%1: %2 unit/div\n")
                .arg(i + 1)
                .arg(m_voltPerDiv[i]);
    }

    m_scaleText->setText(text);

    // =========================
    // FINAL DRAW
    // =========================
    plot->replot(QCustomPlot::rpQueuedReplot);
}
void PlotManager::resetCursor()
{
    // Optional: resume plotting
    pause(false);

    // ✅ Hide cursor lines
    if (m_cursor1) m_cursor1->setVisible(false);
    if (m_cursor2) m_cursor2->setVisible(false);

    // ✅ Hide text
    if (m_cursorText)
    {
        m_cursorText->setText("");
        m_cursorText->setVisible(false);
    }

    // ✅ Reset internal state
    m_cursor1X = 0;
    m_cursor2X = 0;
    m_useSecondCursor = false;

    // ✅ Force redraw
    plot->replot(QCustomPlot::rpQueuedReplot);
}
double PlotManager::niceNumber(double value)
{
    double exp = floor(log10(value));
    double base = value / pow(10, exp);

    if (base < 1.5) base = 1;
    else if (base < 3) base = 2;
    else if (base < 7) base = 5;
    else base = 10;

    return base * pow(10, exp);
}
