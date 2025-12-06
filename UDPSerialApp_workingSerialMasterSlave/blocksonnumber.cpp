#include "blocksonnumber.h"
#include "ui_blocksonnumber.h"

BlocksOnNumber::BlocksOnNumber(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlocksOnNumber)
{
    ui->setupUi(this);

    QWidget *mainWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);

    // ─── Format Dropdown ───────────
    formatCombo = new QComboBox(this);
    formatCombo->addItems({"Hex", "Decimal", "Binary", "ASCII"});

    endianCombo = new QComboBox(this);
    endianCombo->addItems({"Little Endian", "Big Endian"});

    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(new QLabel("Format:"));
    topLayout->addWidget(formatCombo);
    topLayout->addSpacing(20);
    topLayout->addWidget(new QLabel("Endian:"));
    topLayout->addWidget(endianCombo);

    mainLayout->addLayout(topLayout);

    // ─── Scroll Area ──────────────
    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollWidget = new QWidget(scrollArea);
//    scrollWidget->setMinimumHeight(100);
//    scrollWidget->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
    scrollArea->setWidget(scrollWidget);

    grid = new QGridLayout(scrollWidget);
    scrollWidget->setLayout(grid);
    mainLayout->addWidget(scrollArea);

    // ─── Output Box ───────────────
    mainLayout->addWidget(new QLabel("Formatted Output:"));
    outputBox = new QPlainTextEdit(this);
//    outputBox->setMinimumHeight(100);
//    outputBox->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    outputBox->setReadOnly(true);
    outputBox->hide();
    mainLayout->addWidget(outputBox);


    ui->verticalLayout->addWidget(mainWidget);

    byteValidator = new QIntValidator(0, 65535, this);  // Range 0 – 0xFFFF
    //         setInputRange(0,255);
//    setEditsEnabled(false);
//    ui->lineEdit->setText(QString::number(20));
    formatCombo->setCurrentIndex(0);
    endianCombo->setCurrentIndex(1);
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(updateLineEdits(QString)));
    // Refresh output when dropdown changes
    connect(formatCombo, SIGNAL(currentIndexChanged(int)),this, SLOT(onFormatChanged(int)));
    connect(endianCombo, SIGNAL(currentIndexChanged(int)),this, SLOT(onEndianChanged(int)));
    connect(ui->applyFormatButton, &QPushButton::clicked,
            this, &BlocksOnNumber::convertEditsToSelectedFormat);
    ui->lineEdit->setVisible(false);

    connect(ui->checkBox,SIGNAL(clicked(bool)),outputBox,SLOT(setVisible(bool)));
//    uint16_t holdingRegs[6] = {1234, 1000, 15, 65535, 2564};
//    loadRegisters(holdingRegs, ui->lineEdit->text().toInt());
//    updateLineEdits(ui->lineEdit->text().toInt()); // Example initial number

    ui->applyFormatButton->setVisible(false);
//    ui->CmBx_byteFormate->setVisible(false);
}

BlocksOnNumber::~BlocksOnNumber()
{
    delete ui;
}
static uint16_t parseToUint16(const QString &txt)
{
    bool ok = false;

    // Try decimal
    uint16_t v = txt.toUShort(&ok, 10);
    if (ok) return v;

    // Try hex (with or without 0x)
    v = txt.toUShort(&ok, 16);
    if (ok) return v;

    // Try binary
    v = txt.toUShort(&ok, 2);
    if (ok) return v;

    // Fallback: treat as ASCII (take up to 2 chars)
    if (!txt.isEmpty()) {
        QChar c1 = txt.at(0);
        QChar c2 = (txt.size() > 1) ? txt.at(1) : QChar('\0');
        v = (static_cast<uint8_t>(c1.unicode()) << 8) |
             static_cast<uint8_t>(c2.unicode());
        return v;
    }

    return 0;
}

void BlocksOnNumber::updateRegisterCountLineEdit(QString maxData)
{

    ui->lineEdit->setText(maxData);
    updateLineEdits(ui->lineEdit->text().toInt());
}

