#include "mainwindow.h"
#include <QFile>
#include <QTime>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("plastique");
    QFile log("log.txt");
    log.write((QTime::currentTime().toString() + "|||||||||||||||||||||||||||||\n").toStdString().c_str());
    if (!QFile::exists("SharpSvn.dll") || !QFile::exists("svnutils.dll"))
    {
        log.write("SharpSvn.dll missing.");
        QMessageBox::critical(nullptr,"Erreur", "SharpSvn.dll missing. + Local Path : " + QDir::currentPath());
        return -3;
    }

    MainWindow w;
    w.show();
    
    return a.exec();
}
