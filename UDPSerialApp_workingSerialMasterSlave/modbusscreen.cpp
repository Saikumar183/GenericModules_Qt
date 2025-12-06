#include "modbusscreen.h"
#include "ui_modbusscreen.h"

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
    ClassBlocksOnNumber = new BlocksOnNumber(this);
    ui->verticalLayout_3->addWidget(ClassBlocksOnNumber);
}
void ModbusScreen::Init_Hides(bool state)
{
    ui->frame_2->setVisible(!state);
}
void ModbusScreen::Init_Connects(void )
{

}

void ModbusScreen::Init_miscellaneous(void)
{
    scanTimer = new QTimer(this);
    connect(scanTimer,SIGNAL(timeout()),this,SLOT(ScanTimerFunction()));
    scanTimer->start(1);
     m_holdingRegs.resize(256);  // for example 0..255 addresses
    showLogDialog("**************Welcome**************");
    logUI.dialog->hide();
    on_Cmbx_Func_Code_currentIndexChanged("");

    ModbusScreenStartingAddress = ui->le_startaddress->text().toInt();
    ModbusScreenSlaveID = ui->le_slaveid->text().toInt();
    ModbusScreenRegQuantity = ui->le_registercount->text().toInt();

    on_checkBox_Master_clicked(true);
    on_checkBox_ModbusOverSerial_clicked(true);
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

    QVBoxLayout *layout = new QVBoxLayout(logUI.dialog);

    logUI.textEdit = new QTextEdit(logUI.dialog);
    logUI.textEdit->setReadOnly(true);
    layout->addWidget(logUI.textEdit);

    QHBoxLayout *Hlayout = new QHBoxLayout(logUI.dialog);

    logUI.checkBox = new QCheckBox("Log this data", logUI.dialog);
//    logUI.checkBox->setChecked(true);
    Hlayout->addWidget(logUI.checkBox);

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
                    PauseData->setText("PLAY");
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
        ignorePowerOn = true;
        logUI.textEdit->clear();
        return;
    }

    QString timestamp = QDateTime::currentDateTime()
                        .toString("yyyy-MM-dd HH:mm:ss.zzz");

    QString line = QString("[%1] %2").arg(timestamp, data);

    // Show on UI
    logUI.textEdit->append(line);

    // Write to file only if logging enabled
    if (logUI.loggingEnabled && logUI.logFile && logUI.logFile->isOpen()) {
        QTextStream out(logUI.logFile);
        out << line << "\n";
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
     ui->lb_RxPkts->setText("|Rx Packets: "+QString::number(Application.RxPackets));
     ui->lb_ErsPkts->setText("|Error Packets: "+QString::number(Application.ErrorPackets));

}

void ModbusScreen::UpdateRxDataBlink()
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
        QTimer::singleShot(50, this, [this]() {
            ui->label_Rx->setStyleSheet(""); // Restore theme style
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

        QTimer::singleShot(50, this, [this]() {
            ui->label_Tx->setStyleSheet(""); // Restore theme style
        });
        Application.TxPackets++;
        if(logUI.dialog->isVisible())
        {
            showLogDialog(QString::number(Application.TxPackets)+":"+ui->label_Tx->text());
        }
    }
}

void ModbusScreen::on_tbn_SendCmd_clicked()
{
    if(!isModbusMasterEnabled)
    {
        QMessageBox::warning(this, "Selection Error", "Applicable only on Master Selection." );
        return;
    }
    if((!isModbusOverSerial) && (!isModbusOverUDP))
    {
        QMessageBox::warning(this, "Selection Error", "Select 'data over serial / udp' to send." );
        return;
    }

    uint16_t *ptr;
    buildModbusRTUFrame(ModbusScreenSlaveID,ModbusScreenFunctionCode,ModbusScreenStartingAddress
                        ,ptr,ModbusScreenRegQuantity);

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
    emit sendSerialData(Application.TxData);
/*
    // ----- Time-out logic starts here -----

    // Fetch timeout & scan time from UI (adjust widget names)
    bool ok1 = false, ok2 = false;
    int timeoutMs = ui->le_timeOut->text().toInt(&ok1);
    int scanMs    = ui->le_scantime->text().toInt(&ok2);

    if (!ok1 || timeoutMs < 0) timeoutMs = 0;
    if (!ok2 || scanMs < 0)    scanMs = 0;

    // Total wait = timeout + scan time
    int totalWait = timeoutMs + scanMs;
    if (totalWait <= 0)
    {
        totalWait = 500; // default if user kept 0
    }

    // Reset RxFlag before waiting
//    Application.Modbusconnection_RxFlag = false;

    // Timer will check for response
    static QTimer *timer = nullptr;
    if (!timer)
    {
        timer = new QTimer(this);
        timer->setSingleShot(true);

        connect(timer, &QTimer::timeout, this, [=]()
        {

            if(m_rxBuffer.size() > 0)
            {
                handleModbusMasterResponse(m_rxBuffer);
                m_rxBuffer.clear();
            }
            // Timer expired -> Check if we got response
            if (!Application.Modbusconnection_RxFlag)
            {
                // ❌ No data received within wait time -> just wait (stop)
                Application.ErrorPackets++;
                return;
            }

            // ✔ Response came before time-out
            // Now check if scan is enabled
            if (ui->checkBox_autoSend->isChecked())
            {
                // Send same request again after scan time finishes
                QTimer::singleShot(scanMs, this, [=]() {
                    emit sendSerialData(Application.TxData);
                });
            }
        });
    }

    // Start waiting after sending
    timer->start(totalWait);
*/
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
        emit sendSerialData(frame);
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
    emit sendSerialData(frame);

    // ensureLogDialog()->appendBytes(frame, LogDialog::Tx);
}

