#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AppInfo.h"
#include "AppVersionDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Init_Screens();
    Init_Connects();
    Init_Hides(true);
    Init_miscellaneous();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showVersionDetails()
{

    AppInfo info = getAppInfo();

    m_versionButton = new QPushButton(QString("v%1").arg(info.version), this);
    m_versionButton->setFlat(true);
    m_versionButton->setToolTip("Show application information");

    statusBar()->addPermanentWidget(m_versionButton);

    connect(m_versionButton, &QPushButton::clicked, this, [this](){
        AppVersionDialog::show(this);
    });
}
void MainWindow::applyFullScreenSize()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect area = screen->availableGeometry();
    this->setGeometry(area);
    this->showMaximized();  // Optional: auto maximize
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        this->showNormal();      // exit full screen / maximize
//        this->resize(originalSize);  // restore original size
    }

    QMainWindow::keyPressEvent(event);
}
void MainWindow::Init_Screens(void )
{
    SerialPort_Screen = new SerialPortWidget();
    QVBoxLayout *lay = new QVBoxLayout(ui->serialPlaceholder);
    lay->addWidget(SerialPort_Screen);
    ui->serialPlaceholder->setLayout(lay);

    ClassModbusScreen = new ModbusScreen(this);
    ui->verticalLayout_3->addWidget(ClassModbusScreen);
    ClassModbusScreen->CopySerialPor(SerialPort_Screen->getSerialPortAddress());
//    applyFullScreenSize();   // after widgets are created

    ClassSetUpIp = new SetUp_IP(this);
    ui->verticalLayout->addWidget(ClassSetUpIp);
}

void MainWindow::Init_Hides(bool state)
{
    ui->menuBar->setVisible(!state);
    ui->mainToolBar->setVisible(!state);
}
void MainWindow::Init_Connects(void )
{
    connect(ClassModbusScreen,SIGNAL(sendSerialData(QByteArray)),SerialPort_Screen,SLOT(sendSerialData(QByteArray)));
    connect(ClassModbusScreen,SIGNAL(sendUdpData(QByteArray)),ClassSetUpIp,SLOT(SendUdpData(QByteArray)));
    connect(SerialPort_Screen,SIGNAL(onSerialDataReceived(QSerialPort*)),ClassModbusScreen,SLOT(onSerialDataReceived(QSerialPort*)));

    connect(ClassSetUpIp,SIGNAL(ProcessUdpRxData(QByteArray)),ClassModbusScreen,SLOT(ProcessUdpRxData(QByteArray)));
}

void MainWindow::Init_miscellaneous(void)
{
    timer_run = new QTimer(this);
    connect(timer_run, SIGNAL(timeout()), this,SLOT(onTimeout_Run()));
    timer_run->start(Application.TimerTimeout);

    Application.Init_statusLabel(this);
    ui->statusBar->addPermanentWidget(Application.lbl_statuspanel);
    ui->statusBar->addPermanentWidget(ui->checkBox_ConnectStatus);
    ui->statusBar->addPermanentWidget(ui->ui_Style);
    ui->ui_Style->setCurrentIndex(Application.currentTheme);
    on_ui_Style_currentIndexChanged(ui->ui_Style->currentIndex());

    ui->tabWidget->setCurrentIndex(TAB_SERIAL);
    showVersionDetails();
}
void MainWindow::UpdateComStatus()
{
    Application.isSerialPortOpen = SerialPort_Screen->isSerialOpen();
//    Application.isPortBindCompleted = ClassSetUpIp->isUdpOpen();
    if(Application.isSerialPortOpen || Application.isPortBindCompleted)
    {
        ui->checkBox_ConnectStatus->setChecked(true);
    }
    else
    {
        ui->checkBox_ConnectStatus->setChecked(false);
    }
}
void MainWindow::onTimeout_Run()
{
    ActiveProtocolSelection();
    UpdateComStatus();
}
void MainWindow::on_ui_Style_currentIndexChanged(int index)
{
    Application.currentTheme = (AppTheme_et)index;
    qApp->setStyleSheet(Application.getStyleSheet(Application.currentTheme));
}

void MainWindow::ActiveProtocolSelection()
{
    if(Application.isPortBindCompleted)
    {
        ui->tabWidget->tabBar()->setTabEnabled(0,true);
        ui->tabWidget->tabBar()->setTabEnabled(1,false);
    }
    else if(SerialPort_Screen->isSerialOpen())
    {
        ui->tabWidget->tabBar()->setTabEnabled(1,true);
        ui->tabWidget->tabBar()->setTabEnabled(0,false);
    }
    else
    {
        ui->tabWidget->tabBar()->setTabEnabled(1,true);
        ui->tabWidget->tabBar()->setTabEnabled(0,true);
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    switch (index)
    {
    case TAB_UDP:

        break;
    case TAB_SERIAL:

        break;
    default:
        break;
    }
}
