#include "globalclass.h"
ModbusData_st ModbusData;
GlobalClass::GlobalClass()
{

}
void GlobalClass::Init_statusLabel(QWidget *parent)
{
    QFont boldFont("Arial", 8, QFont::Bold);
    // Status Panel Label
    Application.lbl_statuspanel = new QLabel(parent);
    Application.lbl_statuspanel->setFont(boldFont);
    Application.lbl_statuspanel->setText("    ");
    Application.lbl_statuspanel->setStyleSheet("border:none;");
}
void GlobalClass::saveDatatoFile(const QString &fileName, QString str)
{
    QFile file(fileName);
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);

            out << str << "\n";

        file.close();
    }
}
uint32_t GlobalClass::combineToUint32(uint16_t r1, uint16_t r2)
{
    // CDAB word swap: (High word swapped)
    return ((uint32_t)r2 << 16) | r1;
}
// 1) ABCD (big-endian normal)
uint32_t GlobalClass::toABCD(uint16_t r1, uint16_t r2)
{
    return (uint32_t(r1) << 16) | r2;
}

// 2) CDAB (word-swap)
uint32_t GlobalClass::toCDAB(uint16_t r1, uint16_t r2)
{
    return (uint32_t(r2) << 16) | r1;
}

// 3) BADC (byte swap inside each word)
uint32_t GlobalClass::toBADC(uint16_t r1, uint16_t r2)
{
    uint16_t w1 = ((r1 >> 8) | (r1 << 8));
    uint16_t w2 = ((r2 >> 8) | (r2 << 8));
    return (uint32_t(w1) << 16) | w2;
}

// 4) DCBA (reverse all bytes)
uint32_t GlobalClass::toDCBA(uint16_t r1, uint16_t r2)
{
    uint32_t v = ((uint32_t(r1) << 16) | r2);
    return __builtin_bswap32(v);   // GCC/Clang
}

float GlobalClass::convertToFloat(uint32_t raw)
{
    float f;
    memcpy(&f, &raw, sizeof(float));
    return f;
}
QByteArray GlobalClass::convertEndian(const QByteArray &input, EndianMode_et mode)
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

uint32_t GlobalClass::combine32(uint16_t r1, uint16_t r2, EndianMode_et mode)
{
    switch (mode)
    {
        case ABCD:
            return (uint32_t(r1) << 16) | r2;

        case CDAB:
            return (uint32_t(r2) << 16) | r1;

        case BADC:
        {
            uint16_t w1 = (r1 >> 8) | (r1 << 8);
            uint16_t w2 = (r2 >> 8) | (r2 << 8);
            return (uint32_t(w1) << 16) | w2;
        }

        case DCBA:
        {
            uint32_t v = ((uint32_t(r1) << 16) | r2);
            return __builtin_bswap32(v);
        }
    }
    return 0;
}
void GlobalClass::LogModbusData()
{

    QString txHex = "TxPackets: "+QString::number(Application.TxPackets) + QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss.zzz") +" | Tx : " + byteArrayToHexString(Application.TxData);
    QString rxHex = "RxPackets: "+QString::number(Application.RxPackets) + QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss.zzz") +" | Rx : " + byteArrayToHexString(Application.RxData);

    // Path to log file
    QString logPath = QApplication::applicationDirPath() + QDir::separator() + "ModbusFrameLog.txt";

    static bool RestartFlag = false;
    if((Application.isPortBindCompleted)&&(!RestartFlag))
    {
        RestartFlag = true;
        QString newLine = "\n**********************************************" + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")+"\n";
        Application.saveDatatoFile(logPath, newLine);
    }
    else
    {
        if(!(Application.isPortBindCompleted))
        {
            RestartFlag = false;
        }
    }
    // Save to file
    saveDatatoFile(logPath, txHex);
    saveDatatoFile(logPath, rxHex);

}
QString GlobalClass::byteArrayToHexString(const QByteArray &data)
{
    QString hexString;
    for (int i = 0; i < data.size(); ++i) {
        hexString.append(QString::number((unsigned char)data.at(i), 16).rightJustified(2, '0'));
        hexString.append(" ");  // Add a space between hex bytes
    }
    return hexString.trimmed();  // Remove the trailing space
}
void GlobalClass::UpdateStatusLabel(const QString& message, bool isError)
{
    Application.lbl_statuspanel->setText(message);

    QString bgColor = isError ? "" :
                                QString(" %1").arg(getBlinkColor(Application.currentTheme).name());//"red": "green";
    Application.lbl_statuspanel->setStyleSheet(QString("QLabel { padding:7px; background-color: %1; color: white; }").arg(bgColor));
    Application.lbl_statuspanel_flag = true;
    Application.lbl_statuspanel_cntr = 0;

}



