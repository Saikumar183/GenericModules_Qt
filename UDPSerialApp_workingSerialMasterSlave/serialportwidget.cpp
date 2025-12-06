#include "serialportwidget.h"

SerialPortWidget::SerialPortWidget(QWidget *parent) : QWidget(parent),
    serialPort(new QSerialPort(this))
{
    // UI Components
    comboBoxPorts = new QComboBox(this);
    comboBoxBaudRate = new QComboBox(this);
//    comboBoxBaudRate->addItem("1000000", QSerialPort::Baud1000000);
    comboBoxBaudRate->addItem("115200", QSerialPort::Baud115200);
    comboBoxBaudRate->addItem("9600", QSerialPort::Baud9600);
    comboBoxBaudRate->addItem("19200", QSerialPort::Baud19200);
    comboBoxBaudRate->addItem("38400", QSerialPort::Baud38400);
    comboBoxBaudRate->addItem("57600", QSerialPort::Baud57600);

    comboBoxParity = new QComboBox(this);
    comboBoxParity->addItems({"NONE", "EVEN", "ODD"});

    comboBoxStopBits = new QComboBox(this);
    comboBoxStopBits->addItems({"1", "1.5", "2"});

    pushButtonOpen = new QPushButton("OPEN PORT", this);
    pushButtonSend = new QPushButton("SEND DATA", this);
    pushButtonAutoSend = new QPushButton("AUTO SEND DATA", this);
    pushButtonAutoSend->setCheckable(true);
    textEditData = new QTextEdit(this);
    textEditData->setPlaceholderText("Select the data type below and Type Here to send data. To send 'n' number of bytes , use ',' delimitor in between bytes.");
    textEditData->setMinimumHeight(80);
    rxdata = new QLabel(this);
    rxdata->setWordWrap(true);

    pushButtonNumber = new QPushButton("NUMBER", this);
    pushButtonString = new QPushButton("STRING", this);
    pushButtonCRC = new QPushButton("CRC", this);
    pushButtonRefresh = new QPushButton("REFRESH PORTS", this);
    pushButtonExit = new QPushButton("EXIT", this);  // <--- New Exit button

    pushButtonNumber->setCheckable(true);
    pushButtonString->setCheckable(true);
    pushButtonCRC->setCheckable(true);

   // Create a form layout
    QFormLayout *formLayout = new QFormLayout;

    // Label + ComboBox: PORT
    QLabel *labelPort = new QLabel("PORT:", this);
    formLayout->addRow(labelPort, comboBoxPorts);

    // Label + ComboBox: BAUD RATE
    QLabel *labelBaud = new QLabel("BAUD RATE:  ", this);
    formLayout->addRow(labelBaud, comboBoxBaudRate);

    // Label + ComboBox: PARITY
    QLabel *labelParity = new QLabel("PARITY:", this);
    formLayout->addRow(labelParity, comboBoxParity);

    // Label + ComboBox: STOP BITS
    QLabel *labelStopBits = new QLabel("STOP BITS:", this);
    formLayout->addRow(labelStopBits, comboBoxStopBits);


    // Add to main layout
    QVBoxLayout *mainLayout = new QVBoxLayout;


    mainLayout->addLayout(formLayout);

    // Rest of the UI
    mainLayout->addWidget(pushButtonOpen);
    mainLayout->addWidget(textEditData);
    mainLayout->addWidget(rxdata);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(pushButtonNumber);
    buttonLayout->addWidget(pushButtonString);
    buttonLayout->addWidget(pushButtonCRC);
    mainLayout->addLayout(buttonLayout);

    //     New row: Refresh and Exit side by side
    QHBoxLayout *bottomButtonLayout = new QHBoxLayout;
    bottomButtonLayout->addWidget(pushButtonRefresh);
    bottomButtonLayout->addWidget(pushButtonExit);
    mainLayout->addLayout(bottomButtonLayout);

     QHBoxLayout *SendButtonsLayout = new QHBoxLayout;
     SendButtonsLayout->addWidget(pushButtonAutoSend);
     SendButtonsLayout->addWidget(pushButtonSend);
     mainLayout->addLayout(SendButtonsLayout);

    setLayout(mainLayout);
    // Signal-Slot connections
    connect(pushButtonOpen, &QPushButton::clicked, this, &SerialPortWidget::onOpenPortClicked);
    connect(pushButtonSend, &QPushButton::clicked, this, &SerialPortWidget::onSendDataClicked);
    connect(pushButtonAutoSend, &QPushButton::clicked, this, &SerialPortWidget::startSendingCommands);
    connect(pushButtonNumber, &QPushButton::clicked, this, &SerialPortWidget::onNumberButtonClicked);
    connect(pushButtonString, &QPushButton::clicked, this, &SerialPortWidget::onStringButtonClicked);
    connect(pushButtonCRC, &QPushButton::clicked, this, &SerialPortWidget::onCRCButtonClicked);
    connect(pushButtonRefresh, SIGNAL(clicked(bool)), this, SLOT(updatePortList()));
    connect(comboBoxBaudRate, SIGNAL(currentIndexChanged(int)), this, SLOT(onBaudRateSelectionChanged(int)));
    connect(this, SIGNAL(commerror(QString)), this, SLOT(showcomstatus(const QString)));
    connect(serialPort, SIGNAL(errorOccurred(QSerialPort::SerialPortError)), this, SLOT(showErrorOccurred(QSerialPort::SerialPortError)));
    connect(serialPort, SIGNAL(readyRead()), this, SLOT(readSerialPortSettingsAndData()));
      // Exit button slot
    connect(pushButtonExit, &QPushButton::clicked, this, &SerialPortWidget::onReopenButtonClicked);  // <--- Connect exit button

    updatePortList();
    Init_hide();
    pushButtonNumber->setChecked(true);
    onNumberButtonClicked();
    //    pushButtonExit->setEnabled(false);
}

