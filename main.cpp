#include "mainwindow.h"
#include <QFile>
#include <QTime>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("plastique");

    MainWindow w;
    w.show();
    
    return a.exec();
}
