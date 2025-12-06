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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
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
    QGridLayout *gridLayout;
    QFrame *frame_config;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab_UDP;
    QWidget *tab_Serial;
    QGridLayout *gridLayout_4;
    QWidget *serialPlaceholder;
    QFrame *frame_DataView;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_3;
    QWidget *tab_4;
    QComboBox *ui_Style;
    QFrame *line;
    QCheckBox *checkBox_ConnectStatus;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(637, 355);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/protocol.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame_config = new QFrame(centralWidget);
        frame_config->setObjectName(QStringLiteral("frame_config"));
        frame_config->setStyleSheet(QLatin1String("/*QFrame\n"
"{\n"
"border:2px solid white;\n"
"}*/"));
        frame_config->setFrameShape(QFrame::StyledPanel);
        frame_config->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_config);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(frame_config);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        tabWidget->setFont(font);
        tab_UDP = new QWidget();
        tab_UDP->setObjectName(QStringLiteral("tab_UDP"));
        tabWidget->addTab(tab_UDP, QString());
        tab_Serial = new QWidget();
        tab_Serial->setObjectName(QStringLiteral("tab_Serial"));
        gridLayout_4 = new QGridLayout(tab_Serial);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(3, 3, 3, 3);
        serialPlaceholder = new QWidget(tab_Serial);
        serialPlaceholder->setObjectName(QStringLiteral("serialPlaceholder"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(serialPlaceholder->sizePolicy().hasHeightForWidth());
        serialPlaceholder->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(serialPlaceholder, 0, 0, 1, 1);

        tabWidget->addTab(tab_Serial, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);


        gridLayout->addWidget(frame_config, 0, 0, 1, 1);

        frame_DataView = new QFrame(centralWidget);
        frame_DataView->setObjectName(QStringLiteral("frame_DataView"));
        frame_DataView->setStyleSheet(QLatin1String("/*QFrame\n"
"{\n"
"border:2px solid white;\n"
"}*/"));
        frame_DataView->setFrameShape(QFrame::StyledPanel);
        frame_DataView->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_DataView);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        tabWidget_2 = new QTabWidget(frame_DataView);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setFont(font);
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_6 = new QGridLayout(tab_3);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));

        gridLayout_5->addLayout(verticalLayout_3, 0, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget_2->addTab(tab_4, QString());

        gridLayout_3->addWidget(tabWidget_2, 0, 0, 1, 1);


        gridLayout->addWidget(frame_DataView, 0, 2, 1, 1);

        ui_Style = new QComboBox(centralWidget);
        ui_Style->setObjectName(QStringLiteral("ui_Style"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        ui_Style->setFont(font1);

        gridLayout->addWidget(ui_Style, 1, 0, 1, 3);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"border:2px solid white;\n"
"}"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 1, 1, 1);

        checkBox_ConnectStatus = new QCheckBox(centralWidget);
        checkBox_ConnectStatus->setObjectName(QStringLiteral("checkBox_ConnectStatus"));
        checkBox_ConnectStatus->setFont(font1);

        gridLayout->addWidget(checkBox_ConnectStatus, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 637, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ProtocolsApp", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_UDP), QApplication::translate("MainWindow", "UDP", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_Serial), QApplication::translate("MainWindow", "SERIAL", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "MODBUS", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
        ui_Style->clear();
        ui_Style->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "TealGraphite ", Q_NULLPTR)
         << QApplication::translate("MainWindow", "OrangeCharcoal", Q_NULLPTR)
         << QApplication::translate("MainWindow", "EmeraldDarkGray", Q_NULLPTR)
         << QApplication::translate("MainWindow", "PurpleCarbon", Q_NULLPTR)
         << QApplication::translate("MainWindow", "AquaSlate               ", Q_NULLPTR)
         << QApplication::translate("MainWindow", "None", Q_NULLPTR)
        );
        checkBox_ConnectStatus->setText(QApplication::translate("MainWindow", "CONNECTED", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
