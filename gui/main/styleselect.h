#ifndef STYLESELECT_H
#define STYLESELECT_H

#include <QDialog>
#include <QFileDialog>
#include "elements/style.h"


namespace Ui{
class styleSelect;
}


class styleSelect : public QDialog
{

    Q_OBJECT

public:
    friend class MainWindow;
    styleSelect(QWidget *parent = 0);
    virtual ~styleSelect();


public slots:
    void on_Add_clicked();
    void on_Default_clicked();
    void accept();

signals:
    void Update();


private:
    Ui::styleSelect *ui;
    Style style;

};

#endif // STYLESELECT_H
