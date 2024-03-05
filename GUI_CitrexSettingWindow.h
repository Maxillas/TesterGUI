#ifndef GUI_CitrexSettingWindow_H
#define GUI_CitrexSettingWindow_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>

class GUI_CitrexSettingWindow: public QWidget
{
    Q_OBJECT
public:
    explicit GUI_CitrexSettingWindow(QWidget *parent = nullptr);
    //explicit GUI_RS232settingwindow(QWidget *parent = nullptr, CitrexH4 & citrexLink);
    //~GUI_CitrexSettingWindow();
public slots:


private:
    QHBoxLayout* layoutInputHorizontalType;
    QHBoxLayout* layoutInputHorizontalDisplay;
    QHBoxLayout* layoutInputHorizontalTouch;
    QVBoxLayout* layoutMainVertical;

    QLabel* typeDataLabel;
    QComboBox* typeDataComboBox;
    QPushButton* btnCitrexInitiate;
    QPushButton* btnLockDisplay;
    QPushButton* btnUnlockDisplay;
    QPushButton* btnLockTouch;
    QPushButton* btnUnlockTouch;

};

#endif // GUI_CitrexSettingWindow_H
