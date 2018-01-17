#include "graphLayer.h"
#include <QDebug>


GraphLayer::GraphLayer(QGraphicsItem *parent) : QGraphicsItem(parent)
{
//    setFlag(GraphicsItemFlag::ItemIsSelectable);
//    GraphElement * item = new GraphElement(2, 1, this);
//    item->g_x = pos().x() + 70;
//    item->g_y = pos().y() + 75;
//    listElements.push_back(item);
}



GraphLayer::GraphLayer(int _x, int _y, Style &_style, QGraphicsItem *parent) : QGraphicsItem(parent), style(_style)
{
    setPos(_x, _y);
    setFlag(GraphicsItemFlag::ItemIsSelectable);
    int dist_x = 0;
    int dist_y = 0;
    for (int i = 0; i < 3; ++i)
    {
        GraphElement * item = new GraphElement(2, 1, style, this);
        dist_y = item->height * 1.5;
        item->gX = pos().x() + dist_x;
        item->gY = pos().y();
        item->setPinsCoords();
        listElements.push_back(item);
        dist_x += item->width * 1.5;
    }
}



void GraphLayer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int x = 0;
    painter->setPen(QPen(Qt::white, 1));
    painter->setBrush(Qt::white);
//    painter->drawRect(0 , 0, (500+150)*listElements.size(), 150);

    for(auto it = listElements.begin(); it != listElements.end(); it++)
    {
        x = (*it)->gX;
		(*it)->setPos(x, 0);
    }
}



QRectF GraphLayer::boundingRect() const
{
    int y = 0;
    int x = 0;
    return QRectF(x , y, (500+150)*listElements.size(), 150);
}
