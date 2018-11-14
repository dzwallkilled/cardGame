#include "card.h"
#include <QDebug>
#include <QString>
#include "definition.h"
#include <QGraphicsScene>

using namespace std;

Card::Card(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent){
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setAttributes(0,0,1);
}

Card::Card(int x, int y, double scale, int index)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    this->x = x;
    this->y = y;
    this->scale = scale;
    // 0-51
    // -2 xiaowang
    // -3 dawang
    if (index < 0 || index > 54){ //cover
        faceNum = 14;
        suitNum = 6;
    }else if (index < 52) { //regular
        faceNum = index % 13;
        suitNum = index/13;
    }else if (index == 52){ //black joker
        faceNum = 13;
        suitNum = 4;
    }else if (index == 53){ //red joker
        faceNum = 13;
        suitNum = 5;
    }
    faceName = faceNumbers[faceNum];
    suitName = suitNames[suitNum];
    setAttributes(x, y, scale);
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "press mouse to change card positions";
    selected = !selected;
    if (selected){
        setAttributes(x, y - 20, 0);
    }else{
        setAttributes(x, y + 20, 0);
    }
}

void Card::setAttributes(int x, int y, double scale)
{
    if (x >= 0) this->x = x;
    if (y >= 0) this->y = y;
    if (scale > 0) this->scale = scale;

    setPos(this->x, this->y);
    setScale(this->scale);
    QRect rect;
    if (faceNum == 13 && suitNum == 5){
        rect = QRect(0, 4*500, 375, 500); // red joker
    } else if (faceNum == 13 && suitNum == 4){
        rect = QRect(375, 4*500, 375, 500); // black joker
    } else if (faceNum == 14){
        rect = QRect(375*4, 4*500, 375, 500); // cover
    } else{
        rect = QRect(375*faceNum, suitNum*500, 375, 500); //regular
    }
    setPixmap(QPixmap(":/images/cards.png").copy(rect));
}

void Card::onSelected()
{
    setAttributes(x, y-20, 0);
}