void SerialPortWidget::startSendingCommands()
{

}

SerialPortWidget::~SerialPortWidget()
{
    delete serialPort;
}

void SerialPortWidget::updateSendDataField(QString Data)
{
    textEditData->setText(Data);
    //    KeyBoard->hide();
}

void SerialPortWidget::readSerialPortSettingsAndData()
{
    // Check if the serial port is open
    if (!serialPort->isOpen()) {
        emit commerror("Serial port is not open.");
        return;
    }

    if(Application.isModbusSerialEnabled)
    {
        emit onSerialDataReceived(serialPort);
    }
    else
    {
        // Read available data from the serial port
        if (serialPort->bytesAvailable() > 0)
        {
            QByteArray data = serialPort->readAll();  // Read all available data
            //        qDebug() << "Received Data: "<<data;

            // If you want to handle the received data further (e.g., convert it to string or process it)
            SerialRxData = hexToString(data);  // Convert the received data from hex to string
        } else {
            SerialRxData = "";
            //                qDebug() << "No data available to read.";
        }
        showdata(SerialRxData);  // Emit signal with the received data
    }
}

QSerialPort* SerialPortWidget::getSerialPortAddress()
{
    return serialPort;
}

void SerialPortWidget::sendSerialData(QByteArray sendData)
{
    if(serialPort->isOpen())
    {
        serialPort->write(sendData);
    }
    else
    {
        QMessageBox::critical(this, "Serial Port Error",
                                 "Open Serial Port to send.");
    }
}
bool SerialPortWidget::isSerialOpen()
{
    return serialPort->isOpen();
}
void SerialPortWidget::updatePortList()
{
    comboBoxPorts->clear();
    QList<QString> ports;
    foreach (const QSerialPortInfo &port, QSerialPortInfo::availablePorts())
    {
        ports.append(port.portName() +" - "+ port.description());
    }
    comboBoxPorts->addItems(ports);
}

