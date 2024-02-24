#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainWindow = new QWidget;
    mainWindow->setWindowTitle("TesterCitrexH4");
    mainWindow->resize(500, 500);

    // Массив кнопок для отладки
    for (int i = 0; i < 5; i++){
        buttonList.append(new QPushButton("1" , this));
    }

    for (int i = 0; i < 5; i++){
        buttonList.append(new QPushButton("2" , this));
    }


    makeMainLayout();
    makeMenuBar();
    m_mainVerticalLayout->setMenuBar(menuBar);

    makeCitrexDataField();
    makeALVDataField();

    m_mainHorizontalLayoutUpper->addLayout(m_CirexDataLayoutVertical);
    m_mainHorizontalLayoutUpper->addLayout(m_ALVDataLayoutVertical);

    //m_mainHorizontalLayoutUpper->addWidget(buttonList[8]);

    m_mainHorizontalLayoutLower->addWidget(buttonList[5]);
    m_mainHorizontalLayoutLower->addWidget(buttonList[6]);

    //m_horizontalLayoutUpper->addLayout(); // добавить лайаут из метода makeCitrexDataField()
    //m_horizontalLayoutUpper->addLayout(); // добавить лайаут из метода makeALVDataField()

    //m_horizontalLayoutLower->addLayout(); // добавить лайаут из метода makeModeField()
    //m_horizontalLayoutLower->addLayout(); // добавить лайаут из метода makeErrorsField()


    m_mainVerticalLayout->addLayout(m_mainHorizontalLayoutUpper);
    m_mainVerticalLayout->addLayout(m_mainHorizontalLayoutLower);


    //m_horizontalLayout->addWidget(buttonList[0]);


    mainWindow->setLayout(m_mainVerticalLayout);


    mainWindow->show();
}

MainWindow::~MainWindow()
{
   // Спросить про необходимость удаление объектов в деструкторе
   //delete m_verticalLayout;
   //delete m_horizontalLayout;
    delete mainWindow;
}

void MainWindow::makeMenuBar()
{
    //создание меню
    citrexSetting = new QMenu("&Настройки Citrex");
    ALVSetting = new QMenu("&Установка параматров ИВЛ");
    ALVTester = new QMenu("&Параметры тестирования");

    citrexSetting->addAction("Ex&it", mainWindow, SLOT(close()));
    citrexSetting->addAction("E&it", mainWindow, SLOT(close()));


    menuBar = new QMenuBar(this);
    menuBar->addMenu(citrexSetting);
    menuBar->addMenu(ALVSetting);
    menuBar->addMenu(ALVTester);


}


void MainWindow::makeMainLayout()
{
    // Создание разметки основного окна
    m_mainVerticalLayout = new QVBoxLayout(mainWindow);
    m_mainHorizontalLayoutUpper = new QHBoxLayout(mainWindow);
    m_mainHorizontalLayoutLower = new QHBoxLayout(mainWindow);
}

void MainWindow::makeCitrexDataField()
{
    // Создание разметки левого верхнего угла (CitrexData)
    LabelCitrexData = new QLabel("Citrex Data");
    LabelCitrexData->setAlignment(Qt::AlignCenter);
    LabelCitrexData->setFrameShape(QFrame::Panel);

    m_CirexDataLayoutVertical = new QVBoxLayout();
    m_CitrexDataLayoutHorizontal = new QHBoxLayout();
    PsupCitrex = new QLabel("Psup from Citrex");
    PEEPCitrex = new QLabel("PEEP from Citrex");


    m_CirexDataLayoutVertical->addWidget(LabelCitrexData);   
    m_CirexDataLayoutVertical->addWidget(PsupCitrex);
    m_CirexDataLayoutVertical->addWidget(PEEPCitrex);


    m_CirexDataLayoutVertical->addLayout(m_CitrexDataLayoutHorizontal);

}

void MainWindow::makeALVDataField()
{

    // Создание разметки правого верхнего угла (ALVData)
    LabelALVData = new QLabel("ALV Data");
    LabelALVData->setAlignment(Qt::AlignCenter);
    LabelALVData->setFrameShape(QFrame::Panel);

    m_ALVDataLayoutVertical = new QVBoxLayout();
    m_ALVDataLayoutHorizontal = new QHBoxLayout();


    m_ALVDataLayoutVertical->addWidget(LabelALVData);
    m_ALVDataLayoutVertical->addWidget(buttonList[0]);
    m_ALVDataLayoutVertical->addWidget(buttonList[1]);

    m_ALVDataLayoutVertical->addLayout(m_ALVDataLayoutHorizontal);

}


