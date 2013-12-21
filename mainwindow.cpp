#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    context.setLogin(ui->user->text().toStdString().c_str(), ui->password->text().toStdString().c_str());
    context.setLogMessage(std::string(std::string("Commit from KSP MsM (SVN) at") + QTime::currentTime().toString(Qt::TextDate).toStdString()).c_str());
    context.setAuthCache(true);

    client.setContext(&context);

    validator = new QRegExpValidator(QRegExp("((http:\\/\\/|https:\\/\\/)(www.)?(([a-zA-Z0-9-]){2,}\\.){1,4}([a-zA-Z]){2,6}(\\/([a-zA-Z-_\\/\\.0-9#:?=&;,]*)?)?)"), this);
    ui->url->setValidator(validator);

}

void MainWindow::on_check_clicked()
{

    try
    {
        client.checkout(ui->url->text().toStdString().c_str(),svn::Path(ui->path->text().toStdString()),svn::Revision::HEAD,true);
    }
    catch (svn::ClientException & error)
    {
        QMessageBox::critical(this, "Erreur", error.message());
        return;
    }
    catch (std::exception & error)
    {
        QMessageBox::critical(this, "Erreur", error.what());
        return;
    }
    catch (...)
    {
        QMessageBox::critical(this, "Erreur", "Une erreur est survenue.");
    }

    QMessageBox::information(this, "Checkout réussi !", "Le checkout a réussi.");

}
void MainWindow::on_com_clicked()
{

    try
    {
        client.commit(svn::Targets(ui->path->text().toStdString().c_str()),"",false);
    }
    catch (svn::ClientException & error)
    {
        QMessageBox::critical(this, "Erreur", error.message());
        return;
    }
    catch (std::exception & error)
    {
        QMessageBox::critical(this, "Erreur", error.what());
        return;
    }
    catch (...)
    {
        QMessageBox::critical(this, "Erreur", "Une erreur est survenue.");
    }

    QMessageBox::information(this, "Commit réussi !", "Le commit a réussi.");
}

void MainWindow::on_parcourir_clicked()
{
    ui->path->setText(QFileDialog::getExistingDirectory(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}
