#ifndef SCHEME_H
#define SCHEME_H

#include <QDialog>


namespace Ui{
class Scheme;
}

class Scheme : public QDialog
{

    Q_OBJECT

public:
    Scheme(QWidget *parent = 0);
    virtual ~Scheme() {}

private:
    Ui::Scheme *ui;
};

#endif // SCHEME_H
