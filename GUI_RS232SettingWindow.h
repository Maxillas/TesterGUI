#ifndef GUI_RS232222SETTINGWINDOW_H
#define GUI_RS232222SETTINGWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>


class GUI_RS232settingwindow: public QWidget
{
    Q_OBJECT
public:
    explicit GUI_RS232settingwindow(QWidget *parent = nullptr);
    ~GUI_RS232settingwindow();

private:
    QHBoxLayout* layoutInputHorizontalName;
    QHBoxLayout* layoutInputHorizontalBoudRate;
    QHBoxLayout* layoutInputHorizontalDataBits;
    QHBoxLayout* layoutInputHorizontalParity;
    QHBoxLayout* layoutInputHorizontalStopBits;
    QHBoxLayout* layoutInputHorizontalFlowControl;


    QVBoxLayout* layoutMainVertical;
    QLabel* portNameLabel;
    QLabel* portBoudRateLabel;
    QLabel* portDataBitsLabel;
    QLabel* portParityLabel;
    QLabel* portStopBitsLabel;
    QLabel* portFlowControlLabel;
    QPushButton* btnConnectToPort;

    QLineEdit* portNameLineEdit;

    QComboBox* portBoudRateComboBox;
    QComboBox* portDataBitsComboBox;
    QComboBox* portParityComboBox;
    QComboBox* portStopBitsComboBox;
    QComboBox* portFlowControlComboBox;

};

#endif // GUI_RS232222SETTINGWINDOW_H
