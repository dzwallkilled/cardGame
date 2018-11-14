#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>

class Card : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    explicit Card(QGraphicsItem *parent = nullptr);
    Card(int x, int y, double scale, int index);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void setAttributes(int x, int y, double scale);
    // member attributes
    QString getSuitName(){return suitName;}
    QString getFaceNum(){return faceName;}
public slots:
    void onSelected();

private:
    int faceNum = -1;
    int suitNum = -1;
    QString suitName = NULL;
    QString faceName = NULL;
    int x, y;
    double scale;
    bool selected = false;
};

#endif // CARD_H
