#include "pblockstyle.h"


PBlockStyle::PBlockStyle() : Style() {}



PBlockStyle::PBlockStyle(QString _path) : Style(_path) {}



void PBlockStyle::paint(QPainter *painter)
{
    painter->setPen(QPen(getColor(), 2));

    painter->drawEllipse(0, 0, getWidth(), getHeight());
}