void BlocksOnNumber::updateLineEdits(QString maxData)
{
    updateLineEdits(maxData.toInt());
}
void BlocksOnNumber::updateLineEdits(int count)
{
    for (auto *edit : lineEdits)
        delete edit;
    lineEdits.clear();
    Application.lineEditsData.clear();

    uint8_t multiPlier = 1;
    if(Application.is32BitChecked)
    {
        multiPlier *= 2;
    }
    if(Application.FunctionCode == MODBUS_FUNC_WRITE_SINGLE_REGISTER)
    {
        if((count > 1)||(count == 0))
        {
            ui->lineEdit->setText(QString::number(1*multiPlier));
        }
    }
    else
    {
        int val = count ;
        val *= multiPlier;
        ui->lineEdit->setText(QString::number(val));
    }

    const int columns = 6;
    grid->setSpacing(10);

    for (int i = 0; i < count; i++) {
        QLineEdit *edit = new QLineEdit(scrollWidget);
        edit->setValidator(byteValidator);
        int byteStart = i * 2 + 1;
        int byteEnd   = byteStart + 1;

        edit->setPlaceholderText(
                    QString("Byte %1-%2").arg(byteStart).arg(byteEnd)
                    );
        edit->setText(QString::number(0,16).toUpper());
        if((Application.FunctionCode == MODBUS_FUNC_WRITE_SINGLE_REGISTER)
                || (Application.FunctionCode == MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS))
        {
            qDebug()<<"enable"<<Application.FunctionCode;
            edit->setEnabled(true);
        }
        else
        {
            qDebug()<<"disble"<<Application.FunctionCode;
            edit->setDisabled(true);  // Same effect, but visually clear
        }

        lineEdits.push_back(edit);

        int row = i / columns;
        int col = i % columns;
        grid->addWidget(edit, row, col);

        connect(edit, &QLineEdit::textChanged,
                this, &BlocksOnNumber::refreshFormattedData);
    }

    scrollWidget->adjustSize();
    refreshFormattedData();
}

void BlocksOnNumber::onFormatChanged(int)
{
    refreshFormattedData();
}

void BlocksOnNumber::onEndianChanged(int)
{
    refreshFormattedData();
}

static uint16_t parseRegister(const QString &txt)
{
    bool ok;
    uint16_t val = txt.toUShort(&ok, 0);  // auto-detect base: dec, hex(0x..)
    if (!ok)
        return 0;
    return val;
}

void BlocksOnNumber::refreshFormattedData()
{
    std::vector<uint16_t> regs;
    regs.reserve(lineEdits.size());

    for (auto *edit : lineEdits)
        regs.push_back(parseRegister(edit->text()));

    // Convert uint16_t to byte array based on endian
    std::vector<uint8_t> bytes;
    bytes.reserve(regs.size() * 2);

    bool bigEndian = (endianCombo->currentIndex() == 1);

    for (uint16_t r : regs)
    {
        uint8_t hi = (r >> 8) & 0xFF;
        uint8_t lo =  r       & 0xFF;

        if (bigEndian)
        {
            bytes.push_back(hi);
            bytes.push_back(lo);
        }
        else
        {
            bytes.push_back(lo);
            bytes.push_back(hi);
        }
    }

    QString result;

    switch (formatCombo->currentIndex())
    {
    case 0: // HEX
        for (uint8_t b : bytes)
            result += QString("%1 ").arg(b, 2, 16, QChar('0')).toUpper();
        break;

    case 1: // DECIMAL
        for (uint8_t b : bytes)
            result += QString::number(b) + " ";
        break;

    case 2: // BINARY
        for (uint8_t b : bytes)
            result += QString("%1 ").arg(b, 8, 2, QChar('0'));
        break;

    case 3: // ASCII
        for (uint8_t b : bytes)
            result += QChar(b);
        break;
    }
//    memcpy(Application.lineEditsData.data(),bytes.data(),bytes.size());
    Application.lineEditsData.resize(bytes.size());
    for (size_t i = 0; i < bytes.size(); ++i)
    {
        Application.lineEditsData[i] = static_cast<uint16_t>(bytes[i]);
        qDebug()<<"i"<<bytes[i]<<Application.lineEditsData[i];
    }

    outputBox->setPlainText(result.trimmed());

}
void BlocksOnNumber::refreshFormatted_ABCD_Data()
{
    std::vector<uint16_t> regs;
    regs.reserve(lineEdits.size());

    // 1. Read all registers from UI
    for (auto *edit : lineEdits)
        regs.push_back(parseRegister(edit->text()));

    // 2. Convert to bytes using selected endian format
    std::vector<uint8_t> bytes;
    bytes.reserve(regs.size() * 2);

    EndianMode_et endian = (EndianMode_et)ui->CmBx_byteFormate->currentIndex();

    for (uint16_t r : regs)
    {
        uint8_t hi = (r >> 8) & 0xFF;
        uint8_t lo =  r       & 0xFF;

        switch (endian)
        {
        case ABCD:
            // Big endian (normal)
            bytes.push_back(hi);
            bytes.push_back(lo);
            break;

        case CDAB:
            // Word swap (but input is 16-bit word → no per-byte swap here)
            // Actually CDAB only matters when combining words → for individual registers same as ABCD
            bytes.push_back(hi);
            bytes.push_back(lo);
            break;

        case BADC:
            // Swap bytes inside 16-bit register
            bytes.push_back(lo);
            bytes.push_back(hi);
            break;

        case DCBA:
            // Reverse order of all bytes → but per-register reverse is same as BADC
            bytes.push_back(lo);
            bytes.push_back(hi);
            break;
        }
    }

    // 3. Convert to user-selected output format
    QString result;

    switch (formatCombo->currentIndex())
    {
    case 0: // HEX
        for (uint8_t b : bytes)
            result += QString("%1 ").arg(b, 2, 16, QChar('0')).toUpper();
        break;

    case 1: // DECIMAL
        for (uint8_t b : bytes)
            result += QString::number(b) + " ";
        break;

    case 2: // BINARY
        for (uint8_t b : bytes)
            result += QString("%1 ").arg(b, 8, 2, QChar('0'));
        break;

    case 3: // ASCII
        for (uint8_t b : bytes)
            result += QChar(b);
        break;
    }

    // 4. Store in Application buffer
    Application.lineEditsData.resize(bytes.size());
    for (size_t i = 0; i < bytes.size(); ++i)
    {
        Application.lineEditsData[i] = bytes[i];
    }

    outputBox->setPlainText(result.trimmed());
}

