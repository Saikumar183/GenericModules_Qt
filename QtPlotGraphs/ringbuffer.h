#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <vector>

class RingBuffer
{
public:
    RingBuffer(int size = 5000)
        : m_size(size), m_index(0)
    {
        x.resize(size);
        y.resize(size);
    }

    void push(double t, double v)
    {
        x[m_index] = t;
        y[m_index] = v;
        m_index = (m_index + 1) % m_size;
    }

    void getData(std::vector<double>& outX, std::vector<double>& outY)
    {
        outX.clear();
        outY.clear();

        for (int i = 0; i < m_size; i++)
        {
            int idx = (m_index + i) % m_size;
            outX.push_back(x[idx]);
            outY.push_back(y[idx]);
        }
    }

private:
    int m_size;
    int m_index;

    std::vector<double> x;
    std::vector<double> y;
};

#endif
