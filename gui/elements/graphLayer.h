#ifndef LAY_H
#define LAY_H

#include <QGraphicsItem>
#include <QWidget>
#include "graphElement.h"
#include <QPainter>


using gElementPtr = std::unique_ptr<GraphElement>;


class GraphLayer : public QGraphicsItem
{
public:

    GraphLayer(QGraphicsItem * parent = 0);
    GraphLayer(int x, int y, stylePtr _style, QGraphicsItem *parent = 0);
    GraphLayer(const GraphLayer&) = delete;
    GraphLayer& operator=(const GraphLayer&) = delete;
    ~GraphLayer() = default;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const;


    std::vector<gElementPtr> listElements;

    int gX;
    int gY;
    stylePtr style;

};

#endif // LAY_H
