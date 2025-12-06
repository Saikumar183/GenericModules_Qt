#ifndef SERIALPORTWIDGET_H
#define SERIALPORTWIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QComboBox>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QByteArray>
#include <QLabel>
#include <QMessageBox>
#include <QCheckBox>
#include "globalclass.h"
#include <QGroupBox>
//#include "QwertyKeypad.h"


#define gNoOfByteToRecieve_ACK  1
#define CHECKSUM_SIZE       2


class SerialPortWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SerialPortWidget(QWidget *parent = nullptr);
    ~SerialPortWidget();
    QSerialPort *serialPort;
    QPushButton *pushButtonExit;

    void InitCommPort();
    bool Serial_onscreen = false;
    bool isSerialOpen();
    QSerialPort* getSerialPortAddress();

signals:
    void commerror(const QString);
    void onSerialDataReceived(QSerialPort *serialPort);

public slots:
    void updatePortList();
    void onOpenPortClicked();
    void onSendDataClicked();
    bool Send_Serial_Command(uint8_t CMD);
    void showcomstatus(const QString info);
    // Slots for button click events to enable only one button at a time
    void onNumberButtonClicked();
    void onStringButtonClicked();
    void onCRCButtonClicked();
    void updateSendDataField(QString Data);
    void onBaudRateSelectionChanged(int index);
    void showErrorOccurred(QSerialPort::SerialPortError);
    void SendModbusFrame(QByteArray frame, int expectedLength, quint8 functionCode, int timeoutMs);
    void readSerialPortSettingsAndData();
    void sendSerialData(QByteArray);
private:
    QString StringR1;
    bool WaitForAck(int timeoutms, int NOB);
    QByteArray Parameter_Byte;  // Dynamic array to hold parameter data
    QByteArray ConvertToByteArray(long para_data);
    QComboBox *comboBoxPorts;        // For port selection
    QComboBox *comboBoxBaudRate;     // For baud rate selection
    QComboBox *comboBoxParity;       // For parity selection
    QComboBox *comboBoxStopBits;     // For stop bits selection
    QPushButton *pushButtonOpen;
    QTextEdit *textEditData;
    QPushButton *pushButtonSend;
    QPushButton *pushButtonAutoSend;

    QLabel *rxdata;
    QByteArray ActualRxData;
    QString SerialRxData;
    //    QwertyKeypad *KeyBoard;

    // New buttons for Number, String, and CRC
    QPushButton *pushButtonNumber;
    QPushButton *pushButtonString;
    QPushButton *pushButtonCRC;

    QPushButton *pushButtonRefresh;

    bool isValidChecksum(const QByteArray &data) ;
    unsigned short calculateCRC16(const QByteArray &data) ;
    QString hexToString(const QByteArray &hexData);

    void showdata(const QString);
    void Init_hide();

    int i;
    bool Data_Status = false;
    bool DisplayMessageFlag = true;
    uint32_t Serial_Command;

    int DataBytes;
    bool gDataCollectionEnable = false;
    bool gDataCollectionCompleted = false;
    uint_fast32_t gNoOfByteToRecieve = 0;

    QList<QString> available_ports;
    QString available_portsnames;
    QDateTime _DateTime;
    bool Upload_Data_ALL(long* ptr, int NOB);

private slots:
    void startSendingCommands();
signals:
    void onReopenButtonClicked();
    void ModbusFrameResponse(QByteArray data, bool success);

};

#endif // SERIALPORTWIDGET_H
