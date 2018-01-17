#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scheme.h"
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), fileSaved(true)
{
    ui->setupUi(this);
    createFileMenu();
    createSettingsMenu();
    ui->menuBar->show();
    Style newStyle;
    style = newStyle;
    sSelect = new styleSelect(this);
    QObject::connect(ui->textEdit, SIGNAL(textChanged()), this,  SLOT(changed()));
    QObject::connect(sSelect, SIGNAL(Update()), this,  SLOT(styleUpdate()));
}



void MainWindow::changed()
{
    if (this->fileSaved)
    {
        this->fileSaved = false;
        this->setWindowTitle("Cryptosha   " + this->filename + "*");
    }

}



void MainWindow::createFileMenu()
{
    fileMenu = menuBar()->addMenu(tr("&File"));

    auto new_action = new QAction(tr("&New"), this);
    QObject::connect(new_action, SIGNAL(triggered(bool)), this,  SLOT(showNewMenu()));

    auto open_action = new QAction(tr("&Open"), this);
    QObject::connect(open_action, SIGNAL(triggered(bool)), this,  SLOT(showOpenMenu()));

    auto save_action = new QAction(tr("&Save"), this);
    QObject::connect(save_action, SIGNAL(triggered(bool)), this,  SLOT(showSaveMenu()));

    fileMenu->addAction(new_action);
    fileMenu->addAction(open_action);
    fileMenu->addAction(save_action);
}



void MainWindow::createSettingsMenu()
{
    settingsMenu = menuBar()->addMenu(tr("&Settings"));

    auto style_action = new QAction(tr("&Style"), this);
    QObject::connect(style_action, SIGNAL(triggered(bool)), this,  SLOT(showStyleMenu()));


    settingsMenu->addAction(style_action);
}



void MainWindow::showSaveMenu()
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

    if (this->filename.size() != 0)
    {
        QFile file(filename);
        file.open(QIODevice::WriteOnly);
        file.write(ui->textEdit->toPlainText().toUtf8());
        file.close();
        this->fileSaved = true;
        this->setWindowTitle("Cryptosha   " + this->filename);
    }
}



void MainWindow::showOpenMenu()
{
    if (!this->fileSaved)
        this->showSaveMenu();

    QString filename = QFileDialog::getOpenFileName(this, tr("Open Document"), QDir::currentPath(), tr("Cryptosha (*.cry)") );
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QString data = file.readAll();
    file.close();

    ui->textEdit->setText(data);
    this->filename = filename;
    this->fileSaved = true;
    this->setWindowTitle("Cryptosha   " + this->filename);
}



void MainWindow::showNewMenu()
{
    if (!this->fileSaved)
        this->showSaveMenu();

    QString filename = QDir::currentPath() + "/untitled.cry";
    this->filename = filename;

    ui->textEdit->setText(QString());
    this->fileSaved = true;
    this->setWindowTitle("Cryptosha   " + this->filename);
}



void MainWindow::showStyleMenu()
{
    sSelect->show();
}


void MainWindow::styleUpdate()
{
    style = sSelect->style;
}



void MainWindow::on_runButton_clicked()
{
    showSaveMenu();
    Scheme *dialog = new Scheme(style, this);
    dialog->show();
    dialog->setWindowTitle(this->filename);
}



MainWindow::~MainWindow()
{
    delete ui;
}
