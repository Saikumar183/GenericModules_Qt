#ifndef ENDIANREGISTERGRIDWIDGET_H
#define ENDIANREGISTERGRIDWIDGET_H

#include <QWidget>
#include <QByteArray>
#include <QVector>

class QGridLayout;
class QLineEdit;
class QLabel;

// Same endian enum you defined


class EndianRegisterGridWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EndianRegisterGridWidget(QWidget *parent = nullptr);

    // Set raw data (multiple of 2 bytes recommended)
    void setData(const QByteArray &rawBytes);

    // Get the raw base data (ABCD order as passed to setData)
    QByteArray baseData() const { return m_baseBytes; }

    // Get data in current endian mode (display order)
    QByteArray dataInCurrentMode() const;

    // Configure how many cells per row (default 8)
    void setCellsPerRow(int cells);
    typedef enum
    {
        ABCD,
        CDAB,
        BADC,
        DCBA
    } EndianMode_et;
    typedef enum
    {
        DisplayHex = 0,
        DisplayDec,
        DisplayBin
    } DisplayFormat_et;
    // 🔹 NEW:
     DisplayFormat_et m_displayFormat;
      bool m_editable = false;

    bool wordAt(int index, quint16 &value) const;
    int cellCount() const { return m_cells.size(); }
protected:
     bool eventFilter(QObject *obj, QEvent *event) override;
public slots:
    // Set endian mode directly
    void setEndianMode(EndianMode_et mode);
    void setEditable(bool editable);
    // Helper slot to connect from QComboBox::currentIndexChanged(int)
    // index: 0=ABCD, 1=CDAB, 2=BADC, 3=DCBA
    void setEndianModeIndex(int index);
    // 🔹 NEW: display format control
    void setDisplayFormat(DisplayFormat_et fmt);
    void setDisplayFormatIndex(int index); // 0=Hex, 1=Dec, 2=Bin
private:
    QGridLayout *m_grid;
    QVector<QLineEdit*> m_cells;
    QByteArray m_baseBytes;        // bytes as given (ABCD order)
    EndianMode_et m_mode;
    int m_cellsPerRow;
    // 🔹 NEW:
        QLabel *m_statusLabel = nullptr;
    void rebuildGrid();            // rebuild line edits from m_baseBytes + m_mode
    QByteArray convertedBytes() const; // apply endian mode on 4-byte groups
    void updateStatusForIndex(int index);
};

#endif // ENDIANREGISTERGRIDWIDGET_H
