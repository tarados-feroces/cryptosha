#include "graphLayer.h"



GraphLayer::GraphLayer(QGraphicsItem *parent) : QGraphicsItem(parent) {}



GraphLayer::GraphLayer(int _x, int _y, stylePtr _style, QGraphicsItem *parent)
    : gX(_x), gY(_y), style(_style), QGraphicsItem(parent)
{
    setPos(gX, gY);
    setFlag(GraphicsItemFlag::ItemIsSelectable);
    int dist_x = 0;

    for (int i = 0; i < 2; ++i)
    {
        int inputPins = 2;
        int outputPins = 1;

        gElementPtr item = std::make_unique<GraphElement>(inputPins, outputPins, style, this);

        item->gX = pos().x() + dist_x;
        item->gY = pos().y();
        if (i % 2 == 0)
            item->type = "pblock";
        item->setPinsCoords();
        dist_x += item->width * 1.5;
        listElements.push_back(std::move(item));
    }
}



void GraphLayer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int x = 0;

//    painter->setPen(QPen(Qt::black, 5));
//    painter->setBrush(Qt::black);
//    int wid = 0;
//    int hei = 0;

//    if (listElements.size())
//    {
//        wid = listElements.size() * listElements[0]->width * 1.5;
//        hei = listElements[0]->height;
//    }
//    painter->drawRect(0 , 0, wid, hei);

    for(auto& it : listElements)
    {
        x = it->gX;
        it->setPos(x, 0);
    }
}



QRectF GraphLayer::boundingRect() const
{
    int wid = 0;
    int hei = 0;

    if (listElements.size())
    {
        wid = listElements.size() * listElements[0]->width * 1.5;
        hei = listElements[0]->height;
    }

    return QRectF(0, 0, wid, hei);
}
