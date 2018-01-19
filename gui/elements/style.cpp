#include "style.h"

Style::Style() : path(QDir::currentPath() + "/gui/styles/DefaultStyle.json")
{
    read();
}


Style::Style(QString _path) : path(_path)
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


void Style::read()
{
    QFile data(path);
    data.open(QIODevice::ReadOnly);

    QJsonDocument document = QJsonDocument::fromJson(data.readAll());
    QJsonObject root = document.object();

    this->width = root["Width"].toInt();
    this->height = root["Height"].toInt();
    auto rgb = root["Color"].toArray();
    QColor c(rgb[0].toInt(), rgb[1].toInt(), rgb[2].toInt());
    this->color = c;
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
