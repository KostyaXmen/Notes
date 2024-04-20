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

    class GraphWidget : public QWidget
    {
        Q_OBJECT

    public:
        explicit GraphWidget(QWidget *parent = nullptr);
        ~GraphWidget();

    private slots:
        void on_pushButton_clicked();

    private:
        Ui::GraphWidget *ui;
        QGraphicsScene *scene;
    };

    #endif // GRAPHWIDGET_H