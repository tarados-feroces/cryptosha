#include "style.h"




Style::Style() : path(gui::defaultStylePath), correct(true)
{
    read();
}


Style::Style(QString _path) : path(_path), correct(true)
{
    read();
}



void Style::changePath(QString _path)
{
    path = _path;
}



QString Style::getPath()
{
    return this->path;
}



bool Style::isCorrect()
{
    return this->correct;
}


void Style::read()
{
    if (path.size() == 0)
        return;

    QFile data(path);

    data.open(QIODevice::ReadOnly);

    QJsonDocument document = QJsonDocument::fromJson(data.readAll());
    QJsonObject root = document.object();

    if (root.find("Width") != root.end() && root.find("Height") != root.end() && root.find("Color") != root.end())
    {
        this->width = root["Width"].toInt();
        this->height = root["Height"].toInt();
        auto rgb = root["Color"].toArray();
        QColor c(rgb[0].toInt(), rgb[1].toInt(), rgb[2].toInt());
        this->color = c;
    }

    else
    {
        this->correct = false;
    }
    data.close();
}



int Style::getWidth()
{
    return this->width;
}



int Style::getHeight()
{
    return this->height;
}



QColor Style::getColor()
{
    return this->color;
}



void Style::paint(QPainter *painter)
{
    painter->setPen(QPen(color, 2));
    painter->drawRect(0, 0, width, height);
}
