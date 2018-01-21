#pragma once

#ifndef SCHEME_H
#define SCHEME_H

#include <QDialog>
#include "elements/pblockstyle.h"
#include "elements/graphLayer.h"


namespace Ui{
class Scheme;
}

class Scheme : public QDialog
{

    Q_OBJECT

public:
    Scheme(stylePtr _style, QWidget *parent = 0);
    Scheme(const Scheme &) = delete;
    virtual ~Scheme();

    void draw();

private:
    Ui::Scheme *ui;
    stylePtr style;
    std::map<int, GraphElement*> elements;
};

#endif // SCHEME_H
