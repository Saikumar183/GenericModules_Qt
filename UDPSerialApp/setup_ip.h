#ifndef SETUP_IP_H
#define SETUP_IP_H
#include "globalclass.h"
#include "udpcommunication.h"

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
    void on_tbn_ClosePort_clicked();
    QStringList getInterfaceWithIP();
private slots:
    void on_tbn_NetworkSettings_clicked();
    void on_btnShowIPs_clicked();

    void on_tbn_Apply_clicked(bool checked);

signals:
    void UpdateLogString(QString msg);
    void ProcessUdpRxData(QByteArray);
public slots:
    void on_tbn_Apply_clicked();
    void loadNetworkData(void);
    void SendUdpData(QByteArray);
private:
    Ui::SetUp_IP *ui;
    UdpCommunication *UDP_Comm=nullptr;
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
