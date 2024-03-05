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

    layoutMainVertical->addLayout(layoutInputHorizontalName);
    layoutMainVertical->addLayout(layoutInputHorizontalBoudRate);
    layoutMainVertical->addLayout(layoutInputHorizontalDataBits);
    layoutMainVertical->addLayout(layoutInputHorizontalParity);
    layoutMainVertical->addLayout(layoutInputHorizontalStopBits);
    layoutMainVertical->addLayout(layoutInputHorizontalFlowControl);

    this->setLayout(layoutMainVertical);
}

GUI_RS232settingwindow::~GUI_RS232settingwindow()
{
    qDebug() << "its destructor";
   // isOpenStatus = false;
}

