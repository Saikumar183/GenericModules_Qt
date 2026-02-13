#include "modbusscreen.h"
#include "ui_modbusscreen.h"
#include <QScrollArea>
ModbusScreen::ModbusScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModbusScreen)
{
    ui->setupUi(this);

     Init_Screens( );
     Init_Hides(true );
     Init_Connects( );
     Init_miscellaneous( );
}

ModbusScreen::~ModbusScreen()
{
    delete ui;
}
void ModbusScreen::Init_Screens(void )
{

    m_regGrid = new EndianRegisterGridWidget(this);

    QScrollArea *scroll = new QScrollArea(ui->wg_EndianView);
    scroll->setWidget(m_regGrid);
    scroll->setWidgetResizable(true);

    QVBoxLayout *hostLayout = new QVBoxLayout(ui->wg_EndianView);
    hostLayout->addWidget(scroll);
    ui->wg_EndianView->setLayout(hostLayout);
    // Connect your endian dropdown to the grid class
    connect(ui->CmBx_byteFormate,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            m_regGrid,
            &EndianRegisterGridWidget::setEndianModeIndex);

    connect(ui->CmBx_dataFormat,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            m_regGrid,
            &EndianRegisterGridWidget::setDisplayFormatIndex);

}
void ModbusScreen::applyFullScreenSize()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect area = screen->availableGeometry();
    this->setGeometry(area);
    this->showMaximized();  // Optional: auto maximize
}
void ModbusScreen::Init_Hides(bool state)
{
    ui->frame_2->setVisible(!state);
}
void ModbusScreen::Init_Connects(void )
{
    connect(ui->le_registercount, &QLineEdit::textChanged,
            this, &ModbusScreen::onRegisterCountChanged);

}

void ModbusScreen::Init_miscellaneous(void)
{
    scanTimer = new QTimer(this);
    connect(scanTimer,SIGNAL(timeout()),this,SLOT(ScanTimerFunction()));
    scanTimer->start(1);
     m_holdingRegs.resize(256);  // for example 0..255 addresses
    showLogDialog("**************Welcome**************");
    appendLog("**************Welcome**************");

    logUI.dialog->hide();
    on_Cmbx_Func_Code_currentIndexChanged("");

    ModbusScreenStartingAddress = ui->le_startaddress->text().toInt();
    ModbusScreenSlaveID = ui->le_slaveid->text().toInt();
    ModbusScreenRegQuantity = ui->le_registercount->text().toInt();

    on_checkBox_Master_clicked(true);
    on_checkBox_ModbusOverSerial_clicked(true);
    Application.isMasterChecked = ui->checkBox_Master->isChecked();
    Application.isSlaveChecked = ui->checkBox_Slave->isChecked();
}

void ModbusScreen::showLogDialog(const QString &text)
{

    // If dialog already exists → just update and show
    if ((logUI.dialog) && (ui->tbn_ComWindow->isChecked())&&(!PauseDataFlag))
    {
        appendLog(text);
//        logUI.dialog->show();
        return;
    }

    if (logUI.dialog)
    {
        return;
    }
    logUI.dialog = new QDialog(this);
    logUI.dialog->setWindowTitle("Data Viewer");
//    logUI.dialog->setAttribute(Qt::WA_DeleteOnClose);
    logUI.dialog->setFont(QFont(logUI.dialog->fontInfo().family(),logUI.dialog->fontInfo().pixelSize()*1.5,QFont::Bold));
    QVBoxLayout *layout = new QVBoxLayout(logUI.dialog);

    logUI.textEdit = new QTextEdit(logUI.dialog);
    logUI.textEdit->setReadOnly(true);
//    logUI.textEdit->setFont(QFont(logUI.textEdit->fontInfo().family(),20,QFont::Bold));
    layout->addWidget(logUI.textEdit);

    QHBoxLayout *Hlayout = new QHBoxLayout(logUI.dialog);

    logUI.checkBox = new QCheckBox("Log this data", logUI.dialog);
    logUI.checkBox->setChecked(true);
    logUI.loggingEnabled = logUI.checkBox->isChecked();
    Hlayout->addWidget(logUI.checkBox);

    logUI.checkBox_EndianType = new QCheckBox("Enable Endian Type", logUI.dialog);
    logUI.checkBox_EndianType->setChecked(false);
    logUI.EndianTypeEnabled = logUI.checkBox_EndianType->isChecked();
    Hlayout->addWidget(logUI.checkBox_EndianType);

    logUI.FontSizeEdit = new QLineEdit(logUI.dialog);
    logUI.FontSizeEdit->setPlaceholderText("Set Font Size");
    logUI.FontSizeEdit->setHidden(true);
    QIntValidator *validator = new QIntValidator(0, 255, logUI.FontSizeEdit);
    logUI.FontSizeEdit->setValidator(validator);

    connect(logUI.FontSizeEdit,SIGNAL(textChanged(QString)),this,SLOT(SetComLineEditFontSize(QString)));
    Hlayout->addWidget(logUI.FontSizeEdit);

    QPushButton *clearData = new QPushButton("CLEAR",logUI.dialog);
    connect(clearData, &QPushButton::clicked,
            this, [=](){
                logUI.textEdit->clear();
            });
    Hlayout->addWidget(clearData);
    QPushButton *PauseData = new QPushButton("PAUSE",logUI.dialog);
    PauseData->setCheckable(true);
    connect(PauseData, &QPushButton::clicked,
            this, [=](bool checked){
        PauseDataFlag = checked;
                PauseData->setChecked(checked);
                if(checked)
                {
                    PauseData->setStyleSheet(
                        QString("background-color: %1; color: white; border-radius: 5px;")
                        .arg(Application.getBlinkColor(Application.currentTheme).name())
                    );
                    PauseData->setText("START");
                }
                else
                {
                    PauseData->setStyleSheet("");
                    PauseData->setText("PAUSE");
                }
            });

    Hlayout->addWidget(PauseData);

    // Create log file
    logUI.logFile = new QFile("DataLog.txt", this);
    logUI.logFile->open(QFile::Append | QFile::Text);

    connect(logUI.checkBox, &QCheckBox::toggled,
            this, [=](bool checked){
                logUI.loggingEnabled = checked;
            });

    QDialogButtonBox *box =
        new QDialogButtonBox(QDialogButtonBox::Close, logUI.dialog);

    connect(box, &QDialogButtonBox::rejected,
            logUI.dialog, &QDialog::hide);

    connect(box, &QDialogButtonBox::rejected,
            ui->tbn_ComWindow, &QPushButton::click);

    connect(logUI.dialog, &QDialog::rejected,
            logUI.dialog, &QDialog::hide);

    connect(logUI.dialog, &QDialog::rejected,
            ui->tbn_ComWindow, &QPushButton::click);

    Hlayout->addWidget(box);
    layout->addLayout(Hlayout);
    logUI.dialog->setLayout(layout);
    logUI.dialog->resize(500, 350);

//    logUI.dialog->show();
    // Log first data if any
    appendLog(text);
    PauseData->click();
}

