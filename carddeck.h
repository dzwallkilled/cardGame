#ifndef CARDDECK_H
#define CARDDECK_H

#include <QObject>
#include "card.h"

class CardDeck : public QObject
{
    Q_OBJECT
public:
    explicit CardDeck(QObject *parent = nullptr);
    void shuffle();
    void dealCard(Card *);

signals:

public slots:

private:
    QVector<Card *> deck;
};

#endif // CARDDECK_H
