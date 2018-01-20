#pragma once

#ifndef SETTINGS_H
#define SETTINGS_H


#include <QDir>



namespace gui {

    QString defaultStylePath = QDir::currentPath() + "/gui/styles/DefaultStyle.json";
    QString newName = QDir::currentPath() + "/untitled.cry";
}

#endif // SETTINGS_H
