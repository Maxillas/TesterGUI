#include "GUI_CitrexSettingWindow.h"

GUI_CitrexSettingWindow::GUI_CitrexSettingWindow(QWidget *parent)
{
    this->setWindowTitle("Citrex Setting");
    this->setFixedSize(400, 300);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->show();

    layoutInputHorizontalType = new QHBoxLayout();
    layoutInputHorizontalDisplay = new QHBoxLayout();
    layoutInputHorizontalTouch = new QHBoxLayout();
    layoutMainVertical = new QVBoxLayout();

    typeDataLabel = new QLabel("Format of data receive (IMT, ASCII):", this);
    typeDataComboBox = new QComboBox(this);
    typeDataComboBox->addItem("ASCII");
    typeDataComboBox->addItem("IMT");

    btnCitrexInitiate = new QPushButton("Initialization", this);
    btnLockDisplay = new QPushButton("Lock Citrex Display", this);
    btnUnlockDisplay = new QPushButton("Unlock Citrex Display", this);
    btnLockTouch = new QPushButton("Lock Citrex touchscreen", this);
    btnUnlockTouch = new QPushButton("Unlock Citrex touchscreen", this);

    layoutInputHorizontalType->addWidget(typeDataLabel);
    layoutInputHorizontalType->addWidget(typeDataComboBox);
    layoutInputHorizontalDisplay->addWidget(btnLockDisplay);
    layoutInputHorizontalDisplay->addWidget(btnUnlockDisplay);
    layoutInputHorizontalTouch->addWidget(btnLockTouch);
    layoutInputHorizontalTouch->addWidget(btnUnlockTouch);

    layoutMainVertical->addLayout(layoutInputHorizontalType);
    layoutMainVertical->addWidget(btnCitrexInitiate);
    layoutMainVertical->addLayout(layoutInputHorizontalDisplay);
    layoutMainVertical->addLayout(layoutInputHorizontalTouch);

    this->setLayout(layoutMainVertical);
}

