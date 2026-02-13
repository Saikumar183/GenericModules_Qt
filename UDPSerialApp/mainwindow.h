#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serialportwidget.h"
#include "globalclass.h"
#include "modbusscreen.h"
#include "appversiondialog.h"
#include "setup_ip.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SerialPortWidget *SerialPort_Screen;
    ModbusScreen *ClassModbusScreen;
    SetUp_IP *ClassSetUpIp;
    QTimer *timer_run;
    void keyPressEvent(QKeyEvent *event);
    void showVersionDetails();
    QPushButton *m_versionButton = nullptr;
    void applyFullScreenSize();
    void Init_Screens(void );
    void Init_Hides(bool state );
    void Init_Connects(void );
    void Init_miscellaneous(void );
    void UpdateComStatus();
    void ActiveProtocolSelection();
signals:
    void UpdateLogString(QString);
private slots:
    void on_ui_Style_currentIndexChanged(int index);
    void onTimeout_Run();
    void on_tabWidget_currentChanged(int index);
};

#endif // MAINWINDOW_H
