
#include "ExportManager.h"
ExportManager::ExportManager(QCustomPlot* p,QObject* parent):QObject(parent),plot(p){}
void ExportManager::pdf(QString f){plot->savePdf(f);}
void ExportManager::png(QString f)
{
    if (!f.endsWith(".png"))
        f += ".png";

//    plot->savePng(f, 1920, 1080);
    plot->savePng(f, 3840, 2160); // 4K
}
