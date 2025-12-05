#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    UDP_Comm = new Communication(this);
ModbusPort_Screen = new SetUp_IP(this);
    ui->Modbus_Com_Screen->addWidget(ModbusPort_Screen);
    SerialPort_Screen = new SerialPortWidget();
    ui->Serial_Com_Screen->addWidget(SerialPort_Screen);
    ui->checkBox_Slave->setChecked(true);
    ui->checkBox_16bit->setChecked(true);
    Application.is16BitChecked = ui->checkBox_16bit->isChecked();
    ui->frame_2->setDisabled(true);
    connect(ui->checkBox_Master, &QCheckBox::clicked, this, [this](bool checked){
        if (checked)
        {
            ui->checkBox_Slave->setChecked(false);
            ModbusPort_Screen->on_tbn_ResetCounts_clicked();
        }
        else
        {
            // If Master is unchecked, ensure Slave is ON
            if (!ui->checkBox_Slave->isChecked()) {
                ui->checkBox_Slave->setChecked(true);
            }
        }

        Application.isMasterChecked = ui->checkBox_Master->isChecked();
        Application.isSlaveChecked  = ui->checkBox_Slave->isChecked();
        ui->frame_2->setDisabled(!Application.isMasterChecked);

    });

    connect(ui->checkBox_Slave, &QCheckBox::clicked, this, [this](bool checked){
        if (checked) {
            ui->checkBox_Master->setChecked(false);
            ModbusPort_Screen->on_tbn_ResetCounts_clicked();
        } else {
            // If Slave is unchecked, ensure Master is ON
            if (!ui->checkBox_Master->isChecked()) {
                ui->checkBox_Master->setChecked(true);
            }
        }

        Application.isSlaveChecked  = ui->checkBox_Slave->isChecked();
        Application.isMasterChecked = ui->checkBox_Master->isChecked();
        ui->frame_2->setDisabled(Application.isSlaveChecked);


    });

    connect(ui->checkBox_16bit, &QCheckBox::clicked, this, [this](bool checked){

        if (!Application.isMasterChecked) {
            // Slave mode: always 16-bit
            ui->checkBox_16bit->setChecked(true);
            ui->checkBox_32bit->setChecked(false);
            QMessageBox::information(this, "Information",
                                     "Select Master to access. 16-bit is default for Slave");
            return;
        }

        if (checked) {
            ui->checkBox_32bit->setChecked(false);
        } else {
            // If 16-bit is unchecked, ensure 32-bit is ON
            if (!ui->checkBox_32bit->isChecked()) {
                ui->checkBox_32bit->setChecked(true);
            }
        }
ModbusPort_Screen->updateLE_numbers();
        Application.is16BitChecked = ui->checkBox_16bit->isChecked();
        Application.is32BitChecked = ui->checkBox_32bit->isChecked();


    });

    connect(ui->checkBox_32bit, &QCheckBox::clicked, this, [this](bool checked){
        if (!Application.isMasterChecked) {
            // Slave mode: always 16-bit
            ui->checkBox_32bit->setChecked(false);
            ui->checkBox_16bit->setChecked(true);
            QMessageBox::information(this, "Information",
                                     "Select Master to access. 16-bit is default for Slave");
            return;
        }

        if (checked) {
            ui->checkBox_16bit->setChecked(false);
        } else {
            // If 32-bit is unchecked, ensure 16-bit is ON
            if (!ui->checkBox_16bit->isChecked()) {
                ui->checkBox_16bit->setChecked(true);
            }
        }
 ModbusPort_Screen->updateLE_numbers();
        Application.is32BitChecked = ui->checkBox_32bit->isChecked();
        Application.is16BitChecked = ui->checkBox_16bit->isChecked();
    });

    QFont boldFont("Arial", 8, QFont::Bold);
    // Status Panel Label
    Application.lbl_statuspanel = new QLabel(this);
    Application.lbl_statuspanel->setFont(boldFont);
    Application.lbl_statuspanel->setText("    ");
    Application.lbl_statuspanel->setStyleSheet("border:none;");
    ui->statusBar->addPermanentWidget(Application.lbl_statuspanel);

    connect(SerialPort_Screen, &SerialPortWidget::ModbusFrameResponse,UDP_Comm, &Communication::ModbusFrameResponseHandler);
    connect(ModbusPort_Screen,SIGNAL(ConnectNetWork()),UDP_Comm,SLOT(connectNetwork()));
    connect(ModbusPort_Screen,SIGNAL(closePort()),UDP_Comm,SLOT(closePort()));

    connect(ModbusPort_Screen, SIGNAL(buildModbusRTUFrame(quint8,quint8,quint16,long*,quint16)),UDP_Comm,SLOT(buildModbusRTUFrame(quint8,quint8,quint16,long*,quint16)));
    connect(UDP_Comm,SIGNAL(loadNetworkData()),ModbusPort_Screen,SLOT(loadNetworkData()));
    connect(UDP_Comm, &Communication::SendModbusFrame,SerialPort_Screen, &SerialPortWidget::SendModbusFrame);
    connect(UDP_Comm, &Communication::processReceivedFrame,ModbusPort_Screen, &SetUp_IP::processReceivedFrame);
    connect(UDP_Comm, &Communication::processReceivedFrame_Slave,ModbusPort_Screen, &SetUp_IP::processReceivedFrame_Slave);

    timer_run = new QTimer(this);
    connect(timer_run, SIGNAL(timeout()), this,SLOT(onTimeout_Run()));
    connect(ui->stackedWidget, SIGNAL(currentChanged(int)), this, SLOT(onPageChanged(int)));

    timer_run->start(Application.TimerTimeout);
    ui->tabWidget->setCurrentIndex(0);
