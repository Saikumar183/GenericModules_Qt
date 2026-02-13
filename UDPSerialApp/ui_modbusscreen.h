/********************************************************************************
** Form generated from reading UI file 'modbusscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODBUSSCREEN_H
#define UI_MODBUSSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModbusScreen
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_5;
    QFrame *frame_4;
    QGridLayout *gridLayout_7;
    QCheckBox *checkBox_autoSend;
    QLineEdit *le_timeOut;
    QLabel *lb_TxPkts;
    QLabel *label_8;
    QLineEdit *le_startaddress;
    QComboBox *Cmbx_Func_Code;
    QLabel *label_6;
    QLabel *label_3;
    QLineEdit *le_slaveid;
    QLineEdit *le_registercount;
    QLabel *label_9;
    QLabel *label_5;
    QLineEdit *le_scantime;
    QCheckBox *checkBox_ModbusOverUdp;
    QLabel *label_2;
    QCheckBox *checkBox_ModbusOverSerial;
    QPushButton *tbn_SendCmd;
    QCheckBox *checkBox_Master;
    QLabel *lb_ErsPkts;
    QLabel *lb_RxPkts;
    QPushButton *tbn_ResetCounts;
    QCheckBox *checkBox_Slave;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Tx;
    QLabel *label_Error;
    QLabel *label_Rx;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_Frame;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBox_CRCSWAP;
    QSpacerItem *horizontalSpacer;
    QPushButton *tbn_ComWindow;
    QComboBox *CmBx_byteFormate;
    QComboBox *CmBx_dataFormat;
    QVBoxLayout *verticalLayout_3;
    QWidget *wg_EndianView;

    void setupUi(QWidget *ModbusScreen)
    {
        if (ModbusScreen->objectName().isEmpty())
            ModbusScreen->setObjectName(QStringLiteral("ModbusScreen"));
        ModbusScreen->resize(631, 301);
        gridLayout = new QGridLayout(ModbusScreen);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        frame_4 = new QFrame(ModbusScreen);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setStyleSheet(QStringLiteral(""));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_4);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        checkBox_autoSend = new QCheckBox(frame_4);
        checkBox_autoSend->setObjectName(QStringLiteral("checkBox_autoSend"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkBox_autoSend->sizePolicy().hasHeightForWidth());
        checkBox_autoSend->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        checkBox_autoSend->setFont(font);

        gridLayout_7->addWidget(checkBox_autoSend, 0, 6, 1, 1);

        le_timeOut = new QLineEdit(frame_4);
        le_timeOut->setObjectName(QStringLiteral("le_timeOut"));
        le_timeOut->setFont(font);

        gridLayout_7->addWidget(le_timeOut, 2, 4, 1, 1);

        lb_TxPkts = new QLabel(frame_4);
        lb_TxPkts->setObjectName(QStringLiteral("lb_TxPkts"));
        lb_TxPkts->setFont(font);
        lb_TxPkts->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(lb_TxPkts, 4, 0, 1, 1);

        label_8 = new QLabel(frame_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        gridLayout_7->addWidget(label_8, 0, 2, 1, 1);

        le_startaddress = new QLineEdit(frame_4);
        le_startaddress->setObjectName(QStringLiteral("le_startaddress"));
        sizePolicy.setHeightForWidth(le_startaddress->sizePolicy().hasHeightForWidth());
        le_startaddress->setSizePolicy(sizePolicy);
        le_startaddress->setFont(font);

        gridLayout_7->addWidget(le_startaddress, 0, 4, 1, 1);

        Cmbx_Func_Code = new QComboBox(frame_4);
        Cmbx_Func_Code->setObjectName(QStringLiteral("Cmbx_Func_Code"));
        Cmbx_Func_Code->setFont(font);

        gridLayout_7->addWidget(Cmbx_Func_Code, 1, 1, 1, 4);

        label_6 = new QLabel(frame_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout_7->addWidget(label_6, 1, 0, 1, 1);

        label_3 = new QLabel(frame_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout_7->addWidget(label_3, 2, 2, 1, 1);

        le_slaveid = new QLineEdit(frame_4);
        le_slaveid->setObjectName(QStringLiteral("le_slaveid"));
        sizePolicy.setHeightForWidth(le_slaveid->sizePolicy().hasHeightForWidth());
        le_slaveid->setSizePolicy(sizePolicy);
        le_slaveid->setFont(font);

        gridLayout_7->addWidget(le_slaveid, 0, 1, 1, 1);

        le_registercount = new QLineEdit(frame_4);
        le_registercount->setObjectName(QStringLiteral("le_registercount"));
        sizePolicy.setHeightForWidth(le_registercount->sizePolicy().hasHeightForWidth());
        le_registercount->setSizePolicy(sizePolicy);
        le_registercount->setFont(font);
        le_registercount->setStyleSheet(QStringLiteral(""));
        le_registercount->setMaxLength(250);

        gridLayout_7->addWidget(le_registercount, 2, 1, 1, 1);

        label_9 = new QLabel(frame_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        gridLayout_7->addWidget(label_9, 2, 0, 1, 1);

        label_5 = new QLabel(frame_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout_7->addWidget(label_5, 0, 0, 1, 1);

        le_scantime = new QLineEdit(frame_4);
        le_scantime->setObjectName(QStringLiteral("le_scantime"));
        le_scantime->setFont(font);

        gridLayout_7->addWidget(le_scantime, 3, 4, 1, 1);

        checkBox_ModbusOverUdp = new QCheckBox(frame_4);
        checkBox_ModbusOverUdp->setObjectName(QStringLiteral("checkBox_ModbusOverUdp"));
        sizePolicy.setHeightForWidth(checkBox_ModbusOverUdp->sizePolicy().hasHeightForWidth());
        checkBox_ModbusOverUdp->setSizePolicy(sizePolicy);
        checkBox_ModbusOverUdp->setFont(font);

        gridLayout_7->addWidget(checkBox_ModbusOverUdp, 2, 6, 1, 1);

        label_2 = new QLabel(frame_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout_7->addWidget(label_2, 3, 2, 1, 1);

        checkBox_ModbusOverSerial = new QCheckBox(frame_4);
        checkBox_ModbusOverSerial->setObjectName(QStringLiteral("checkBox_ModbusOverSerial"));
        sizePolicy.setHeightForWidth(checkBox_ModbusOverSerial->sizePolicy().hasHeightForWidth());
        checkBox_ModbusOverSerial->setSizePolicy(sizePolicy);
        checkBox_ModbusOverSerial->setFont(font);

        gridLayout_7->addWidget(checkBox_ModbusOverSerial, 3, 0, 1, 2);

        tbn_SendCmd = new QPushButton(frame_4);
        tbn_SendCmd->setObjectName(QStringLiteral("tbn_SendCmd"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tbn_SendCmd->sizePolicy().hasHeightForWidth());
        tbn_SendCmd->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        tbn_SendCmd->setFont(font1);

        gridLayout_7->addWidget(tbn_SendCmd, 1, 6, 1, 1);

        checkBox_Master = new QCheckBox(frame_4);
        checkBox_Master->setObjectName(QStringLiteral("checkBox_Master"));
        sizePolicy.setHeightForWidth(checkBox_Master->sizePolicy().hasHeightForWidth());
        checkBox_Master->setSizePolicy(sizePolicy);
        checkBox_Master->setFont(font);

        gridLayout_7->addWidget(checkBox_Master, 3, 6, 1, 1);

        lb_ErsPkts = new QLabel(frame_4);
        lb_ErsPkts->setObjectName(QStringLiteral("lb_ErsPkts"));
        lb_ErsPkts->setFont(font);
        lb_ErsPkts->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(lb_ErsPkts, 4, 1, 1, 1);

        lb_RxPkts = new QLabel(frame_4);
        lb_RxPkts->setObjectName(QStringLiteral("lb_RxPkts"));
        lb_RxPkts->setFont(font);
        lb_RxPkts->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_7->addWidget(lb_RxPkts, 4, 2, 1, 1);

        tbn_ResetCounts = new QPushButton(frame_4);
        tbn_ResetCounts->setObjectName(QStringLiteral("tbn_ResetCounts"));
        sizePolicy1.setHeightForWidth(tbn_ResetCounts->sizePolicy().hasHeightForWidth());
        tbn_ResetCounts->setSizePolicy(sizePolicy1);
        tbn_ResetCounts->setFont(font1);

        gridLayout_7->addWidget(tbn_ResetCounts, 4, 4, 1, 1);

        checkBox_Slave = new QCheckBox(frame_4);
        checkBox_Slave->setObjectName(QStringLiteral("checkBox_Slave"));
        sizePolicy.setHeightForWidth(checkBox_Slave->sizePolicy().hasHeightForWidth());
        checkBox_Slave->setSizePolicy(sizePolicy);
        checkBox_Slave->setFont(font);

        gridLayout_7->addWidget(checkBox_Slave, 4, 6, 1, 1);


        gridLayout_5->addWidget(frame_4, 0, 0, 1, 1);

        frame_2 = new QFrame(ModbusScreen);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_Tx = new QLabel(frame_2);
        label_Tx->setObjectName(QStringLiteral("label_Tx"));
        label_Tx->setFont(font);
        label_Tx->setWordWrap(true);

        horizontalLayout_2->addWidget(label_Tx);

        label_Error = new QLabel(frame_2);
        label_Error->setObjectName(QStringLiteral("label_Error"));
        label_Error->setFont(font);
        label_Error->setWordWrap(true);

        horizontalLayout_2->addWidget(label_Error);

        label_Rx = new QLabel(frame_2);
        label_Rx->setObjectName(QStringLiteral("label_Rx"));
        label_Rx->setFont(font);
        label_Rx->setWordWrap(true);

        horizontalLayout_2->addWidget(label_Rx);


        gridLayout_5->addWidget(frame_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBox_Frame = new QCheckBox(ModbusScreen);
        checkBox_Frame->setObjectName(QStringLiteral("checkBox_Frame"));
        checkBox_Frame->setFont(font);

        horizontalLayout->addWidget(checkBox_Frame);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        checkBox_CRCSWAP = new QCheckBox(ModbusScreen);
        checkBox_CRCSWAP->setObjectName(QStringLiteral("checkBox_CRCSWAP"));
        checkBox_CRCSWAP->setFont(font);

        horizontalLayout->addWidget(checkBox_CRCSWAP);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        tbn_ComWindow = new QPushButton(ModbusScreen);
        tbn_ComWindow->setObjectName(QStringLiteral("tbn_ComWindow"));
        tbn_ComWindow->setFont(font);
        tbn_ComWindow->setCheckable(true);

        horizontalLayout->addWidget(tbn_ComWindow);

        CmBx_byteFormate = new QComboBox(ModbusScreen);
        CmBx_byteFormate->setObjectName(QStringLiteral("CmBx_byteFormate"));
        CmBx_byteFormate->setFont(font);

        horizontalLayout->addWidget(CmBx_byteFormate);

        CmBx_dataFormat = new QComboBox(ModbusScreen);
        CmBx_dataFormat->setObjectName(QStringLiteral("CmBx_dataFormat"));
        CmBx_dataFormat->setFont(font);

        horizontalLayout->addWidget(CmBx_dataFormat);


        gridLayout_5->addLayout(horizontalLayout, 3, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        wg_EndianView = new QWidget(ModbusScreen);
        wg_EndianView->setObjectName(QStringLiteral("wg_EndianView"));

        verticalLayout_3->addWidget(wg_EndianView);


        gridLayout_5->addLayout(verticalLayout_3, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_5, 0, 0, 1, 1);


        retranslateUi(ModbusScreen);

        Cmbx_Func_Code->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ModbusScreen);
    } // setupUi

    void retranslateUi(QWidget *ModbusScreen)
    {
        ModbusScreen->setWindowTitle(QApplication::translate("ModbusScreen", "Form", Q_NULLPTR));
        checkBox_autoSend->setText(QApplication::translate("ModbusScreen", "AUTO SEND", Q_NULLPTR));
        le_timeOut->setText(QApplication::translate("ModbusScreen", "1000", Q_NULLPTR));
        lb_TxPkts->setText(QApplication::translate("ModbusScreen", "Tx Packets:", Q_NULLPTR));
        label_8->setText(QApplication::translate("ModbusScreen", "START ADDR:", Q_NULLPTR));
        le_startaddress->setText(QApplication::translate("ModbusScreen", "0", Q_NULLPTR));
        Cmbx_Func_Code->clear();
        Cmbx_Func_Code->insertItems(0, QStringList()
         << QApplication::translate("ModbusScreen", "03 (0x03) Read Holding Registers", Q_NULLPTR)
         << QApplication::translate("ModbusScreen", "04 (0x04) Read Input Registers", Q_NULLPTR)
         << QApplication::translate("ModbusScreen", "06 (0x06) Write Single Register", Q_NULLPTR)
         << QApplication::translate("ModbusScreen", "16 (0x10) Write Multiple Registers", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("ModbusScreen", "FUNC. CODE:", Q_NULLPTR));
        label_3->setText(QApplication::translate("ModbusScreen", "TIME OUT:", Q_NULLPTR));
        le_slaveid->setText(QApplication::translate("ModbusScreen", "1", Q_NULLPTR));
        le_registercount->setText(QApplication::translate("ModbusScreen", "2", Q_NULLPTR));
        label_9->setText(QApplication::translate("ModbusScreen", "QUANTITY:", Q_NULLPTR));
        label_5->setText(QApplication::translate("ModbusScreen", "SLAVE ID:", Q_NULLPTR));
        le_scantime->setText(QApplication::translate("ModbusScreen", "100", Q_NULLPTR));
        checkBox_ModbusOverUdp->setText(QApplication::translate("ModbusScreen", "MODBUS OVER UDP", Q_NULLPTR));
        label_2->setText(QApplication::translate("ModbusScreen", "SCAN (ms )", Q_NULLPTR));
        checkBox_ModbusOverSerial->setText(QApplication::translate("ModbusScreen", "MODBUS OVER SERIAL", Q_NULLPTR));
        tbn_SendCmd->setText(QApplication::translate("ModbusScreen", "SEND", Q_NULLPTR));
        checkBox_Master->setText(QApplication::translate("ModbusScreen", "MASTER", Q_NULLPTR));
        lb_ErsPkts->setText(QApplication::translate("ModbusScreen", "|Error Packets:", Q_NULLPTR));
        lb_RxPkts->setText(QApplication::translate("ModbusScreen", "|Rx Packets:", Q_NULLPTR));
        tbn_ResetCounts->setText(QApplication::translate("ModbusScreen", "RESET COUNTS", Q_NULLPTR));
        checkBox_Slave->setText(QApplication::translate("ModbusScreen", "SLAVE\n"
"(0x06,0x10)", Q_NULLPTR));
        label_Tx->setText(QApplication::translate("ModbusScreen", "Tx:", Q_NULLPTR));
        label_Error->setText(QApplication::translate("ModbusScreen", "Er:", Q_NULLPTR));
        label_Rx->setText(QApplication::translate("ModbusScreen", "Rx:", Q_NULLPTR));
        checkBox_Frame->setText(QApplication::translate("ModbusScreen", "Frames", Q_NULLPTR));
        checkBox_CRCSWAP->setText(QApplication::translate("ModbusScreen", "CRC SWAP", Q_NULLPTR));
        tbn_ComWindow->setText(QApplication::translate("ModbusScreen", "COMMUNICATION WINDOW", Q_NULLPTR));
        CmBx_byteFormate->clear();
        CmBx_byteFormate->insertItems(0, QStringList()
         << QApplication::translate("ModbusScreen", "0x0A0B0C0D", Q_NULLPTR)
         << QApplication::translate("ModbusScreen", "0x0C0D0A0B", Q_NULLPTR)
         << QApplication::translate("ModbusScreen", "0x0B0A0D0C", Q_NULLPTR)
         << QApplication::translate("ModbusScreen", "0x0D0C0B0A", Q_NULLPTR)
        );
        CmBx_dataFormat->clear();
        CmBx_dataFormat->insertItems(0, QStringList()
         << QApplication::translate("ModbusScreen", "HEX", Q_NULLPTR)
         << QApplication::translate("ModbusScreen", "DECIMAL", Q_NULLPTR)
         << QApplication::translate("ModbusScreen", "BINARY", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class ModbusScreen: public Ui_ModbusScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODBUSSCREEN_H