void ModbusScreen::SetComLineEditFontSize(QString Font)
{
    qDebug()<<Font;
//    logUI.textEdit->setFont(QFont(logUI.textEdit->fontInfo().family(),Font.toInt(),QFont::Bold));
}
void ModbusScreen::CopySerialPor(QSerialPort *Serial)
{
    if(Serial)
    {
        SerialPortCopy = Serial;
    }
}
void ModbusScreen::appendLog(const QString &data)
{
    if (!logUI.textEdit)
        return;
    static bool ignorePowerOn = false;
    if(!ignorePowerOn)
    {
//        qDebug()<<"11..."<<data;
        ignorePowerOn = true;
        logUI.textEdit->clear();
        return;
    }
//qDebug()<<"10..."<<data;
    QString timestamp = QDateTime::currentDateTime()
                        .toString("yyyy-MM-dd HH:mm:ss.zzz");

    QString line = QString("[%1] %2").arg(timestamp, data);
//    QString line = QString("[%1]").arg(timestamp);

    // Show on UI
    logUI.textEdit->append(line);

    // Write to file only if logging enabled
    if (logUI.loggingEnabled && logUI.logFile && logUI.logFile->isOpen())
    {
        QTextStream out(logUI.logFile);
        out << line << "\n";
//        qDebug()<<"12..."<<data;
        logUI.logFile->flush();
    }
}
void ModbusScreen::on_tbn_ComWindow_clicked()
{
   /* logUI.dialog->show()*/;
//    showLogDialog("**************Welcome**************");
}

void ModbusScreen::on_tbn_ResetCounts_clicked()
{
     Application.TxPackets=0;
     Application.RxPackets=0;
     Application.ErrorPackets=0;
     UpdatePackeCounts();

}
int ModbusScreen::get_scanTime()
{
    if(ui->le_scantime->text().toInt() <= 0)
    {
        ui->le_scantime->setText(QString::number(10));
    }
    return ui->le_scantime->text().toInt();
}

void ModbusScreen::UpdatePackeCounts()
{
     ui->lb_TxPkts->setText("Tx Packets: "+QString::number(Application.TxPackets));
     ui->lb_RxPkts->setText("| Rx Packets: "+QString::number(Application.RxPackets));
     ui->lb_ErsPkts->setText("| Error Packets: "+QString::number(Application.ErrorPackets));

}
void ModbusScreen::UpdateErrorPacketsBlink()
{
    if(logUI.EndianTypeEnabled)
    {
        Application.ErrorData = convertEndian(Application.ErrorData,(EndianMode_et)ui->CmBx_byteFormate->currentIndex());

    }
    ui->label_Error->setText(
        "(" + QString::number(Application.ErrorData.size()) + " Bytes) Error: " + informationString+
        Application.ErrorData.toHex().toUpper()
    );

    if (Application.Modbusconnection_ErrorFlag)
    {
        // Get blink color based on current theme
        QColor blinkColor = Application.getBlinkColor(Application.currentTheme);

        ui->label_Error->setStyleSheet(
            QString("background-color: %1; color: white; border-radius: 5px;")
            .arg(blinkColor.name())
        );
        ui->lb_ErsPkts->setStyleSheet(ui->label_Error->styleSheet());

        // Reset flag so we only blink once per packet
        Application.Modbusconnection_ErrorFlag = false;

        // Blink OFF after 200 ms
        QTimer::singleShot(50, this, [this]() {
            ui->label_Error->setStyleSheet(""); // Restore theme style
            ui->lb_ErsPkts->setStyleSheet(ui->label_Error->styleSheet());
        });
        Application.ErrorPackets++;
        if(logUI.dialog->isVisible())
        {
            showLogDialog(QString::number(Application.ErrorPackets)+":"+ui->label_Error->text());

        }

//        Application.LogModbusData();
    }
}
void ModbusScreen::UpdateRxDataBlink()
{
    if(logUI.EndianTypeEnabled)
    {
        Application.RxData = convertEndian(Application.RxData,(EndianMode_et)ui->CmBx_byteFormate->currentIndex());
    }
    ui->label_Rx->setText(
        "(" + QString::number(Application.RxData.size()) + " Bytes) Rx(0x): " +
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
        ui->lb_RxPkts->setStyleSheet(ui->label_Rx->styleSheet());

        // Reset flag so we only blink once per packet
        Application.Modbusconnection_RxFlag = false;
        timeoutSendCmdFlag = false;

        // Blink OFF after 200 ms
        QTimer::singleShot(50, this, [this]() {
            ui->label_Rx->setStyleSheet(""); // Restore theme style
            ui->lb_RxPkts->setStyleSheet(ui->label_Rx->styleSheet());
        });
        Application.RxPackets++;
        if(logUI.dialog->isVisible())
        {
            showLogDialog(QString::number(Application.RxPackets)+":"+ui->label_Rx->text());
        }

//        Application.LogModbusData();
    }
}

void ModbusScreen::UpdateTxDataBlink()
{
    if(logUI.EndianTypeEnabled)
    {
        Application.TxData = convertEndian(Application.TxData,(EndianMode_et)ui->CmBx_byteFormate->currentIndex());
    }
    ui->label_Tx->setText(
        "(" + QString::number(Application.TxData.size()) + " Bytes) Tx(0x): " +
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

        ui->lb_TxPkts->setStyleSheet(ui->label_Tx->styleSheet());
        Application.Modbusconnection_TxFlag = false;

        QTimer::singleShot(50, this, [this]() {

            ui->label_Tx->setStyleSheet(""); // Restore theme style
            ui->lb_TxPkts->setStyleSheet(ui->label_Tx->styleSheet());
        });
        Application.TxPackets++;
        if(logUI.dialog->isVisible())
        {
            showLogDialog(QString::number(Application.TxPackets)+":"+ui->label_Tx->text());
        }
    }
}

