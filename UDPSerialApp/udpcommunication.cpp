#include "udpcommunication.h"

UdpCommunication::UdpCommunication(QObject *parent) : QObject(parent)
{
    udpSocket = new QUdpSocket(this);

    connect(udpSocket, &QUdpSocket::readyRead, this, &UdpCommunication::handleReadyRead);
    connect(udpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
}


void UdpCommunication::handleReadyRead()
{
//    qDebug()<<"rx---0";
//    if(Application.isMasterChecked && !Application.isSlaveChecked)
    if(!(Application.isMasterChecked && (Application.isSlaveChecked == false)))
    {
        return;
    }
    if(!Application.isModbusUdpEnabled)
    {
        return;
    }
    if(!Application.Modbusconnection_TxFlag)
    {
//         qDebug()<<"rx---1";
        while (udpSocket->hasPendingDatagrams())
        {

//            Application.Modbusconnection_RxFlag = true;
            QByteArray datagram;
            datagram.resize(udpSocket->pendingDatagramSize());
            QHostAddress sender;
            unsigned short senderPort;
            udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
//            qDebug()<<"rx---"<<datagram;
            emit ProcessUdpRxData(datagram);
//            Application.RxData = datagram;
//            Application.RxPackets++;
        }
    }
}

void UdpCommunication::displayError(QAbstractSocket::SocketError socketError)
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

void UdpCommunication::sendData(QByteArray data)
{
    udpSocket->writeDatagram(data,Destination_address, Destination_PortNumber);
    Tx_Modbusframebytes = data;
    Rx_Modbusframebytes = 0;
}

bool UdpCommunication::Reconnect_UDP()
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
        emit UpdateLogString(QString("Listening on port:- %1  %2 ").arg(Source_PortNumber).arg(Source_address.toString()));
    }
    else
    {
        Application.isPortBindCompleted = false;
        emit UpdateLogString(QString("Failed to bind to port:- %1  %2 ").arg(Source_PortNumber).arg(Source_address.toString()));
    }
    return CommState;
}
void UdpCommunication::closePort()
{
    if(Application.isPortBindCompleted)
    {
        emit UpdateLogString(QString("Port Closed :- %1  %2 ").arg(Application.Source_PortNumber).arg(Application.Source_address.toString()));
        Application.isPortBindCompleted = false;
        udpSocket->abort();
    }
}
