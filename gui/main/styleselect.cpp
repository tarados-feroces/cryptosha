#include "styleselect.h"
#include "ui_styleselect.h"

StyleSelect::StyleSelect(QWidget *parent) : QDialog(parent), ui(new Ui::StyleSelect)
{
    ui->setupUi(this);
}



void StyleSelect::on_Add_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Document"), QDir::currentPath(), tr("Style (*.json)") );
    ui->label->setText(filename);
    style = std::move(std::make_shared<Style>(filename));
}



void StyleSelect::on_Default_clicked()
{
    QString filename = QDir::currentPath() + "/gui/styles/DefaultStyle.json";
    ui->label->setText(filename);
    style = std::move(std::make_shared<Style>(filename));
}



void StyleSelect::accept()
{
    emit Update();
    this->close();
}



StyleSelect::~StyleSelect()
{
    delete ui;
}
