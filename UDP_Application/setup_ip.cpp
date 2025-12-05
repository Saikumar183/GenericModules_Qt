#include "setup_ip.h"
#include "ui_setup_ip.h"

SetUp_IP::SetUp_IP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetUp_IP)
{
    ui->setupUi(this);
    ClassBlocksOnNumber = new BlocksOnNumber(this);
    ui->verticalLayout_5->addWidget(ClassBlocksOnNumber);

    NetworkFileName = QApplication::applicationDirPath()+QDir::separator()+"network.txt";
    setModal(true);
    Init_QMbx_KeyBoard();
    ui->tbn_NetworkSettings->setVisible(true);
    ui->tbn_Apply->setVisible(true);
    ui->frame_3->setVisible(true);
    ui->tbn_SendCmd->setVisible(true);
    ui->Cmbx_Func_Code->setCurrentIndex(2);
    on_Cmbx_Func_Code_currentIndexChanged(ui->Cmbx_Func_Code->currentText());

    ui->lb_SPortNum_2->hide();
    ui->lineEdit_SlaveID->hide();

    connect(ui->le_registercount,SIGNAL(textChanged(QString)),ClassBlocksOnNumber,SLOT(updateRegisterCountLineEdit(QString)));
    ClassBlocksOnNumber->updateRegisterCountLineEdit(ui->le_registercount->text());

    connect(ui->le_scantime,SIGNAL(textChanged(QString)),this,SIGNAL(updateScanTime(QString)));

    ui->label->setText("Scan ("+QString::number(Application.TimerTimeout)+" * ms )");
    Application.FunctionCode = (ModbusFunctionCode_et)ui->Cmbx_Func_Code->currentIndex();
}

SetUp_IP::~SetUp_IP()
{
    delete ui;
}
QFrame* SetUp_IP::getMasterFrame(void)
{
    return ui->frame_4;
}
int SetUp_IP::get_scanTime()
{
    if(ui->le_scantime->text().toInt() <= 0)
    {
        ui->le_scantime->setText(QString::number(10));
    }
    return ui->le_scantime->text().toInt();
}
void SetUp_IP::Init_QMbx_KeyBoard()
{
    loadDataFromFile(NetworkFileName);

    QWidget *customWidget = new QWidget();

    ui->lineEdit_SPortNum->setMaxLength(10);
    ui->lineEdit_DPortNum->setMaxLength(10);
    QRegExp ipRegex("^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");  // Matches each octet of an IP address
    ipValidator = new QRegExpValidator(ipRegex, this);
    ui->lineEdit_Sip->setValidator(ipValidator);
    ui->lineEdit_Dip->setValidator(ipValidator);
    setWindowFlags(Qt::FramelessWindowHint);

}
QDockWidget *SetUp_IP::getDockWidgetAddress(void)
{
    return ui->dockWidget;
}
void SetUp_IP::UpdatePasswordString(QString _PassWord)
{
    QLineEdit *le = qobject_cast<QLineEdit*>(focusWidget());
    if(le)
    {
        le->setText(_PassWord);
    }
}

void SetUp_IP::on_tbn_Apply_clicked()
{
    saveDatatoFile(NetworkFileName);
    emit save_ip();
    emit ConnectNetWork();
}

void SetUp_IP::on_tbn_ClosePort_clicked()
{

    emit closePort();
}


void SetUp_IP::saveDatatoFile(const QString &fileName )
{
    QString portnu = ui->lineEdit_SPortNum->text();


        ipSetting[SOURCE].Ip_Address  = ui->lineEdit_Sip->text();
        ipSetting[SOURCE].PortNumber =portnu.toInt(); //ui->lineEdit_SPortNum->text().toShort();

        ipSetting[DESTINATION].Ip_Address  = ui->lineEdit_Dip->text();
        ipSetting[DESTINATION].PortNumber = ui->lineEdit_DPortNum->text().toInt();

        Application.Source_address = QHostAddress(ipSetting[SOURCE].Ip_Address);
        Application.Source_PortNumber = ipSetting[SOURCE].PortNumber;
        Application.Destination_address = QHostAddress(ipSetting[DESTINATION].Ip_Address);
        Application.Destination_PortNumber = ipSetting[DESTINATION].PortNumber;

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);

        out << ipSetting[SOURCE].Ip_Address << "," << ipSetting[SOURCE].PortNumber << ",";
        out << ipSetting[DESTINATION].Ip_Address << "," << ipSetting[DESTINATION].PortNumber << ",";
        out<<"\n";
        file.close();
    }
