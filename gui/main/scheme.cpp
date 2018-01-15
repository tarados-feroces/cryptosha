#include "scheme.h"
#include "ui_scheme.h"
#include "elements/graph_layer.h"
#include <QGraphicsScene>

Scheme::Scheme(QWidget *parent) : QDialog(parent), ui(new Ui::Scheme)
{
    ui->setupUi(this);
    auto scene = new QGraphicsScene();
    auto lay = new GraphLayer(-300, -100);

    ui->graphicsView->setScene(scene);
//    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    scene->setSceneRect(-250, -250, 500, 500);

    scene->addItem(lay);
}
