
#include "mainwindow.h"
#include <QtMath>
#include <QHBoxLayout>
#include <QFileDialog>

MainWindow::MainWindow(QWidget* parent):QMainWindow(parent)
{
    QWidget* w = new QWidget;
    setCentralWidget(w);

    QHBoxLayout* mainL = new QHBoxLayout(w);

    plot = new QCustomPlot;
    mainL->addWidget(plot, 3);

    QVBoxLayout* side = new QVBoxLayout;
    mainL->addLayout(side, 1);

    pm = new PlotManager(plot, &dm, this);
    ex = new ExportManager(plot, this);

    // ✅ Add channels ONLY ONCE
    pm->addChannel(Channels::CH1, "CH1");
    pm->addChannel(Channels::CH2, "CH2");
    pm->addChannel(Channels::CH3, "CH3");
    pm->addChannel(Channels::CH4, "CH4");
    pm->addChannel(Channels::CH5, "CH5");

    // ✅ Checkbox mapping (ENUM SAFE)
    struct ChannelUI {
        QString name;
        Channels ch;
    };

    QVector<ChannelUI> channels = {
        {"CH1", Channels::CH1},
        {"CH2", Channels::CH2},
        {"CH3", Channels::CH3},
        {"CH4", Channels::CH4},
        {"CH5", Channels::CH5}
    };

    for (auto chData : channels)
    {
        QCheckBox* cb = new QCheckBox(chData.name);
        cb->setChecked(true);
        side->addWidget(cb);

        connect(cb, &QCheckBox::toggled, this, [=](bool en){
            pm->enable(chData.ch, en);
        });
    }

    // ✅ Time window
    QLineEdit* timeEdit = new QLineEdit("5");
    side->addWidget(timeEdit);

    QPushButton* apply = new QPushButton("Apply Time");
    side->addWidget(apply);

    connect(apply, &QPushButton::clicked, [=](){
        pm->setWindow(timeEdit->text().toDouble());
    });

    // ✅ Pause / Resume
    QPushButton* pause = new QPushButton("Pause");
    QPushButton* resume = new QPushButton("Resume");

    side->addWidget(pause);
    side->addWidget(resume);

    connect(pause, &QPushButton::clicked, [=](){ pm->pause(true); });
    connect(resume, &QPushButton::clicked, [=](){ pm->pause(false); });

    // ✅ Export buttons
    QPushButton* pdf = new QPushButton("Export PDF");
    QPushButton* png = new QPushButton("Export PNG");
    QPushButton* jpg = new QPushButton("Export JPG");

    side->addWidget(pdf);
    side->addWidget(png);
    side->addWidget(jpg);

    connect(png, &QPushButton::clicked, this, [=]() {
        QString file = QFileDialog::getSaveFileName(this, "Save PNG", "", "PNG Files (*.png)");
        if (!file.isEmpty()) ex->png(file);
    });

    connect(pdf, &QPushButton::clicked, this, [=]() {
        QString file = QFileDialog::getSaveFileName(this, "Save PDF", "", "PDF Files (*.pdf)");
        if (!file.isEmpty()) ex->pdf(file);
    });

    connect(jpg, &QPushButton::clicked, this, [=]() {
        QString file = QFileDialog::getSaveFileName(this, "Save JPG", "", "JPG Files (*.jpg)");
        if (!file.isEmpty()) plot->saveJpg(file, 1920, 1080);
    });

    // ✅ Cursor reset
    QPushButton *resetCursor = new QPushButton("Reset Cursor");
    side->addWidget(resetCursor);

    connect(resetCursor, &QPushButton::clicked, [=]() {
        pm->resetCursor();
    });

    // 🔥 IMPORTANT: Separate timers

    // ✅ FAST DATA TIMER (simulate high-speed input)
    QTimer* dataTimer = new QTimer(this);
    connect(dataTimer, &QTimer::timeout, [=]() {
        static double x = 0;
        x += 0.001;  // high-speed

        dm.addSample(Channels::CH1, x, 1.0 * sin(x));          // small sine
        dm.addSample(Channels::CH2, x, 5.0 * cos(x));          // big cosine
        dm.addSample(Channels::CH3, x, 2.0 * sin(2*x));        // fast sine
        dm.addSample(Channels::CH4, x, (int(x*2)%2)*4 - 2);    // square
        dm.addSample(Channels::CH5, x, fmod(x,2.0));           // sawtooth

//        log.log("CH1", x, qSin(x));
    });
    dataTimer->start(1); // 1 ms

    // ✅ SLOW UI TIMER (smooth rendering)
    QTimer* uiTimer = new QTimer(this);
    connect(uiTimer, &QTimer::timeout, pm, &PlotManager::updatePlot);
    uiTimer->start(50); // 20 FPS

    log.start("log.csv");
}
