#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QTime>
#include <QtGlobal>
//#include <QProcess>
#include <QtDebug>
#include <QRegExpValidator>
#include <client.hpp>
#include <targets.hpp>

//inline char* tocchar(QString str)
//{
//    return const_cast<char*>(str.toStdString().c_str());
//}

namespace Ui {
class MainWindow;
}

//typedef  bool  (*Check)(char*,char*);
//typedef  bool (*Commit)(char*,char*,char*);

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_check_clicked();
    void on_com_clicked();
    void on_parcourir_clicked();
//    void readStdOut();
//    void readStdErr();
    
private:
    Ui::MainWindow *ui;
    svn::Client client;
//    QProcess exes;
    QValidator *validator;
};

#endif // MAINWINDOW_H