void SerialPortWidget::onOpenPortClicked()
{
    QString Pname = comboBoxPorts->currentText();
    QString portName ;
    // Check if the port name contains "COM"
    if (Pname.contains("COM")) {
        // Find the index of the hyphen (" - ")
        int hyphenIndex = Pname.indexOf(" - ");

        // Extract the substring before the hyphen, which is the port name (e.g., COM7)
        portName = Pname.left(hyphenIndex);

        //        qDebug() << "Port Name:" << portName;  // Output: COM7
    }

    serialPort->setPortName(portName);

    // Set baud rate
    int baudRate = comboBoxBaudRate->currentText().toInt();
    serialPort->setBaudRate(baudRate);

    // Set parity
    QString parityText = comboBoxParity->currentText();
    if (parityText == "None")
        serialPort->setParity(QSerialPort::NoParity);
    else if (parityText == "Even")
        serialPort->setParity(QSerialPort::EvenParity);
    else if (parityText == "Odd")
        serialPort->setParity(QSerialPort::OddParity);

    // Set stop bits
    double stopBits = comboBoxStopBits->currentText().toDouble();
    if (stopBits == 1)
        serialPort->setStopBits(QSerialPort::OneStop);
    else if (stopBits == 1.5)
        serialPort->setStopBits(QSerialPort::OneAndHalfStop);
    else if (stopBits == 2)
        serialPort->setStopBits(QSerialPort::TwoStop);

    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    // Open the port
    if (serialPort->open(QIODevice::ReadWrite))
    {

        pushButtonOpen->setText("CLOSE PORT");
        pushButtonOpen->setStyleSheet(
            QString("background-color: %1; color: white; border-radius: 5px;")
            .arg(Application.getBlinkColor(Application.currentTheme).name())
        );
        rxdata->setText("Com port is open: " + portName);

        if(Application.ModbusURATCONN_Flag)
        {
            Application.Modbusconnection_Flag = true;
        }
        else
        {
            Application.Modbusconnection_Flag = false;
        }
    } else {
        serialPort->close();
        pushButtonOpen->setText("OPEN PORT");
        pushButtonOpen->setStyleSheet("");
        emit commerror("Comm Port Closed: " + Pname);
        if(Application.ModbusURATCONN_Flag)
        {
            Application.Modbusconnection_Flag = false;
        }
    }
}

void SerialPortWidget::onBaudRateSelectionChanged(int index)
{
    if (comboBoxBaudRate->itemData(index).toInt() == -1) {
        comboBoxBaudRate->setEditable(true);  // Allow editing when "Custom" is selected
    } else {
        comboBoxBaudRate->setEditable(false); // Disable editing for predefined baud rates
    }
}

void SerialPortWidget::onNumberButtonClicked()
{
    // Disable the other buttons when one is selected
    if (pushButtonNumber->isChecked())
    {
        pushButtonNumber->setStyleSheet(
            QString("background-color: %1; color: white; border-radius: 5px;")
            .arg(Application.getBlinkColor(Application.currentTheme).name())
        );
        pushButtonString->setChecked(false);
        onStringButtonClicked();
        //        KeyBoard->show();
        //        pushButtonCRC->setChecked(false);
        showdata(SerialRxData);

    }
    else
    {
        pushButtonNumber->setStyleSheet("");
        //        KeyBoard->hide();
    }

    pushButtonNumber->setChecked(pushButtonNumber->isChecked());
}

void SerialPortWidget::onStringButtonClicked()
{
    // Disable the other buttons when one is selected
    if (pushButtonString->isChecked())
    {
        pushButtonNumber->setChecked(false);
        onNumberButtonClicked();
        pushButtonString->setStyleSheet(
            QString("background-color: %1; color: white; border-radius: 5px;")
            .arg(Application.getBlinkColor(Application.currentTheme).name())
        );

        //        KeyBoard->show();
        //        pushButtonCRC->setChecked(false);
        showdata(SerialRxData);
    }
    else
    {
        pushButtonString->setStyleSheet("");
        //        KeyBoard->hide();
    }

    pushButtonString->setChecked(pushButtonString->isChecked());
}

void SerialPortWidget::onCRCButtonClicked()
{
       // Disable the other buttons when CRC is selected
    if (pushButtonCRC->isChecked())
    {

        pushButtonCRC->setStyleSheet(
            QString("background-color: %1; color: white; border-radius: 5px;")
            .arg(Application.getBlinkColor(Application.currentTheme).name())
        );

        pushButtonNumber->setChecked(false);
        pushButtonString->setChecked(false);
        onNumberButtonClicked();
        onStringButtonClicked();

    }
    else
    {
        pushButtonCRC->setStyleSheet("");
    }
    pushButtonCRC->setChecked(pushButtonCRC->isChecked());
}

