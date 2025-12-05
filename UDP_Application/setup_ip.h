#ifndef SETUP_IP_H
#define SETUP_IP_H
#include "globalclass.h"
#include "blocksonnumber.h"
namespace Ui {
class SetUp_IP;
}

class SetUp_IP : public QDialog
{
    Q_OBJECT

public:
    explicit SetUp_IP(QWidget *parent = 0);
    ~SetUp_IP();

    typedef struct
    {
        QString Ip_Address;
        int PortNumber;
    }ipSetting_t;
    ipSetting_t ipSetting[2];
    int get_scanTime();
    void UpdatePackeCounts();
    long WriteRegisterValue = 0;
    long functionCode = 0;
    QDockWidget *getDockWidgetAddress(void);
    QFrame* getMasterFrame(void);
    bool processModbusFrame(const QByteArray &rx, ModbusData_st &outData);
    void updateLE_numbers();
private slots:
    void on_tbn_NetworkSettings_clicked();

    void on_tbn_SendCmd_clicked();

    void on_tbn_ClosePort_clicked();

    void on_le_slaveid_textChanged(const QString &arg1);

    void on_Cmbx_Func_Code_currentIndexChanged(const QString &arg1);



signals:
    void ConnectNetWork();
    void load_ip();
    void save_ip();
    void buildModbusRTUFrame(quint8 slaveId, quint8 functionCode, quint16 startAddress,
                             long* dataAddress, quint16 dataSize);
    void closePort();
public slots:
    void on_le_registercount_textChanged(const QString &arg1);
    void on_tbn_Apply_clicked();
    void UpdatePasswordString(QString _PassWord);
    void loadNetworkData(void);
    void on_tbn_ResetCounts_clicked();
    void processReceivedFrame(QByteArray rxData);
    void processReceivedFrame_Slave(QByteArray rxData);
private:
    Ui::SetUp_IP *ui;
    BlocksOnNumber *ClassBlocksOnNumber;
    typedef enum
    {
        SOURCE=0,
        DESTINATION,
        MAX_CLIENTS
    }IP_PortNumber;
    //    QwertyKeypad *KeyPad_Qwerty;
    //    QMessageBox KeyboardMsgBox;
    QValidator *ipValidator;
    QIntValidator *portValidator;

    QString NetworkFileName;

    bool fileNotFoundFlag = false;
    void Init_QMbx_KeyBoard();
    void saveDatatoFile(const QString &fileName );
    void loadDataFromFile(const QString &fileName);
signals:
    void updateScanTime(QString);
};

#endif // SETUP_IP_H
