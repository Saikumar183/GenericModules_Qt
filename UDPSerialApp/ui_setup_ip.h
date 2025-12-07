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
#include <QtWidgets/QDialog>
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

QT_BEGIN_NAMESPACE

class Ui_SetUp_IP
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
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
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnShowIPs;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *tbn_Apply;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QFrame *line_15;

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
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer_2);

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

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        btnShowIPs = new QPushButton(frame_3);
        btnShowIPs->setObjectName(QStringLiteral("btnShowIPs"));
        sizePolicy.setHeightForWidth(btnShowIPs->sizePolicy().hasHeightForWidth());
        btnShowIPs->setSizePolicy(sizePolicy);
        btnShowIPs->setMinimumSize(QSize(0, 50));
        btnShowIPs->setFont(font1);

        horizontalLayout_2->addWidget(btnShowIPs);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        tbn_Apply = new QPushButton(frame_3);
        tbn_Apply->setObjectName(QStringLiteral("tbn_Apply"));
        sizePolicy.setHeightForWidth(tbn_Apply->sizePolicy().hasHeightForWidth());
        tbn_Apply->setSizePolicy(sizePolicy);
        tbn_Apply->setMinimumSize(QSize(0, 50));
        tbn_Apply->setFont(font1);
        tbn_Apply->setCheckable(true);

        horizontalLayout_2->addWidget(tbn_Apply);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(frame_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer);

        line_15 = new QFrame(frame_2);
        line_15->setObjectName(QStringLiteral("line_15"));
        line_15->setStyleSheet(QStringLiteral(""));
        line_15->setFrameShape(QFrame::HLine);
        line_15->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_15);


        gridLayout_2->addWidget(frame_2, 0, 0, 1, 1);


        retranslateUi(SetUp_IP);

        QMetaObject::connectSlotsByName(SetUp_IP);
    } // setupUi

    void retranslateUi(QDialog *SetUp_IP)
    {
        SetUp_IP->setWindowTitle(QApplication::translate("SetUp_IP", "SetUp IP", Q_NULLPTR));
        label_4->setText(QApplication::translate("SetUp_IP", "SOURCE", Q_NULLPTR));
        lb_Sip->setText(QApplication::translate("SetUp_IP", "IP", Q_NULLPTR));
        lb_SPortNum->setText(QApplication::translate("SetUp_IP", "PORT NUMBER", Q_NULLPTR));
        label_7->setText(QApplication::translate("SetUp_IP", "DESTINATION", Q_NULLPTR));
        lb_Dip->setText(QApplication::translate("SetUp_IP", "IP ", Q_NULLPTR));
        lb_DPortNum->setText(QApplication::translate("SetUp_IP", "PORT NUMBER", Q_NULLPTR));
        tbn_NetworkSettings->setText(QApplication::translate("SetUp_IP", "IP CONFIG", Q_NULLPTR));
        btnShowIPs->setText(QApplication::translate("SetUp_IP", "AVAILABLE IP's", Q_NULLPTR));
        tbn_Apply->setText(QApplication::translate("SetUp_IP", "OPEN PORT", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetUp_IP: public Ui_SetUp_IP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUP_IP_H
