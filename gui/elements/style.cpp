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


void Style::read()
{
    QFile data(path);
    data.open(QIODevice::ReadOnly);

    QJsonDocument document = QJsonDocument::fromJson(data.readAll());
    QJsonObject root = document.object();

    this->width = root["Width"].toInt();
    this->height = root["Height"].toInt();

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


void Style::paint(QPainter *painter)
{
    QColor color;
    color.setRgb(123,123,123);
    painter->setPen(QPen(color, 2));
    painter->drawRect(0, 0, width, height);
}
