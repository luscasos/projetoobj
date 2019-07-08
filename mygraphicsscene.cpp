#include "mygraphicsscene.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QInputDialog>


MyGraphicsScene::MyGraphicsScene(QObject * parent,int x,int y): QGraphicsScene(parent)
{
    _x=x;
    _y=y;
    _image = new QImage(x, y, QImage::Format_RGB32);
    QRgb value;


    for(int i=0;i<x*y;i++){
        value = qRgb(255, 255,255); // 0xffbd9527
        _image->setPixel(i/y, i%y, value);
    }
    addPixmap(QPixmap::fromImage(*_image));
}
void MyGraphicsScene::reset(){
    QRgb value;

    for(int i=0;i<_image->size().width()*_image->size().height();i++){
        value = qRgb(255, 255,255);
        _image->setPixel(i/_image->size().height(), i%_image->size().height(), value);
    }
    addPixmap(QPixmap::fromImage(*_image));
}

void MyGraphicsScene::converter(QWidget *parent){

    bool ok;
        QString text = QInputDialog::getText(
                          parent,
                          tr("Salvar"),
                          tr("Digite o nome do arquivo:"),
                          QLineEdit::Normal,
                          tr("Imagem"),
                          &ok );


    QFile arquivo("./"+text+".h");
    arquivo.open(QFile::WriteOnly);
    QTextStream out(&arquivo);
    out <<"static const uint8_t " + text+"[] = {\n";

    for(int i =0;i<_image->width();i++){
        for(int j=0; j<_image->height();j++){
            if(_image->pixel(i,j)==0xFF000000){
                out <<j<<","<<i<<",";
                QTextStream(stdout) << j <<i<< "\n";
            }
        }
        out <<"\n";
    }
    out <<"}";

}

void MyGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    clear();
    if(event->button() == Qt::LeftButton){
        _image->setPixel((int)event->scenePos().x(),(int)event->scenePos().y(),qRgb(0,0,0));
    } else {
        _image->setPixel((int)event->scenePos().x(),(int)event->scenePos().y(),qRgb(255,255,255));
    }
    addPixmap(QPixmap::fromImage(*_image));
    //QTextStream(stdout) << "X:" << event->scenePos().x() << ",Y:" << event->scenePos().y() << "\n";
}