//    qDebug()<<ipSetting[DESTINATION].PortNumber<<"----"<<ipSetting[SOURCE].PortNumber<<portnu.toInt();
    loadDataFromFile(fileName);

}

void SetUp_IP::loadDataFromFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.exists()) {
        qWarning() << "File does not exist: " << fileName;


        emit load_ip();
        fileNotFoundFlag = true;
        saveDatatoFile(fileName);
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file: " << fileName;
        return;
    }

    QTextStream in(&file);

    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        ipSetting[SOURCE].Ip_Address = fields[0];
        ipSetting[SOURCE].PortNumber = fields[1].toInt();
        ipSetting[DESTINATION].Ip_Address = fields[2];
        ipSetting[DESTINATION].PortNumber = fields[3].toInt();
    }
    Application.Source_address = QHostAddress(ipSetting[SOURCE].Ip_Address);
    Application.Source_PortNumber = ipSetting[SOURCE].PortNumber;
    Application.Destination_address = QHostAddress(ipSetting[DESTINATION].Ip_Address);
    Application.Destination_PortNumber = ipSetting[DESTINATION].PortNumber;



    file.close();

    ui->lineEdit_Sip->setText(ipSetting[SOURCE].Ip_Address );
    ui->lineEdit_SPortNum->setText(QString::number(ipSetting[SOURCE].PortNumber));

    ui->lineEdit_Dip->setText(ipSetting[DESTINATION].Ip_Address );
    ui->lineEdit_DPortNum->setText(QString::number(ipSetting[DESTINATION].PortNumber));

}


void SetUp_IP::on_tbn_NetworkSettings_clicked()
{
#if defined(Q_OS_WIN)
    // Windows: open Network & Internet settings
    QProcess::startDetached("control.exe", QStringList() << "ncpa.cpl");

#elif defined(Q_OS_MAC)
    // macOS: open Network preferences
    QProcess::startDetached("open", QStringList() << "/System/Library/PreferencePanes/Network.prefPane");

#elif defined(Q_OS_LINUX)
    // Linux: GNOME example (adjust if using KDE or others)
    QProcess::startDetached("gnome-control-center", QStringList() << "network");

#else
    // Fallback: do nothing or show a message
    qDebug() << "Network settings not supported on this OS.";
#endif
}
void SetUp_IP::loadNetworkData(void)
{
    loadDataFromFile(NetworkFileName);
}

