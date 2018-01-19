#ifndef PBLOCKSTYLE_H
#define PBLOCKSTYLE_H

#include "style.h"


using stylePtr = std::shared_ptr<Style>;


class PBlockStyle : public Style
{
public:
    PBlockStyle();
    PBlockStyle(QString _path);
    PBlockStyle(const PBlockStyle & obj) = default;
    virtual ~PBlockStyle() = default;

    void paint(QPainter *painter);
};

#endif // PBLOCKSTYLE_H
