#include "setup_ip.h"
#include "ui_setup_ip.h"

SetUp_IP::SetUp_IP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetUp_IP)
{
    ui->setupUi(this);

    NetworkFileName = QApplication::applicationDirPath()+QDir::separator()+"network.txt";
    setModal(true);
    Init_QMbx_KeyBoard();
    ui->tbn_NetworkSettings->setVisible(true);
    ui->tbn_Apply->setVisible(true);
    ui->frame_3->setVisible(true);

    UDP_Comm = new UdpCommunication(this);
    connect(UDP_Comm,SIGNAL(ProcessUdpRxData(QByteArray)),this,SIGNAL(ProcessUdpRxData(QByteArray)));
}

SetUp_IP::~SetUp_IP()
{
    delete ui;
}

void SetUp_IP::Init_QMbx_KeyBoard()
{
    loadDataFromFile(NetworkFileName);

    ui->lineEdit_SPortNum->setMaxLength(10);
    ui->lineEdit_DPortNum->setMaxLength(10);
    QRegExp ipRegex("^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");  // Matches each octet of an IP address
    ipValidator = new QRegExpValidator(ipRegex, this);
    ui->lineEdit_Sip->setValidator(ipValidator);
    ui->lineEdit_Dip->setValidator(ipValidator);
    setWindowFlags(Qt::FramelessWindowHint);

}


void SetUp_IP::on_tbn_Apply_clicked()
{
//    saveDatatoFile(NetworkFileName);
//    UDP_Comm->Reconnect_UDP();
}

void SetUp_IP::on_tbn_ClosePort_clicked()
{
    UDP_Comm->closePort();
}


void SetUp_IP::saveDatatoFile(const QString &fileName )
{
    QString portnu = ui->lineEdit_SPortNum->text();


        ipSetting[SOURCE].Ip_Address  = ui->lineEdit_Sip->text();
        ipSetting[SOURCE].PortNumber =portnu.toInt(); //ui->lineEdit_SPortNum->text().toShort();

        ipSetting[DESTINATION].Ip_Address  = ui->lineEdit_Dip->text();
        ipSetting[DESTINATION].PortNumber = ui->lineEdit_DPortNum->text().toInt();

        Application.Source_address = QHostAddress(ipSetting[SOURCE].Ip_Address);
        Application.Source_PortNumber = ipSetting[SOURCE].PortNumber;
        Application.Destination_address = QHostAddress(ipSetting[DESTINATION].Ip_Address);
        Application.Destination_PortNumber = ipSetting[DESTINATION].PortNumber;

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);

        out << ipSetting[SOURCE].Ip_Address << "," << ipSetting[SOURCE].PortNumber << ",";
        out << ipSetting[DESTINATION].Ip_Address << "," << ipSetting[DESTINATION].PortNumber << ",";
        out<<"\n";
        file.close();
    }
//    qDebug()<<ipSetting[DESTINATION].PortNumber<<"----"<<ipSetting[SOURCE].PortNumber<<portnu.toInt();
    loadDataFromFile(fileName);

}

void SetUp_IP::loadDataFromFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.exists()) {
        qWarning() << "File does not exist: " << fileName;


//        emit load_ip();
        fileNotFoundFlag = true;
        saveDatatoFile(fileName);
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file: " << fileName;
        return;
    }

    QTextStream in(&file);

    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        ipSetting[SOURCE].Ip_Address = fields[0];
        ipSetting[SOURCE].PortNumber = fields[1].toInt();
        ipSetting[DESTINATION].Ip_Address = fields[2];
        ipSetting[DESTINATION].PortNumber = fields[3].toInt();
    }
    Application.Source_address = QHostAddress(ipSetting[SOURCE].Ip_Address);
    Application.Source_PortNumber = ipSetting[SOURCE].PortNumber;
    Application.Destination_address = QHostAddress(ipSetting[DESTINATION].Ip_Address);
    Application.Destination_PortNumber = ipSetting[DESTINATION].PortNumber;



    file.close();

    ui->lineEdit_Sip->setText(ipSetting[SOURCE].Ip_Address );
    ui->lineEdit_SPortNum->setText(QString::number(ipSetting[SOURCE].PortNumber));

    ui->lineEdit_Dip->setText(ipSetting[DESTINATION].Ip_Address );
    ui->lineEdit_DPortNum->setText(QString::number(ipSetting[DESTINATION].PortNumber));

}


void SetUp_IP::on_tbn_NetworkSettings_clicked()
{
#if defined(Q_OS_WIN)
    // Windows: open Network & Internet settings
    QProcess::startDetached("control.exe", QStringList() << "ncpa.cpl");

#elif defined(Q_OS_MAC)
    // macOS: open Network preferences
    QProcess::startDetached("open", QStringList() << "/System/Library/PreferencePanes/Network.prefPane");

#elif defined(Q_OS_LINUX)
    // Linux: GNOME example (adjust if using KDE or others)
    QProcess::startDetached("gnome-control-center", QStringList() << "network");

#else
    // Fallback: do nothing or show a message
    qDebug() << "Network settings not supported on this OS.";
#endif
}
void SetUp_IP::loadNetworkData(void)
{
    loadDataFromFile(NetworkFileName);
}

void SetUp_IP::SendUdpData(QByteArray data)
{
    UDP_Comm->sendData(data);
}


QStringList SetUp_IP::getInterfaceWithIP()
{
    QStringList list;

    const auto interfaces = QNetworkInterface::allInterfaces();
    for (const QNetworkInterface &iface : interfaces)
    {
        // Filter only active, non-loopback interfaces
        if (!(iface.flags() & QNetworkInterface::IsUp) ||
            !(iface.flags() & QNetworkInterface::IsRunning) ||
            (iface.flags() & QNetworkInterface::IsLoopBack))
            continue;

        for (const QNetworkAddressEntry &entry : iface.addressEntries())
        {
            QHostAddress ip = entry.ip();
            if (ip.protocol() == QAbstractSocket::IPv4Protocol)
            {
                list << QString("%1 : %2")
                        .arg(iface.humanReadableName())
                        .arg(ip.toString());
            }
        }
    }

    return list;
}
void SetUp_IP::on_btnShowIPs_clicked()
{
    QStringList list = getInterfaceWithIP();

    QString message;
    if (list.isEmpty())
        message = "No Active Network Interface Found!";
    else
        message = list.join("\n");

    QMessageBox::information(this,
                             "Available IP Addresses",
                             message);
}
void SetUp_IP::on_tbn_Apply_clicked(bool checked)
{
    ui->tbn_Apply->setChecked(checked);
    if(checked)
    {
        saveDatatoFile(NetworkFileName);
        UDP_Comm->Reconnect_UDP();
         ui->tbn_Apply->setText("CLOSE PORT");
        ui->tbn_Apply->setStyleSheet(
            QString("background-color: %1; color: white; border-radius: 5px;")
            .arg(Application.getBlinkColor(Application.currentTheme).name())
        );
    }
    else
    {
        on_tbn_ClosePort_clicked();
        ui->tbn_Apply->setText("OPEN PORT");
        ui->tbn_Apply->setStyleSheet("");
    }
}