void SerialPortWidget::onSendDataClicked() {

    if(!serialPort->isOpen())
    {
        QMessageBox::warning(this, "Comm Port Error", "Serial Port is not opened yet..." );
        return;
    }
    if((!pushButtonCRC->isChecked()) &&(!pushButtonNumber->isChecked()) &&(!pushButtonString->isChecked()))
    {
        QMessageBox::warning(this, "Selection Error", "Select data type to Send." );
        return;
    }
    if((pushButtonCRC->isChecked()) &&((!pushButtonNumber->isChecked()) && (!pushButtonString->isChecked())))
    {
        QMessageBox::warning(this, "Selection Error", "Select data type to Send." );
        return;
    }

    QString data = textEditData->toPlainText();  // Get input from text edit

    if (!data.isEmpty() && serialPort->isOpen())  // Check if input data is not empty and serial port is open
    {
        QByteArray sendData;  // QByteArray to hold the data to be sent
        QString delimiter = ",";  // The delimiter to be used between bytes

        // Split the input data by comma to get each byte
        QStringList dataList = data.split(delimiter, QString::SkipEmptyParts);

        // Check if the "Number" button is selected
        if (pushButtonNumber->isChecked()) {
            // Iterate over the list of bytes (numbers in string format)
            for (int i = 0; i < dataList.size(); ++i) {
                bool ok;
                int byteValue = dataList[i].trimmed().toInt(&ok);  // Convert the string to integer

                if (ok) {
                    // Append the byte value to the sendData QByteArray
                    sendData.append(static_cast<char>(byteValue));  // Convert the int value to byte and append
                } else {
                    qWarning() << "Invalid byte value:" << dataList[i];
                    QMessageBox::warning(this, "Input Error", "Invalid byte value: " + dataList[i]);
                    return;  // Stop the process if invalid input is encountered
                }
            }
        }
        // Check if the "String" button is selected
        else if (pushButtonString->isChecked()) {
            // If String button is enabled, send data as string (UTF-8 encoding)
            sendData = data.toUtf8();
        }
        // Check if the "CRC" button is selected
        if (pushButtonCRC->isChecked())
        {
            QByteArray hexData = sendData;  // Use the existing data

            // Calculate CRC16 for the hexData
            uint16_t crc = calculateCRC16(hexData);

            // Convert CRC16 to QByteArray and append it to the hexData
            QByteArray crcData = QByteArray::fromRawData(reinterpret_cast<const char*>(&crc), sizeof(crc));
            hexData.append(crcData);

            // Final data to be sent (with CRC)
            sendData = hexData;
        }

        // Debugging output: display the data to be sent
//                qDebug() << "Data to Send:" << sendData;

        serialPort->write(sendData);
    }
    else
    {
        QMessageBox::warning(this, "Input Error", "Text field is empty. ");
    }
}


void SerialPortWidget::showdata(const QString data)
{
    //    qDebug() << "rx.."<<data;
    if (pushButtonNumber->isChecked())
    {
        rxdata->setText("Rx (Hex) : " + Application.byteArrayToHexString(data.toUtf8()));
    }
    else if (pushButtonString->isChecked())
    {
        // If it's a string, display it directly
        rxdata->setText("Rx : " + data);
    }
    else
    {
        if(data.isEmpty())
        {
            rxdata->setText("Rx : No data available to read.");
        }
    }
}

