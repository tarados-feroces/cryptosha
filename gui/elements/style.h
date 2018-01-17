#ifndef STYLE_H
#define STYLE_H

#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDir>
#include <QCoreApplication>


class Style
{
public:
    Style();
    Style(QString _path);
    ~Style() {}

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void read();
    void changePath(QString _path);
    int getWidth();
    int getHeight();

private:
    int width;
    int height;
    QString path;
};

#endif // STYLE_H
