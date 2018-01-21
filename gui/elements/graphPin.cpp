#include "graphPin.h"



GraphPin::GraphPin(QGraphicsItem *parent) : QGraphicsItem(parent)
{
    setFlag(QGraphicsItem::ItemIsSelectable);
}



GraphPin::GraphPin(int val, QGraphicsItem *parent) : QGraphicsItem(parent)
{
    setFlag(QGraphicsItem::ItemIsSelectable);
    value = val;
}



QPointF GraphPin::getPoint()
{
    return QPointF(gX, gY);
}



void GraphPin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 1));
    if(value)
    {
        painter->setBrush(Qt::black);
        painter->drawEllipse(0, -2, 4, 4);
    }
    else
    {
        painter->setBrush(Qt::white);
        painter->drawEllipse(0, -2, 4, 4);
    }
}



QRectF GraphPin::boundingRect() const
{
    return QRectF(0, -2, 4, 4);
}


void GraphPin::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}