void SerialPortWidget::Init_hide()
{
    bool visible_state = false;
    textEditData->setVisible(!visible_state);
//    textEditData->setStyleSheet("");
    rxdata->setVisible(!visible_state);
//    rxdata->setStyleSheet("");
    pushButtonNumber->setVisible(!visible_state);
//    pushButtonNumber->setStyleSheet("");
    pushButtonString->setVisible(!visible_state);
//    pushButtonString->setStyleSheet("");
    pushButtonCRC->setVisible(!visible_state);
//    pushButtonCRC->setStyleSheet("");
    pushButtonRefresh->setVisible(!visible_state);
//    pushButtonRefresh->setStyleSheet("");
    pushButtonExit->setVisible(visible_state);
//    pushButtonExit->setStyleSheet("");
    pushButtonSend->setVisible(!visible_state);
//    pushButtonSend->setStyleSheet("");
    pushButtonOpen->setVisible(!visible_state);
//    pushButtonOpen->setStyleSheet("");
    pushButtonAutoSend->setVisible(visible_state);

}

void SerialPortWidget::showcomstatus(const QString info)
{
    QMessageBox::information(this,"ErrorInfo",info);
}

QString SerialPortWidget::hexToString(const QByteArray &hexData)
{
    QString result;

    // Iterate through the data byte by byte
    for (int i = 0; i < hexData.size(); ++i) {
        char byte = hexData.at(i);  // Get each byte

        // Check if the byte can be converted to a valid character
        result.append(byte);
    }

    return result;
}

// CRC-16 polynomial: 0x8005 (x^16 + x^15 + x^2 + 1)
unsigned short SerialPortWidget::calculateCRC16(const QByteArray &data)
{
    unsigned short crc = 0xFFFF;  // Initial value (can vary depending on the protocol)

    for (int i = 0; i < data.size(); i++) {
        crc ^= (unsigned char)data[i];  // XOR byte into the CRC

        for (int j = 8; j > 0; j--) {
            if (crc & 0x0001) {  // Check if the least significant bit is set
                crc = (crc >> 1) ^ 0xA001;  // Shift right and apply the polynomial
            } else {
                crc >>= 1;  // Just shift right if no polynomial is needed
            }
        }
    }

    return crc;  // Return the calculated CRC value
}

// Function to check if the checksum is valid
bool SerialPortWidget::isValidChecksum(const QByteArray &data)
{
    // Extract the received checksum (last 2 bytes in the data frame, for example)
    uint8_t CRC_low = (uint8_t)(data[data.size() - 2]);
    uint8_t CRC_high = (uint8_t)(data[data.size() - 1]);
    unsigned short receivedChecksum =0;
    receivedChecksum  = CRC_low;
    receivedChecksum = ((receivedChecksum) | CRC_high<<8);
    // Calculate the checksum for the data (excluding the last 2 bytes)
    ActualRxData = data.left(data.size() - CHECKSUM_SIZE);
    unsigned short calculatedChecksum = calculateCRC16(ActualRxData);

    //    qDebug() << "Calculated CRC: " <<dataWithoutChecksum<<data[data.size() - 1]<<data[data.size() - 2]<< QString::number(calculatedChecksum, 16).toUpper();
    //    qDebug() << "Received CRC: " <<CRC_high<<CRC_low<<receivedChecksum<< QString::number(receivedChecksum, 16).toUpper();

    return calculatedChecksum == receivedChecksum;
}

bool SerialPortWidget::WaitForAck(int timeoutms, int NOB)
{
    static QByteArray response;
    bool ackReceived_waiting = false;
    bool ackReceived = false;

    response.clear();

    QTimer* timer_ms = new QTimer(this);
    timer_ms->setSingleShot(true);

    connect(timer_ms, &QTimer::timeout, this, [&]() {
        if (!ackReceived_waiting) {
            ackReceived_waiting = true;
        }
    });

    timer_ms->start(timeoutms);

    while (!ackReceived_waiting) {
        if (serialPort->bytesAvailable() != 0) {
            response.append(serialPort->readAll());

            if (response.size() == NOB)
            {
                if (response.left(1).toHex() == "41")
                {
                    ackReceived = true;
                    break;
                }
            }
        }

        QCoreApplication::processEvents();
    }

    timer_ms->stop();

    return ackReceived;
}

