/********************************************************************************
** Form generated from reading UI file 'setup_ip.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUP_IP_H
#define UI_SETUP_IP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFormLayout>
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

class Ui_SetUp_IP
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QFrame *line_2;
    QFormLayout *formLayout;
    QLabel *lb_Sip;
    QLineEdit *lineEdit_Sip;
    QLabel *lb_SPortNum;
    QLineEdit *lineEdit_SPortNum;
    QLabel *lb_SPortNum_2;
    QLineEdit *lineEdit_SlaveID;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QFrame *line_3;
    QFormLayout *formLayout_2;
    QLabel *lb_Dip;
    QLineEdit *lineEdit_Dip;
    QLabel *lb_DPortNum;
    QLineEdit *lineEdit_DPortNum;
    QFrame *line_4;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *tbn_NetworkSettings;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *tbn_Apply;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *tbn_ClosePort;
    QSpacerItem *horizontalSpacer_12;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *le_slaveid;
    QLabel *label_6;
    QComboBox *Cmbx_Func_Code;
    QLabel *label_8;
    QLineEdit *le_startaddress;
    QLabel *label_9;
    QLineEdit *le_registercount;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *checkBox_autoSend;
    QPushButton *tbn_SendCmd;
    QFrame *line_15;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_22;
    QLabel *lb_txP;
    QLabel *label_23;
    QLabel *lb_ErrorP;
    QLabel *label_24;
    QLabel *lb_RxP;
    QPushButton *tbn_ResetCounts;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *le_scantime;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;

    void setupUi(QDialog *SetUp_IP)
    {
        if (SetUp_IP->objectName().isEmpty())
            SetUp_IP->setObjectName(QStringLiteral("SetUp_IP"));
        SetUp_IP->resize(975, 498);
        SetUp_IP->setStyleSheet(QStringLiteral("border:none;"));
        gridLayout_2 = new QGridLayout(SetUp_IP);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(SetUp_IP);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        frame = new QFrame(frame_2);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setStyleSheet(QStringLiteral("QFrame{border:none;}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);
        label_4->setScaledContents(true);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        line_2 = new QFrame(frame);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setStyleSheet(QStringLiteral(""));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        lb_Sip = new QLabel(frame);
        lb_Sip->setObjectName(QStringLiteral("lb_Sip"));
        sizePolicy.setHeightForWidth(lb_Sip->sizePolicy().hasHeightForWidth());
        lb_Sip->setSizePolicy(sizePolicy);
        lb_Sip->setFont(font);
        lb_Sip->setScaledContents(true);
        lb_Sip->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, lb_Sip);

        lineEdit_Sip = new QLineEdit(frame);
        lineEdit_Sip->setObjectName(QStringLiteral("lineEdit_Sip"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_Sip->sizePolicy().hasHeightForWidth());
        lineEdit_Sip->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_Sip);

        lb_SPortNum = new QLabel(frame);
        lb_SPortNum->setObjectName(QStringLiteral("lb_SPortNum"));
        lb_SPortNum->setFont(font);
        lb_SPortNum->setScaledContents(true);
        lb_SPortNum->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, lb_SPortNum);

        lineEdit_SPortNum = new QLineEdit(frame);
        lineEdit_SPortNum->setObjectName(QStringLiteral("lineEdit_SPortNum"));
        sizePolicy1.setHeightForWidth(lineEdit_SPortNum->sizePolicy().hasHeightForWidth());
        lineEdit_SPortNum->setSizePolicy(sizePolicy1);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_SPortNum);

        lb_SPortNum_2 = new QLabel(frame);
        lb_SPortNum_2->setObjectName(QStringLiteral("lb_SPortNum_2"));
        lb_SPortNum_2->setFont(font);
        lb_SPortNum_2->setScaledContents(true);
        lb_SPortNum_2->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(2, QFormLayout::LabelRole, lb_SPortNum_2);

        lineEdit_SlaveID = new QLineEdit(frame);
        lineEdit_SlaveID->setObjectName(QStringLiteral("lineEdit_SlaveID"));
        sizePolicy1.setHeightForWidth(lineEdit_SlaveID->sizePolicy().hasHeightForWidth());
        lineEdit_SlaveID->setSizePolicy(sizePolicy1);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_SlaveID);


        verticalLayout->addLayout(formLayout);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);

        line = new QFrame(frame);
        line->setObjectName(QStringLiteral("line"));
        line->setStyleSheet(QStringLiteral(""));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 0);
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setStyleSheet(QStringLiteral(""));
        label_7->setScaledContents(true);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_7);

        line_3 = new QFrame(frame);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setStyleSheet(QStringLiteral(""));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        lb_Dip = new QLabel(frame);
        lb_Dip->setObjectName(QStringLiteral("lb_Dip"));
        lb_Dip->setFont(font);
        lb_Dip->setScaledContents(true);
        lb_Dip->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, lb_Dip);

        lineEdit_Dip = new QLineEdit(frame);
        lineEdit_Dip->setObjectName(QStringLiteral("lineEdit_Dip"));
        sizePolicy1.setHeightForWidth(lineEdit_Dip->sizePolicy().hasHeightForWidth());
        lineEdit_Dip->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit_Dip);

        lb_DPortNum = new QLabel(frame);
        lb_DPortNum->setObjectName(QStringLiteral("lb_DPortNum"));
        lb_DPortNum->setFont(font);
        lb_DPortNum->setScaledContents(true);
        lb_DPortNum->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, lb_DPortNum);

        lineEdit_DPortNum = new QLineEdit(frame);
        lineEdit_DPortNum->setObjectName(QStringLiteral("lineEdit_DPortNum"));
        sizePolicy1.setHeightForWidth(lineEdit_DPortNum->sizePolicy().hasHeightForWidth());
        lineEdit_DPortNum->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEdit_DPortNum);


        verticalLayout_2->addLayout(formLayout_2);


        gridLayout_3->addLayout(verticalLayout_2, 0, 2, 1, 1);


        verticalLayout_3->addWidget(frame);

        line_4 = new QFrame(frame_2);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setStyleSheet(QStringLiteral(""));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_4);

        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        tbn_NetworkSettings = new QPushButton(frame_3);
        tbn_NetworkSettings->setObjectName(QStringLiteral("tbn_NetworkSettings"));
        sizePolicy.setHeightForWidth(tbn_NetworkSettings->sizePolicy().hasHeightForWidth());
        tbn_NetworkSettings->setSizePolicy(sizePolicy);
        tbn_NetworkSettings->setMinimumSize(QSize(0, 50));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        tbn_NetworkSettings->setFont(font1);

        horizontalLayout_2->addWidget(tbn_NetworkSettings);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        tbn_Apply = new QPushButton(frame_3);
        tbn_Apply->setObjectName(QStringLiteral("tbn_Apply"));
        sizePolicy.setHeightForWidth(tbn_Apply->sizePolicy().hasHeightForWidth());
        tbn_Apply->setSizePolicy(sizePolicy);
        tbn_Apply->setMinimumSize(QSize(0, 50));
        tbn_Apply->setFont(font1);

        horizontalLayout_2->addWidget(tbn_Apply);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        tbn_ClosePort = new QPushButton(frame_3);
        tbn_ClosePort->setObjectName(QStringLiteral("tbn_ClosePort"));
        sizePolicy.setHeightForWidth(tbn_ClosePort->sizePolicy().hasHeightForWidth());
        tbn_ClosePort->setSizePolicy(sizePolicy);
        tbn_ClosePort->setMinimumSize(QSize(0, 50));
        tbn_ClosePort->setFont(font1);

        horizontalLayout_2->addWidget(tbn_ClosePort);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_12);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(frame_3);

        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setStyleSheet(QStringLiteral(""));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(frame_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_5->setFont(font2);

        horizontalLayout_4->addWidget(label_5);

        le_slaveid = new QLineEdit(frame_4);
        le_slaveid->setObjectName(QStringLiteral("le_slaveid"));
        le_slaveid->setFont(font2);

        horizontalLayout_4->addWidget(le_slaveid);

        label_6 = new QLabel(frame_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font2);

        horizontalLayout_4->addWidget(label_6);

        Cmbx_Func_Code = new QComboBox(frame_4);
        Cmbx_Func_Code->setObjectName(QStringLiteral("Cmbx_Func_Code"));
        Cmbx_Func_Code->setFont(font2);

        horizontalLayout_4->addWidget(Cmbx_Func_Code);

        label_8 = new QLabel(frame_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font2);

        horizontalLayout_4->addWidget(label_8);

        le_startaddress = new QLineEdit(frame_4);
        le_startaddress->setObjectName(QStringLiteral("le_startaddress"));
        le_startaddress->setFont(font2);

        horizontalLayout_4->addWidget(le_startaddress);

        label_9 = new QLabel(frame_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font2);

        horizontalLayout_4->addWidget(label_9);

        le_registercount = new QLineEdit(frame_4);
        le_registercount->setObjectName(QStringLiteral("le_registercount"));
        le_registercount->setFont(font2);

        horizontalLayout_4->addWidget(le_registercount);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        checkBox_autoSend = new QCheckBox(frame_4);
        checkBox_autoSend->setObjectName(QStringLiteral("checkBox_autoSend"));

        horizontalLayout_4->addWidget(checkBox_autoSend);

        tbn_SendCmd = new QPushButton(frame_4);
        tbn_SendCmd->setObjectName(QStringLiteral("tbn_SendCmd"));
        sizePolicy.setHeightForWidth(tbn_SendCmd->sizePolicy().hasHeightForWidth());
        tbn_SendCmd->setSizePolicy(sizePolicy);
        tbn_SendCmd->setMinimumSize(QSize(0, 50));
        tbn_SendCmd->setFont(font1);

        horizontalLayout_4->addWidget(tbn_SendCmd);


        verticalLayout_3->addWidget(frame_4);

        line_15 = new QFrame(frame_2);
        line_15->setObjectName(QStringLiteral("line_15"));
        line_15->setStyleSheet(QStringLiteral(""));
        line_15->setFrameShape(QFrame::HLine);
        line_15->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_15);

        frame_5 = new QFrame(frame_2);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_9 = new QHBoxLayout(frame_5);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_22 = new QLabel(frame_5);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setFont(font2);
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_22);

        lb_txP = new QLabel(frame_5);
        lb_txP->setObjectName(QStringLiteral("lb_txP"));
        sizePolicy.setHeightForWidth(lb_txP->sizePolicy().hasHeightForWidth());
        lb_txP->setSizePolicy(sizePolicy);
        lb_txP->setFont(font2);

        horizontalLayout_9->addWidget(lb_txP);

        label_23 = new QLabel(frame_5);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setFont(font2);
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_23);

        lb_ErrorP = new QLabel(frame_5);
        lb_ErrorP->setObjectName(QStringLiteral("lb_ErrorP"));
        sizePolicy.setHeightForWidth(lb_ErrorP->sizePolicy().hasHeightForWidth());
        lb_ErrorP->setSizePolicy(sizePolicy);
        lb_ErrorP->setFont(font2);

        horizontalLayout_9->addWidget(lb_ErrorP);

        label_24 = new QLabel(frame_5);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font2);
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_24);

        lb_RxP = new QLabel(frame_5);
        lb_RxP->setObjectName(QStringLiteral("lb_RxP"));
        sizePolicy.setHeightForWidth(lb_RxP->sizePolicy().hasHeightForWidth());
        lb_RxP->setSizePolicy(sizePolicy);
        lb_RxP->setFont(font2);

        horizontalLayout_9->addWidget(lb_RxP);

        tbn_ResetCounts = new QPushButton(frame_5);
        tbn_ResetCounts->setObjectName(QStringLiteral("tbn_ResetCounts"));
        sizePolicy.setHeightForWidth(tbn_ResetCounts->sizePolicy().hasHeightForWidth());
        tbn_ResetCounts->setSizePolicy(sizePolicy);
        tbn_ResetCounts->setMinimumSize(QSize(0, 50));
        tbn_ResetCounts->setFont(font1);

        horizontalLayout_9->addWidget(tbn_ResetCounts);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        label = new QLabel(frame_5);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_9->addWidget(label);

        le_scantime = new QLineEdit(frame_5);
        le_scantime->setObjectName(QStringLiteral("le_scantime"));
        le_scantime->setFont(font2);

        horizontalLayout_9->addWidget(le_scantime);


        verticalLayout_3->addWidget(frame_5);

        dockWidget = new QDockWidget(frame_2);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy2);
        dockWidget->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"border:2px solid black;\n"
"}"));
        dockWidget->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_7 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        frame_6 = new QFrame(dockWidgetContents);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy3);
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));

        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_7->addWidget(frame_6);

        dockWidget->setWidget(dockWidgetContents);

        verticalLayout_3->addWidget(dockWidget);


        gridLayout_2->addWidget(frame_2, 0, 0, 1, 1);


        retranslateUi(SetUp_IP);

        Cmbx_Func_Code->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SetUp_IP);
    } // setupUi

    void retranslateUi(QDialog *SetUp_IP)
    {
        SetUp_IP->setWindowTitle(QApplication::translate("SetUp_IP", "SetUp IP", Q_NULLPTR));
        label_4->setText(QApplication::translate("SetUp_IP", "SOURCE", Q_NULLPTR));
        lb_Sip->setText(QApplication::translate("SetUp_IP", "IP", Q_NULLPTR));
        lb_SPortNum->setText(QApplication::translate("SetUp_IP", "PORT NUMBER", Q_NULLPTR));
        lb_SPortNum_2->setText(QApplication::translate("SetUp_IP", "SLAVE ID", Q_NULLPTR));
        lineEdit_SlaveID->setText(QApplication::translate("SetUp_IP", "1", Q_NULLPTR));
        label_7->setText(QApplication::translate("SetUp_IP", "DESTINATION", Q_NULLPTR));
        lb_Dip->setText(QApplication::translate("SetUp_IP", "IP ", Q_NULLPTR));
        lb_DPortNum->setText(QApplication::translate("SetUp_IP", "PORT NUMBER", Q_NULLPTR));
        tbn_NetworkSettings->setText(QApplication::translate("SetUp_IP", "IP CONFIG", Q_NULLPTR));
        tbn_Apply->setText(QApplication::translate("SetUp_IP", "OPEN PORT", Q_NULLPTR));
        tbn_ClosePort->setText(QApplication::translate("SetUp_IP", "CLOSE PORT", Q_NULLPTR));
        label_5->setText(QApplication::translate("SetUp_IP", "Slave ID:", Q_NULLPTR));
        le_slaveid->setText(QApplication::translate("SetUp_IP", "1", Q_NULLPTR));
        label_6->setText(QApplication::translate("SetUp_IP", "Func Code:", Q_NULLPTR));
        Cmbx_Func_Code->clear();
        Cmbx_Func_Code->insertItems(0, QStringList()
         << QApplication::translate("SetUp_IP", "None", Q_NULLPTR)
         << QApplication::translate("SetUp_IP", "03 (0x03) Read Holding Registers", Q_NULLPTR)
         << QApplication::translate("SetUp_IP", "04 (0x04) Read Input Registers", Q_NULLPTR)
         << QApplication::translate("SetUp_IP", "06 (0x06) Write Single Register", Q_NULLPTR)
         << QApplication::translate("SetUp_IP", "16 (0x10) Write Multiple Registers", Q_NULLPTR)
        );
        label_8->setText(QApplication::translate("SetUp_IP", "Start Address:", Q_NULLPTR));
        le_startaddress->setText(QApplication::translate("SetUp_IP", "0", Q_NULLPTR));
        label_9->setText(QApplication::translate("SetUp_IP", "Register Count", Q_NULLPTR));
        le_registercount->setText(QApplication::translate("SetUp_IP", "2", Q_NULLPTR));
        checkBox_autoSend->setText(QString());
        tbn_SendCmd->setText(QApplication::translate("SetUp_IP", "SEND", Q_NULLPTR));
        label_22->setText(QApplication::translate("SetUp_IP", "Tx Packets:", Q_NULLPTR));
        lb_txP->setText(QApplication::translate("SetUp_IP", "0", Q_NULLPTR));
        label_23->setText(QApplication::translate("SetUp_IP", "|Error Packets:", Q_NULLPTR));
        lb_ErrorP->setText(QApplication::translate("SetUp_IP", "0", Q_NULLPTR));
        label_24->setText(QApplication::translate("SetUp_IP", "|Rx Packets:", Q_NULLPTR));
        lb_RxP->setText(QApplication::translate("SetUp_IP", "0", Q_NULLPTR));
        tbn_ResetCounts->setText(QApplication::translate("SetUp_IP", "RESET COUNT", Q_NULLPTR));
        label->setText(QApplication::translate("SetUp_IP", "Scan (10 * ms )", Q_NULLPTR));
        le_scantime->setText(QApplication::translate("SetUp_IP", "500", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetUp_IP: public Ui_SetUp_IP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUP_IP_H
