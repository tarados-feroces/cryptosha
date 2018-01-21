#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextEdit>





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), fileSaved(true)
{
    ui->setupUi(this);
    menuBar();
    createFileMenu();
    createSettingsMenu();
    ui->menuBar->show();
    style = std::make_shared<Style>();
    sSelect = std::make_unique<StyleSelect>(this);
    QObject::connect(ui->textEdit, SIGNAL(textChanged()), this,  SLOT(changed()));
    QObject::connect(sSelect.get(), SIGNAL(Update()), this,  SLOT(styleUpdate()));
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

    auto newAction = new QAction(tr("&New"), this);
    QObject::connect(newAction, SIGNAL(triggered(bool)), this,  SLOT(showNewMenu()));

    auto openAction = new QAction(tr("&Open"), this);
    QObject::connect(openAction, SIGNAL(triggered(bool)), this,  SLOT(showOpenMenu()));

    auto saveAction = new QAction(tr("&Save"), this);
    QObject::connect(saveAction, SIGNAL(triggered(bool)), this,  SLOT(showSaveMenu()));

    auto saveAsAction = new QAction(tr("&Save As"), this);
    QObject::connect(saveAsAction, SIGNAL(triggered(bool)), this,  SLOT(showSaveAsMenu()));

    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
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



void MainWindow::showSaveAsMenu()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Save Document"), QDir::currentPath() + "/" +
                                                    this->filename, tr("Cryptosha (*.cry)") );

    if (path.split('.')[path.split('.').size() - 1] != "cry")
        path += ".cry";

    this->filename = path;

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
    if (filename.size() == 0)
        return;
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

    QString filename = gui::newName;
    this->filename = filename;

    ui->textEdit->setText(QString());
    this->fileSaved = false;
    this->setWindowTitle("Cryptosha   " + this->filename + "*");
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
//    QSharedPointer<Scheme> dialog = QSharedPointer<Scheme>(new Scheme(style, this));
    Scheme * dialog = new Scheme(style, this);
    dialog->setWindowTitle(this->filename);
    dialog->show();

}



MainWindow::~MainWindow()
{
    delete ui;
}
