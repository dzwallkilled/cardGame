#include "carddeck.h"

CardDeck::CardDeck(QObject *parent) : QObject(parent)
{
    for (int i = 0; i < 54; i++){
        Card card = new Card(25*i, 0, 0.2, i);
        deck.push_back(card);
    }

}
