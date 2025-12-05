#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "setup_ip.h"
#include "communication.h"

#include "serialportwidget.h"

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
    SetUp_IP *ModbusPort_Screen;
    Communication *UDP_Comm;
    SerialPortWidget *SerialPort_Screen;
    void checkTxFlag();
    void checkRxFlag();
    QTimer *timer_run;
 private slots:
    void onTimeout_Run();
    void onPageChanged(int index);
    void on_tabWidget_currentChanged(int index);
    void on_ui_Style_currentIndexChanged(int index);
};

#endif // MAINWINDOW_H
