
#ifndef LOGGER_H
#define LOGGER_H
#include <QObject>
#include <QFile>
#include <QTextStream>

class Logger: public QObject
{
    Q_OBJECT
public:
    Logger(QObject* p=nullptr);
    void start(QString);
    void log(QString,double,double);

private:
    QFile f;
    QTextStream s;
};
#endif
