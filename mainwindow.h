#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QLabel>


#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Методы для установки параметров основного окна
    void makeMenuBar();
    void makeMainLayout();

    // Методы для созданий локальных лайаутов и заполнения их
    void makeCitrexDataField();
    void makeALVDataField();
    void makeModeField();
    void makeErrorsField();

private:
    // Основные лайауты
    QHBoxLayout * m_mainHorizontalLayoutUpper;
    QHBoxLayout * m_mainHorizontalLayoutLower;
    QVBoxLayout * m_mainVerticalLayout;

    // Локальные лайауты для каждого из 4х блоков
    QVBoxLayout * m_CirexDataLayoutVertical;
    QHBoxLayout * m_CitrexDataLayoutHorizontal;
    QVBoxLayout * m_ALVDataLayoutVertical;
    QHBoxLayout * m_ALVDataLayoutHorizontal;
    QVBoxLayout * m_ModeLayoutVertical;
    QHBoxLayout * m_ModeLayoutHorizontal;
    QVBoxLayout * m_ErrorsLayoutVertical;
    QHBoxLayout * m_ErrorsLayoutHorizontal;



    // Отладка
    QList<QPushButton*> buttonList;

    // Пункты меню
    QMenu * citrexSetting;
    QMenu * ALVSetting;
    QMenu * ALVTester;

    // Текстовые поля
    QLabel *LabelCitrexData;
    QLabel *LabelALVData;
    QLabel *LabelMode;
    QLabel *LabelErrors;


    QMenuBar *menuBar;

    QWidget *mainWindow;

};
#endif // MAINWINDOW_H