void ModbusScreen::SendCmd()
{
    if(!isCommunicationActiveToSend())
    {
        return;
    }

    // Common things you already do...
    quint8  slaveId      = ModbusScreenSlaveID;
    quint8  functionCode = ModbusScreenFunctionCode;
    quint16 startAddress = ModbusScreenStartingAddress;
    quint16 regCount     = ModbusScreenRegQuantity;

    const uint16_t *ptr = nullptr;
    quint16 dataSize = 0;

    QVector<uint16_t> txValues;   // buffer to hold values from grid

    // ─────────────────────────────
    // WRITE functions: 0x06, 0x10
    // ─────────────────────────────
    if (functionCode == MODBUS_FUNC_WRITE_SINGLE_REGISTER ||
        functionCode == MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS)
    {
        if (!m_regGrid)
        {
            informationString = "Grid not ready.";
            UpdateLogString(informationString);
            return;
        }

        // 0x06 = only 1 register
        if (functionCode == MODBUS_FUNC_WRITE_SINGLE_REGISTER)
            regCount = 1;

        // Ensure we don't read more cells than grid has
        int cellsAvailable = m_regGrid->cellCount();
        if (cellsAvailable < regCount)
        {
            informationString = "Not enough values in grid.";
            UpdateLogString(informationString);
            return;
        }

        txValues.reserve(regCount);

        for (int i = 0; i < regCount; ++i)
        {
            quint16 value = 0;
            if (!m_regGrid->wordAt(i, value))
            {

                informationString = QString("Invalid value at register %1.").arg(i);
                UpdateLogString(informationString);
                return;
            }
            txValues.push_back(value);
        }

        ptr      = txValues.constData();
        dataSize = static_cast<quint16>(txValues.size());
    }
    else
    {
        // ─────────────────────────────
        // READ functions: 0x01, 0x02, 0x03, 0x04
        // No data payload needed
        // ─────────────────────────────
        ptr      = nullptr;
        dataSize = regCount;
    }

    // 🔹 Final call – now ptr points to real data for 0x06 / 0x10
    buildModbusRTUFrame(slaveId,
                        functionCode,
                        startAddress,
                        ptr,
                        dataSize);
}


void ModbusScreen::on_tbn_ComWindow_clicked(bool checked)
{
    ui->tbn_ComWindow->setChecked(checked);
    if(checked)
    {
        logUI.dialog->show();
        ui->tbn_ComWindow->setStyleSheet(
            QString("background-color: %1; color: white; border-radius: 5px;")
            .arg(Application.getBlinkColor(Application.currentTheme).name())
        );
    }
    else
    {
        logUI.dialog->hide();
        ui->tbn_ComWindow->setStyleSheet("" );
    }
}

