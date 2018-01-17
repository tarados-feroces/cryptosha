#include "styleselect.h"
#include <ui_styleselect.h>

styleSelect::styleSelect(QWidget *parent) : QDialog(parent), ui(new Ui::styleSelect)
{
    ui->setupUi(this);
}

void styleSelect::on_Add_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Document"), QDir::currentPath(), tr("Style (*.json)") );
    ui->label->setText(filename);
    Style newStyle(filename);
    style = newStyle;
}


void styleSelect::on_Default_clicked()
{

}



void styleSelect::accept()
{
    emit Update();
    this->close();
}


styleSelect::~styleSelect()
{
    delete ui;
}
