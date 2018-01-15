#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPainter>
#include "elements/graph_layer.h"
#include <QMenuBar>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QAction>



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
    void create_file_menu();

public slots:
    void on_runButton_clicked();
    void show_save_menu();
    void show_open_menu();
    void show_new_menu();
    void changed();

private:
    Ui::MainWindow *ui;
    QMenu *file_menu;
    QString filename;
    bool file_saved;
};

#endif // MAINWINDOW_H