void ModbusScreen::buildModbusRTUFrame(quint8 slaveId,
                                       quint8 functionCode,
                                       quint16 startAddress,
                                       const uint16_t *dataAddress,
                                       quint16 dataSize)
{
    QByteArray frame;
    Application.TxData.clear();
    Application.RxData.clear();

    const quint16 registerCount = dataSize;

    frame.append(static_cast<char>(slaveId));
    frame.append(static_cast<char>(functionCode));

    switch (functionCode) {
    case MODBUS_FUNC_READ_COILS:
    case MODBUS_FUNC_READ_DISCRETE_INPUTS:
    {
        quint16 coilCount = registerCount;
        quint8 byteCount = static_cast<quint8>((coilCount + 7) / 8);
        Application.expectedLength = 5 + byteCount;

        frame.append(static_cast<char>((startAddress >> 8) & 0xFF));
        frame.append(static_cast<char>(startAddress & 0xFF));
        frame.append(static_cast<char>((coilCount >> 8) & 0xFF));
        frame.append(static_cast<char>(coilCount & 0xFF));
        break;
    }

    case MODBUS_FUNC_READ_HOLDING_REGISTERS:
    case MODBUS_FUNC_READ_INPUT_REGISTERS:
    {
        Application.expectedLength = 5 + (registerCount * 2);

        frame.append(static_cast<char>((startAddress >> 8) & 0xFF));
        frame.append(static_cast<char>(startAddress & 0xFF));
        frame.append(static_cast<char>((registerCount >> 8) & 0xFF));
        frame.append(static_cast<char>(registerCount & 0xFF));
        break;
    }

    case MODBUS_FUNC_WRITE_SINGLE_REGISTER:
    {
        Application.expectedLength = 8;
        uint16_t value = dataAddress[0];

        frame.append(static_cast<char>((startAddress >> 8) & 0xFF));
        frame.append(static_cast<char>(startAddress & 0xFF));
        frame.append(static_cast<char>((value >> 8) & 0xFF));
        frame.append(static_cast<char>(value & 0xFF));
        break;
    }

    case MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS:
    {
        uint8_t byteCount = static_cast<uint8_t>(registerCount * 2);
        Application.expectedLength = 8;

        frame.append(static_cast<char>((startAddress >> 8) & 0xFF));
        frame.append(static_cast<char>(startAddress & 0xFF));
        frame.append(static_cast<char>((registerCount >> 8) & 0xFF));
        frame.append(static_cast<char>(registerCount & 0xFF));
        frame.append(static_cast<char>(byteCount));

        for (int i = 0; i < dataSize; ++i) {
            uint16_t value = dataAddress[i];
            frame.append(static_cast<char>((value >> 8) & 0xFF));  // Hi
            frame.append(static_cast<char>(value & 0xFF));         // Lo
        }
        break;
    }

    default:
        QMessageBox::warning(this, "Function Code Error",
                              "Unsupported function code: " + QString::number(functionCode));
        return;
    }

    // CRC
    uint16_t crc = calculateCRC16(frame);
    frame.append(static_cast<char>(crc & 0xFF));
    frame.append(static_cast<char>((crc >> 8) & 0xFF));

    Application.TxData = frame;
    Application.Modbusconnection_TxFlag = true;

    if((Application.isPortBindCompleted)&&(isModbusOverUDP))
    {
        sendUdpData(Application.TxData);
    }
    else if ((Application.isSerialPortOpen)&&(isModbusOverSerial))
    {
        sendSerialData(Application.TxData);
    }

}
void ModbusScreen::buildModbusRTUSlaveResponse(quint8 slaveId,
                                               quint8 functionCode,
                                               quint16 startAddress,
                                               const uint16_t *dataAddress,
                                               quint16 dataSize,
                                               ModbusException ex)
{
    QByteArray frame;

    if (ex != MODBUS_EX_NONE) {
        frame.append(static_cast<char>(slaveId));
        frame.append(static_cast<char>(functionCode | 0x80));  // error bit
        frame.append(static_cast<char>(ex));

        uint16_t crc = calculateCRC16(frame);
        frame.append(static_cast<char>(crc & 0xFF));
        frame.append(static_cast<char>((crc >> 8) & 0xFF));

        Application.TxData = frame;
        Application.Modbusconnection_TxFlag = true;
        if((Application.isPortBindCompleted)&&(isModbusOverUDP))
        {
            sendUdpData(Application.TxData);
        }
        else if ((Application.isSerialPortOpen)&&(isModbusOverSerial))
        {
            sendSerialData(Application.TxData);
        }
        // ensureLogDialog()->appendBytes(frame, LogDialog::Tx);
        return;
    }

    frame.append(static_cast<char>(slaveId));
    frame.append(static_cast<char>(functionCode));

    switch (functionCode) {
    case MODBUS_FUNC_READ_HOLDING_REGISTERS:
    case MODBUS_FUNC_READ_INPUT_REGISTERS:
    {
        uint8_t byteCount = static_cast<uint8_t>(dataSize * 2);
        frame.append(static_cast<char>(byteCount));

        for (int i = 0; i < dataSize; ++i) {
            uint16_t value = dataAddress[i];
            frame.append(static_cast<char>((value >> 8) & 0xFF));
            frame.append(static_cast<char>(value & 0xFF));
        }
        break;
    }

    case MODBUS_FUNC_WRITE_SINGLE_REGISTER:
    {
        uint16_t value = dataAddress[0];

        frame.append(static_cast<char>((startAddress >> 8) & 0xFF));
        frame.append(static_cast<char>(startAddress & 0xFF));
        frame.append(static_cast<char>((value >> 8) & 0xFF));
        frame.append(static_cast<char>(value & 0xFF));
        break;
    }

    case MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS:
    {
        frame.append(static_cast<char>((startAddress >> 8) & 0xFF));
        frame.append(static_cast<char>(startAddress & 0xFF));
        frame.append(static_cast<char>((dataSize >> 8) & 0xFF));
        frame.append(static_cast<char>(dataSize & 0xFF));
        break;
    }

    default:
        buildModbusRTUSlaveResponse(slaveId, functionCode, startAddress,
                                    dataAddress, dataSize,
                                    MODBUS_EX_ILLEGAL_FUNC);
        return;
    }

    uint16_t crc = calculateCRC16(frame);
    frame.append(static_cast<char>(crc & 0xFF));
    frame.append(static_cast<char>((crc >> 8) & 0xFF));

    Application.TxData = frame;
    Application.Modbusconnection_TxFlag = true;
    Application.UpdateStatusLabel("",false);
    if((Application.isPortBindCompleted)&&(isModbusOverUDP))
    {
        sendUdpData(Application.TxData);
    }
    else if ((Application.isSerialPortOpen)&&(isModbusOverSerial))
    {
        sendSerialData(Application.TxData);
    }
    else
    {
        Application.UpdateStatusLabel("Select 'data over serial / udp' to send.Check ports were opened or not.",false);
//        QMessageBox::warning(this, "Selection Error", "Select 'data over serial / udp' to send.Check ports were opened or not." );
    }
    // ensureLogDialog()->appendBytes(frame, LogDialog::Tx);
}