void SerialPortWidget::InitCommPort()
{
    try {
        if (!serialPort->isOpen()) {
            serialPort->setPortName(serialPort->portName());
            serialPort->setBaudRate(QSerialPort::Baud115200);
            serialPort->setDataBits(QSerialPort::Data8);
            serialPort->setParity(QSerialPort::NoParity);
            serialPort->setStopBits(QSerialPort::OneStop);
            serialPort->setFlowControl(QSerialPort::NoFlowControl);

//            qDebug() << "== Initializing Serial Port ==";

            if (!serialPort->open(QIODevice::ReadWrite)) {
                QString errMsg = "Failed to open serial port: " + serialPort->portName();
                throw std::runtime_error(errMsg.toStdString());
            }

            rxdata->setText("Com port is open: " + serialPort->portName());
        }

        serialPort->clear();

    } catch (const std::exception& e) {
        QMessageBox::critical(nullptr, "System Error", QString("Serial Port Error: %1").arg(e.what()));
    }
}

void SerialPortWidget::showErrorOccurred(QSerialPort::SerialPortError)
{
    if (serialPort->error() == QSerialPort::ResourceError )
    {
        serialPort->close();
        pushButtonOpen->setText("OPEN PORT");
        rxdata->setText("Com port is closed: " + comboBoxPorts->currentText());
        emit commerror("Comm Port Closed: " + comboBoxPorts->currentText());
    }
}

bool SerialPortWidget::Send_Serial_Command(uint8_t CMD)
{
    QByteArray command;  // Command to be sent via serial port

    try {
        // Initialize communication port
        InitCommPort();

        // Determine the Serial Command and the number of bytes to send based on Axis and DataType
        // Append appropriate command for parameter data based on the axis
        command.append(static_cast<char>(CMD));
        // Clear the serial port buffer and send the command
        serialPort->clear();
        serialPort->write(command);  // Send the initial command
        //        qDebug()<<"----"<<command;
        gDataCollectionEnable = true;  // Enable data collection flag

        // Wait for acknowledgment (ACK) from the drive, with a timeout of 500ms
        if (WaitForAck(150, gNoOfByteToRecieve_ACK))
        {
            gDataCollectionEnable = false;  // Disable data collection flag after success
            return true;  // Successfully sent data
        } else {
            // Display an error message if no ACK is received within the timeout period
            QMessageBox::critical(nullptr, "Error", "No ACK From The Drive");
        }
    } catch (const std::exception& e) {
        // Catch and display any exceptions that occur during the process
        QMessageBox::critical(nullptr, "Error", QString("System Error: %1").arg(e.what()));
    }

    // Disable data collection flag if an error occurs
    gDataCollectionEnable = false;

    // Return false if the data transmission fails
    return false;
}

void SerialPortWidget::SendModbusFrame(QByteArray dataFrame, int expectedLength, quint8 functionCode, int timeoutMs)
{
    InitCommPort();

    QByteArray receivedData;
    bool timeoutOccurred = false;

    serialPort->clear();
    serialPort->write(dataFrame);
    serialPort->flush();

    QTimer timerdata;
    timerdata.setSingleShot(true);

    connect(&timerdata, &QTimer::timeout, this, [&]() {
        timeoutOccurred = true;
    });

    timerdata.start(timeoutMs);

    // Main loop to collect data until timeout or enough data received
    while (!timeoutOccurred && receivedData.size() <= expectedLength) {
        if (serialPort->bytesAvailable() > 0) {
            receivedData.append(serialPort->readAll());
        }
        QCoreApplication::processEvents(QEventLoop::AllEvents, 10);  // Let Qt process events
    }

    // One final read in case data arrived at the last moment
    if (serialPort->bytesAvailable() > 0) {
        receivedData.append(serialPort->readAll());
    }

    bool success = false;
    if (receivedData.size() >= expectedLength) {
        quint8 respFuncCode = static_cast<quint8>(receivedData[1]);
        success = (respFuncCode == functionCode);
        if (!success) {
            qWarning() << "Function code mismatch. Expected:" << functionCode << "Received:" << respFuncCode;
        }
    } else {
        qWarning() << "Timeout or incomplete Modbus response. Got:" << receivedData.size()
                   << "Expected:" << expectedLength;
    }

    if (!success) {
        Application.UpdateStatusLabel("Modbus UART: Failed to get complete valid response.", true);
    }

    emit ModbusFrameResponse(receivedData, success);
}