//    ui->mainToolBar->addWidget((QWidget*)ModbusPort_Screen->getDockWidgetAddress());

    ui->statusBar->addPermanentWidget(ui->ui_Style);
    ui->ui_Style->setCurrentIndex(Application.currentTheme);
    qApp->setStyleSheet(Application.getStyleSheet(Application.currentTheme));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onTimeout_Run()
{

    checkTxFlag();
    checkRxFlag();
    ModbusPort_Screen->UpdatePackeCounts();
    if(Application.isPortBindCompleted)
    {
        static uint8_t retry = 0;
        if(retry++ > ModbusPort_Screen->get_scanTime())
        {
            retry = 0;
            Application.UpdateStatusLabel(QString(" - "), false);
//            UDP_Comm->Reconnect_UDP();
        }
    }
    else
    {
        UDP_Comm->closePort();
    }
    ui->checkBox_connectio_status->setChecked(Application.isPortBindCompleted);

}
void MainWindow::onPageChanged(int index)
{

}
void MainWindow::checkRxFlag()
{
    ui->label_Rx->setText(
        "(" + QString::number(Application.RxData.size()) + " Bytes) Rx: " +
        Application.RxData.toHex().toUpper()
    );

    if (Application.Modbusconnection_RxFlag)
    {
        // Get blink color based on current theme
        QColor blinkColor = Application.getBlinkColor(Application.currentTheme);

        // Blink ON
        ui->label_Rx->setStyleSheet(
            QString("background-color: %1; color: white; border-radius: 5px;")
            .arg(blinkColor.name())
        );

        // Reset flag so we only blink once per packet
        Application.Modbusconnection_RxFlag = false;

        // Blink OFF after 200 ms
        QTimer::singleShot(200, this, [this]() {
            ui->label_Rx->setStyleSheet(""); // Restore theme style
        });
        Application.LogModbusData();
    }
}

void MainWindow::checkTxFlag()
{
    ui->label_Tx->setText(
        "(" + QString::number(Application.TxData.size()) + " Bytes) Tx: " +
        Application.TxData.toHex().toUpper()
    );

    if (Application.Modbusconnection_TxFlag)
    {
        QColor blinkColor = Application.getBlinkColor(Application.currentTheme);

        // Blink ON
        ui->label_Tx->setStyleSheet(
            QString("background-color: %1; color: white; border-radius: 5px;")
            .arg(blinkColor.name())
        );

        Application.Modbusconnection_TxFlag = false;

        QTimer::singleShot(200, this, [this]() {
            ui->label_Tx->setStyleSheet(""); // Restore theme style
        });
    }
}


void MainWindow::on_tabWidget_currentChanged(int index)
{
    QWidget *frmWidget = (QWidget*)ModbusPort_Screen->getDockWidgetAddress();
    switch (index)
    {
    case 0:
        frmWidget->setVisible(true);
        break;
    case 1:
        frmWidget->setVisible(false);
        break;
    default:
        break;
    }
}

void MainWindow::on_ui_Style_currentIndexChanged(int index)
{
//    qApp->setStyleSheet("");
    Application.currentTheme = (AppTheme_et)index;
    qApp->setStyleSheet(Application.getStyleSheet(Application.currentTheme));
}
