#include "GUI_MainWindow.h"

GUI_mainwindow::GUI_mainwindow(QWidget *parent):
    QWidget(parent)
{
    //citrexH4 = new CitrexH4();
    //Создаем объект цитрикса при открытии окна



    this->setWindowTitle("TesterCitrexH4");
    this->resize(800, 600);

    /*
    // Массив кнопок для отладки
    for (int i = 0; i < 5; i++){
        buttonList.append(new QPushButton("1" , mainWindow));
    }

    for (int i = 0; i < 5; i++){
        buttonList.append(new QPushButton("2" , mainWindow));
    }
*/

    makeMainLayout();
    makeMenuBar();
    m_mainVerticalLayout->setMenuBar(menuBar);

    //Вызов методов для создания персональных лайаутов
    makeCitrexDataField();
    makeALVDataField();
    makeModeField();
    makeErrorsField();
    //Установка в горизонтальные лайауты локальные лайауты
    m_mainHorizontalLayoutUpper->addLayout(m_CitrexDataLayoutVertical);
    m_mainHorizontalLayoutUpper->addLayout(m_ALVDataLayoutVertical);
    m_mainHorizontalLayoutLower->addLayout(m_ModeLayoutVertical);
    m_mainHorizontalLayoutLower->addLayout(m_ErrorsLayoutVertical);
    //Добавление горизонтальных лайаутов в основной
    m_mainVerticalLayout->addLayout(m_mainHorizontalLayoutUpper);
    m_mainVerticalLayout->addLayout(m_mainHorizontalLayoutLower);
    //Установка лайаута в основное окно
    this->setLayout(m_mainVerticalLayout);
    this->show();


    //this->setAttribute(Qt::WA_DeleteOnClose);

}

GUI_mainwindow::~GUI_mainwindow()
{
    qDebug() << "its main destructor";
    //rs232SettingWindow->close();
    //delete rs232SettingWindow;
    if (rs232SettingWindow != nullptr){
        delete rs232SettingWindow;
        rs232SettingWindow = nullptr;
    }

}

void GUI_mainwindow::makeMenuBar()
{
    //создание меню
    citrexSetting = new QMenu("&Настройки Citrex", this);
    ALVSetting = new QMenu("&Установка параматров ИВЛ", this);
    ALVTester = new QMenu("&Параметры тестирования", this);
    RS232Setting = new QMenu("Настройка &RS232", this);

    citrexSetting->addAction("Установка параметров");
    citrexSetting->addAction("Ex&it", this, SLOT(close()));

    RS232Setting->addAction("Настройки подключения", this, SLOT(makeRS232SettingWindow()));
    RS232Setting->addAction("Подключиться", this, SLOT(connectRS232()));
    RS232Setting->addAction("Отключиться", this, SLOT(disconnectRS232()));


    menuBar = new QMenuBar(this);
    menuBar->addMenu(citrexSetting);
    menuBar->addMenu(ALVSetting);
    menuBar->addMenu(ALVTester);
    menuBar->addMenu(RS232Setting);


}


void GUI_mainwindow::makeMainLayout()
{
    // Создание разметки основного окна
    m_mainVerticalLayout = new QVBoxLayout();
    m_mainHorizontalLayoutUpper = new QHBoxLayout();
    m_mainHorizontalLayoutLower = new QHBoxLayout();
}

void GUI_mainwindow::makeCitrexDataField()
{
    // Создание разметки левого верхнего угла (CitrexData)

    m_CitrexDataLayoutVertical = new QVBoxLayout();
    m_CitrexDataLayoutHorizontal = new QHBoxLayout();
    PsupCitrex = new QLabel("Psup from Citrex", this);
    PEEPCitrex = new QLabel("PEEP from Citrex", this);
    LabelCitrexData = new QLabel("Citrex Data", this);
    LabelCitrexData->setAlignment(Qt::AlignCenter);
    LabelCitrexData->setFrameShape(QFrame::Panel);
    LabelCitrexData->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    LabelCitrexData->setFixedHeight(70);

    m_CitrexDataLayoutVertical->setAlignment(Qt::AlignTop);
    m_CitrexDataLayoutVertical->addWidget(LabelCitrexData);
    m_CitrexDataLayoutVertical->addWidget(PsupCitrex);
    m_CitrexDataLayoutVertical->addWidget(PEEPCitrex);
    m_CitrexDataLayoutVertical->addLayout(m_CitrexDataLayoutHorizontal);


}

