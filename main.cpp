#include "GUI_MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUI_mainwindow w;
    return a.exec();
}
