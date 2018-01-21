#include "styleerror.h"
#include "ui_styleerror.h"


StyleError::StyleError(QWidget *parent) : QDialog(parent), ui(new Ui::StyleError)
{
    ui->setupUi(this);
}



void StyleError::on_Ok_clicked()
{
    this->close();
}


StyleError::~StyleError()
{
    delete ui;
}
