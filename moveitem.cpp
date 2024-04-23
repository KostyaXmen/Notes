#include "moveitem.h"

MoveItem::MoveItem(QObject *parent) : QObject(parent), QGraphicsItem()
{
}

MoveItem::~MoveItem()
{
}

QRectF MoveItem::boundingRect() const
{
    return QRectF(-30, -30, 60, 60);
}

void MoveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawEllipse(-30, -30, 60, 60);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void MoveItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}

void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void MoveItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

void MoveItem::setupMoveItem(const Note &note)
{
    titleText = new QGraphicsTextItem(note.title, this);
    titleText->setPos(-30, 30);

    title = note.title;
    id = note.id;
}