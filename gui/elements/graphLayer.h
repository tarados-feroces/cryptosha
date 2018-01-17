#ifndef LAY_H
#define LAY_H

#include <QGraphicsItem>
#include <QWidget>
#include "graphElement.h"
#include <QList>
#include <QPainter>

class GraphLayer : public QGraphicsItem
{
public:

    GraphLayer(QGraphicsItem * parent = 0);
    GraphLayer(int x, int y, Style &_style, QGraphicsItem *parent = 0);

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	QRectF boundingRect() const;

	QVector<GraphElement*> listElements;

    int gX;
    int gY;
    Style style;

};

#endif // LAY_H