QString GlobalClass::getStyleSheet(AppTheme_et themeId)
{
    switch(themeId)
    {
    case TealGraphite:
        return R"(
               /* ------------------------ Common ------------------------ */
               QWidget {
               background-color: #1F2428;
               color: #EAEAEA;
               font-family: 'Segoe UI', 'Roboto', sans-serif;
               font-size: 14px;
               }

               /* ------------------------ Buttons ------------------------ */
               QPushButton {
               background-color: #282E33;
               border: 1px solid #3A4249;
               border-radius: 4px;
               color: #EAEAEA;
               padding: 6px 12px;
               }
               QPushButton:hover { background-color: #00B8A9; border-color: #00B8A9; }
               QPushButton:pressed { background-color: #009688; }
               QPushButton:disabled { background-color: #282E33; color: #7A7A7A; }

               /* ------------------------ LineEdit ------------------------ */
               QLineEdit {
               background-color: #282E33;
               border: 1px solid #3A4249;
               border-radius: 4px;
               padding: 4px;
               color: #EAEAEA;
               }
               QLineEdit:focus { border: 1px solid #00B8A9; }

               /* ------------------------ ComboBox ------------------------ */
               QComboBox {
               background-color: #282E33;
               border: 1px solid #3A4249;
               padding: 4px 8px;
               border-radius: 4px;
               color: #EAEAEA;
               }
               QComboBox QAbstractItemView {
               background-color: #282E33;
               border: 1px solid #3A4249;
               selection-background-color: #00B8A9;
               }

               /* ------------------------ TabWidget ------------------------ */
               QTabWidget::pane {
               border: 1px solid #3A4249;
               background-color: #252526;
               }
               QTabBar::tab {
               background-color: #282E33;
               color: #EAEAEA;
               padding: 6px 12px;
               border: 1px solid #3A4249;
               border-bottom: none;
               border-top-left-radius: 4px;
               border-top-right-radius: 4px;
               }
               QTabBar::tab:selected {
               background-color: #00B8A9;
               color: #1F2428;
               }

               /* ------------------------ StackedWidget ------------------------ */
               QStackedWidget {
               background-color: #252526;
               }

               /* ------------------------ CheckBox & RadioButton ------------------------ */
               QCheckBox, QRadioButton { spacing: 6px; }
               QCheckBox::indicator, QRadioButton::indicator {
               width: 16px; height: 16px;
               border: 1px solid #3A4249;
               background-color: #1F2428;
               }
               QCheckBox::indicator:checked, QRadioButton::indicator:checked {
               background-color: #00B8A9; border: 1px solid #00B8A9;
               }

               /* ------------------------ TableView ------------------------ */
               QTableView {
               background-color: #1F2428;
               gridline-color: #3A4249;
               color: #EAEAEA;
               border: 1px solid #3A4249;
               }
               QHeaderView::section {
               background-color: #282E33;
               color: #EAEAEA;
               border-bottom: 1px solid #3A4249;
               padding: 6px;
               }

               /* ------------------------ ScrollBars ------------------------ */
               QScrollBar:horizontal, QScrollBar:vertical {
               background-color: #252526;
               width: 12px; height: 12px; border: none; margin: 0;
               }
               QScrollBar::handle {
               background-color: #3A4249;
               border-radius: 6px;
               }
               QScrollBar::handle:hover { background-color: #00B8A9; }
               QScrollBar::add-line, QScrollBar::sub-line { background: none; }

               /* ------------------------ GroupBox ------------------------ */
               QGroupBox {
               border: 1px solid #3A4249;
               border-radius: 4px;
               padding: 8px;
               margin-top: 6px;
               }
               QGroupBox:title {
               subcontrol-origin: margin;
               subcontrol-position: top left;
               padding: 0 6px;
               color: #EAEAEA;
               }

               /* ------------------------ DockWidget ------------------------ */
               QDockWidget {
               titlebar-close-icon: url(:/icons/close.png);
               titlebar-normal-icon: url(:/icons/undock.png);
               background: #252526;
               border: 1px solid #3A4249;
               }
               QDockWidget::title {
               text-align: center;
               background: #282E33;
               padding: 4px;
               color: #EAEAEA;
               }

               /* ------------------------ MenuBar & Menu ------------------------ */
               QMenuBar {
               background-color: #252526;
               color: #EAEAEA;
               }
               QMenuBar::item:selected {
               background-color: #00B8A9;
               color: #1F2428;
               }
               QMenu {
               background-color: #252526;
               color: #EAEAEA;
               border: 1px solid #3A4249;
               }
               QMenu::item:selected {
               background-color: #00B8A9;
               color: #1F2428;
               }
               )";



        // ---------------- Orange + Charcoal ----------------
    case OrangeCharcoal:
        return R"(
               QWidget { background-color: #1E1E1E; color: #EEEEEE; font-family: 'Segoe UI', sans-serif; font-size: 14px; }

               QPushButton {
               background-color: #2A2A2A; border: 1px solid #3C3C3C; border-radius: 4px; color: #EEEEEE; padding: 6px 12px;
               }
               QPushButton:hover { background-color: #FF9800; border-color: #FF9800; }
               QPushButton:pressed { background-color: #E68900; }

               QLineEdit { background-color: #2A2A2A; border: 1px solid #3C3C3C; border-radius: 4px; padding: 4px; color: #EEEEEE; }
               QLineEdit:focus { border: 1px solid #FF9800; }

               QComboBox { background-color: #2A2A2A; border: 1px solid #3C3C3C; padding: 4px 8px; border-radius: 4px; color: #EEEEEE; }
               QComboBox QAbstractItemView { background-color: #2A2A2A; border: 1px solid #3C3C3C; selection-background-color: #FF9800; }

               QTabWidget::pane { border: 1px solid #3C3C3C; background-color: #252525; }
               QTabBar::tab { background-color: #2A2A2A; color: #EEEEEE; padding: 6px 12px; border: 1px solid #3C3C3C; border-bottom: none; border-top-left-radius: 4px; border-top-right-radius: 4px; }
               QTabBar::tab:selected { background-color: #FF9800; color: #1E1E1E; }

               QStackedWidget { background-color: #252525; }

               QCheckBox, QRadioButton { spacing: 6px; }
               QCheckBox::indicator, QRadioButton::indicator { width: 16px; height: 16px; border: 1px solid #3C3C3C; background-color: #1E1E1E; }
               QCheckBox::indicator:checked, QRadioButton::indicator:checked { background-color: #FF9800; border: 1px solid #FF9800; }

               QTableView { background-color: #1E1E1E; gridline-color: #3C3C3C; color: #EEEEEE; border: 1px solid #3C3C3C; }
               QHeaderView::section { background-color: #2A2A2A; color: #EEEEEE; border-bottom: 1px solid #3C3C3C; padding: 6px; }

               QScrollBar:horizontal, QScrollBar:vertical { background-color: #252525; width: 12px; border: none; margin: 0; }
               QScrollBar::handle { background-color: #3C3C3C; border-radius: 6px; }
               QScrollBar::handle:hover { background-color: #FF9800; }

               QGroupBox { border: 1px solid #3C3C3C; border-radius: 4px; padding: 8px; margin-top: 6px; }
               QGroupBox:title { subcontrol-origin: margin; subcontrol-position: top left; padding: 0 6px; color: #EEEEEE; }

               QDockWidget { background: #252525; border: 1px solid #3C3C3C; }
               QDockWidget::title { background: #2A2A2A; padding: 4px; color: #EEEEEE; }

               QMenuBar { background-color: #252525; color: #EEEEEE; }
               QMenuBar::item:selected { background-color: #FF9800; color: #1E1E1E; }
               QMenu { background-color: #252525; color: #EEEEEE; border: 1px solid #3C3C3C; }
               QMenu::item:selected { background-color: #FF9800; color: #1E1E1E; }
               )";

        // ---------------- Emerald Green + Dark Gray ----------------
    case EmeraldDarkGray:
        return R"(
               QWidget { background-color: #1C1D1F; color: #E6E6E6; font-family: 'Segoe UI', sans-serif; font-size: 14px; }

               QPushButton { background-color: #232527; border: 1px solid #3A3D3F; border-radius: 4px; color: #E6E6E6; padding: 6px 12px; }
               QPushButton:hover { background-color: #43A047; border-color: #43A047; }
               QPushButton:pressed { background-color: #388E3C; }

               QLineEdit { background-color: #232527; border: 1px solid #3A3D3F; border-radius: 4px; padding: 4px; color: #E6E6E6; }
               QLineEdit:focus { border: 1px solid #43A047; }

               QComboBox { background-color: #232527; border: 1px solid #3A3D3F; padding: 4px 8px; border-radius: 4px; color: #E6E6E6; }
               QComboBox QAbstractItemView { background-color: #232527; border: 1px solid #3A3D3F; selection-background-color: #43A047; }

               QTabWidget::pane { border: 1px solid #3A3D3F; background-color: #252526; }
               QTabBar::tab { background-color: #232527; color: #E6E6E6; padding: 6px 12px; border: 1px solid #3A3D3F; border-bottom: none; border-top-left-radius: 4px; border-top-right-radius: 4px; }
               QTabBar::tab:selected { background-color: #43A047; color: #1C1D1F; }

               QStackedWidget { background-color: #252526; }

               QCheckBox, QRadioButton { spacing: 6px; }
               QCheckBox::indicator, QRadioButton::indicator { width: 16px; height: 16px; border: 1px solid #3A3D3F; background-color: #1C1D1F; }
               QCheckBox::indicator:checked, QRadioButton::indicator:checked { background-color: #43A047; border: 1px solid #43A047; }

               QTableView { background-color: #1C1D1F; gridline-color: #3A3D3F; color: #E6E6E6; border: 1px solid #3A3D3F; }
               QHeaderView::section { background-color: #232527; color: #E6E6E6; border-bottom: 1px solid #3A3D3F; padding: 6px; }

               QScrollBar:horizontal, QScrollBar:vertical { background-color: #252526; width: 12px; border: none; margin: 0; }
               QScrollBar::handle { background-color: #3A3D3F; border-radius: 6px; }
               QScrollBar::handle:hover { background-color: #43A047; }

               QGroupBox { border: 1px solid #3A3D3F; border-radius: 4px; padding: 8px; margin-top: 6px; }
               QGroupBox:title { subcontrol-origin: margin; subcontrol-position: top left; padding: 0 6px; color: #E6E6E6; }

               QDockWidget { background: #252526; border: 1px solid #3A3D3F; }
               QDockWidget::title { background: #232527; padding: 4px; color: #E6E6E6; }

               QMenuBar { background-color: #252526; color: #E6E6E6; }
               QMenuBar::item:selected { background-color: #43A047; color: #1C1D1F; }
               QMenu { background-color: #252526; color: #E6E6E6; border: 1px solid #3A3D3F; }
               QMenu::item:selected { background-color: #43A047; color: #1C1D1F; }
               )";

        // ---------------- Purple + Carbon ----------------
    case PurpleCarbon:
        return R"(
               QWidget { background-color: #1A1A1D; color: #E0E0E0; font-family: 'Segoe UI', sans-serif; font-size: 14px; }

               QPushButton { background-color: #232326; border: 1px solid #39393D; border-radius: 4px; color: #E0E0E0; padding: 6px 12px; }
               QPushButton:hover { background-color: #9C27B0; border-color: #9C27B0; }
               QPushButton:pressed { background-color: #7B1FA2; }

               QLineEdit { background-color: #232326; border: 1px solid #39393D; border-radius: 4px; padding: 4px; color: #E0E0E0; }
               QLineEdit:focus { border: 1px solid #9C27B0; }

               QComboBox { background-color: #232326; border: 1px solid #39393D; padding: 4px 8px; border-radius: 4px; color: #E0E0E0; }
               QComboBox QAbstractItemView { background-color: #232326; border: 1px solid #39393D; selection-background-color: #9C27B0; }

               QTabWidget::pane { border: 1px solid #39393D; background-color: #252526; }
               QTabBar::tab { background-color: #232326; color: #E0E0E0; padding: 6px 12px; border: 1px solid #39393D; border-bottom: none; border-top-left-radius: 4px; border-top-right-radius: 4px; }
               QTabBar::tab:selected { background-color: #9C27B0; color: #1A1A1D; }

               QStackedWidget { background-color: #252526; }

               QCheckBox, QRadioButton { spacing: 6px; }
               QCheckBox::indicator, QRadioButton::indicator { width: 16px; height: 16px; border: 1px solid #39393D; background-color: #1A1A1D; }
               QCheckBox::indicator:checked, QRadioButton::indicator:checked { background-color: #9C27B0; border: 1px solid #9C27B0; }

               QTableView { background-color: #1A1A1D; gridline-color: #39393D; color: #E0E0E0; border: 1px solid #39393D; }
               QHeaderView::section { background-color: #232326; color: #E0E0E0; border-bottom: 1px solid #39393D; padding: 6px; }

               QScrollBar:horizontal, QScrollBar:vertical { background-color: #232326; width: 12px; border: none; margin: 0; }
               QScrollBar::handle { background-color: #39393D; border-radius: 6px; }
               QScrollBar::handle:hover { background-color: #9C27B0; }

               QGroupBox { border: 1px solid #39393D; border-radius: 4px; padding: 8px; margin-top: 6px; }
               QGroupBox:title { subcontrol-origin: margin; subcontrol-position: top left; padding: 0 6px; color: #E0E0E0; }

               QDockWidget { background: #252526; border: 1px solid #39393D; }
               QDockWidget::title { background: #232326; padding: 4px; color: #E0E0E0; }

               QMenuBar { background-color: #252526; color: #E0E0E0; }
               QMenuBar::item:selected { background-color: #9C27B0; color: #1A1A1D; }
               QMenu { background-color: #252526; color: #E0E0E0; border: 1px solid #39393D; }
               QMenu::item:selected { background-color: #9C27B0; color: #1A1A1D; }
               )";

        // ---------------- Aqua + Slate ----------------
    case AquaSlate:
        return R"(
               QWidget { background-color: #202124; color: #ECECEC; font-family: 'Segoe UI', sans-serif; font-size: 14px; }

               QPushButton { background-color: #2A2B2E; border: 1px solid #3B3C3F; border-radius: 4px; color: #ECECEC; padding: 6px 12px; }
               QPushButton:hover { background-color: #26C6DA; border-color: #26C6DA; }
               QPushButton:pressed { background-color: #00ACC1; }

               QLineEdit { background-color: #2A2B2E; border: 1px solid #3B3C3F; border-radius: 4px; padding: 4px; color: #ECECEC; }
               QLineEdit:focus { border: 1px solid #26C6DA; }

               QComboBox { background-color: #2A2B2E; border: 1px solid #3B3C3F; padding: 4px 8px; border-radius: 4px; color: #ECECEC; }
               QComboBox QAbstractItemView { background-color: #2A2B2E; border: 1px solid #3B3C3F; selection-background-color: #26C6DA; }

               QTabWidget::pane { border: 1px solid #3B3C3F; background-color: #252526; }
               QTabBar::tab { background-color: #2A2B2E; color: #ECECEC; padding: 6px 12px; border: 1px solid #3B3C3F; border-bottom: none; border-top-left-radius: 4px; border-top-right-radius: 4px; }
               QTabBar::tab:selected { background-color: #26C6DA; color: #202124; }

               QStackedWidget { background-color: #252526; }

               QCheckBox, QRadioButton { spacing: 6px; }
               QCheckBox::indicator, QRadioButton::indicator { width: 16px; height: 16px; border: 1px solid #3B3C3F; background-color: #202124; }
               QCheckBox::indicator:checked, QRadioButton::indicator:checked { background-color: #26C6DA; border: 1px solid #26C6DA; }

               QTableView { background-color: #202124; gridline-color: #3B3C3F; color: #ECECEC; border: 1px solid #3B3C3F; }
               QHeaderView::section { background-color: #2A2B2E; color: #ECECEC; border-bottom: 1px solid #3B3C3F; padding: 6px; }

               QScrollBar:horizontal, QScrollBar:vertical { background-color: #2A2B2E; width: 12px; border: none; margin: 0; }
               QScrollBar::handle { background-color: #3B3C3F; border-radius: 6px; }
               QScrollBar::handle:hover { background-color: #26C6DA; }

               QGroupBox { border: 1px solid #3B3C3F; border-radius: 4px; padding: 8px; margin-top: 6px; }
               QGroupBox:title { subcontrol-origin: margin; subcontrol-position: top left; padding: 0 6px; color: #ECECEC; }

               QDockWidget { background: #252526; border: 1px solid #3B3C3F; }
               QDockWidget::title { background: #2A2B2E; padding: 4px; color: #ECECEC; }

               QMenuBar { background-color: #252526; color: #ECECEC; }
               QMenuBar::item:selected { background-color: #26C6DA; color: #202124; }
               QMenu { background-color: #252526; color: #ECECEC; border: 1px solid #3B3C3F; }
               QMenu::item:selected { background-color: #26C6DA; color: #202124; }
               )";

    case CrimsonBlack:
        return R"(
               /* ------------------------ Common ------------------------ */
               QWidget {
                   background-color: #000000;
                   color: #E6E6E6;
                   font-family: 'Segoe UI', 'Roboto', sans-serif;
                   font-size: 14px;
               }

               /* ------------------------ Buttons ------------------------ */
               QPushButton {
                   background-color: #1A1A1A;
                   border: 1px solid #2A2A2A;
                   border-radius: 4px;
                   color: #E6E6E6;
                   padding: 6px 12px;
               }
               QPushButton:hover { background-color: #db251b; border-color: #db251b; }
               QPushButton:pressed { background-color: #A81C15; }
               QPushButton:disabled { background-color: #1A1A1A; color: #777777; }

               /* ------------------------ LineEdit ------------------------ */
               QLineEdit {
                   background-color: #1A1A1A;
                   border: 1px solid #2A2A2A;
                   border-radius: 4px;
                   padding: 4px;
                   color: #E6E6E6;
               }
               QLineEdit:focus { border: 1px solid #db251b; }

               /* ------------------------ ComboBox ------------------------ */
               QComboBox {
                   background-color: #1A1A1A;
                   border: 1px solid #2A2A2A;
                   padding: 4px 8px;
                   border-radius: 4px;
                   color: #E6E6E6;
               }
               QComboBox QAbstractItemView {
                   background-color: #1A1A1A;
                   border: 1px solid #2A2A2A;
                   selection-background-color: #db251b;
               }

               /* ------------------------ TabWidget ------------------------ */
               QTabWidget::pane {
                   border: 1px solid #2A2A2A;
                   background-color: #323232;
               }
               QTabBar::tab {
                   background-color: #1A1A1A;
                   color: #E6E6E6;
                   padding: 6px 12px;
                   border: 1px solid #2A2A2A;
                   border-bottom: none;
                   border-top-left-radius: 4px;
                   border-top-right-radius: 4px;
               }
               QTabBar::tab:selected {
                   background-color: #db251b;
                   color: #000000;
               }

               /* ------------------------ StackedWidget ------------------------ */
               QStackedWidget {
                   background-color: #323232;
               }

               /* ------------------------ CheckBox & RadioButton ------------------------ */
               QCheckBox, QRadioButton { spacing: 6px; }
               QCheckBox::indicator, QRadioButton::indicator {
                   width: 16px; height: 16px;
                   border: 1px solid #2A2A2A;
                   background-color: #000000;
               }
               QCheckBox::indicator:checked, QRadioButton::indicator:checked {
                   background-color: #db251b;
                   border: 1px solid #db251b;
               }

               /* ------------------------ TableView ------------------------ */
               QTableView {
                   background-color: #000000;
                   gridline-color: #2A2A2A;
                   color: #E6E6E6;
                   border: 1px solid #2A2A2A;
               }
               QHeaderView::section {
                   background-color: #1A1A1A;
                   color: #E6E6E6;
                   border-bottom: 1px solid #2A2A2A;
                   padding: 6px;
               }

               /* ------------------------ ScrollBars ------------------------ */
               QScrollBar:horizontal, QScrollBar:vertical {
                   background-color: #323232;
                   width: 12px; height: 12px;
                   border: none;
                   margin: 0;
               }
               QScrollBar::handle {
                   background-color: #2A2A2A;
                   border-radius: 6px;
               }
               QScrollBar::handle:hover {
                   background-color: #db251b;
               }
               QScrollBar::add-line, QScrollBar::sub-line { background: none; }

               /* ------------------------ GroupBox ------------------------ */
               QGroupBox {
                   border: 1px solid #2A2A2A;
                   border-radius: 4px;
                   padding: 8px;
                   margin-top: 6px;
                   color: #E6E6E6;
               }
               QGroupBox:title {
                   subcontrol-origin: margin;
                   subcontrol-position: top left;
                   padding: 0 6px;
                   color: #E6E6E6;
               }

               /* ------------------------ DockWidget ------------------------ */
               QDockWidget {
                   titlebar-close-icon: url(:/icons/close.png);
                   titlebar-normal-icon: url(:/icons/undock.png);
                   background: #323232;
                   border: 1px solid #2A2A2A;
               }
               QDockWidget::title {
                   text-align: center;
                   background: #1A1A1A;
                   padding: 4px;
                   color: #E6E6E6;
               }

               /* ------------------------ MenuBar & Menu ------------------------ */
               QMenuBar {
                   background-color: #323232;
                   color: #E6E6E6;
               }
               QMenuBar::item:selected {
                   background-color: #db251b;
                   color: #000000;
               }
               QMenu {
                   background-color: #323232;
                   color: #E6E6E6;
                   border: 1px solid #2A2A2A;
               }
               QMenu::item:selected {
                   background-color: #db251b;
                   color: #000000;
               }
               )";

    default:
        return "";
    }
}
QColor GlobalClass::getBlinkColor(AppTheme_et theme)
{
    switch(theme)
    {
        case TealGraphite:      return QColor("#00B8A9"); // Teal
        case OrangeCharcoal:    return QColor("#FF9800"); // Orange
        case EmeraldDarkGray:   return QColor("#43A047"); // Green
        case PurpleCarbon:      return QColor("#9C27B0"); // Purple
        case AquaSlate:         return QColor("#26C6DA"); // Aqua
        case CrimsonBlack:         return QColor("#db251b"); // Aqua
        default:                          return QColor("");
    }
}

GlobalClass Application;
