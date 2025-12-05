#ifndef GLOBALCLASS_H
#define GLOBALCLASS_H

#include <QHostAddress>

#include <QApplication>
#include <QtCore>
#include <QCoreApplication>
#include <QWidget>
#include <QString>
#include <stdint.h>
#include <QByteArray>
#include <QGraphicsView>
#include <QGraphicsDropShadowEffect>
#include <QToolButton>
#include <QProcess>
#include <QComboBox>
#include <QLine>
#include <QVBoxLayout>
#include <QMenu>
#include <QTimer>
#include <QProgressBar>
#include <QLabel>
#include <queue>
#include <QDebug>
#include <QScrollArea>
#include <QString>
#include <QFormLayout>
#include <QLineEdit>  // Make sure to include this header
#include <QPushButton>
#include"qmessagebox.h"
#include <QProcess>
#include <QSysInfo>

#include <QDialog>
#include <QIntValidator>
#include <QProcess>
//#include "QwertyKeypad.h"
#include <QFile>
#include <QDebug>
#include <QDir>

#include <cfloat>
#include <QCloseEvent>
#include <qfiledialog.h>
#include <QRadioButton>
#include <QLabel>
#include <QGroupBox>
#include <QCheckBox>
#include <QMessageBox>  // Ensure this include is present

typedef struct
{

    QVector<uint16_t> registers16;   // FC 03 / 04 / 06 / 16
    QVector<uint32_t> registers32;   // combined 32-bit values
    QVector<float>    floats32;      // optional float conversions
    QVector<bool>     coils;         // FC 01 / 02 / 05 / 15

    uint8_t slaveAddress = 0;
    uint8_t functionCode = 0;

}ModbusData_st;

extern ModbusData_st ModbusData;
typedef enum
{
    MODBUS_FUNC_READ_COILS               = 0x01,
    MODBUS_FUNC_READ_DISCRETE_INPUTS    = 0x02,
    MODBUS_FUNC_READ_HOLDING_REGISTERS  = 0x03,
    MODBUS_FUNC_READ_INPUT_REGISTERS    = 0x04,
    MODBUS_FUNC_WRITE_SINGLE_COIL       = 0x05,
    MODBUS_FUNC_WRITE_SINGLE_REGISTER   = 0x06,
    MODBUS_FUNC_WRITE_MULTIPLE_COILS    = 0x0F,
    MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS= 0x10,
    // Add more if your application supports other function codes
} ModbusFunctionCode_et;
typedef enum
{
    ABCD,
    CDAB,
    BADC,
    DCBA
}EndianMode_et;
typedef enum
{
    TealGraphite = 0,      // Industrial / SCADA
    OrangeCharcoal,         // Cybersecurity / Monitoring
    EmeraldDarkGray,        // Medical / Instrumentation
    PurpleCarbon,           // AI / Analytics / Cloud
    AquaSlate               // Corporate / Clean
}AppTheme_et;
class GlobalClass
{
public:
    GlobalClass();
 void UpdateStatusLabel(const QString& message, bool isError);
    void saveDatatoFile(const QString &fileName, QString str);
    uint32_t combineToUint32(uint16_t r1, uint16_t r2);
    uint32_t toABCD(uint16_t r1, uint16_t r2);
    uint32_t toCDAB(uint16_t r1, uint16_t r2);
    uint32_t toBADC(uint16_t r1, uint16_t r2);
    uint32_t toDCBA(uint16_t r1, uint16_t r2);
    uint32_t combine32(uint16_t r1, uint16_t r2, EndianMode_et mode);
    QString getStyleSheet(AppTheme_et themeId);
    QColor getBlinkColor(AppTheme_et theme);
    float convertToFloat(uint32_t raw);
    void LogModbusData();
    QString byteArrayToHexString(const QByteArray &data);

    AppTheme_et currentTheme = EmeraldDarkGray;
    QLabel *lbl_statuspanel;
    QByteArray RxData;
    QByteArray TxData;
    bool lbl_statuspanel_flag = false;
    unsigned int lbl_statuspanel_cntr = 0;
    uint16_t AckErrorCntr = 0;
    QHostAddress Source_address;
    unsigned short Source_PortNumber;
    long Device_SlaveID = 1;
    uint16_t TimerTimeout=10;
    int32_t TxPackets=0;
    int32_t RxPackets=0;
    int32_t ErrorPackets=0;
    QHostAddress Destination_address ;
    unsigned short Destination_PortNumber;
    bool Modbusconnection_RxFlag = false;

    std::vector<uint16_t> lineEditsData;
    bool is32BitChecked = false;
    bool is16BitChecked = false;
    uint8_t FunctionCode = MODBUS_FUNC_READ_INPUT_REGISTERS;
    bool Modbusconnection_Flag = false;
    bool isPortBindCompleted=false;
    bool isConnectionActive=false;
    bool Modbusconnection_isUdpBusy = false;
    bool Modbusconnection_TxFlag = false;
    bool ModbusURATCONN_Flag = false;
    quint16 expectedLength = 5;
    bool Readcontmodbus = false;
    bool isMasterChecked = false;
    bool isSlaveChecked = false;

