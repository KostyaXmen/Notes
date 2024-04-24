#pragma once

#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QWidget>
#include <QGraphicsScene>

#include "moveitem.h"

namespace Ui
{
    class GraphWidget;
}

class Note;

class GraphWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GraphWidget(QWidget *parent = nullptr);
    ~GraphWidget();
    void addNote(const Note &note);
    void updateLines();

private:
    void drawLineBetweenItems(MoveItem *noteItem, MoveItem *tagItem);
    void connectItems(MoveItem* noteItem);


    QSet<QString> m_addedNames;

private:
    Ui::GraphWidget *ui;
    QGraphicsScene *scene;
};

#endif // GRAPHWIDGET_H