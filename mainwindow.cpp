#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "mygraphicsscene.h"
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(play()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(reset()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(converter()));

    ui->graphicsView->scale(scalax,scalay);
    ui->graphicsView->setVisible(false);


}

void MainWindow:: play(){
        bool ok;
    int x = QInputDialog::getInt(
                      this,
                      tr("String"),
                      tr("Largura"),
                      QLineEdit::Normal,
                      1,
                      84,
                      1,
                      &ok);
    int y = QInputDialog::getInt(
                      this,
                      tr("String"),
                      tr("Altura"),
                      QLineEdit::Normal,
                      1,
                      48,
                      1,
                      &ok);
    graphic=new MyGraphicsScene(this,x,y);
    ui->graphicsView->setMinimumWidth(x*scalax+2);
    ui->graphicsView->setMinimumHeight(y*scalay+2);
    ui->graphicsView->setMaximumWidth(x*scalax+2);
    ui->graphicsView->setMaximumHeight(y*scalay+2);
    ui->graphicsView->setScene(graphic);
    ui->graphicsView->setVisible(true);

    if(x*(scalax)+20<1300&&y*(scalay)+60<730){
        resize(x*(scalax)+20,y*(scalay)+60);
    }

}

void MainWindow:: reset(){
     graphic->reset();
}

void MainWindow:: converter(){
    graphic->converter(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}
