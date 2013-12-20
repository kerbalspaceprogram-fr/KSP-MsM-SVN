#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) /*,exes(this),*/ /*lib("svnutils.dll",this)*/
{

    ui->setupUi(this);
//    QMessageBox::critical(this, "Erreur", QString(QChar((int)lib.load())) + "  " + lib.errorString());
    validator = new QRegExpValidator(QRegExp("((http:\\/\\/|https:\\/\\/)(www.)?(([a-zA-Z0-9-]){2,}\\.){1,4}([a-zA-Z]){2,6}(\\/([a-zA-Z-_\\/\\.0-9#:?=&;,]*)?)?)"), this);
    ui->url->setValidator(validator);
//    connect(&exes,SIGNAL(readyReadStandardOutput()),this,SLOT(readStdOut()));
//    connect(&exes,SIGNAL(readyReadStandardError()),this,SLOT(readStdErr()));
}

void MainWindow::on_check_clicked()
{
//    if(!ui->url->text().isEmpty() && !ui->path->text().isEmpty())
//    {
//    QStringList args = {ui->url->text(), "\"" + ui->path->text() + "\""};

//    exes.start("SVNCheck.exe", args);
//    if(exes.exitCode())
//    {
//        QMessageBox::critical(this, "Erreur", "Une erreur s'est produite lors du checkout. Code : " + QString::number(exes.exitCode()));
//    }
//    else
//        QMessageBox::information(this, "Checkout Réussi", "Le checkout a réussi !" + QString::number(exes.exitCode()));
//    }
//    else
//        QMessageBox::critical(this,"Erreur","Veuillez spécifier l\'url et le répertoire de la save.");

    try {
    client.checkout(ui->url->text().toStdString().c_str(),svn::Path(ui->path->text().toStdString()),-1,true);
    }
    catch (svn::ClientException & error)
    {
        QMessageBox::critical(this, "Erreur", error.message());
    }

}
void MainWindow::on_com_clicked()
{
//    if (!ui->path->text().isEmpty())
//    {
//    exes.start("SVNUpdt", QStringList(ui->path->text()));
//    if(exes.exitCode())
//    {
//        QMessageBox::critical(this, "Erreur", "Une erreur s'est produite lors du commit, veuillez contacter l'auteur du programme (Stellaris sur Ksp-Fr). Code : " + QString::number(exes.exitCode()));
//    }
//    else
//        QMessageBox::information(this, "Commit Réussi", "Le commit a réussi !");
//    }
//    else
//         QMessageBox::critical(this,"Erreur","Veuillez spécifier le répertoire de la save.");
try {
        client.commit(svn::Targets(ui->path->text().toStdString().c_str()),std::string("Commit from KSP MsM (SVN) at" + QTime::currentTime().toString(Qt::TextDate).toStdString()).c_str(),false);

    }
    catch (svn::ClientException & error)
    {
        QMessageBox::critical(this, "Erreur", error.message());
    }
}

void MainWindow::on_parcourir_clicked()
{
    ui->path->setText(QFileDialog::getExistingDirectory(this));
}
//void MainWindow::readStdOut(){
//    qDebug()<< exes.readAllStandardOutput();
//    QFile log("log.txt");

//    log.write(exes.readAllStandardOutput());
//}

//void MainWindow::readStdErr(){
//    qDebug() << exes.readAllStandardError();
//    QFile log("log.txt");
//    log.write(exes.readAllStandardError());
//}

MainWindow::~MainWindow()
{
    delete ui;
}
