#pragma once

#ifndef MOVEITEM_H
#define MOVEITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

#include "note.h"

class MoveItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    enum ItemType
    {
        noteType,
        tagType
    };
    explicit MoveItem(ItemType type, QObject *parent = 0);
    ~MoveItem();

signals:

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public:
    void setupMoveItemNote(const Note &note);
    void setupMoveItemTag(const QString tag);
    QString title;
    QString tags;
    int id;
    ItemType itemType;

    QPointF getPosition() const;

private:
    QGraphicsTextItem *titleText;
};

#endif // MOVEITEM_H