void ModbusScreen::handleModbusRequest(const QByteArray &frame)
{
    Application.Modbusconnection_RxFlag = true;
    Application.RxData = m_rxBuffer;

    if (frame.size() < 4)
    {
        Application.UpdateStatusLabel("Less Bytes Recieved.",true);
        return;
    }

    uint8_t slaveId = static_cast<uint8_t>(frame[0]);
    uint8_t func    = static_cast<uint8_t>(frame[1]);

    if (!checkCRC(frame))
    {
        Application.UpdateStatusLabel("CRC Mismatch.",true);
        return;
    }
    // If you want slave address filtering:
    if (slaveId != ModbusScreenSlaveID && slaveId != 0) {

        Application.UpdateStatusLabel("Slave ID Mismatch.",true);
        // not for us (and not broadcast)
        return;
    }

    switch (func) {
    case MODBUS_FUNC_READ_HOLDING_REGISTERS:
    case MODBUS_FUNC_READ_INPUT_REGISTERS:
    {
        if (frame.size() < 8)
        {

            Application.UpdateStatusLabel("Data Size Mismatch.",true);
            return;
        }

        uint16_t addr  = (static_cast<uint8_t>(frame[2]) << 8)
                         | static_cast<uint8_t>(frame[3]);
        uint16_t count = (static_cast<uint8_t>(frame[4]) << 8)
                         | static_cast<uint8_t>(frame[5]);
//        qDebug()<<"addr "<<addr<<count<<m_holdingRegs.size();
        // Address range check
        if (addr + count > m_holdingRegs.size())
        {
            buildModbusRTUSlaveResponse(slaveId, func, addr,
                                        nullptr, 0,
                                        MODBUS_EX_ILLEGAL_DATA_ADDR);

            Application.UpdateStatusLabel("Address range exceeded.",true);
            return;
        }

        const uint16_t *p = reinterpret_cast<const uint16_t*>(&m_holdingRegs[addr]);
        buildModbusRTUSlaveResponse(slaveId, func, addr, p, count,
                                    MODBUS_EX_NONE);
        break;
    }

    case MODBUS_FUNC_WRITE_SINGLE_REGISTER:
    {
        if (frame.size() < 8)
        {

            Application.UpdateStatusLabel("Data Size Mismatch.",true);
            return;
        }

        uint16_t addr  = (static_cast<uint8_t>(frame[2]) << 8)
                         | static_cast<uint8_t>(frame[3]);
        uint16_t value = (static_cast<uint8_t>(frame[4]) << 8)
                         | static_cast<uint8_t>(frame[5]);

        if (addr >= m_holdingRegs.size()) {
            buildModbusRTUSlaveResponse(slaveId, func, addr,
                                        nullptr, 0,
                                        MODBUS_EX_ILLEGAL_DATA_ADDR);
            Application.UpdateStatusLabel("Address range exceeded.",true);
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

            Application.UpdateStatusLabel("Data Size Mismatch.",true);
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
        Application.UpdateStatusLabel("Address range exceeded.",true);
        return;
        }

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
        Application.UpdateStatusLabel("Master: Less bytes received.", true);
        return;
    }

    quint8 slaveId = static_cast<quint8>(frame[0]);
    quint8 func    = static_cast<quint8>(frame[1]);

    // CRC check
    if (!checkCRC(frame))
    {
        Application.UpdateStatusLabel("Master: CRC mismatch.", true);
        return;
    }

    // Slave ID check (ignore broadcast = 0 if you want)
    if (slaveId != ModbusScreenSlaveID && slaveId != 0)
    {
        Application.UpdateStatusLabel("Master: Unexpected slave ID.", true);
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
            Application.UpdateStatusLabel("Master: Data size mismatch.", true);
            return;
        }

        quint8 byteCount = static_cast<quint8>(frame[2]);
        if (frame.size() != (3 + byteCount + 2))   // slave+func+byteCount + data + CRC
        {
            Application.UpdateStatusLabel("Master: Length/byteCount mismatch.", true);
            return;
        }

        if (byteCount % 2 != 0)
        {
            Application.UpdateStatusLabel("Master: Odd byte count for registers.", true);
            return;
        }

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
                m_holdingRegs[startAddr + i] = regs[i];
        }

        // Option 2: also update your dynamic line-edit grid, if you have a function for it:
        // loadRegisters(regs.data(), regs.size());

        Application.UpdateStatusLabel("Master: Read registers OK.", false);
        break;
    }

    // -------------------- WRITE SINGLE REGISTER (0x06) --------------------
    case MODBUS_FUNC_WRITE_SINGLE_REGISTER:
    {
        if (frame.size() != 8)
        {
            Application.UpdateStatusLabel("Master: Write single response size mismatch.", true);
            return;
        }

        quint16 addr  = (static_cast<quint8>(frame[2]) << 8)
                        | static_cast<quint8>(frame[3]);
        quint16 value = (static_cast<quint8>(frame[4]) << 8)
                        | static_cast<quint8>(frame[5]);

        // Optional: verify it matches what we sent
        // (ModbusScreenStartingAddress, last written value...)
        if (addr >= m_holdingRegs.size())
        {
            Application.UpdateStatusLabel("Master: Echo address out of range.", true);
        }
        else
        {
            m_holdingRegs[addr] = value;
            Application.UpdateStatusLabel("Master: Write single OK.", false);
        }
        break;
    }

    // -------------------- WRITE MULTIPLE REGISTERS (0x10) --------------------
    case MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS:
    {
        if (frame.size() != 8)
        {
            Application.UpdateStatusLabel("Master: Write multiple response size mismatch.", true);
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
            Application.UpdateStatusLabel("Master: Write multiple echo mismatch.", true);
            return;
        }

        Application.UpdateStatusLabel("Master: Write multiple OK.", false);
        break;
    }

    // -------------------- READ COILS / INPUTS (0x01 / 0x02) (optional decode) --------------------
    case MODBUS_FUNC_READ_COILS:
    case MODBUS_FUNC_READ_DISCRETE_INPUTS:
    {
        if (frame.size() < 5)
        {
            Application.UpdateStatusLabel("Master: Coils size mismatch.", true);
            return;
        }

        quint8 byteCount = static_cast<quint8>(frame[2]);
        if (frame.size() != (3 + byteCount + 2))
        {
            Application.UpdateStatusLabel("Master: Coils length/byteCount mismatch.", true);
            return;
        }

        // You can decode bits into a QVector<bool> if needed:
        // quint16 coilCount = ModbusScreenRegQuantity;  // from last request
        // QVector<bool> coils;
        // ...
        Application.UpdateStatusLabel("Master: Read coils OK.", false);
        break;
    }

    // -------------------- EXCEPTION RESPONSE (func | 0x80) --------------------
    default:
    {
        if (func & 0x80)
        {
            if (frame.size() < 5)
            {
                Application.UpdateStatusLabel("Master: Short exception frame.", true);
                return;
            }

            quint8 originalFunc  = func & 0x7F;
            quint8 exceptionCode = static_cast<quint8>(frame[2]);

            QString msg = QString("Master: Exception from slave. Func %1, Code %2")
                          .arg(originalFunc)
                          .arg(exceptionCode);

            Application.UpdateStatusLabel(msg, true);
            Application.ErrorPackets++;
        }
        else
        {
            Application.UpdateStatusLabel("Master: Unsupported function in response.", true);
        }
        break;
    }
    }
}

