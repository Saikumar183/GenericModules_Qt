#include "communication.h"
#include <QApplication>
#include <QElapsedTimer>

Communication::Communication(QObject *parent) :
    QObject(parent)
{
    udpSocket = new QUdpSocket(this);

    connect(udpSocket, &QUdpSocket::readyRead, this, &Communication::handleReadyRead);
    connect(udpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
}

void Communication::Init_UDP_Communication()
{
    Source_address = QHostAddress("172.16.31.58");
    Source_PortNumber = 53010;

    Destination_address = QHostAddress("192.168.127.51");
    Destination_PortNumber = 53011;

//    if (udpSocket) {
//        delete udpSocket;
//    }

    udpSocket = new QUdpSocket(this);

    connect(udpSocket, &QUdpSocket::readyRead, this, &Communication::handleReadyRead);

    if (udpSocket->bind(Source_address, Source_PortNumber, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint)) {
        Application.UpdateStatusLabel(QString("Listening on port: %1 — %2")
                              .arg(Source_PortNumber)
                              .arg(Source_address.toString()), false);

    } else {
         Application.UpdateStatusLabel(QString("Failed to bind to port:- %1 — %2 ")
                           .arg(Source_PortNumber)
                           .arg(Source_address.toString()), true);
    }

    // Use old style signal-slot for error signal on Qt < 5.15
    connect(udpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
}

void Communication::handleReadyRead()
{
//     qDebug()<<"----";
//    if(Application.Modbusconnection_isUdpBusy) return;
    if(Application.isMasterChecked && !Application.isSlaveChecked) return;

    while (udpSocket->hasPendingDatagrams())
    {
        //        qDebug()<<"----";//<<MyApplication.UDP_ConnectionStatus;
        Application.Modbusconnection_RxFlag = true;
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        QHostAddress sender;
        unsigned short senderPort;
        udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        // Assuming Application.RxData is a char* or uint8_t* buffer
        Application.RxData = datagram;
        //        memcpy(Application.RxData.Data(), datagram.constData(), datagram.size());
        if (datagram.size() >= Application.expectedLength)
        {
            Application.RxPackets++;
            ProcessRxData(datagram);
        }
    }
}

void Communication::displayError(QAbstractSocket::SocketError socketError)
{
    QString UdpErrorStatus = udpSocket->errorString();
//    qDebug()<<socketError<<UdpErrorStatus;
//    emit UpdateLogTable(UdpErrorStatus);
//    emit showStatusMessage(UdpErrorStatus);
    if( UdpErrorStatus =="The bound address is already in use")
    {
        QMessageBox msgBox(QMessageBox::Warning, "Alert", "Application is already Open. By clicking Ok or close icon, this application will quit.",QMessageBox::Ok);
        msgBox.setWindowFlags(Qt::FramelessWindowHint);
        msgBox.show();

        // Quit Application
        QApplication::quit();
    }
    else if(( UdpErrorStatus == "Unknown error") || (UdpErrorStatus == "Unable to send a message"))
    {
        Application.isConnectionActive =false;
        Application.isPortBindCompleted = false;
        qDebug() << "Socket error occurred:"<<socketError ;
        Reconnect_UDP();
        //        QMessageBox::warning(nullptr,"Alert","Check Network Cable or CPU Status");
    }
//    qDebug() << "Socket error occurred:" << socketError<<udpSocket->errorString();
}

bool Communication::_check_CRC(unsigned short checkSum)
{
    static unsigned int _trueCntr=0;
    static unsigned int _falseCntr=0;
    if(_checkSum.m_CheckSum == checkSum)
    {
        _trueCntr++;
        //        qDebug()<<"CRC Mached - True......"<<_trueCntr;
        return true;
    }
    _falseCntr++;
    //    qDebug()<<"CRC Not Mached - False......"<<_falseCntr;
    return false;
}

void Communication::ProcessRxData(QByteArray rxData)
{
//     qDebug()<<"\nRx - String ;"<<rxData.size()<<rxData;

         emit processReceivedFrame_Slave(rxData);
}

QByteArray Communication::ReturnFinalDataFrame_Tx(const uint32_t _Data, unsigned short _dataSize)
{
#define DATA_SIZE_INDEX 3
#define DATA_INDEX      5
#define DATA_CRC_INDEX      8

    unsigned short ID[3];
    ID[0] = 1;
    ID[1] = 2;
    ID[2] = 1;

    QByteArray FinalData(10,0);

    unsigned short checkSum=0;
    FinalData[0] = ID[0]  ;
    FinalData[1] = ID[1]  ;
    FinalData[2] = ID[2]  ;
    qDebug()<<0<<FinalData;
    memcpy(FinalData.data()+DATA_SIZE_INDEX, &_dataSize, sizeof(_dataSize));
    qDebug()<<1<<FinalData;
    memcpy(FinalData.data()+DATA_INDEX, &_Data, sizeof(_Data));
    qDebug()<<2<<FinalData;

    checkSum=MODBUS_CRC16_v1((unsigned char*)FinalData.data(),(FinalData.size()-2));
    memcpy(FinalData.data()+DATA_CRC_INDEX,&checkSum,sizeof(checkSum));

    qDebug()<<3<<FinalData<<checkSum;
    return FinalData;
}

QByteArray Communication::ReturnFinalDataFrame_Tx(const char *_Data, unsigned short _dataSize)
{
    unsigned short ID[3];
    ID[0] = 1;
    ID[1] = 2;
    ID[2] = 1;
    size_t sourceSize = strlen(_Data);

    QByteArray FinalData(sourceSize+7,0);

    unsigned short checkSum=0;
    FinalData[0] = ID[0]  ;
    FinalData[1] = ID[1]  ;
    FinalData[2] = ID[2]  ;

    memcpy(FinalData.data()+3,&_dataSize,sizeof(_dataSize));
    memcpy(FinalData.data()+5,_Data,_dataSize);

    checkSum=MODBUS_CRC16_v1((unsigned char*)FinalData.data(),(FinalData.size()-2));
    memcpy(FinalData.data()+5+_dataSize,&checkSum,sizeof(checkSum));

    //    qDebug() << "Final Data...."<<_dataSize<<checkSum<<FinalData;
    return FinalData;

}

uint16_t Communication::MODBUS_CRC16_v1(const unsigned char *buf, unsigned int len)
{
    uint16_t crc = 0xFFFF;
    unsigned int i = 0;
    char bit = 0;

    for( i = 0; i < len; i++ )
    {
        crc ^= buf[i];

        for( bit = 0; bit < 8; bit++ )
        {
            if( crc & 0x0001 )
            {
                crc >>= 1;
                crc ^= 0xA001;
            }
            else
            {
                crc >>= 1;
            }
        }
    }
    return crc;
}

void Communication::sendData(const QHostAddress &destination, quint16 destinationPort, const QByteArray &data)
{
    udpSocket->writeDatagram(data, destination, destinationPort);
}

void Communication::sendData(char _flagStatus)
{
    QByteArray data;
    char *_Data;//(char *)&_flagStatus;
    _Data = &_flagStatus;
//    qDebug() << "........"<<_flagStatus;

    data = ReturnFinalDataFrame_Tx(_Data,sizeof(_flagStatus));

    udpSocket->writeDatagram(data,Destination_address, Destination_PortNumber);
    //    qDebug() << "Data.............."<<data;
}

void Communication::sendData(QByteArray data)
{
//    for(int i= 0; i<data.size(); i++)
//    {
//        qDebug() << "\n..."<<data.at(i);
//    }
    udpSocket->writeDatagram(data,Destination_address, Destination_PortNumber);
    Tx_Modbusframebytes = data;
    Rx_Modbusframebytes = 0;
    Application.RxData = 0;


    Application.Modbusconnection_TxFlag = true;
    Application.TxPackets++;
}

void Communication::sendData(uint32_t _flagStatus)
{
    QByteArray data;
//    qDebug() << "........"<<_flagStatus;

    data = ReturnFinalDataFrame_Tx(_flagStatus,sizeof(_flagStatus));

    udpSocket->writeDatagram(data,Destination_address, Destination_PortNumber);
//    qDebug() << "Data.............."<<data;
}

void Communication::CheckHeartBeat()
{
    // Example Modbus frame bytes (hex): 01 10 00 00 00 02 04 00 0A 00 00 D3 AD
    // We'll build it as a QByteArray (without CRC first, will add after)

    QByteArray frame;
    frame.append(char(0x01)); // Slave ID
    frame.append(char(0x10)); // Function code
    frame.append(char(0x00)); // Starting address high byte
    frame.append(char(0x00)); // Starting address low byte
    frame.append(char(0x00)); // Quantity high byte
    frame.append(char(0x02)); // Quantity low byte
    frame.append(char(0x04)); // Byte count
    frame.append(char(0x00)); // Data bytes start
    frame.append(char(0x0A));
    frame.append(char(0x00));
    frame.append(char(0x00));

    // Calculate CRC16 over the frame (all bytes so far)
    uint16_t crc = MODBUS_CRC16_v1(reinterpret_cast<const unsigned char*>(frame.constData()), frame.size());

    // Append CRC low byte then high byte (Modbus CRC is little endian)
    frame.append(char(crc & 0xFF));         // CRC Low byte
    frame.append(char((crc >> 8) & 0xFF));  // CRC High byte

    qDebug() << "Sending Modbus Frame Size:" << frame.size() << "Data (hex):" << frame.toHex()<<"---------"<<frame.toUpper();

    // Send frame over UDP
    sendData(frame);
}

void Communication::Test_Frame(QByteArray _Data, unsigned int _size)
{
    // Frame bytes without CRC (first 11 bytes)
    QByteArray frame;
    frame.append(char(0x01)); // Slave ID
    frame.append(char(0x10)); // Function code
    frame.append(char(0x00)); // Starting address high byte
    frame.append(char(0x00)); // Starting address low byte
    frame.append(char(0x00)); // Quantity high byte
    frame.append(char(0x02)); // Quantity low byte
    frame.append(char(0x04)); // Byte count
    frame.append(char(0x00)); // Data bytes start
    frame.append(char(0x0A));
    frame.append(char(0x00));
    frame.append(char(0x00));

    // Calculate CRC16 on the first 11 bytes
    uint16_t crc = MODBUS_CRC16_v1(reinterpret_cast<const unsigned char*>(frame.constData()), frame.size());

    // Append CRC (low byte first, then high byte)
    frame.append(char(crc & 0xFF));         // CRC low byte
    frame.append(char((crc >> 8) & 0xFF));  // CRC high byte

    // Debug output
    qDebug() << "Sending Modbus frame:" << frame.toHex().toUpper();

    // Send via UDP
    if (udpSocket)
    {
        udpSocket->writeDatagram(frame, Destination_address, Destination_PortNumber);
    }
}

bool Communication::Reconnect_UDP()
{
    bool CommState = false;

    Source_address = Application.Source_address;
    Source_PortNumber = Application.Source_PortNumber;
    Destination_address = Application.Destination_address;
    Destination_PortNumber = Application.Destination_PortNumber;

    // Abort if it's in any state other than unconnected
    if (udpSocket->state() != QAbstractSocket::UnconnectedState) {
        udpSocket->abort();  // Closes the socket immediately
    }
    // Attempt to bind with ReuseAddressHint for more reliability
    if (udpSocket->bind(Source_address, Source_PortNumber, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint))
    {
         Application.isPortBindCompleted = true;
        CommState = true;
        Application.UpdateStatusLabel(QString("Listening on port:- %1  %2 ").arg(Source_PortNumber).arg(Source_address.toString()), false);
    }
    else
    {
        Application.isPortBindCompleted = false;
        Application.UpdateStatusLabel(QString("Failed to bind to port:- %1  %2 ").arg(Source_PortNumber).arg(Source_address.toString()), true);
    }
//    // Try sending a heartbeat after bind
//    CheckHeartBeat();

    return CommState;
}

void Communication::connectNetwork()
{

    emit loadNetworkData();
    if(!Application.ModbusURATCONN_Flag)
    {
        Reconnect_UDP();

    }
}

void Communication::closePort()
{
    if(Application.isPortBindCompleted)
    {
//        qDebug()<<"abort";
        Application.isPortBindCompleted = false;
         Application.UpdateStatusLabel(QString("Port Closed :- %1  %2 ").arg(Application.Source_PortNumber).arg(Application.Source_address.toString()), true);
        udpSocket->abort();
    }
}

void Communication::buildModbusRTUFrame(quint8 slaveId, quint8 functionCode, quint16 startAddress,
                                        long* dataAddress, quint16 dataSize)
{
    qDebug()<<"....00";
    QByteArray frame;
    QByteArray receivedData;
    int timeoutMs = 500;      // response timeout
    int maxRetries = 2;
    int retries = 0;
    bool success = false;
//    memset(Application.TxData.data(),0,256);
    Application.TxData = 0;
    Application.RxData = 0;
    quint16 registerCount = dataSize;
    if(Application.is32BitChecked)
    {
        registerCount = dataSize * 2;
    }
    frame.append(static_cast<char>(slaveId));
    frame.append(static_cast<char>(functionCode));

    switch (functionCode) {
    case MODBUS_FUNC_READ_COILS:
    case MODBUS_FUNC_READ_DISCRETE_INPUTS:
        Application.expectedLength = 5 + (registerCount * 2);
        frame.append(static_cast<char>((startAddress >> 8) & 0xFF));
        frame.append(static_cast<char>(startAddress & 0xFF));
        frame.append(static_cast<char>((registerCount >> 8) & 0xFF));
        frame.append(static_cast<char>(registerCount & 0xFF));
        break;
    case MODBUS_FUNC_READ_HOLDING_REGISTERS:
    case MODBUS_FUNC_READ_INPUT_REGISTERS:
        Application.expectedLength = 5 + (registerCount * 2);
        frame.append(static_cast<char>((startAddress >> 8) & 0xFF));
        frame.append(static_cast<char>(startAddress & 0xFF));
        frame.append(static_cast<char>((registerCount >> 8) & 0xFF));
        frame.append(static_cast<char>(registerCount & 0xFF));
        break;

    case MODBUS_FUNC_WRITE_SINGLE_REGISTER:
        Application.expectedLength = 8;
        {  qDebug()<<"....010";
            quint16 value = static_cast<quint16>(*dataAddress & 0xFFFF);
            frame.append(static_cast<char>((startAddress >> 8) & 0xFF));
            frame.append(static_cast<char>(startAddress & 0xFF));
            frame.append(static_cast<char>((value >> 8) & 0xFF));
            frame.append(static_cast<char>(value & 0xFF));
        }  qDebug()<<"....011";
        break;

    case MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS:
        Application.expectedLength = 8;
        {
            quint8 byteCount = registerCount * 2;
            frame.append(static_cast<char>((startAddress >> 8) & 0xFF));
            frame.append(static_cast<char>(startAddress & 0xFF));
            frame.append(static_cast<char>((registerCount >> 8) & 0xFF));
            frame.append(static_cast<char>(registerCount & 0xFF));
            frame.append(static_cast<char>(byteCount));

            for (int i = 0; i < dataSize; ++i) {
                quint32 val = static_cast<quint32>(dataAddress[i]);
                quint16 high = static_cast<quint16>((val >> 16) & 0xFFFF);
                quint16 low  = static_cast<quint16>(val & 0xFFFF);

                frame.append(static_cast<char>((low >> 8) & 0xFF));
                frame.append(static_cast<char>(low & 0xFF));
                frame.append(static_cast<char>((high >> 8) & 0xFF));
                frame.append(static_cast<char>(high & 0xFF));
            }
        }
        break;

    default:
        Application.UpdateStatusLabel(QString("Unsupported function code: %1").arg(functionCode), true);
        Application.Modbusconnection_isUdpBusy  = false;
        return;
    }
    qDebug()<<"....01";
    // Append CRC
    quint16 crc = calculateCRC16(frame);
    frame.append(static_cast<char>(crc & 0xFF));         // CRC Low byte
    frame.append(static_cast<char>((crc >> 8) & 0xFF));  // CRC High byte

//    Application.UpdateStatusLabel("Sending Modbus frame: " + frame.toHex(), false);
    Application.TxData = frame;
    // Retry loop for sending and receiving
    while (retries < maxRetries && !success)
    {
        if(!Application.ModbusURATCONN_Flag)
        {
            Application.RxData.clear();
            Application.Modbusconnection_isUdpBusy  = true;
            sendData(frame);
            success = waitForModbusUDPResponse(receivedData, Application.expectedLength, functionCode, timeoutMs);

            emit processReceivedFrame(receivedData);

            // Assign Modbus data
            Tx_Modbusframebytes = frame;                // assuming 'frame' is QString
            Rx_Modbusframebytes = receivedData;         // assuming 'receivedData' is QString
            // Convert QByteArray to hex string with space-separated bytes
        }
        else
        {
            // Use QEventLoop to wait for asynchronous response via signal

            Tx_Modbusframebytes = frame;
            Rx_Modbusframebytes.clear();


            QEventLoop loop;
            QByteArray responseData;
            bool responseSuccess = false;

            QTimer timer;
            timer.setSingleShot(true);
            connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);

            // Connect the ModbusFrameResponse signal to capture the async response
            auto conn = connect(this, &Communication::ModbusFrameResponse,
                                &loop, [&](QByteArray resp, bool ok) {
                    responseData = resp;
                    responseSuccess = ok;
                    loop.quit();
        });

            emit SendModbusFrame(frame, Application.expectedLength, functionCode, timeoutMs);

            timer.start(timeoutMs + 100);
            loop.exec();

            disconnect(conn);

            receivedData = responseData;
            success = responseSuccess;
            Rx_Modbusframebytes = receivedData;
        }
        if (!success)
        {
            retries++;
            Application.ErrorPackets++;

            Application.UpdateStatusLabel(QString("Retrying... Attempt %1").arg(retries), true);
        }
        else
        {
            Application.RxData = receivedData;
            Application.Modbusconnection_RxFlag = true;
            Application.RxPackets++;
        }
    }

    if (!success) {
        Application.UpdateStatusLabel("No Response from the slave after retries.", true);
        Application.Modbusconnection_isUdpBusy  = false;
        return;
    }

    if (receivedData.size() < 3) {
        Application.UpdateStatusLabel("Incomplete Modbus response.", true);
        Application.Modbusconnection_isUdpBusy  = false;
        return;
    }

    // Check for Modbus exception response
    if (static_cast<quint8>(receivedData[1]) & 0x80)
    {
        quint8 exceptionCode = static_cast<quint8>(receivedData[2]);
        QString msg = QString("Modbus Exception: Function %1, Code %2")
                        .arg(static_cast<quint8>(receivedData[1]) & 0x7F)
                        .arg(exceptionCode);
        Application.UpdateStatusLabel(msg, true);

        switch (exceptionCode) {
        case 0x01:
            Application.UpdateStatusLabel("Illegal Function", true);
            break;
        case 0x02:
            Application.UpdateStatusLabel("Illegal Data Address", true);
            break;
        case 0x03:
            Application.UpdateStatusLabel("Illegal Data Value", true);
            break;
        case 0x04:
            Application.UpdateStatusLabel("Slave Device Failure", true);
            break;
        case 0x06:
            Application.UpdateStatusLabel("Slave Device Busy", true);
            break;
        default:
            Application.UpdateStatusLabel("Unknown Modbus Exception Code", true);
            break;
        }

        Application.Modbusconnection_isUdpBusy  = false;
        return;
    }
/*
    // Process normal responses
    if (functionCode == 0x03 || functionCode == 0x04)
    {
        quint16 registerCount = (Application.expectedLength - 5) / 2;
        quint16 dataSizeResp = registerCount / 2;

        quint8 byteCount = static_cast<quint8>(receivedData[2]);
        if (byteCount != registerCount * 2) {
            Application.UpdateStatusLabel("Byte count mismatch in Modbus response.", true);
            Application.Modbusconnection_isUdpBusy  = false;
            return;
        }

        for (int i = 0; i < dataSizeResp; ++i)
        {
            int base = 3 + (i * 4);
            if (base + 3 >= receivedData.size())
            {
                Application.UpdateStatusLabel("Index out of bounds while parsing response.", true);
                Application.Modbusconnection_isUdpBusy  = false;
                return;
            }

            quint8 lowHi = static_cast<quint8>(receivedData[base]);
            quint8 lowLo = static_cast<quint8>(receivedData[base + 1]);
            quint8 highHi = static_cast<quint8>(receivedData[base + 2]);
            quint8 highLo = static_cast<quint8>(receivedData[base + 3]);

            quint16 lowWord = (lowHi << 8) | lowLo;
            quint16 highWord = (highHi << 8) | highLo;
            quint32 full = (static_cast<quint32>(highWord) << 16) | lowWord;

            dataAddress[i] = full;
        }

        Application.UpdateStatusLabel("data updated.", false);

    } else if (functionCode == 0x06)
    {
        if (receivedData.size() < 8) {
            Application.UpdateStatusLabel("Invalid response length for 0x06", true);
            Application.Modbusconnection_isUdpBusy  = false;
            return;
        }

        quint16 recvValue = (static_cast<quint8>(receivedData[4]) << 8) |
                             static_cast<quint8>(receivedData[5]);

        dataAddress[0] = static_cast<quint32>(recvValue);
        Application.UpdateStatusLabel(QString("Write Single Confirmed. Value = %1").arg(recvValue), false);

    } else if (functionCode == 0x10) {
        if (receivedData.size() < 8) {
            Application.UpdateStatusLabel("Invalid response length for 0x10", true);
            Application.Modbusconnection_isUdpBusy  = false;
            return;
        }

        quint16 recvAddress = (static_cast<quint8>(receivedData[2]) << 8) |
                              static_cast<quint8>(receivedData[3]);
        quint16 recvCount = (static_cast<quint8>(receivedData[4]) << 8) |
                            static_cast<quint8>(receivedData[5]);

        if (recvAddress != startAddress || recvCount != registerCount) {
            Application.UpdateStatusLabel("Mismatch in write confirmation.", true);
            Application.Modbusconnection_isUdpBusy  = false;
            return;            
        }
        Application.UpdateStatusLabel(QString("Write Multiple Confirmed. Address = %1 Count = %2")
                          .arg(recvAddress).arg(recvCount), false);
    }*/
    Application.RxData = receivedData;
    Application.Modbusconnection_isUdpBusy  = false;
}

bool Communication::waitForModbusUDPResponse(QByteArray &receivedData, int expectedLength, quint8 functionCode, int timeoutMs)
{
    receivedData.clear();

    QElapsedTimer timer;
    timer.start();

    while (timer.elapsed() < timeoutMs) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 10);

        while (udpSocket->hasPendingDatagrams()) {
            QByteArray datagram;
            datagram.resize(static_cast<int>(udpSocket->pendingDatagramSize()));
            udpSocket->readDatagram(datagram.data(), datagram.size());
            receivedData.append(datagram);
        }

        if (expectedLength > 0 && receivedData.size() >= expectedLength) {
            break;
        }
    }

    // Final validation
    if (receivedData.size() < 5)
    {
        Application.UpdateStatusLabel(QString("Response too short"), true);
        return false;
    }

    quint8 respFuncCode = static_cast<quint8>(receivedData[1]);
    if (respFuncCode != functionCode)
    {
        Application.UpdateStatusLabel(QString("Function code mismatch. Expected: %1 Got: %2")
                          .arg(functionCode).arg(respFuncCode), true);
        return false;
    }

    if (expectedLength > 0 && receivedData.size() < expectedLength)
    {
        Application.UpdateStatusLabel(QString("Timeout waiting for full response. Got: %1 Expected: %2")
                          .arg(receivedData.size()).arg(expectedLength), true);
        return false;
    }

    return true;
}

// CRC-16 (Modbus) calculation
quint16 Communication:: calculateCRC16(const QByteArray &data) {
    quint16 crc = 0xFFFF;
    for (char byte : data) {
        crc ^= static_cast<quint8>(byte);
        for (int i = 0; i < 8; ++i) {
            if (crc & 0x0001)
                crc = (crc >> 1) ^ 0xA001;
            else
                crc >>= 1;
        }
    }
    return crc;
}


void Communication::ModbusFrameResponseHandler(QByteArray data, bool success)
{
    emit ModbusFrameResponse(data, success);
}