void ModbusScreen::handleModbusRequest(const QByteArray &frame)
{
    Application.Modbusconnection_RxFlag = true;
    Application.RxData = m_rxBuffer;
    if (frame.size() < 4)
    {

        informationString = "Slave response Less Bytes Recieved.";
        UpdateLogString(informationString);
         Application.Modbusconnection_ErrorFlag = true;
        return;
    }
//UpdateLogString("Slave response Rx------1.");
    uint8_t slaveId = static_cast<uint8_t>(frame[0]);
    uint8_t func    = static_cast<uint8_t>(frame[1]);

    if (!checkCRC(frame))
    {
        buildModbusRTUSlaveResponse(slaveId, func, 0,
                                    nullptr, 0,
                                    MODBUS_EX_CRC_MISMATCH);
        informationString = "Slave response CRC Mismatch.";
        UpdateLogString(informationString);
         Application.Modbusconnection_ErrorFlag = true;
        return;
    }

//    UpdateLogString("Slave response Rx------2.");
    // If you want slave address filtering:
    if (slaveId != ModbusScreenSlaveID && slaveId != 0) {

        informationString = "Slave ID Mismatch.";
        UpdateLogString(informationString);
         Application.Modbusconnection_ErrorFlag = true;
        // not for us (and not broadcast)
        return;
    }

//    UpdateLogString("Slave response Rx------3."+QString::number(func));
    switch (func) {
    case MODBUS_FUNC_READ_HOLDING_REGISTERS:
    case MODBUS_FUNC_READ_INPUT_REGISTERS:
    {
        if (frame.size() < 8)
        {
            informationString = "Slave response Data Size Mismatch.";
            UpdateLogString(informationString);
            return;
        }
//UpdateLogString("Slave response Rx------4."+QString::number(func));
        uint16_t addr  = (static_cast<uint8_t>(frame[2]) << 8)
                         | static_cast<uint8_t>(frame[3]);
        uint16_t count = (static_cast<uint8_t>(frame[4]) << 8)
                         | static_cast<uint8_t>(frame[5]);
//        qDebug()<<"addr "<<addr<<count<<m_holdingRegs.size();
        // Address range check
        int16_t startAddr = (addr - ui->le_startaddress->text().toInt());
        if((startAddr >= 0) && (ui->le_registercount->text().toInt() >= count))
        {
            //        // 🔹 Example: update some registers before responding
            if ((addr + count) >= (ui->le_startaddress->text().toInt() + m_holdingRegs.size()))
            {
                buildModbusRTUSlaveResponse(slaveId, func, addr,
                                            nullptr, 0,
                                            MODBUS_EX_ILLEGAL_DATA_ADDR);
                informationString = "Slave response Address range exceeded.";
                UpdateLogString(informationString);
                return;
            }

            for (int i = 0; i < count; ++i)
            {
                m_regGrid->wordAt(i, m_holdingRegs[startAddr + i]);
            }

            const uint16_t *p = reinterpret_cast<const uint16_t*>(&m_holdingRegs[startAddr]);
            buildModbusRTUSlaveResponse(slaveId, func, addr, p, count,
                                        MODBUS_EX_NONE);
        }
        else
        {
            buildModbusRTUSlaveResponse(slaveId, func, addr,
                                        nullptr, 0,
                                        MODBUS_EX_ILLEGAL_DATA_ADDR);
            informationString = "Slave response Address range exceeded.";
            UpdateLogString(informationString);
            return;
        }
        break;
    }

    case MODBUS_FUNC_WRITE_SINGLE_REGISTER:
    {
        if (frame.size() < 8)
        {
            informationString = "Slave response Data Size Mismatch.";
            UpdateLogString(informationString);
            return;
        }

        uint16_t addr  = (static_cast<uint8_t>(frame[2]) << 8)
                         | static_cast<uint8_t>(frame[3]);
        uint16_t value = (static_cast<uint8_t>(frame[4]) << 8)
                         | static_cast<uint8_t>(frame[5]);
        // 🔹 NEW: show that single register in the grid
            if (m_regGrid)
            {
                QByteArray dataBytes;
                dataBytes.append(static_cast<char>((value >> 8) & 0xFF));
                dataBytes.append(static_cast<char>( value       & 0xFF));
                m_regGrid->setData(dataBytes);
            }
        if (addr >= m_holdingRegs.size()) {
            buildModbusRTUSlaveResponse(slaveId, func, addr,
                                        nullptr, 0,
                                        MODBUS_EX_ILLEGAL_DATA_ADDR);
            informationString = "Slave response Address range exceeded.";
            UpdateLogString(informationString);
            return;
        }


        m_holdingRegs[addr] = value;

        uint16_t temp = value;
        buildModbusRTUSlaveResponse(slaveId, func, addr, &temp, 1,
                                    MODBUS_EX_NONE);
        break;
    }

    case MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS:
    {
        if (frame.size() < 9)
        {
            informationString = "Slave response Data Size Mismatch.";
            UpdateLogString(informationString);
            return;
        }

        uint16_t addr  = (static_cast<uint8_t>(frame[2]) << 8)
                         | static_cast<uint8_t>(frame[3]);
        uint16_t count = (static_cast<uint8_t>(frame[4]) << 8)
                         | static_cast<uint8_t>(frame[5]);
        uint8_t byteCount = static_cast<uint8_t>(frame[6]);

        if (byteCount != count * 2 ||
            frame.size() < (7 + byteCount + 2))  // +2 for CRC
            return;

        if (addr + count > m_holdingRegs.size()) {
            buildModbusRTUSlaveResponse(slaveId, func, addr,
                                        nullptr, 0,
                                        MODBUS_EX_ILLEGAL_DATA_ADDR);

            informationString = "Slave response Address range exceeded.";
            UpdateLogString(informationString);
        return;
        }

        // 🔹 Data bytes from master (write values)
        QByteArray dataBytes = frame.mid(7, byteCount);

        // 🔹 Show in the grid
        if (m_regGrid)
            m_regGrid->setData(dataBytes);
        // Data starts at index 7
        for (int i = 0; i < count; ++i)
        {
            int index = 7 + i * 2;
            uint16_t value = (static_cast<uint8_t>(frame[index]) << 8)
                             | static_cast<uint8_t>(frame[index + 1]);
            m_holdingRegs[addr + i] = value;
        }

        buildModbusRTUSlaveResponse(slaveId, func, addr, nullptr, count,
                                    MODBUS_EX_NONE);
        break;
    }

    default:
        buildModbusRTUSlaveResponse(slaveId, func, 0,
                                    nullptr, 0,
                                    MODBUS_EX_ILLEGAL_FUNC);
        break;
    }
}
void ModbusScreen::handleModbusMasterResponse(const QByteArray &frame)
{
    Application.Modbusconnection_RxFlag = true;
    Application.RxData = m_rxBuffer;

    // Basic length sanity
    if (frame.size() < 5)  // slave + func + byteCount + CRC is minimum
    {
        informationString = "Master: Less bytes received.";
        UpdateLogString(informationString);
        return;
    }

    quint8 slaveId = static_cast<quint8>(frame[0]);
    quint8 func    = static_cast<quint8>(frame[1]);

    // CRC check
    if (!checkCRC(frame))
    {
        informationString = "Master: CRC mismatch.";
        UpdateLogString(informationString);
        buildModbusRTUSlaveResponse(slaveId, func, 0,
                                    nullptr, 0,
                                    MODBUS_EX_CRC_MISMATCH);
        return;
    }

    // Slave ID check (ignore broadcast = 0 if you want)
    if (slaveId != ModbusScreenSlaveID && slaveId != 0)
    {
        informationString = "Master: Unexpected slave ID.";
        UpdateLogString(informationString);
        return;
    }

    // At this point we have a valid response addressed to us

    switch (func)
    {
    // -------------------- READ REGISTERS (0x03 / 0x04) --------------------
    case MODBUS_FUNC_READ_HOLDING_REGISTERS:
    case MODBUS_FUNC_READ_INPUT_REGISTERS:
    {
        if (frame.size() < 5)
        {
            informationString = "Master: Data size mismatch.";
            UpdateLogString(informationString);
            return;
        }

        quint8 byteCount = static_cast<quint8>(frame[2]);
        if (frame.size() != (3 + byteCount + 2))   // slave+func+byteCount + data + CRC
        {
            informationString = "Master: Length/byteCount mismatch.";
            UpdateLogString(informationString);
            return;
        }

        if (byteCount % 2 != 0)
        {
            informationString = "Master: Odd byte count for registers.";
            UpdateLogString(informationString);

            return;
        }
        // 🔹 Data bytes from slave
        QByteArray dataBytes = frame.mid(3, byteCount);

        // 🔹 Show in the new grid (each cell = 2 bytes)
        if (m_regGrid)
            m_regGrid->setData(dataBytes);

        quint16 regCount = byteCount / 2;
        QVector<uint16_t> regs;
        regs.reserve(regCount);

        // Data starts at index 3
        for (int i = 0; i < regCount; ++i)
        {
            int index = 3 + i * 2;
            quint16 value = (static_cast<quint8>(frame[index])     << 8)
                            | static_cast<quint8>(frame[index + 1]);
            regs.push_back(value);
        }

        // Option 1: write into your holding register buffer using last requested address.
        quint16 startAddr = ModbusScreenStartingAddress;        // assumed member
        if (startAddr + regCount <= static_cast<quint16>(m_holdingRegs.size()))
        {
            for (int i = 0; i < regCount; ++i)
            {
                m_holdingRegs[startAddr + i] = regs[i];
//                qDebug()<<i<<m_holdingRegs[startAddr + i];
            }
        }

        // Option 2: also update your dynamic line-edit grid, if you have a function for it:
        // loadRegisters(regs.data(), regs.size());
        informationString = "Master: Read registers OK.";
        UpdateLogString(informationString);
        break;
    }

    // -------------------- WRITE SINGLE REGISTER (0x06) --------------------
    case MODBUS_FUNC_WRITE_SINGLE_REGISTER:
    {
        if (frame.size() != 8)
        {
            informationString ="Master: Write single response size mismatch.";
            UpdateLogString(informationString);
            return;
        }

        quint16 addr  = (static_cast<quint8>(frame[2]) << 8)
                        | static_cast<quint8>(frame[3]);
        quint16 value = (static_cast<quint8>(frame[4]) << 8)
                        | static_cast<quint8>(frame[5]);
        // Show the echoed written value in grid (2 bytes)
        if (m_regGrid)
        {
            QByteArray dataBytes;
            dataBytes.append(static_cast<char>((value >> 8) & 0xFF));
            dataBytes.append(static_cast<char>( value       & 0xFF));
            m_regGrid->setData(dataBytes);
        }

        // Optional: verify it matches what we sent
        // (ModbusScreenStartingAddress, last written value...)
        if (addr >= m_holdingRegs.size())
        {
            informationString ="Master: Echo address out of range.";
            UpdateLogString(informationString);

        }
        else
        {
            m_holdingRegs[addr] = value;
            informationString ="Master: Write single OK.";
            UpdateLogString(informationString);
        }
        break;
    }

    // -------------------- WRITE MULTIPLE REGISTERS (0x10) --------------------
    case MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS:
    {
        if (frame.size() != 8)
        {
            informationString ="Master: Write multiple response size mismatch.";
            UpdateLogString(informationString);
            return;
        }

        quint16 addr  = (static_cast<quint8>(frame[2]) << 8)
                        | static_cast<quint8>(frame[3]);
        quint16 count = (static_cast<quint8>(frame[4]) << 8)
                        | static_cast<quint8>(frame[5]);

        // Optional: check with last request
        if (addr != ModbusScreenStartingAddress ||
            count != ModbusScreenRegQuantity)
        {
            informationString ="Master: Write multiple echo mismatch.";
            UpdateLogString(informationString);
            return;
        }
        informationString ="Master: Write multiple OK.";
        UpdateLogString(informationString);
        break;
    }

    // -------------------- READ COILS / INPUTS (0x01 / 0x02) (optional decode) --------------------
    case MODBUS_FUNC_READ_COILS:
    case MODBUS_FUNC_READ_DISCRETE_INPUTS:
    {
        if (frame.size() < 5)
        {
            informationString ="Master: Coils size mismatch.";
            UpdateLogString(informationString);
            return;
        }

        quint8 byteCount = static_cast<quint8>(frame[2]);
        if (frame.size() != (3 + byteCount + 2))
        {
            informationString ="Master: Coils length/byteCount mismatch.";
            UpdateLogString(informationString);
            return;
        }

        // You can decode bits into a QVector<bool> if needed:
        // quint16 coilCount = ModbusScreenRegQuantity;  // from last request
        // QVector<bool> coils;
        // ...

        informationString ="Master: Read coils OK.";
        UpdateLogString(informationString);
        break;
    }

    // -------------------- EXCEPTION RESPONSE (func | 0x80) --------------------
    default:
    {
        if (func & 0x80)
        {
            if (frame.size() < 5)
            {
                informationString ="Master: Short exception frame.";
                UpdateLogString(informationString);
                return;
            }

            quint8 originalFunc  = func & 0x7F;
            quint8 exceptionCode = static_cast<quint8>(frame[2]);

            QString msg = QString("Master: Exception from slave. Func %1, Code %2")
                          .arg(originalFunc)
                          .arg(exceptionCode);

            UpdateLogString(msg);
             Application.Modbusconnection_ErrorFlag = true;

        }
        else
        {
            informationString ="Master: Unsupported function in response.";
            UpdateLogString(informationString);
        }
        break;
    }
    }
}

