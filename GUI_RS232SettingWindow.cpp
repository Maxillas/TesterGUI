#include "GUI_RS232SettingWindow.h"

GUI_RS232settingwindow::GUI_RS232settingwindow(QWidget *parent):
    QWidget(parent)

{
    this->setWindowTitle("RS232 Port Setting");
    this->resize(400, 300);
    this->show();
    this->setAttribute(Qt::WA_DeleteOnClose);
    layoutInputHorizontalName = new QHBoxLayout();
    layoutInputHorizontalBoudRate = new QHBoxLayout();
    layoutInputHorizontalDataBits = new QHBoxLayout();
    layoutInputHorizontalParity = new QHBoxLayout();
    layoutInputHorizontalStopBits = new QHBoxLayout();
    layoutInputHorizontalFlowControl = new QHBoxLayout();
    layoutInputHorizontalButtons = new QHBoxLayout();
    layoutMainVertical = new QVBoxLayout();

    portNameLabel = new QLabel("RS232 Port Name: ", this);
    portBoudRateLabel = new QLabel("RS232 Port Speed (Baud): ", this);
    portDataBitsLabel = new QLabel("Data Bits:", this);
    portParityLabel = new QLabel("Parity:", this);
    portStopBitsLabel = new QLabel("StopBits:", this);
    portFlowControlLabel = new QLabel("Flow Control", this);

    portNameLineEdit = new QLineEdit("ttyUSB0", this);

    portBoudRateComboBox = new QComboBox(this);
    portBoudRateComboBox->addItem("9600");
    portBoudRateComboBox->addItem("19200");
    portBoudRateComboBox->addItem("38400");
    portBoudRateComboBox->addItem("57600");
    portBoudRateComboBox->addItem("115200");
    portDataBitsComboBox= new QComboBox(this);
    portDataBitsComboBox->addItem("10");
    portDataBitsComboBox->addItem("8");
    portDataBitsComboBox->addItem("6");
    portDataBitsComboBox->addItem("4");
    portDataBitsComboBox->addItem("2");
    portParityComboBox = new QComboBox(this);
    portParityComboBox->addItem("Yes");
    portParityComboBox->addItem("No");
    portStopBitsComboBox = new QComboBox(this);
    portStopBitsComboBox->addItem("Yes");
    portStopBitsComboBox->addItem("No");
    portFlowControlComboBox = new QComboBox(this);
    portFlowControlComboBox->addItem("Yes");
    portFlowControlComboBox->addItem("No");

    //btnConnectToPort = new QPushButton("Connect");
    //btnDisconnectFromPort = new QPushButton("Disconnect");
    btnAcceptSetting = new QPushButton("Accept");
    btnCancelSetting = new QPushButton("Cancel");

    layoutInputHorizontalName->addWidget(portNameLabel);
    layoutInputHorizontalName->addWidget(portNameLineEdit);
    layoutInputHorizontalBoudRate->addWidget(portBoudRateLabel);
    layoutInputHorizontalBoudRate->addWidget(portBoudRateComboBox);
    layoutInputHorizontalDataBits->addWidget(portDataBitsLabel);
    layoutInputHorizontalDataBits->addWidget(portDataBitsComboBox);
    layoutInputHorizontalParity->addWidget(portParityLabel);
    layoutInputHorizontalParity->addWidget(portParityComboBox);
    layoutInputHorizontalStopBits->addWidget(portStopBitsLabel);
    layoutInputHorizontalStopBits->addWidget(portStopBitsComboBox);
    layoutInputHorizontalFlowControl->addWidget(portFlowControlLabel);
    layoutInputHorizontalFlowControl->addWidget(portFlowControlComboBox);
    layoutInputHorizontalButtons->addWidget(btnAcceptSetting);
    layoutInputHorizontalButtons->addWidget(btnCancelSetting);

    layoutMainVertical->addLayout(layoutInputHorizontalName);
    layoutMainVertical->addLayout(layoutInputHorizontalBoudRate);
    layoutMainVertical->addLayout(layoutInputHorizontalDataBits);
    layoutMainVertical->addLayout(layoutInputHorizontalParity);
    layoutMainVertical->addLayout(layoutInputHorizontalStopBits);
    layoutMainVertical->addLayout(layoutInputHorizontalFlowControl);
    layoutMainVertical->addLayout(layoutInputHorizontalButtons);

    //layoutMainVertical->addWidget(btnConnectToPort);
    //layoutMainVertical->addWidget(btnDisconnectFromPort);

    this->setLayout(layoutMainVertical);
    int a = 10;
    int b = 20;
    connect(btnAcceptSetting, SIGNAL(clicked(bool)), this, SLOT(setRS232PortSetting())); // устанавливает настройки
    connect(btnCancelSetting, SIGNAL(clicked(bool)), this, SLOT(setRS232PortSettingDefault())); // по умолчанию
}

GUI_RS232settingwindow::~GUI_RS232settingwindow()
{
    qDebug() << "its destructor";
    // isOpenStatus = false;
}

void GUI_RS232settingwindow::setRS232PortSetting()
{
    //citrexH4Ptr.setRS232setting(a);
    //Реализовать этот метод в классе citrex, сохраняем настройки, но порт НЕ СОЗДАЕМ
    //Принимаем значение,
    qDebug() << "это от пользователя установки";
    this->close();
}

void GUI_RS232settingwindow::setRS232PortSettingDefault()
{
    //citrexH4Ptr.setRS232setting(a); //a - Будет дефолтными!
    //Реализовать этот метод в классе citrex, сохраняем настройки, но порт НЕ СОЗДАЕМ
    //дефолтные значения устанавливаем
    qDebug() << "это дефолтные";
    this->close();
}

