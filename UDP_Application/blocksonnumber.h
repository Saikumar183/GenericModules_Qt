#ifndef BLOCKSONNUMBER_H
#define BLOCKSONNUMBER_H

#include <QWidget>
#include "qtheaderfiles.h"
#include "globalclass.h"
namespace Ui {
class BlocksOnNumber;
}

class BlocksOnNumber : public QWidget
{
    Q_OBJECT

public:
    explicit BlocksOnNumber(QWidget *parent = 0);
    ~BlocksOnNumber();
    void loadRegisters(const uint16_t *regs, int count);
        void setInputRange(int min = 0, int max = 65535);
    void setEditsEnabled(bool enable);
    std::vector<uint16_t> getRegisters();
    void refreshFormatted_ABCD_Data();
private:

    Ui::BlocksOnNumber *ui;
    QWidget *scrollWidget;        // widget inside the scroll area
    QScrollArea *scrollArea;
    QGridLayout *grid;
    std::vector<QLineEdit*> lineEdits;

    QComboBox *formatCombo;
    QComboBox *endianCombo;
    QPlainTextEdit *outputBox;
    QIntValidator *byteValidator;
public slots:
    void updateLineEdits(int count);
    void updateLineEdits(QString);
    void refreshFormattedData();
    void onFormatChanged(int);
    void onEndianChanged(int);
    void convertEditsToSelectedFormat();
    void updateRegisterCountLineEdit(QString maxData);

private slots:
    void on_CmBx_byteFormate_currentIndexChanged(int index);
};

#endif // BLOCKSONNUMBER_H
