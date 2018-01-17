#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPainter>
#include <QMenuBar>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QAction>
#include "styleselect.h"
#include "elements/style.h"



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
    Style style;
    styleSelect *sSelect;
};

#endif // MAINWINDOW_H