    QString styleSheet = R"(
                         /* ===== Global Base ===== */
                         QWidget {
                             background-color: #F5F5F5;   /* light gray background */
                             color: #202020;              /* dark text for readability */
                             font-family: "Segoe UI", "Helvetica Neue", Arial, sans-serif;
                             font-size: 14px;
                         }

                         /* ===== Buttons ===== */
                         QPushButton {
                             background-color: #FFFFFF;
                             border: 1px solid rgba(200, 0, 0, 0.6); /* subtle red border */
                             border-radius: 4px;
                             padding: 6px 12px;
                         }
                         QPushButton:hover {
                             background-color: rgba(255, 0, 0, 0.1); /* soft red hover */
                         }
                         QPushButton:pressed {
                             background-color: rgba(255, 0, 0, 0.25); /* stronger red press */
                         }
                         QPushButton:disabled {
                             color: #999;
                             border: 1px solid #CCC;
                         }

                         /* ===== Line Edit / Text Fields ===== */
                         QLineEdit, QTextEdit {
                             background-color: #FFFFFF;
                             border: 1px solid rgba(200, 0, 0, 0.5);
                             border-radius: 3px;
                             padding: 4px;
                             selection-background-color: rgba(255, 0, 0, 0.3);
                             selection-color: #202020;
                         }

                         /* ===== Labels ===== */
                         QLabel {
                             color: #202020;
                             background: transparent;
                         }

                         /* ===== ComboBox ===== */
                         QComboBox {
                             background-color: #FFFFFF;
                             border: 1px solid rgba(200, 0, 0, 0.5);
                             border-radius: 3px;
                             padding: 4px;
                         }
                         QComboBox::drop-down {
                             border-left: 1px solid rgba(200, 0, 0, 0.5);
                             background-color: #F0F0F0;
                         }
                         QComboBox QAbstractItemView {
                             background-color: #FFFFFF;
                             selection-background-color: rgba(255, 0, 0, 0.3);
                             selection-color: #202020;
                         }

                         /* ===== Checkboxes & Radio Buttons ===== */
                         QCheckBox, QRadioButton {
                             spacing: 6px;
                         }
                         QCheckBox::indicator, QRadioButton::indicator {
                             width: 16px;
                             height: 16px;
                             border: 1px solid rgba(200, 0, 0, 0.6);
                             background-color: #FFFFFF;
                         }
                         QCheckBox::indicator:checked, QRadioButton::indicator:checked {
                             background-color: rgba(255, 0, 0, 0.7);
                         }

                         /* ===== Scrollbars ===== */
                         QScrollBar:vertical {
                             background: #F0F0F0;
                             width: 10px;
                             margin: 0px;
                         }
                         QScrollBar::handle:vertical {
                             background: rgba(255, 0, 0, 0.5);
                             border-radius: 5px;
                         }
                         QScrollBar::handle:vertical:hover {
                             background: rgba(255, 0, 0, 0.7);
                         }
                         QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
                             background: none;
                         }

                         /* ===== Menus ===== */
                         QMenu {
                             background-color: #FFFFFF;
                             border: 1px solid rgba(200, 0, 0, 0.5);
                         }
                         QMenu::item:selected {
                             background-color: rgba(255, 0, 0, 0.3);
                             color: #202020;
                         }

                         /* ===== Tabs ===== */
                         QTabWidget::pane {
                             border: 1px solid rgba(200, 0, 0, 0.5);
                         }
                         QTabBar::tab {
                             background: #FFFFFF;
                             color: #202020;
                             padding: 6px 12px;
                         }
                         QTabBar::tab:selected {
                             background: rgba(255, 0, 0, 0.3);
                             color: #202020;
                         }
                         QTabBar::tab:hover {
                             background: rgba(255, 0, 0, 0.15);
                         }

                         /* ===== Progress Bar ===== */
                         QProgressBar {
                             border: 1px solid rgba(200, 0, 0, 0.6);
                             border-radius: 3px;
                             text-align: center;
                             background: #FFFFFF;
                         }
                         QProgressBar::chunk {
                             background-color: rgba(255, 0, 0, 0.7);
                         }

                         /* ===== Dock Widgets ===== */
                         QDockWidget {
                             border: 1px solid rgba(200, 0, 0, 0.6);
                             border-radius: 4px;
                             background-color: #FAFAFA;
                         }
                         QDockWidget::title {
                             text-align: center;
                             background-color: #F0F0F0;
                             color: #202020;
                             padding: 4px;
                             border-bottom: 1px solid rgba(200, 0, 0, 0.6);
                             font-weight: bold;
                         }
                         QDockWidget[floatable="true"] {
                             border: 1px solid rgba(255, 0, 0, 0.8);
                             background-color: #FFFFFF;
                         }
                         QDockWidget[closable="true"]::title {
                             background-color: rgba(255, 0, 0, 0.15);
                             color: #202020;
                         }
                         )";
};

extern GlobalClass Application;
#endif // GLOBALCLASS_H