void ModbusScreen::ScanTimerFunction()
{

    static bool waitForRxFlag = true;
    if((isModbusAutoSendEnabled)&&(isModbusMasterEnabled)&&
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
                on_tbn_SendCmd_clicked();
                waitForRxFlag = true;
            }
        }

        if((waitForRxFlag) && (Application.Modbusconnection_RxFlag))
        {
            waitForRxFlag = false;
            cntr = 0;
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
            }
        }

    }
    UpdateTxDataBlink();
    UpdateRxDataBlink();
    UpdatePackeCounts();
}

void ModbusScreen::on_Cmbx_Func_Code_currentIndexChanged(const QString &arg1)
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
    ModbusScreenFunctionCode = Application.FunctionCode;
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
void ModbusScreen::onSerialDataReceived(QSerialPort *serialPort)
{
    m_rxBuffer.clear();
    m_rxBuffer = serialPort->readAll();
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
    if(ui->checkBox_Slave->isChecked())
    {
        ui->checkBox_Slave->setChecked(false);
        isModbusSlaveEnabled = false;
    }
     isModbusMasterEnabled = checked;
     ui->checkBox_Master->setChecked(isModbusMasterEnabled);
}

void ModbusScreen::on_checkBox_Slave_clicked(bool checked)
{
    if(ui->checkBox_Master->isChecked())
    {
        ui->checkBox_Master->setChecked(false);
        isModbusMasterEnabled = false;
    }
     isModbusSlaveEnabled = checked;
     ui->checkBox_Slave->setChecked(isModbusSlaveEnabled);
}

void ModbusScreen::on_checkBox_autoSend_clicked(bool checked)
{
    if(checked)
    {
        on_tbn_SendCmd_clicked();
    }
    isModbusAutoSendEnabled = checked;

    ui->checkBox_autoSend->setChecked(isModbusAutoSendEnabled);
}
