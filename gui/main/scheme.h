#ifndef SCHEME_H
#define SCHEME_H

#include <QDialog>
#include "elements/pblockstyle.h"


namespace Ui{
class Scheme;
}

class Scheme : public QDialog
{

    Q_OBJECT

public:
    Scheme(stylePtr _style, QWidget *parent = 0);
    virtual ~Scheme();

private:
    Ui::Scheme *ui;
    stylePtr style;
};

#endif // SCHEME_H
