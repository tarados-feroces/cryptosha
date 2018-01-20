#pragma once

#ifndef STYLESELECT_H
#define STYLESELECT_H

#include <QDialog>
#include <QFileDialog>
#include "elements/pblockstyle.h"





namespace Ui{
class StyleSelect;
}


class StyleSelect : public QDialog
{

    Q_OBJECT

public:
    friend class MainWindow;
    StyleSelect(QWidget *parent = 0);
    virtual ~StyleSelect() = default;


public slots:
    void on_Add_clicked();
    void on_Default_clicked();
    void accept();

signals:
    void Update();


private:
    Ui::StyleSelect *ui;
    stylePtr style;

};

#endif // STYLESELECT_H
