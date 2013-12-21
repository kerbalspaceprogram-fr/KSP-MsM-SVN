#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QTime>
#include <QtGlobal>
#include <QtDebug>
#include <QRegExpValidator>
#include <client.hpp>
#include <targets.hpp>
#include <context.hpp>



namespace Ui {
class MainWindow;
}



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

    
private:
    Ui::MainWindow *ui;
    svn::Client client;
    svn::Context context;
    QValidator *validator;
};

#endif // MAINWINDOW_H
