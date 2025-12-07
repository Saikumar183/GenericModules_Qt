#ifndef MODBUSSCREEN_H
#define MODBUSSCREEN_H

#include <QWidget>
#include "globalclass.h"
#include "endianregistergridwidget.h"
#include <QSerialPort>
// Simple enum for Modbus exception (optional)
enum ModbusException {
    MODBUS_EX_NONE          = 0x00,
    MODBUS_EX_ILLEGAL_FUNC  = 0x01,
    MODBUS_EX_ILLEGAL_DATA_ADDR = 0x02,
    MODBUS_EX_ILLEGAL_DATA_VAL  = 0x03,
    // ... add others if needed
};

namespace Ui {
class ModbusScreen;
}

class ModbusScreen : public QWidget
{
    Q_OBJECT

public:
    explicit ModbusScreen(QWidget *parent = 0);
    ~ModbusScreen();

    bool isModbusOverSerial = false;
    bool isModbusOverUDP = false;
    bool isModbusMasterEnabled = false;
    bool isModbusSlaveEnabled = false;
    bool isModbusAutoSendEnabled= false;
    uint16_t ModbusScreenStartingAddress;
    uint16_t ModbusScreenRegQuantity;
    uint8_t ModbusScreenFunctionCode;
    uint8_t ModbusScreenSlaveID=1;

    void UpdateTxDataBlink();
    void UpdateRxDataBlink();
    void UpdatePackeCounts();
    void UpdateErrorPacketsBlink();
    void showLogDialog(const QString &text);
    void CopySerialPor(QSerialPort *Serial);
private:
    Ui::ModbusScreen *ui;
    EndianRegisterGridWidget *m_regGrid = nullptr;
    struct LogDialogUI {
        QDialog *dialog = nullptr;
        QTextEdit *textEdit = nullptr;
        QCheckBox *checkBox = nullptr;
        QFile *logFile = nullptr;
        bool loggingEnabled = false;
    };

    LogDialogUI logUI;
    QByteArray m_rxBuffer;
    QVector<uint16_t> m_holdingRegs;   // simple holding register map
    QByteArray FinalModbusTxByteArray;
    bool PauseDataFlag = false;
    QSerialPort *SerialPortCopy;
    QTimer *scanTimer;
    bool timeoutSendCmdFlag = false;
    void appendLog(const QString &data);
    void Init_Screens(void );
    void Init_Hides(bool state );
    void Init_Connects(void );
    void Init_miscellaneous(void );
    int get_scanTime();
    quint16 calculateCRC16(const QByteArray &data);
    bool checkCRC(const QByteArray &frame);
    int expectedRequestLength(const QByteArray &buf);
    void handleModbusRequest(const QByteArray &frame);
    void handleModbusMasterResponse(const QByteArray &frame);
    QByteArray convertEndian(const QByteArray &input, EndianMode_et mode);
    bool isCommunicationActiveToSend();
signals:
    void sendSerialData(QByteArray);
    void sendUdpData(QByteArray);
public slots:

    void ScanTimerFunction();
    void on_tbn_ComWindow_clicked();
    void buildModbusRTUFrame(quint8 slaveId,
                                           quint8 functionCode,
                                           quint16 startAddress,
                                           const uint16_t *dataAddress,   // changed
                                           quint16 dataSize);

    void buildModbusRTUSlaveResponse(quint8 slaveId,
                                                   quint8 functionCode,
                                                   quint16 startAddress,
                                                   const uint16_t *dataAddress, // changed
                                                   quint16 dataSize,
                                                   ModbusException ex);
    void on_Cmbx_Func_Code_currentIndexChanged(const QString &arg1);
    void onSerialDataReceived(QSerialPort *serialPort);
    void ProcessUdpRxData(QByteArray UdpData);


private slots:
    void onRegisterCountChanged(const QString &text);

    void SendCmd();
    void on_tbn_ResetCounts_clicked();
    void on_tbn_ComWindow_clicked(bool checked);
    void on_le_slaveid_textChanged(const QString &arg1);
    void on_le_registercount_textChanged(const QString &arg1);
    void on_le_startaddress_textChanged(const QString &arg1);
    void on_checkBox_ModbusOverSerial_clicked(bool checked);
    void on_checkBox_ModbusOverUdp_clicked(bool checked);
    void on_checkBox_Master_clicked(bool checked);
    void on_checkBox_Slave_clicked(bool checked);
    void on_checkBox_autoSend_clicked(bool checked);
    void on_tbn_SendCmd_clicked();
};

#endif // MODBUSSCREEN_H
