#ifndef CUSTONSCENE_H
#define CUSTONSCENE_H
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "ui_mainwindow.h"
#include "mainwindow.h"



class CustonScene : public QGraphicsScene
{
    Q_OBJECT
    QGraphicsLineItem *item;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event){

        item = new QGraphicsLineItem;
        addItem(item);
        const QPointF p = event->scenePos();

        item->setPos(p);
    }

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event){
        const QPointF p  =item->mapFromScene(event->scenePos());
        QLineF l = item->line();
        l.setP2(p);
        item->setLine(l);
    }

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
        const QPointF p  =item->mapFromScene(event->scenePos());
        QLineF l = item->line();
        l.setP2(p);
        item->setLine(l);
    }
public:
    CustonScene();
};
#endif // CUSTONSCENE_H
