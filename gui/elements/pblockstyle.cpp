#include "pblockstyle.h"


PBlockStyle::PBlockStyle() : Style() {}



PBlockStyle::PBlockStyle(QString _path) : Style(_path) {}



void PBlockStyle::paint(QPainter *painter)
{

    painter->setPen(QPen(getColor(), 2));

    painter->drawEllipse(0, 0, getWidth(), getHeight());

//    QRectF rect(0, 0, getWidth(), getHeight());
//    QPainterPath path;

//    path.moveTo(rect.center().x(), rect.top());
//    path.lineTo(rect.right(), rect.center ().y());
//    path.lineTo(rect.center ().x(), rect.bottom());
//    path.lineTo(rect.left(), rect.center ().y());
//    path.lineTo(rect.center ().x(), rect.top ());
}
