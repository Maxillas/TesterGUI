#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainWindow = new QWidget;
    mainWindow->setWindowTitle("TesterCitrexH4");
    mainWindow->resize(500, 500);

    button1 = new QPushButton("ass" , this);
    for (int i = 0; i < 10; i++){
        buttonList.append(new QPushButton("1" , this));
    }

    m_verticalLayout = new QVBoxLayout(mainWindow);
    m_horizontalLayout = new QHBoxLayout(mainWindow);

    makeMenuBar();
    m_verticalLayout->setMenuBar(menuBar);


    m_horizontalLayout->addWidget(buttonList[0]);
    m_horizontalLayout->addWidget(buttonList[5]);
    m_verticalLayout->addLayout(m_horizontalLayout);



    //m_horizontalLayout->addWidget(buttonList[0]);


    mainWindow->setLayout(m_verticalLayout);


    mainWindow->show();
}

MainWindow::~MainWindow()
{
   delete button1;
   //delete m_verticalLayout;
   //delete m_horizontalLayout;
    delete mainWindow;
}

void MainWindow::makeMenuBar()
{
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


