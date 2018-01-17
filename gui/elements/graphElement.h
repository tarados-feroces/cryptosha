#ifndef GRAPH_ELEMENT_H
#define GRAPH_ELEMENT_H
#include <QGraphicsItem>
#include <QGraphicsLayoutItem>
#include <QPainter>
#include <QVector>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QObject>
#include <memory>

#include "graphPin.h"
#include "style.h"



class GraphElement : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    GraphElement(QGraphicsItem * parent = 0);
    GraphElement(int input, int output, Style& _style, QGraphicsItem * parent = 0);
    GraphElement(const GraphElement &) = default;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setPinsCoords();


    //void mousePressEvent(QGraphicsSceneMouseEvent *event);

    QRectF boundingRect() const;

    int id;

    using gpin_ptr = std::shared_ptr<GraphPin>;
    QVector<gpin_ptr> vInPins;
    QVector<gpin_ptr> vOutPins;
    Style style;
    int gX;
    int gY;
    int InputPins;
    int OutputPins;


    int get_width() const
    {
        return width;
    }

signals:
    void coordChanged();

private:

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

public:
    QString type;
    QString name;

    int width = 150;
    int height = 50;
};

#endif // GRAPH_ELEMENT_H
