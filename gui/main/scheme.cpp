#include "scheme.h"
#include "ui_scheme.h"
#include <QGraphicsScene>
#include <memory>



using gLayPtr = std::shared_ptr<GraphLayer>;


Scheme::Scheme(stylePtr _style, QWidget *parent) : QDialog(parent), ui(new Ui::Scheme), style(_style)
{
    ui->setupUi(this);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}


void Scheme::draw()
{
    auto scene = new QGraphicsScene();

    ui->graphicsView->setScene(scene);

    std::vector<gLayPtr> layers;

    int inter_layer_width = 200;

//	elements.clear();

    int lay_counter = 0;
    int laySize = 4;
    int id = 0;
    for (int i = 0; i < 30; ++i)
    {
        auto ptr_lay = new GraphLayer(0, 0 + lay_counter++ * inter_layer_width, style);

        int dist_x = 0;

        for (int j = 0; j < laySize; ++j)
        {
            int inputPins = 2;
            int outputPins = 2;

            gElementPtr item(new GraphElement(inputPins, outputPins, style, ptr_lay));

            item->gX = ptr_lay->pos().x() + dist_x;
            item->gY = ptr_lay->pos().y();

            if (j % 2 == 0)
                item->type = "pblock";

            item->setPinsCoords();
            dist_x += item->width * 1.5;

            elements[id++] = item.get();

            ptr_lay->listElements.push_back(std::move(item));
        }
        scene->addItem(ptr_lay);
        layers.push_back(std::make_shared<GraphLayer>(ptr_lay));

    }

    QPointF out_pin;
    QPointF in_pin;

    QPointF out_pin2;
    QPointF in_pin2;

    bool is_true;
    bool is_true2;

    for (int i = 0; i < elements.size() - laySize; ++i)
    {
        out_pin = elements[i]->vOutPins[0]->getPoint();
        out_pin2 = elements[i]->vOutPins[1]->getPoint();

        if (i % 2 == 0)
        {
            in_pin = elements[i + laySize + 1]->vInPins[0]->getPoint();
            in_pin2 = elements[i + laySize + 1]->vInPins[1]->getPoint();
        }

        else
        {
            in_pin = elements[i + laySize - 1]->vInPins[0]->getPoint();
            in_pin2 = elements[i + laySize - 1]->vInPins[1]->getPoint();
        }

        is_true = elements[i]->vOutPins[0]->value;
        is_true2 = elements[i]->vOutPins[1]->value;

        if (is_true)
            scene->addLine(QLineF(out_pin, in_pin), QPen(Qt::red, 1));
        else
            scene->addLine(QLineF(out_pin, in_pin), QPen(Qt::black, 1));

        if (is_true2)
            scene->addLine(QLineF(out_pin2, in_pin2), QPen(Qt::red, 1));
        else
            scene->addLine(QLineF(out_pin2, in_pin2), QPen(Qt::black, 1));


    }
}



Scheme::~Scheme()
{
    delete ui;
}
