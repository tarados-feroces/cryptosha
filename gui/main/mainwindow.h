#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPainter>
#include <QMenuBar>
#include <QDir>
#include <QAction>

#include "scheme.h"
#include "styleselect.h"


using sSelectPtr = std::unique_ptr<StyleSelect>;

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void draw();
    void createFileMenu();
    void createSettingsMenu();

public slots:
    void on_runButton_clicked();
    void showSaveMenu();
    void showSaveAsMenu();
    void showOpenMenu();
    void showNewMenu();
    void showStyleMenu();
    void changed();
    void styleUpdate();

private:
    Ui::MainWindow *ui;
    QMenu *fileMenu;
    QMenu *settingsMenu;
    QString filename;
    bool fileSaved;
    stylePtr style;
    sSelectPtr sSelect;
};

#endif // MAINWINDOW_H
