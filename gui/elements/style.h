#pragma once

#ifndef STYLE_H
#define STYLE_H

#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QCoreApplication>
#include <memory>

#include "../settings.hpp"



class Style
{
public:
    Style();
    Style(QString _path);
    Style(const Style & obj) = default;
    virtual ~Style() = default;

    virtual void paint(QPainter *painter);
    void read();
    void changePath(QString _path);
    int getWidth();
    int getHeight();
    QString getPath();
    QColor getColor();

private:
    int width;
    int height;
    QColor color;
    QString path;
};

#endif // STYLE_H
