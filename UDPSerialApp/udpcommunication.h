#ifndef UDPCOMMUNICATION_H
#define UDPCOMMUNICATION_H

#include <QObject>
#include <QCoreApplication>
#include <QAbstractSocket>
#include <QUdpSocket>
#include <QHostAddress>
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QDataStream>
#include <QMessageBox>
#include <QThread>
#include <QDir>
#include "globalclass.h"

class UdpCommunication : public QObject
{
    Q_OBJECT
public:
    explicit UdpCommunication(QObject *parent = 0);

private:
    QUdpSocket *udpSocket;
    QHostAddress Source_address;
    unsigned short Source_PortNumber;

    QByteArray Tx_Modbusframebytes;
    QByteArray Rx_Modbusframebytes;

    QHostAddress Destination_address ;
    unsigned short Destination_PortNumber;


signals:
    void ProcessUdpRxData(QByteArray);
public slots:
    void handleReadyRead();
    void displayError(QAbstractSocket::SocketError socketError);
    void closePort();
    bool Reconnect_UDP();
    void sendData(QByteArray data);

};

#endif // UDPCOMMUNICATION_H