void BlocksOnNumber::loadRegisters(const uint16_t *data, int length)
{
    if (!data || length <= 0)
    {
        qDebug()<<"return..";
        return;
    }

    // 1️⃣ Adjust UI count if needed
    if (length != (int)lineEdits.size())
        updateLineEdits(length);

    bool bigEndian = (endianCombo->currentIndex() == 1);
    int formatIndex = formatCombo->currentIndex();
//    qDebug()<<bigEndian<<formatIndex;
    // 2️⃣ Update line edits based on current format
    for (int i = 0; i < length; i++)
    {
        uint16_t value = data[i];
        QString text;

        switch (formatIndex)
        {
        case 0: // HEX 4-digit padded
            text = QString("0x%1")
                     .arg(value, 4, 16, QChar('0'))
                     .toUpper();
            break;

        case 1: // DECIMAL
            text = QString::number(value);
            break;

        case 2: // BINARY 16-bit padded
            text = QString("%1")
                     .arg(value, 16, 2, QChar('0'));
            break;

        case 3: // ASCII (2 chars from 16-bit)
        {
            uint8_t hi = (value >> 8) & 0xFF;
            uint8_t lo =  value       & 0xFF;

            if (bigEndian)
                text = QString("%1%2").arg(QChar(hi)).arg(QChar(lo));
            else
                text = QString("%1%2").arg(QChar(lo)).arg(QChar(hi));
            break;
        }
        }
//        uint32_t val = text.toInt();
//         text = QString::number(Application.combine32((val&0xFF),(val&0xFF00),(EndianMode_et)ui->CmBx_byteFormate->currentIndex()));
        lineEdits[i]->setText(text);
    }

    // 3️⃣ Update output display also
    refreshFormattedData();
}

void BlocksOnNumber::setInputRange(int min, int max)
{
    delete byteValidator;
    byteValidator = new QIntValidator(min, max, this);

    for (auto *edit : lineEdits)
        edit->setValidator(byteValidator);
}
void BlocksOnNumber::setEditsEnabled(bool enable)
{
    for (auto *edit : lineEdits)
    {
        if (edit)
            edit->setEnabled(enable);
    }
}
void BlocksOnNumber::convertEditsToSelectedFormat()
{

#if 1
    switch ((EndianMode_et)ui->CmBx_byteFormate->currentIndex())
    {
    case ABCD:

        break;
    case CDAB:

        break;
    case BADC:

        break;
    case DCBA:

        break;
    default:
        break;
    }

#else
    int formatIndex = formatCombo->currentIndex();
    bool bigEndian  = (endianCombo->currentIndex() == 1);

    for (QLineEdit *edit : lineEdits)
    {
        if (!edit)
            continue;

        // 1️⃣ Get current numeric value from whatever is in the edit
        uint16_t value = parseToUint16(edit->text());

        // 2️⃣ Convert numeric value to the selected display format
        QString text;

        switch (formatIndex)
        {
        case 0: // HEX, 4-digit, padded
            text = QString("0x%1")
                     .arg(value, 4, 16, QLatin1Char('0'))
                     .toUpper();
            break;

        case 1: // DECIMAL
            text = QString::number(value);
            break;

        case 2: // BINARY, 16 bits
            text = QString("%1")
                     .arg(value, 16, 2, QLatin1Char('0'));
            break;

        case 3: // ASCII: two chars from 16-bit, endian affects order
        {
            uint8_t hi = (value >> 8) & 0xFF;
            uint8_t lo =  value       & 0xFF;

            if (bigEndian)
                text = QString("%1%2").arg(QChar(hi)).arg(QChar(lo));
            else
                text = QString("%1%2").arg(QChar(lo)).arg(QChar(hi));

            break;
        }

        default:
            text = QString::number(value);
            break;
        }

        edit->setText(text);
    }

    // 3️⃣ Also update the combined output view using your existing logic
    refreshFormattedData();
#endif
}

std::vector<uint16_t> BlocksOnNumber::getRegisters()
{
    std::vector<uint16_t> regs;
    regs.reserve(lineEdits.size());

    for (auto *edit : lineEdits)
        regs.push_back(parseRegister(edit->text()));

    return regs;
}

void BlocksOnNumber::on_CmBx_byteFormate_currentIndexChanged(int index)
{
    refreshFormatted_ABCD_Data();
}
