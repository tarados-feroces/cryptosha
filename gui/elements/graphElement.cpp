#include "graphElement.h"



GraphElement::GraphElement(QGraphicsItem *parent)
{
    setFlag(QGraphicsItem::ItemIsSelectable);
}



GraphElement::GraphElement(int input, int output, stylePtr _style, QGraphicsItem * parent)
    : QGraphicsItem(parent), style(_style)
{
	setFlag(QGraphicsItem::ItemIsSelectable);
    InputPins = input;
    OutputPins = output;

    width = style->getWidth();
    height = style->getHeight();
    int k = 0;

    for (int  i = 0; i < InputPins; ++i)
    {
        gPinPtr pin = std::make_unique<GraphPin>(this);

		pin->number = i+1;
        pin->value = 1;

        vInPins.push_back(std::move(pin));
    }

    for (int  i = 0; i < OutputPins; ++i)
    {
        gPinPtr pin = std::make_unique<GraphPin>(this);

		pin->number = i+1;
        pin->value = 0;


        vOutPins.push_back(std::move(pin));
    }
}



void GraphElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int k = 0;
    painter->setBrush(Qt::white);

    if (type == "pblock")
    {
        auto p = std::make_shared<PBlockStyle>(style->getPath());
        style = std::dynamic_pointer_cast<PBlockStyle>(p);
    }

    style->paint(painter);

    for (auto& i: vInPins)
    {
        k += width/(InputPins + 1);
        i->setPos(k, 0);
    }

    k = 0;

    for (auto& i: vOutPins)
    {
        k += width/(OutputPins + 1);
        i->setPos(k, height);
    }
}



void GraphElement::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);

}



void GraphElement::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
    emit coordChanged();
}



void GraphElement::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->gX = mapToScene(event->pos()).x();
    this->gY = mapToScene(event->pos()).y();
    this->setPos(mapToScene(event->pos()));
    setPinsCoords();
    emit coordChanged();
}



void GraphElement::setPinsCoords()
{
    int k = 0;
    for (auto i = vInPins.begin(); i != vInPins.end(); ++i)
    {
		k += width / (InputPins + 1);
        (*i)->gX = gX + k + 2;
        (*i)->gY = gY + 2;
    }
    k = 0;
    for (auto i = vOutPins.begin(); i != vOutPins.end(); ++i)
    {
		k += width / (OutputPins + 1);
        (*i)->gX = gX + k + 2;
        (*i)->gY = gY + height + 2;
    }
}



QRectF GraphElement::boundingRect() const
{
    return QRectF(0, 0, width, height);
}



