#include "scheme.h"
#include "ui_scheme.h"
#include "elements/graphLayer.h"
#include <QGraphicsScene>

Scheme::Scheme(stylePtr _style, QWidget *parent) : QDialog(parent), ui(new Ui::Scheme), style(_style)
{
    ui->setupUi(this);
    auto scene = new QGraphicsScene();
//    auto style = new Style();



    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

//    scene->setSceneRect(-250, -250, 500, 500);

    auto graphLay = new GraphLayer(100, 100, style);

    scene->addItem(graphLay);
}



Scheme::~Scheme()
{
    delete ui;
}
