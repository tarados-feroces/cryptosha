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
#include "pblockstyle.h"

using gPinPtr = std::unique_ptr<GraphPin>;




class GraphElement : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit GraphElement(QGraphicsItem * parent = 0);
    GraphElement(int input, int output, stylePtr _style, QGraphicsItem * parent = 0);
    GraphElement(const GraphElement &) = delete;
    GraphElement& operator=(const GraphElement&) = delete;
    ~GraphElement() = default;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setPinsCoords();


    //void mousePressEvent(QGraphicsSceneMouseEvent *event);

    QRectF boundingRect() const;

    int id;


    std::vector<gPinPtr> vInPins;
    std::vector<gPinPtr> vOutPins;
    stylePtr style;
    int gX;
    int gY;
    int InputPins;
    int OutputPins;


signals:
    void coordChanged();

private:

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

public:
    QString type;
    QString name;

    int width;
    int height;
};

#endif // GRAPH_ELEMENT_H