void ModbusScreen::ScanTimerFunction()
{

    static bool waitForRxFlag = true;
    if((timeoutSendCmdFlag ||isModbusAutoSendEnabled)&&(isModbusMasterEnabled)&&
            (Application.isSerialPortOpen || Application.isPortBindCompleted)
            &&((isModbusOverSerial) || (isModbusOverUDP)))
    {


        static int32_t cntr = 0;
        static int32_t waitTimeCntr = 0;
        int totalWaitTime = ui->le_scantime->text().toInt() + ui->le_timeOut->text().toInt();

        if((!waitForRxFlag))
        {
            if(cntr++ > ui->le_scantime->text().toInt())
            {
                cntr = 0;
                waitTimeCntr = 0;
                SendCmd();
                waitForRxFlag = true;
            }
        }

        if((waitForRxFlag) && (Application.Modbusconnection_RxFlag))
        {
            waitForRxFlag = false;
            cntr = 0;
            timeoutSendCmdFlag = false;

        }
        else if((waitForRxFlag) && (!Application.Modbusconnection_RxFlag))
        {
            if(waitTimeCntr++ > totalWaitTime)
            {
                QMessageBox::information(nullptr,"TimeOut Error",
                                         "No response from Slave after "+QString::number(totalWaitTime)+" ms");
                waitTimeCntr = 0;
                cntr = 0;
                waitForRxFlag = false;
                timeoutSendCmdFlag = false;
            }
        }

    }
    UpdateTxDataBlink();
    UpdateErrorPacketsBlink();
    UpdateRxDataBlink();
    UpdatePackeCounts();
}

