#include "EndianRegisterGridWidget.h"

#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QRegularExpressionValidator>
#include <QEvent>
// ─────────────────────────────
// Constructor
// ─────────────────────────────
EndianRegisterGridWidget::EndianRegisterGridWidget(QWidget *parent)
    : QWidget(parent),
      m_grid(new QGridLayout(this)),
      m_mode(ABCD),
      m_cellsPerRow(4),     // 8 registers per row by default
      m_displayFormat(DisplayHex),
      m_editable(false),
    m_statusLabel(new QLabel(this))
{
    m_statusLabel->setText("No cell selected.");
    m_statusLabel->setWordWrap(true);
    m_statusLabel->setVisible(false);
    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(m_grid);        // grid on top
    mainLayout->addWidget(m_statusLabel); // status line below
    mainLayout->setContentsMargins(0, 0, 0, 0);

    setLayout(m_grid);
}

// ─────────────────────────────
// Public API
// ─────────────────────────────
void EndianRegisterGridWidget::setData(const QByteArray &rawBytes)
{
    m_baseBytes = rawBytes;
    rebuildGrid();
}

QByteArray EndianRegisterGridWidget::dataInCurrentMode() const
{
    return convertedBytes();
}

void EndianRegisterGridWidget::setCellsPerRow(int cells)
{
    if (cells < 1) cells = 1;
    m_cellsPerRow = cells;
    rebuildGrid();
}

// ─────────────────────────────
// Endian mode setters
// ─────────────────────────────
void EndianRegisterGridWidget::setEndianMode(EndianMode_et mode)
{
    m_mode = mode;
    rebuildGrid();
}

void EndianRegisterGridWidget::setEndianModeIndex(int index)
{
    switch (index)
    {
    case 0: m_mode = ABCD; break;
    case 1: m_mode = CDAB; break;
    case 2: m_mode = BADC; break;
    case 3: m_mode = DCBA; break;
    default: m_mode = ABCD; break;
    }
    rebuildGrid();
}

// ─────────────────────────────
// Internal: apply endian mode
// Each cell is 2 bytes, but we
// reorder in 4-byte groups:
// [A B C D] -> depends on m_mode
// ─────────────────────────────
QByteArray EndianRegisterGridWidget::convertedBytes() const
{
    QByteArray out = m_baseBytes;
    int fullGroups = (out.size() / 4) * 4; // multiple of 4

    for (int i = 0; i < fullGroups; i += 4)
    {
        char A = out[i];
        char B = out[i + 1];
        char C = out[i + 2];
        char D = out[i + 3];

        switch (m_mode)
        {
        case ABCD:
            // No change
            out[i]     = A;
            out[i + 1] = B;
            out[i + 2] = C;
            out[i + 3] = D;
            break;

        case CDAB:
            // Word swap: C D A B
            out[i]     = C;
            out[i + 1] = D;
            out[i + 2] = A;
            out[i + 3] = B;
            break;

        case BADC:
            // Byte swap inside each 16-bit word: B A D C
            out[i]     = B;
            out[i + 1] = A;
            out[i + 2] = D;
            out[i + 3] = C;
            break;

        case DCBA:
            // Full reverse: D C B A
            out[i]     = D;
            out[i + 1] = C;
            out[i + 2] = B;
            out[i + 3] = A;
            break;
        }
    }

    // If size is not multiple of 4, remaining last 2 bytes (if any)
    // are left unchanged.
    return out;
}
void EndianRegisterGridWidget::rebuildGrid()
{
    // Clear previous widgets from layout
    QLayoutItem *item;
    while ((item = m_grid->takeAt(0)) != nullptr)
    {
        if (QWidget *w = item->widget())
            w->deleteLater();
        delete item;
    }
    m_cells.clear();

    if (m_baseBytes.isEmpty())
        return;

    QByteArray bytes = convertedBytes();

    // Ensure even number of bytes; if odd, ignore last byte
    int size = bytes.size();
    if (size % 2 != 0)
        size -= 1;

    int registerCount = size / 2;

    // Common hex validator (in case you later allow editing)
    QRegularExpressionValidator *hexValidator =
        new QRegularExpressionValidator(QRegularExpression("[0-9A-Fa-f]{0,4}"), this);

    for (int i = 0; i < registerCount; ++i)
    {
        int byteIndex = i * 2;
        int byteStart = byteIndex;
        int byteEnd   = byteIndex + 1;

        // Label like "0-1", "2-3", ...
        QLabel *lbl = new QLabel(
            QString("%1-%2").arg(byteStart).arg(byteEnd),
            this);

        QLineEdit *edit = new QLineEdit(this);
        edit->setAlignment(Qt::AlignCenter);
        edit->setMaxLength(16);
        // editable or not based on flag
        edit->setReadOnly(!m_editable);
        edit->setProperty("cellIndex", i);
        edit->installEventFilter(this);
        // Optional: only use hex validator in hex mode and when editable
        if (m_editable && m_displayFormat == DisplayHex)
            edit->setValidator(hexValidator);

        // Get the 16-bit word value
        quint8 hi = static_cast<quint8>(bytes[byteIndex]);
        quint8 lo = static_cast<quint8>(bytes[byteIndex + 1]);
        quint16 value = (static_cast<quint16>(hi) << 8) | lo;

        QString text;
        switch (m_displayFormat)
        {
        case DisplayHex:
            text = QString("%1").arg(value, 4, 16, QLatin1Char('0')).toUpper();  // 4-digit HEX
            break;

        case DisplayDec:
            text = QString::number(value);                                      // decimal
            break;

        case DisplayBin:
            text = QString("%1").arg(value, 16, 2, QLatin1Char('0'));           // 16-bit binary
            break;
        }

        edit->setText(text);
        edit->setToolTip(QString("Register %1 (bytes %2-%3)\nValue: %4")
                         .arg(i)
                         .arg(byteStart)
                         .arg(byteEnd)
                         .arg(text));

        m_cells.push_back(edit);

        // Each register uses [label][edit] in one row
        int row      = i / m_cellsPerRow;
        int colPair  = i % m_cellsPerRow;
        int colLabel = colPair * 2;
        int colEdit  = colLabel + 1;

        m_grid->addWidget(lbl,  row, colLabel);
        m_grid->addWidget(edit, row, colEdit);

    }

    m_grid->setHorizontalSpacing(6);
    m_grid->setVerticalSpacing(4);
}
bool EndianRegisterGridWidget::eventFilter(QObject *obj, QEvent *event)
{
    // We only care about our QLineEdits
    QLineEdit *edit = qobject_cast<QLineEdit*>(obj);
    if (!edit)
        return QWidget::eventFilter(obj, event);

    // React when user clicks or focuses a cell
    if (event->type() == QEvent::MouseButtonPress ||
        event->type() == QEvent::FocusIn)
    {
        bool ok = false;
        int idx = edit->property("cellIndex").toInt(&ok);
        if (ok)
            updateStatusForIndex(idx);
    }

    // You can also update on text change, but this is enough for now
    return QWidget::eventFilter(obj, event);
}

