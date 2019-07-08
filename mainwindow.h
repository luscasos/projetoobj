#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include "mygraphicsscene.h"
#include <QLabel>
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    MyGraphicsScene *graphic;
    int scalax=10,scalay=10;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void reset();
    void play();
    void converter();
private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
