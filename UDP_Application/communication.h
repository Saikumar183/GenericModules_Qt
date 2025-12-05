#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QObject>
#include <QCoreApplication>
#include <QAbstractSocket>
#include <QUdpSocket>
#include <QHostAddress>
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QDataStream>
//#include "application_variables.h"
#include <QMessageBox>
#include <QThread>
#include <QDir>
#include "globalclass.h"
class Communication : public QObject
{
    Q_OBJECT
public:
    explicit Communication(QObject *parent = 0);
    uint16_t MODBUS_CRC16_v1( const unsigned char *buf, unsigned int len );
    QHostAddress Source_address;
    unsigned short Source_PortNumber;

    QByteArray Tx_Modbusframebytes;
    QByteArray Rx_Modbusframebytes;

    QHostAddress Destination_address ;
    unsigned short Destination_PortNumber;
    void Test_Frame(QByteArray, unsigned int);
    typedef enum
    {
        SOURCE=0,
        DESTINATION,
        MAX_CLIENTS
    }IP_PortNumber;
    typedef enum
    {
        SOURCEID_INDEX=0,
        DESTID_INDEX,
        PAYLOADSIZE_INDEX,
        PAYLOAD_INDEX=4
    }Rx_DataIndex;
    bool waitForModbusUDPResponse(QByteArray &receivedData, int expectedLength, quint8 functionCode, int timeoutMs);

    bool ModbusdataoverUart_flag = false;

signals:
    void SendData_toMainWindow(uint8_t, uint8_t ,const QByteArray );
    void updateAlarmTableWithString(uint16_t _nodeNumber, uint16_t _ErrorNumber);
    void UpdateLogTable(QString);
    void showStatusMessage(QString);
    void showStatusMessage(QString,int);
    void UpdateScreen();
    void RetryCommuinication();
    void UpdateDateTime();
    void Debug_Application(void);
    void loadNetworkData(void);
    void showMsgOnLoginScreen(QString);
    void processReceivedFrame(QByteArray rxData);
    void processReceivedFrame_Slave(QByteArray rxData);
    void SendModbusFrame(QByteArray frame, int expectedLength, quint8 functionCode, int timeoutMs);
void ModbusFrameResponse(QByteArray data, bool success);
public slots:
void handleReadyRead();
    void CheckHeartBeat();
    void displayError(QAbstractSocket::SocketError socketError);
    void sendData(const QHostAddress &destination, quint16 destinationPort, const QByteArray &data) ;
    void sendData(uint32_t );
    void sendData(char );
    void sendData(QByteArray);
    void Init_UDP_Communication();
    bool Reconnect_UDP();
    void connectNetwork();
    void closePort();
    void buildModbusRTUFrame(quint8 slaveId, quint8 functionCode, quint16 startAddress,
                             long* dataAddress, quint16 dataSize);
      void ModbusFrameResponseHandler(QByteArray data, bool success);

private:
    QUdpSocket *udpSocket;
#if 0
    QHostAddress Source_address = (QHostAddress)"192.168.2.80";
    unsigned short Source_PortNumber = 2002;

    QHostAddress Destination_address = (QHostAddress)"192.168.2.81";
    unsigned short Destination_PortNumber = 2001;
#else


#endif
    QDateTime lastHeartbeatReceived;
    char _heartBeartStatus;

    bool _check_CRC(unsigned short checkSum);
    void ProcessRxData(QByteArray);
    quint16 calculateCRC16(const QByteArray &data);
    QByteArray ReturnFinalDataFrame_Tx(const char* _Data,unsigned short _dataSize);
    QByteArray ReturnFinalDataFrame_Tx(const uint32_t _Data,unsigned short _dataSize);
    //     uint16_t MODBUS_CRC16_v1( const unsigned char *buf, unsigned int len );

    typedef struct
    {
        unsigned char m_CRC_HIGH;
        unsigned char m_CRC_LOW;

    }CRC;
    union
    {
        unsigned short m_CheckSum;
        CRC _crcData;
    }_checkSum;

};

#endif // COMMUNICATION_H
