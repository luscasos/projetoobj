#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include <stdio.h>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QImage>
#include <QPixmap>


class MyGraphicsScene : public QGraphicsScene
{
    QImage* _image;
    int _x,_y;

public:
    MyGraphicsScene(QObject * parent,int x,int y);
    void reset();
    void converter(QWidget( *parent));
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // MYGRAPHICSSCENE_H
