/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QLabel *label_Tx;
    QLabel *label_Rx;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBox_Master;
    QCheckBox *checkBox_Slave;
    QVBoxLayout *Modbus_Com_Screen;
    QCheckBox *checkBox_connectio_status;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_16bit;
    QCheckBox *checkBox_32bit;
    QWidget *page_2;
    QWidget *Serial;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *Serial_Com_Screen;
    QComboBox *ui_Style;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(885, 493);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/Images/protocol.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        stackedWidget = new QStackedWidget(tab);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout = new QGridLayout(page);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_Tx = new QLabel(page);
        label_Tx->setObjectName(QStringLiteral("label_Tx"));
        label_Tx->setMinimumSize(QSize(0, 40));
        label_Tx->setFont(font);

        gridLayout->addWidget(label_Tx, 2, 1, 1, 1);

        label_Rx = new QLabel(page);
        label_Rx->setObjectName(QStringLiteral("label_Rx"));
        label_Rx->setMinimumSize(QSize(0, 40));
        label_Rx->setFont(font);

        gridLayout->addWidget(label_Rx, 2, 2, 1, 1);

        frame = new QFrame(page);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        checkBox_Master = new QCheckBox(frame);
        checkBox_Master->setObjectName(QStringLiteral("checkBox_Master"));
        checkBox_Master->setFont(font);

        gridLayout_2->addWidget(checkBox_Master, 0, 0, 1, 1);

        checkBox_Slave = new QCheckBox(frame);
        checkBox_Slave->setObjectName(QStringLiteral("checkBox_Slave"));
        checkBox_Slave->setFont(font);

        gridLayout_2->addWidget(checkBox_Slave, 0, 1, 1, 1);

        Modbus_Com_Screen = new QVBoxLayout();
        Modbus_Com_Screen->setSpacing(6);
        Modbus_Com_Screen->setObjectName(QStringLiteral("Modbus_Com_Screen"));

        gridLayout_2->addLayout(Modbus_Com_Screen, 2, 0, 1, 5);

        checkBox_connectio_status = new QCheckBox(frame);
        checkBox_connectio_status->setObjectName(QStringLiteral("checkBox_connectio_status"));
        checkBox_connectio_status->setEnabled(false);
        checkBox_connectio_status->setFont(font);

        gridLayout_2->addWidget(checkBox_connectio_status, 0, 4, 1, 1);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QFont font1;
        font1.setPointSize(14);
        frame_2->setFont(font1);
        frame_2->setStyleSheet(QLatin1String("QFrame\n"
"{border:2px solid black;}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBox_16bit = new QCheckBox(frame_2);
        checkBox_16bit->setObjectName(QStringLiteral("checkBox_16bit"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        checkBox_16bit->setFont(font2);

        horizontalLayout->addWidget(checkBox_16bit);

        checkBox_32bit = new QCheckBox(frame_2);
        checkBox_32bit->setObjectName(QStringLiteral("checkBox_32bit"));
        checkBox_32bit->setFont(font2);

        horizontalLayout->addWidget(checkBox_32bit);


        gridLayout_2->addWidget(frame_2, 0, 2, 1, 1);


        gridLayout->addWidget(frame, 1, 1, 1, 2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        verticalLayout_3->addWidget(stackedWidget);

        tabWidget->addTab(tab, QString());
        Serial = new QWidget();
        Serial->setObjectName(QStringLiteral("Serial"));
        verticalLayout_4 = new QVBoxLayout(Serial);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        Serial_Com_Screen = new QVBoxLayout();
        Serial_Com_Screen->setSpacing(6);
        Serial_Com_Screen->setObjectName(QStringLiteral("Serial_Com_Screen"));

        verticalLayout_4->addLayout(Serial_Com_Screen);

        tabWidget->addTab(Serial, QString());

        verticalLayout->addWidget(tabWidget);

        ui_Style = new QComboBox(centralWidget);
        ui_Style->setObjectName(QStringLiteral("ui_Style"));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        ui_Style->setFont(font3);

        verticalLayout->addWidget(ui_Style);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 885, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "UDP SERIAL APPLICATION", Q_NULLPTR));
        label_Tx->setText(QString());
        label_Rx->setText(QString());
        checkBox_Master->setText(QApplication::translate("MainWindow", "Master", Q_NULLPTR));
        checkBox_Slave->setText(QApplication::translate("MainWindow", "Slave", Q_NULLPTR));
        checkBox_connectio_status->setText(QApplication::translate("MainWindow", "Connected", Q_NULLPTR));
        checkBox_16bit->setText(QApplication::translate("MainWindow", "16bit(1 reg's = 1)", Q_NULLPTR));
        checkBox_32bit->setText(QApplication::translate("MainWindow", "32bit(2 reg's = 1)", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "UDP", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Serial), QApplication::translate("MainWindow", "SERIAL", Q_NULLPTR));
        ui_Style->clear();
        ui_Style->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "TealGraphite ", Q_NULLPTR)
         << QApplication::translate("MainWindow", "OrangeCharcoal", Q_NULLPTR)
         << QApplication::translate("MainWindow", "EmeraldDarkGray", Q_NULLPTR)
         << QApplication::translate("MainWindow", "PurpleCarbon", Q_NULLPTR)
         << QApplication::translate("MainWindow", "AquaSlate               ", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
