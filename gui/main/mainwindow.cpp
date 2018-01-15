#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scheme.h"
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), file_saved(true)
{
    ui->setupUi(this);
    create_file_menu();
    ui->menuBar->show();

    QObject::connect(ui->textEdit, SIGNAL(textChanged()), this,  SLOT(changed()));
}



void MainWindow::changed()
{
    if (this->file_saved)
    {
        this->file_saved = false;
        this->setWindowTitle("Cryptosha   " + this->filename + "*");
    }

}



void MainWindow::create_file_menu()
{
    file_menu = menuBar()->addMenu(tr("&File"));

    auto new_action = new QAction(tr("&New"), this);
    QObject::connect(new_action, SIGNAL(triggered(bool)), this,  SLOT(show_new_menu()));

    auto open_action = new QAction(tr("&Open"), this);
    QObject::connect(open_action, SIGNAL(triggered(bool)), this,  SLOT(show_open_menu()));

    auto save_action = new QAction(tr("&Save"), this);
    QObject::connect(save_action, SIGNAL(triggered(bool)), this,  SLOT(show_save_menu()));

    file_menu->addAction(new_action);
    file_menu->addAction(open_action);
    file_menu->addAction(save_action);
}



void MainWindow::show_save_menu()
{

    if (this->filename.size() == 0)
    {
        QString filename = QFileDialog::getSaveFileName(this, tr("Save Document"), QDir::currentPath() + "/" +
                                                        this->filename, tr("Cryptosha (*.cry)") );

        if (filename.split('.')[filename.split('.').size() - 1] != "cry")
            filename += ".cry";
    }
    else
    {
        QString filename = this->filename;
    }

    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    file.write(ui->textEdit->toPlainText().toUtf8());
    file.close();
    this->file_saved = true;
    this->setWindowTitle("Cryptosha   " + this->filename);
}



void MainWindow::show_open_menu()
{
    if (!this->file_saved)
        this->show_save_menu();

    QString filename = QFileDialog::getOpenFileName(this, tr("Open Document"), QDir::currentPath(), tr("Cryptosha (*.cry)") );
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QString data = file.readAll();
    file.close();

    ui->textEdit->setText(data);
    this->filename = filename;
    this->file_saved = true;
    this->setWindowTitle("Cryptosha   " + this->filename);
}



void MainWindow::show_new_menu()
{
    if (!this->file_saved)
        this->show_save_menu();

    QString filename = QDir::currentPath() + "/untitled.cry";
    this->filename = filename;

    ui->textEdit->setText(QString());
    this->file_saved = true;
    this->setWindowTitle("Cryptosha   " + this->filename);
}



void MainWindow::on_runButton_clicked()
{
    Scheme *dialog = new Scheme(this);
    dialog->show();
}



MainWindow::~MainWindow()
{
    delete ui;
}
