
#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <QObject>
#include <QMap>
#include <QVector>
#include "channels.h"
#include "RingBuffer.h"
#include <array>


class DataManager: public QObject
{
    Q_OBJECT
public:
    DataManager(QObject* p=nullptr);
    void addSample(Channels ch, double t, double v);
    RingBuffer& getBuffer(Channels ch);

signals:
    void updated();

private:
    std::array<RingBuffer, (int)Channels::COUNT> m_buffers;
};
#endif
