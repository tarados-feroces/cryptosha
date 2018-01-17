#ifndef SCHEME_H
#define SCHEME_H

#include <QDialog>
#include "elements/style.h"


namespace Ui{
class Scheme;
}

class Scheme : public QDialog
{

    Q_OBJECT

public:
    Scheme(Style &_style, QWidget *parent = 0);
    virtual ~Scheme();

private:
    Ui::Scheme *ui;
    Style style;
};

#endif // SCHEME_H
