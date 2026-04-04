
#include "Logger.h"
Logger::Logger(QObject* p):QObject(p){}
void Logger::start(QString file){
    f.setFileName(file);
    f.open(QIODevice::WriteOnly|QIODevice::Text);
    s.setDevice(&f);
}
void Logger::log(QString p,double t,double v){
    s<<p<<","<<t<<","<<v<<"\n";
}