void ModbusScreen::UpdateLogString(QString msg)
{
    static QString prevString,CurrentString;
    CurrentString = msg;
//     qDebug()<<"Text :"<<msg;
    if(CurrentString != prevString)
    {
//        showLogDialog(CurrentString);
        appendLog(CurrentString);
        prevString = CurrentString;
//        qDebug()<<prevString;
    }
}
QByteArray ModbusScreen::convertEndian(const QByteArray &input, EndianMode_et mode)
{
    QByteArray output = input;

    // Only operate on blocks of 4 bytes (Modbus 2 registers = 32-bit)
    for (int i = 0; i + 3 < output.size(); i += 4)
    {
        char A = output[i];
        char B = output[i+1];
        char C = output[i+2];
        char D = output[i+3];

        switch(mode)
        {
        case ABCD:
            // Normal, no change
            output[i]   = A;
            output[i+1] = B;
            output[i+2] = C;
            output[i+3] = D;
            break;

        case CDAB:
            // Word swap: C D A B
            output[i]   = C;
            output[i+1] = D;
            output[i+2] = A;
            output[i+3] = B;
            break;

        case BADC:
            // Byte swap inside each word: B A D C
            output[i]   = B;
            output[i+1] = A;
            output[i+2] = D;
            output[i+3] = C;
            break;

        case DCBA:
            // Full reverse: D C B A
            output[i]   = D;
            output[i+1] = C;
            output[i+2] = B;
            output[i+3] = A;
            break;
        }
    }

    return output;
}
void ModbusScreen::on_Cmbx_Func_Code_currentIndexChanged(const QString &arg1)
{
    // Existing code to extract function code
    QString selectedText = ui->Cmbx_Func_Code->currentText();
    QRegularExpression regex("\\(0x([0-9A-Fa-f]+)\\)");
    QRegularExpressionMatch match = regex.match(selectedText);

    uint8_t functionCode = 0;
    if (match.hasMatch()) {
        QString hexString = match.captured(1);  // e.g., "06"
        functionCode = hexString.toUInt(nullptr, 16);
    }

    Application.FunctionCode   = functionCode;
    ModbusScreenFunctionCode   = Application.FunctionCode;
#if 1
    // 🔹 NEW: configure the register grid based on function code
    if (!m_regGrid)
        return;

    // Clear old content behavior depending on function code
    if (functionCode == MODBUS_FUNC_WRITE_SINGLE_REGISTER)   // 0x06
    {
        // One register = 2 bytes, editable
        m_regGrid->setEditable(true);

        QByteArray dataBytes;
        dataBytes.append(char(0x00));   // hi byte
        dataBytes.append(char(0x00));   // lo byte

        m_regGrid->setData(dataBytes);

        // Optionally force register count to 1 in UI:
        if (ui->le_registercount)
            ui->le_registercount->setText("1");
    }
    else if (functionCode == MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS) // 0x10
    {
        // 🔹 instead of duplicating logic, just call the new slot:
        onRegisterCountChanged(ui->le_registercount->text());
        m_regGrid->setEditable(true);

//        // Create N registers (2 bytes each) from register count line edit
//        bool ok = false;
//        int regCount = ui->le_registercount->text().toInt(&ok);
//        if (!ok || regCount <= 0) regCount = 1;

//        QByteArray dataBytes(regCount * 2, char(0x00));  // all zeros initially
//        m_regGrid->setData(dataBytes);
    }
    else
    {
        // For read functions etc → just show data received, no editing
        m_regGrid->setEditable(false);
        // optionally clear or leave last response
        // m_regGrid->setData(QByteArray());
    }
#endif
}
void ModbusScreen::onRegisterCountChanged(const QString &text)
{
    // Only care when function code is WRITE_MULTIPLE_REGISTERS (0x10)
    if (ModbusScreenFunctionCode != MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS)
        return;

    if (!m_regGrid)
        return;

    bool ok = false;
    int regCount = text.toInt(&ok);
    if (!ok || regCount <= 0)
    {
        // No valid register count → clear grid
        m_regGrid->setData(QByteArray());
        return;
    }

    // Optional: limit max registers (Modbus spec: often 123 or 125)
//     int maxRegs = 125;
//     if (regCount > maxRegs) regCount = maxRegs;

    // Each register = 2 bytes
    QByteArray dataBytes(regCount * 2, char(0x00));

    m_regGrid->setEditable(true);     // write-multiple is user-editable
    m_regGrid->setData(dataBytes);    // will rebuild grid with N cells
}

bool ModbusScreen::checkCRC(const QByteArray &frame)
{
    if (frame.size() < 4)
        return false;

    QByteArray data = frame.left(frame.size() - 2);
    uint16_t calc = calculateCRC16(data);

    const int n = frame.size();
    uint8_t crcLo = static_cast<uint8_t>(frame[n - 2]);
    uint8_t crcHi = static_cast<uint8_t>(frame[n - 1]);
    uint16_t recv = static_cast<uint16_t>(crcLo | (crcHi << 8));

    return (calc == recv);
}

// Minimal expected request length for RTU master->slave
int ModbusScreen::expectedRequestLength(const QByteArray &buf)
{
    if (buf.count() < 2)
        return -1;

    uint8_t func = static_cast<uint8_t>(buf[1]);

    switch (func) {
    case MODBUS_FUNC_READ_COILS:
    case MODBUS_FUNC_READ_DISCRETE_INPUTS:
    case MODBUS_FUNC_READ_HOLDING_REGISTERS:
    case MODBUS_FUNC_READ_INPUT_REGISTERS:
    case MODBUS_FUNC_WRITE_SINGLE_REGISTER:
        // slave + func + addr(2) + count/value(2) + CRC(2)
        return 8;

    case MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS:
        // slave + func + addr(2) + count(2) + byteCount + data + CRC(2)
        if (buf.size() < 7)
            return -1; // need at least to read byteCount
        {
            uint8_t byteCount = static_cast<uint8_t>(buf[6]);
            return 9 + byteCount;
        }

    default:
        // unknown func -> can't know length, but min 4:
        return -1;
    }
}
void ModbusScreen::onSerialDataReceived(QByteArray serialPortData)
{
    m_rxBuffer.clear();
    m_rxBuffer = serialPortData;//serialPort->readAll();
    if (isModbusMasterEnabled)
    {
        handleModbusMasterResponse(m_rxBuffer);
    }
    else if((isModbusSlaveEnabled)&&(!Application.Modbusconnection_RxFlag))
    {
        handleModbusRequest(m_rxBuffer);   // your existing slave handler
    }
}
void ModbusScreen::ProcessUdpRxData(QByteArray UdpData)
{
    m_rxBuffer.clear();
    m_rxBuffer = UdpData;
    if (isModbusMasterEnabled)
    {
        handleModbusMasterResponse(m_rxBuffer);
    }
    else if(isModbusSlaveEnabled)
    {
        handleModbusRequest(m_rxBuffer);   // your existing slave handler
    }

}
// CRC-16 (Modbus) calculation
quint16 ModbusScreen:: calculateCRC16(const QByteArray &data)
{
    quint16 crc = 0xFFFF;
    for (char byte : data) {
        crc ^= static_cast<quint8>(byte);
        for (int i = 0; i < 8; ++i) {
            if (crc & 0x0001)
                crc = (crc >> 1) ^ 0xA001;
            else
                crc >>= 1;
        }
    }
    if(ui->checkBox_CRCSWAP->isChecked())
    {
        crc = (((crc & 0xFF)<<8) | ((crc & 0xFF00)>>8));
    }
    return crc;
}

