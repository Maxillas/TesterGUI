#ifndef GUI_RS232222SETTINGWINDOW_H
#define GUI_RS232222SETTINGWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>


class GUI_RS232SettingWindow: public QWidget
{
    Q_OBJECT
public:
    explicit GUI_RS232SettingWindow(QWidget *parent = nullptr);
    //explicit GUI_RS232SettingWindow(QWidget *parent = nullptr, CitrexH4 & citrexLink);
public slots:
   void setRS232PortSetting(); //внутри массив с настройками, которые ввел пользователь
   void setRS232PortSettingDefault(); //внутри стандартные настройки


private:
    QHBoxLayout* layoutInputHorizontalName;
    QHBoxLayout* layoutInputHorizontalBoudRate;
    QHBoxLayout* layoutInputHorizontalDataBits;
    QHBoxLayout* layoutInputHorizontalParity;
    QHBoxLayout* layoutInputHorizontalStopBits;
    QHBoxLayout* layoutInputHorizontalFlowControl;
    QHBoxLayout* layoutInputHorizontalButtons;


    QVBoxLayout* layoutMainVertical;
    QLabel* portNameLabel;
    QLabel* portBoudRateLabel;
    QLabel* portDataBitsLabel;
    QLabel* portParityLabel;
    QLabel* portStopBitsLabel;
    QLabel* portFlowControlLabel;
    QPushButton* btnAcceptSetting;
    QPushButton* btnCancelSetting;
    //QPushButton* btnConnectToPort;
    //QPushButton* btnDisconnectFromPort;

    QLineEdit* portNameLineEdit;

    QComboBox* portBoudRateComboBox;
    QComboBox* portDataBitsComboBox;
    QComboBox* portParityComboBox;
    QComboBox* portStopBitsComboBox;
    QComboBox* portFlowControlComboBox;

    //CitrexH4& citrexH4Ptr; //ссылка на класс цитрекса для настройки порта

};

#endif // GUI_RS232222SETTINGWINDOW_H
