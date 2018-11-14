#include "game.h"
#include <QDebug>

Game::Game(QWidget *parent)
{
    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,900,600);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    for (int i = 0; i < 54; i++){
        card = new Card(i%13*50, i/13*100, 0.2, i);
        scene->addItem(card);
        text = new QGraphicsTextItem();
        text->setPos(i%13*50+10, i/13*100+30);
        text->setPlainText(card->getFaceNum());
        scene->addItem(text);
    }

}


