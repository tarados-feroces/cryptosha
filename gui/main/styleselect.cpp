#include "styleselect.h"
#include "styleerror.h"
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
    if (!style->isCorrect())
    {
//        std::unique_ptr<StyleError> error = std::make_unique<StyleError>(this->parentWidget());
        StyleError * error = new StyleError(this->parentWidget());
        error->show();
    }
}



void StyleSelect::on_Default_clicked()
{
    QString filename = gui::defaultStylePath;
    ui->label->setText(filename);
    style = std::move(std::make_shared<Style>(filename));
    if (!style->isCorrect())
    {
        std::unique_ptr<StyleError> Error = std::make_unique<StyleError>();
        Error->show();
    }
}



void StyleSelect::accept()
{
    emit Update();
    this->close();
}