void SetUp_IP::on_tbn_SendCmd_clicked()
{
    if(!Application.isPortBindCompleted)
    {
        QMessageBox::information(this,"Network Error","Click "+ui->tbn_Apply->text()+" to start.");

        return;
    }
    if(!Application.isMasterChecked)
    {
        QMessageBox::information(this,"Information","Select Master to access.");
        return;

    }
    if(!(Application.is32BitChecked || Application.is16BitChecked))
    {
        QMessageBox::information(this,"Selection Error","Select 16bit or 32bit to proced further.");

        return;
    }

    uint8_t slaveId = ui->le_slaveid->text().toUShort();

    // Extract hex value from selected text
    QString selectedText = ui->Cmbx_Func_Code->currentText();
    QRegularExpression regex("\\(0x([0-9A-Fa-f]+)\\)");
    QRegularExpressionMatch match = regex.match(selectedText);

    if (match.hasMatch()) {
        QString hexString = match.captured(1);  // e.g., "04"
        functionCode = hexString.toUInt(nullptr, 16);  // convert hex to int
    }

//    qDebug()<<functionCode;
    quint16 startAddress = ui->le_startaddress->text().toUShort();
    quint16 noOfRegs = ui->le_registercount->text().toUShort();
    if(noOfRegs == 0)
    {
        QMessageBox::information(this,ui->label_9->text(),"1 is the minimum value.");
        return;
    }
    if(Application.is32BitChecked)
    {
        noOfRegs *= 2;
    }
    emit buildModbusRTUFrame(slaveId, functionCode, startAddress,(long*) Application.lineEditsData.data(), noOfRegs);

    if (Application.lbl_statuspanel->text()=="data updated.")
    {
        Application.Device_SlaveID = slaveId;
        Application.Modbusconnection_Flag = true;
        ClassBlocksOnNumber->loadRegisters(Application.lineEditsData.data(),Application.RxData.size());
        //        Application.Var[AXIS1].Genpa.ReservedPara5 = Application.Device_SlaveID;

    }

}
bool SetUp_IP::processModbusFrame(const QByteArray &rx, ModbusData_st &out)
{
    out.registers16.clear();
    out.registers32.clear();
    out.floats32.clear();
    out.coils.clear();

    if (rx.size() < 5) {
        QMessageBox::information(this,"Frame Error","Invalid Modbus frame");
//        qWarning() << "Invalid Modbus frame:" << rx.toHex();
        return false;
    }

    out.slaveAddress = (uint8_t)rx[0];
    out.functionCode = (uint8_t)rx[1];
    uint8_t fc = out.functionCode;

    // -----------------------------------
    // FC 01 / FC 02 / FC 03 / FC 04
    // -----------------------------------
    if (fc == 0x01 || fc == 0x02 || fc == 0x03 || fc == 0x04)
    {
        uint8_t byteCount = (uint8_t)rx[2];

        if (rx.size() < 3 + byteCount + 2) {
            qWarning() << "Invalid Byte Count:" << rx.toHex();
            return false;
        }

        // --- FC 01, 02 (COILS) ---
        if (fc == 0x01 || fc == 0x02)
        {
            for (int i = 0; i < byteCount; i++)
            {
                uint8_t b = (uint8_t)rx[3 + i];
                for (int bit = 0; bit < 8; bit++)
                    out.coils.append((b >> bit) & 0x01);
            }
        }

        // --- FC 03, 04 (REGISTERS 16-bit) ---
        if (fc == 0x03 || fc == 0x04)
        {
            for (int i = 0; i < byteCount; i += 2)
            {
                uint16_t val = (uint16_t(rx[3 + i]) << 8) |
                                uint8_t(rx[4 + i]);
                qDebug()<<"byte "<<i<<byteCount<<val;
                out.registers16.append(val);
            }
        }
        return false;
    }

    // -----------------------------------
    // FC 05 – Write Single Coil
    // -----------------------------------
    else if (fc == 0x05)
    {
        if (rx.size() < 8) return false;

        uint16_t value = (uint16_t(rx[4]) << 8) | uint8_t(rx[5]);
        out.coils.append(value == 0xFF00);  // 0xFF00 = ON
    }

    // -----------------------------------
    // FC 06 – Write Single Register
    // -----------------------------------
    else if (fc == 0x06)
    {
        if (rx.size() < 8) return false;

        uint16_t value = (uint16_t(rx[4]) << 8) | uint8_t(rx[5]);
        out.registers16.append(value);
    }

    // -----------------------------------
    // FC 15 – Write Multiple Coils
    // -----------------------------------
    else if (fc == 0x0F)
    {
        if (rx.size() < 8) return false;

        uint16_t count = (uint16_t(rx[4]) << 8) | uint8_t(rx[5]);
        out.coils.resize(count);
    }

    // -----------------------------------
    // FC 16 – Write Multiple Registers
    // -----------------------------------
    else if (fc == 0x10)
    {
        if (rx.size() < 8) return false;

        uint16_t count = (uint16_t(rx[4]) << 8) | uint8_t(rx[5]);
        out.registers16.resize(count);
    }

    else {
        // Check for Modbus exception response
        if (fc == 0x80)
        {
            quint8 exceptionCode = static_cast<quint8>(rx[2]);
            QString msg = QString("Modbus Exception: Function %1, Code %2")
                    .arg(static_cast<quint8>(rx[1]) & 0x7F)
                    .arg(exceptionCode);
            Application.UpdateStatusLabel(msg, true);

            switch (exceptionCode) {
            case 0x01:
                Application.UpdateStatusLabel("Illegal Function", true);
                break;
            case 0x02:
                Application.UpdateStatusLabel("Illegal Data Address", true);
                break;
            case 0x03:
                Application.UpdateStatusLabel("Illegal Data Value", true);
                break;
            case 0x04:
                Application.UpdateStatusLabel("Slave Device Failure", true);
                break;
            case 0x06:
                Application.UpdateStatusLabel("Slave Device Busy", true);
                break;
            default:
                Application.UpdateStatusLabel("Unknown Modbus Exception Code", true);
                break;
            }

            Application.Modbusconnection_isUdpBusy  = false;
            QMessageBox::information(this,"Function Code Error","Unsupported Function Code");
            return false;
        }

        //        qWarning() << "Unsupported Function Code:" << fc;
    }
    return true;
}

