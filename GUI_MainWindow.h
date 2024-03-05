#ifndef GUI_MAINWINDOW_H
#define GUI_MAINWINDOW_H

//#include <QMainWindow>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QComboBox>
//#include <QSerialPort>
#include <GUI_RS232SettingWindow.h>


#include <QDebug>


//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

class GUI_mainwindow : public QWidget
{
    Q_OBJECT
public:
    explicit GUI_mainwindow(QWidget *parent = nullptr);
    ~GUI_mainwindow();

    // Методы для установки параметров основного окна
    void makeMenuBar();
    void makeMainLayout();

    // Методы для созданий локальных лайаутов и заполнения их
    void makeCitrexDataField();
    void makeALVDataField();
    void makeModeField();
    void makeErrorsField();
    void closeEvent(QCloseEvent *event) override;
private slots:
    void makeRS232SettingWindow();
    void setRS232SettingWindowPtrInNull();
    void connectRS232();
    void disconnectRS232();

private:
   // QSerialPort * rs232Ptr;


    // Основные лайауты
    QHBoxLayout * m_mainHorizontalLayoutUpper;
    QHBoxLayout * m_mainHorizontalLayoutLower;
    QVBoxLayout * m_mainVerticalLayout;

    // Локальные лайауты для каждого из 4х блоков
    QVBoxLayout * m_CitrexDataLayoutVertical;
    QHBoxLayout * m_CitrexDataLayoutHorizontal;
    QVBoxLayout * m_ALVDataLayoutVertical;
    QHBoxLayout * m_ALVDataLayoutHorizontal;
    QVBoxLayout * m_ModeLayoutVertical;
    QVBoxLayout * m_ModeLayoutVerticalInternalLeft;
    QVBoxLayout * m_ModeLayoutVerticalInternalRight;
    QHBoxLayout * m_ModeLayoutHorizontal;
    QVBoxLayout * m_ErrorsLayoutVertical;
    QHBoxLayout * m_ErrorsLayoutHorizontal;

    //QSpinBox P

    // Отладка
    QList<QPushButton*> buttonList;

    // Пункты меню
    QMenu * citrexSetting;
    QMenu * ALVSetting;
    QMenu * ALVTester;
    QMenu * RS232Setting;

    // Текстовые поля
    QLabel *LabelCitrexData;
    QLabel *LabelALVData;

    QLabel *LabelMode;
    QLabel *LabelModePSup;
    QLabel *LabelModePEEP;
    QLabel *LabelModePvar;

    QLabel *LabelErrors;

    QLabel *PsupCitrex;
    QLabel *PEEPCitrex;

    QDoubleSpinBox * SpinBoxModePsup;
    QDoubleSpinBox * SpinBoxModePEEP;
    QDoubleSpinBox * SpinBoxModePvar;


    QMenuBar *menuBar;

    //QWidget *mainWindow;

    GUI_RS232settingwindow * rs232SettingWindow = nullptr;
};
#endif // GUI_MAINWINDOW_H