void EndianRegisterGridWidget::setDisplayFormat(DisplayFormat_et fmt)
{
    m_displayFormat = fmt;
    rebuildGrid();
}
void EndianRegisterGridWidget::setEditable(bool editable)
{
    m_editable = editable;
    rebuildGrid();
}
bool EndianRegisterGridWidget::wordAt(int index, quint16 &value) const
{
    if (index < 0 || index >= m_cells.size())
        return false;

    QString text = m_cells[index]->text().trimmed();
    if (text.isEmpty())
        return false;

    bool ok = false;
    switch (m_displayFormat)
    {
    case DisplayHex:
        value = text.toUShort(&ok, 16);
        break;
    case DisplayDec:
        value = text.toUShort(&ok, 10);
        break;
    case DisplayBin:
        value = text.toUShort(&ok, 2);
        break;
    }
    return ok;
}

void EndianRegisterGridWidget::updateStatusForIndex(int index)
{
    if (!m_statusLabel)
        return;

    quint16 value = 0;
    if (!wordAt(index, value))
    {
        m_statusLabel->setText("Invalid or empty value.");
        return;
    }

    int byteStart = index * 2;
    int byteEnd   = byteStart + 1;

    QString hexStr = QString("0x%1").arg(value, 4, 16, QLatin1Char('0')).toUpper();
    QString decStr = QString::number(value);
    QString binStr = QString("%1").arg(value, 16, 2, QLatin1Char('0'));

    QString msg = QString("Cell %1 (bytes %2-%3):  HEX=%4  DEC=%5  BIN=%6")
                  .arg(index)
                  .arg(byteStart)
                  .arg(byteEnd)
                  .arg(hexStr)
                  .arg(decStr)
                  .arg(binStr);

    m_statusLabel->setText(msg);
}


void EndianRegisterGridWidget::setDisplayFormatIndex(int index)
{
    switch (index)
    {
    case 0: m_displayFormat = DisplayHex; break;
    case 1: m_displayFormat = DisplayDec; break;
    case 2: m_displayFormat = DisplayBin; break;
    default: m_displayFormat = DisplayHex; break;
    }
    rebuildGrid();
}
