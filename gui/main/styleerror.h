#ifndef STYLEERROR_H
#define STYLEERROR_H

#include <QDialog>



namespace Ui{
class StyleError;
}




class StyleError : public QDialog
{

    Q_OBJECT

public:
    StyleError(QWidget *parent = 0);
    virtual ~StyleError();


public slots:
    void on_Ok_clicked();


private:
    Ui::StyleError *ui;
};

#endif // STYLEERROR_H
