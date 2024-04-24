#include <QRandomGenerator>

#include "graphwidget.h"
#include "ui_graphwidget.h"
#include "note.h"

static int randomBetween(int low, int high)
{
    return QRandomGenerator::global()->bounded(low, high + 1);
}

GraphWidget::GraphWidget(QWidget *parent) : QWidget(parent), ui(new Ui::GraphWidget)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    scene->setSceneRect(0, 0, 500, 500);

    connect(scene, &QGraphicsScene::changed, this, &GraphWidget::updateLines);
}

GraphWidget::~GraphWidget()
{
    delete ui;
}

void GraphWidget::addNote(const Note &note)
{
    MoveItem *item = new MoveItem(MoveItem::noteType);
    item->setPos(randomBetween(30, 470), randomBetween(30, 470));
    scene->addItem(item);
    item->setupMoveItemNote(note);

    for (const QString &tag : note.tags.split(' '))
    {
        if (!m_addedNames.contains(tag))
        {
            MoveItem *tagItem = new MoveItem(MoveItem::tagType);
            tagItem->setPos(randomBetween(30, 470), randomBetween(30, 470));
            scene->addItem(tagItem);
            tagItem->setupMoveItemTag(tag);
            m_addedNames.insert(tag);
        }
    }
    connectItems(item);
}

void GraphWidget::updateLines()
{
    QList<QGraphicsItem *> lines = scene->items();
    for (QGraphicsItem *item : lines)
    {
        QGraphicsLineItem *line = dynamic_cast<QGraphicsLineItem *>(item);
        if (line)
        {
            scene->removeItem(line);
            delete line;
        }
    }
    QList<QGraphicsItem *> items = scene->items();
    for (QGraphicsItem *item : items)
    {
        MoveItem *noteItem = dynamic_cast<MoveItem *>(item);
        if (noteItem && noteItem->itemType == MoveItem::noteType)
        {
            connectItems(noteItem);
        }
    }
}

void GraphWidget::drawLineBetweenItems(MoveItem *noteItem, MoveItem *tagItem)
{
    QGraphicsLineItem *line = new QGraphicsLineItem(noteItem->getPosition().x(), noteItem->getPosition().y(),
                                                    tagItem->getPosition().x(), tagItem->getPosition().y());
    line->setPen(QPen(Qt::black));

    scene->addItem(line);
}

void GraphWidget::connectItems(MoveItem *noteItem)
{
    QStringList tagList = noteItem->tags.split(' ');

    for (const QString &tag : tagList)
    {
        QList<QGraphicsItem *> items = scene->items();
        for (QGraphicsItem *item : items)
        {
            MoveItem *tagItem = dynamic_cast<MoveItem *>(item);
            if (tagItem && tagItem->itemType == MoveItem::tagType && tagItem->title == tag)
            {
                drawLineBetweenItems(noteItem, tagItem);
                break;
            }
        }
    }
}