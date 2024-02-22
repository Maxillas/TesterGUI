#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QAction>


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

    void makeMenuBar();



    QHBoxLayout * m_horizontalLayout;
    QVBoxLayout * m_verticalLayout;
    QList<QPushButton*> buttonList;

    QMenu * citrexSetting;
    QMenu * ALVSetting;
    QMenu * ALVTester;

    //QAction * ;
    QMenuBar *menuBar;


    QPushButton *button1;
    QWidget *mainWindow;

};
#endif // MAINWINDOW_H

