#ifndef GRAPH_PIN_H
#define GRAPH_PIN_H
#include <QGraphicsItem>
#include <QGraphicsLayoutItem>
#include <QPainter>



class GraphPin : public QGraphicsItem
{
public:
    GraphPin(QGraphicsItem *parent = 0);
	GraphPin(int val, QGraphicsItem *parent = 0);
    GraphPin(const GraphPin&) = delete;
    ~GraphPin() = default;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setCoords(int, int);

    void setNumber(int);

    QRectF boundingRect() const;

	void mousePressEvent(QGraphicsSceneMouseEvent *event);

    bool value;
    int gX;
    int gY;
    int number;
};

#endif // GRAPH_PIN_H
