#include "graph_layer.h"
#include <QDebug>


GraphLayer::GraphLayer(QGraphicsItem *parent) : QGraphicsItem(parent)
{
    setFlag(GraphicsItemFlag::ItemIsSelectable);
    GraphElement * item = new GraphElement(2, 1, this);
    item->g_x = pos().x() + 70;
    item->g_y = pos().y() + 75;
    listElements.push_back(item);
}



GraphLayer::GraphLayer(int _x, int _y, QGraphicsItem *parent) : QGraphicsItem(parent)
{
    setPos(_x, _y);
    setFlag(GraphicsItemFlag::ItemIsSelectable);
    int dist = 0;
    for (int i = 0; i < 3; ++i)
    {
        GraphElement * item = new GraphElement(2, 1, this);
        item->g_x = pos().x() + 70 + dist;
        item->g_y = pos().y() + 75;
        item->SetPinsCoords();
        listElements.push_back(item);
        dist+=100;
    }
}



void GraphLayer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int x = 0;
    painter->setPen(QPen(Qt::white, 1));
    painter->setBrush(Qt::white);
    painter->drawRect(0 , 0, (500+150)*listElements.size(), 150);

    for(auto it = listElements.begin(); it != listElements.end(); it++)
    {
		x = (*it)->g_x - this->pos().x();
		(*it)->setPos(x, 0);
    }
}



QRectF GraphLayer::boundingRect() const
{
    int y = 0;
    int x = 0;
    return QRectF(x , y, (500+150)*listElements.size(), 150);
}
