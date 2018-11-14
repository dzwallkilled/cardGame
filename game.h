#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsTextItem>
#include "carddeck.h"
#include "card.h"

class Game : public QGraphicsView
{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    CardDeck * carddeck;
    Card * card;
    QGraphicsTextItem * text;

private:
    int index = 0;
};

#endif // GAME_H