void GUI_mainwindow::makeALVDataField()
{

    // Создание разметки правого верхнего угла (ALVData)
    LabelALVData = new QLabel(this);
    LabelALVData->setText("ALV Data");
    LabelALVData->setAlignment(Qt::AlignCenter);
    LabelALVData->setFrameShape(QFrame::Panel);
    LabelALVData->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    LabelALVData->setFixedHeight(70);


    m_ALVDataLayoutVertical = new QVBoxLayout();
    m_ALVDataLayoutHorizontal = new QHBoxLayout();


    m_ALVDataLayoutVertical->setAlignment(Qt::AlignTop);

    m_ALVDataLayoutVertical->addWidget(LabelALVData);

    //m_ALVDataLayoutVertical->addWidget(buttonList[0]);
    //m_ALVDataLayoutVertical->addWidget(buttonList[1]);

    m_ALVDataLayoutVertical->addLayout(m_ALVDataLayoutHorizontal);

}

void GUI_mainwindow::makeModeField()
{

    LabelMode = new QLabel(this);
    LabelMode->setText("Manual Edit");
    LabelMode->setAlignment(Qt::AlignCenter);
    LabelMode->setFrameShape(QFrame::Panel);
    LabelMode->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    LabelMode->setFixedHeight(70);

    m_ModeLayoutVertical = new QVBoxLayout();
    m_ModeLayoutHorizontal = new QHBoxLayout();

    m_ModeLayoutVertical->setAlignment(Qt::AlignTop);
    m_ModeLayoutVertical->addWidget(LabelMode);

    m_ModeLayoutVerticalInternalLeft = new QVBoxLayout();
    m_ModeLayoutVerticalInternalRight = new QVBoxLayout();

    LabelModePSup = new QLabel("Psup (см/H2O)", this);
    LabelModePEEP = new QLabel("Введите PEEP (Па)", this);
    LabelModePvar = new QLabel("Введите Pvar (%)", this);
    SpinBoxModePsup = new QDoubleSpinBox(this);
    SpinBoxModePsup->setSingleStep(0.1);
    SpinBoxModePsup->setMaximum(150);
    SpinBoxModePEEP = new QDoubleSpinBox(this);
    SpinBoxModePEEP->setSingleStep(0.1);
    SpinBoxModePEEP->setMaximum(150);
    SpinBoxModePvar = new QDoubleSpinBox(this);
    SpinBoxModePvar->setMaximum(100);


    m_ModeLayoutVerticalInternalLeft->addWidget(LabelModePSup);
    m_ModeLayoutVerticalInternalLeft->addWidget(LabelModePEEP);
    m_ModeLayoutVerticalInternalLeft->addWidget(LabelModePvar);
    m_ModeLayoutVerticalInternalRight->addWidget(SpinBoxModePsup);
    m_ModeLayoutVerticalInternalRight->addWidget(SpinBoxModePEEP);
    m_ModeLayoutVerticalInternalRight->addWidget(SpinBoxModePvar);

    m_ModeLayoutHorizontal->addLayout(m_ModeLayoutVerticalInternalLeft);
    m_ModeLayoutHorizontal->addLayout(m_ModeLayoutVerticalInternalRight);

    m_ModeLayoutVertical->addLayout(m_ModeLayoutHorizontal);


}

void GUI_mainwindow::makeErrorsField()
{

    LabelErrors = new QLabel(this);
    LabelErrors->setText("Errors");
    LabelErrors->setAlignment(Qt::AlignCenter);
    LabelErrors->setFrameShape(QFrame::Panel);
    LabelErrors->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    LabelErrors->setFixedHeight(70);



    m_ErrorsLayoutVertical = new QVBoxLayout();
    m_ErrorsLayoutHorizontal = new QHBoxLayout();


    m_ErrorsLayoutVertical->setAlignment(Qt::AlignTop);

    m_ErrorsLayoutVertical->addWidget(LabelErrors);

   // m_ErrorsLayoutVertical->addWidget(buttonList[7]);
    //m_ErrorsLayoutVertical->addWidget(buttonList[8]);

    //m_ErrorsLayoutVertical->addLayout(m_ModeLayoutHorizontal);
}

void GUI_mainwindow::makeRS232SettingWindow()
{
    if(rs232SettingWindow == nullptr){
        rs232SettingWindow = new GUI_RS232settingwindow();
        connect(rs232SettingWindow, SIGNAL(destroyed(QObject*)), this, SLOT(setRS232SettingWindowPtrInNull()));
        return;
    }
    QMessageBox::critical(this, "Error", "RS232 Setting window already open");
}

void GUI_mainwindow::setRS232SettingWindowPtrInNull()
{
    rs232SettingWindow = nullptr;
}

void GUI_mainwindow::connectRS232()
{
    qDebug() << "RS232 Connect";
    //citrexH4->createRS232Port;
}

void GUI_mainwindow::disconnectRS232()
{
    qDebug() << "RS232 Disconnect";
}

void GUI_mainwindow::closeEvent(QCloseEvent *event)
{
    //Переопределенный метод для закрытия дополнительно окна при закрытии основного
    if (rs232SettingWindow != nullptr) {
        delete rs232SettingWindow;
        rs232SettingWindow = nullptr;
    }
}