void SetUp_IP::processReceivedFrame(QByteArray rxData)
{
    ModbusData_st parsed;
//    qDebug()<<"9...."<<rxData;
    if(!processModbusFrame(rxData, parsed))
    {
        return;
    }
//qDebug()<<"10....";
    // --------------------------
    // 16-bit Mode
    // --------------------------
    if (Application.is16BitChecked)
    {

        ClassBlocksOnNumber->loadRegisters(
            parsed.registers16.data(),
            parsed.registers16.size()
        );

        qDebug() << "16-bit registers loaded:" << parsed.registers16<< parsed.registers16.size();
    }

    // --------------------------
    // 32-bit Mode
    // --------------------------
    if (Application.is32BitChecked)
    {
        parsed.registers32.clear();
        parsed.floats32.clear();

        for (int i = 0; i + 1 < parsed.registers16.size(); i += 2)
        {
            uint16_t r1 = parsed.registers16[i];
            uint16_t r2 = parsed.registers16[i + 1];

            uint32_t val32 = Application.combineToUint32(r1, r2); // CDAB format
            parsed.registers32.append(val32);
            parsed.floats32.append(Application.convertToFloat(val32));
        }

        ClassBlocksOnNumber->loadRegisters((uint16_t*)parsed.registers32.data(),parsed.registers32.size());

        qDebug() << "32-bit registers loaded:" << parsed.registers32<< parsed.registers32.size();
//        qDebug() << "32-bit float values   :" << parsed.floats32;
    }
}

void SetUp_IP::processReceivedFrame_Slave(QByteArray rxData)
{
    ClassBlocksOnNumber->loadRegisters((uint16_t*)rxData.data(),rxData.size());
}

void SetUp_IP::on_le_slaveid_textChanged(const QString &arg1)
{
    int slaveId = ui->le_slaveid->text().toInt();
    if(slaveId < 0)
    {
        ui->le_slaveid->setText(QString::number(Application.Device_SlaveID));
    }
}

void SetUp_IP::on_tbn_ResetCounts_clicked()
{
     Application.TxPackets=0;
     Application.RxPackets=0;
     Application.ErrorPackets=0;
     UpdatePackeCounts();

}
void SetUp_IP::UpdatePackeCounts()
{
     ui->lb_txP->setText(QString::number(Application.TxPackets));
     ui->lb_RxP->setText(QString::number(Application.RxPackets));
     ui->lb_ErrorP->setText(QString::number(Application.ErrorPackets));


     getMasterFrame()->setVisible(Application.isMasterChecked);
     if((Application.isPortBindCompleted)&&(ui->checkBox_autoSend->isChecked())&&(Application.isMasterChecked))
     {
         static int timerCntr = 0;
         if(timerCntr++ > get_scanTime())
         {
             timerCntr = 0;
             ui->tbn_SendCmd->click();
         }
     }
}

void SetUp_IP::on_Cmbx_Func_Code_currentIndexChanged(const QString &arg1)
{
    // Extract hex value from selected text
    QString selectedText = ui->Cmbx_Func_Code->currentText();
    QRegularExpression regex("\\(0x([0-9A-Fa-f]+)\\)");
    QRegularExpressionMatch match = regex.match(selectedText);

    uint8_t functionCode = 0;
    if (match.hasMatch()) {
        QString hexString = match.captured(1);  // e.g., "04"
        functionCode = hexString.toUInt(nullptr, 16);  // convert hex to int
    }
    bool valVisible =  false;


    switch (functionCode)
    {
    case MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS:
    case MODBUS_FUNC_WRITE_SINGLE_REGISTER:
         valVisible =  true;
        break;

    default:
        break;
    }
    ClassBlocksOnNumber->setEditsEnabled(valVisible);
    Application.FunctionCode = functionCode;
    updateLE_numbers();
}

void SetUp_IP::on_le_registercount_textChanged(const QString &arg1)
{
 /*   uint8_t multiPlier = 1;
    if(Application.is32BitChecked)
    {
        multiPlier *= 2;
    }
    if(Application.FunctionCode == MODBUS_FUNC_WRITE_SINGLE_REGISTER)
    {
        if((arg1.toInt() > 1)||(arg1.toInt() == 0))
        {
            ui->le_registercount->setText(QString::number(1*multiPlier));
        }
    }
    else
    {
        int val = arg1.toInt() ;
        val *= multiPlier;
        ui->le_registercount->setText(QString::number(val));
    }
    */
    qDebug()<<"****1";
    if(Application.FunctionCode == MODBUS_FUNC_WRITE_SINGLE_REGISTER)
    {

        qDebug()<<"****2";
        if((arg1.toInt() > 1)||(arg1.toInt() == 0))
        {

            qDebug()<<"****3";
            ui->le_registercount->setText(QString::number(1));
        }
    }
    else
    {
        ui->le_registercount->setText(arg1);
    }

}
void SetUp_IP::updateLE_numbers()
{
    on_le_registercount_textChanged(ui->le_registercount->text());
}
