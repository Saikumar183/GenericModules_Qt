#include "DataManager.h"

DataManager::DataManager(QObject *parent)
    : QObject(parent)
{
}

void DataManager::addSample(Channels ch, double t, double v)
{
    m_buffers[(int)ch].push(t, v);
}

RingBuffer& DataManager::getBuffer(Channels ch)
{
    return m_buffers[(int)ch];
}