void ModbusScreen::on_le_slaveid_textChanged(const QString &arg1)
{
    ModbusScreenSlaveID = arg1.toUShort();
}

void ModbusScreen::on_le_registercount_textChanged(const QString &arg1)
{
    ModbusScreenRegQuantity = arg1.toUShort();
}

void ModbusScreen::on_le_startaddress_textChanged(const QString &arg1)
{
    ModbusScreenStartingAddress = arg1.toUShort();
}

void ModbusScreen::on_checkBox_ModbusOverSerial_clicked(bool checked)
{
    if(ui->checkBox_ModbusOverUdp->isChecked())
    {
        ui->checkBox_ModbusOverUdp->setChecked(false);
        isModbusOverUDP = false;
        Application.isModbusUdpEnabled = isModbusOverUDP ;
    }
    isModbusOverSerial = checked;
    Application.isModbusSerialEnabled = isModbusOverSerial;

    ui->checkBox_ModbusOverSerial->setChecked(isModbusOverSerial);
}

void ModbusScreen::on_checkBox_ModbusOverUdp_clicked(bool checked)
{

    if(ui->checkBox_ModbusOverSerial->isChecked())
    {
        ui->checkBox_ModbusOverSerial->setChecked(false);
        isModbusOverSerial = false;
        Application.isModbusSerialEnabled = isModbusOverSerial ;
    }
    isModbusOverUDP = checked;
    Application.isModbusUdpEnabled = isModbusOverUDP ;
    ui->checkBox_ModbusOverUdp->setChecked(isModbusOverUDP);
}

void ModbusScreen::on_checkBox_Master_clicked(bool checked)
{
    // Block signals so changing slave checkbox won't trigger its slot
    ui->checkBox_Slave->blockSignals(true);
    ui->checkBox_Master->blockSignals(true);

    if (checked)
    {
        ui->checkBox_Slave->setChecked(false);
        isModbusSlaveEnabled = false;
    }

    isModbusMasterEnabled = checked;
    ui->checkBox_Master->setChecked(checked);

    // Re-enable signals
    ui->checkBox_Slave->blockSignals(false);
    ui->checkBox_Master->blockSignals(false);
    Application.isSlaveChecked = isModbusSlaveEnabled;
    Application.isMasterChecked = isModbusMasterEnabled;
}

void ModbusScreen::on_checkBox_Slave_clicked(bool checked)
{
    ui->checkBox_Slave->blockSignals(true);
    ui->checkBox_Master->blockSignals(true);

    if (checked)
    {
        ui->checkBox_Master->setChecked(false);
        isModbusMasterEnabled = false;
    }

    isModbusSlaveEnabled = checked;
    ui->checkBox_Slave->setChecked(checked);

    ui->checkBox_Slave->blockSignals(false);
    ui->checkBox_Master->blockSignals(false);

    Application.isSlaveChecked = isModbusSlaveEnabled;
    Application.isMasterChecked = isModbusMasterEnabled;
}


void ModbusScreen::on_checkBox_autoSend_clicked(bool checked)
{
    if(checked)
    {
        SendCmd();
    }
    isModbusAutoSendEnabled = checked;

    ui->checkBox_autoSend->setChecked(isModbusAutoSendEnabled);
}
bool ModbusScreen::isCommunicationActiveToSend()
{
    if(!isModbusMasterEnabled)
    {
        QMessageBox::warning(this, "Selection Error", "Applicable only on Master Selection." );
        return false;
    }
    if((!isModbusOverSerial) && (!isModbusOverUDP))
    {
        QMessageBox::warning(this, "Selection Error", "Select 'data over serial / udp' to send." );
        return false;

    }
    if((!Application.isSerialPortOpen) && (isModbusOverSerial))
    {
        QMessageBox::warning(this, "Selection Error", "Open Seria Port to send." );
        return false;
    }
    if((!Application.isPortBindCompleted) && (isModbusOverUDP))
    {
        QMessageBox::warning(this, "Selection Error", "Open udp Port to send." );
        return false;
    }
    //    if((!isModbusOverSerial) && (!isModbusOverUDP))
    //    if((isModbusOverSerial) && (!isModbusOverUDP))
    //    {
    //        QMessageBox::warning(this, "Selection Error", "Select 'data over serial / udp' to send." );
    //        return;
    //    }
    //    else if((!isModbusOverSerial) && (isModbusOverUDP))
    //    {
    //        QMessageBox::warning(this, "Selection Error", "Select 'data over serial / udp' to send." );
    //        return;
    //    }
    //    else
    //    {
    //        qDebug()<<"10...";
    //    }

    return true;
}
void ModbusScreen::on_tbn_SendCmd_clicked()
{
    if(!isCommunicationActiveToSend())
    {
        return;
    }
    static bool OntimeSendFlag = true;
    if(OntimeSendFlag)
    {
        OntimeSendFlag = false;
        SendCmd();
    }
    timeoutSendCmdFlag = true;
}

void ModbusScreen::on_checkBox_Frame_clicked(bool checked)
{
    ui->frame_2->setVisible(checked);
    applyFullScreenSize();
}
