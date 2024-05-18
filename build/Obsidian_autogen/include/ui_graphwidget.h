/********************************************************************************
** Form generated from reading UI file 'graphwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHWIDGET_H
#define UI_GRAPHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphWidget
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *GraphWidget)
    {
        if (GraphWidget->objectName().isEmpty())
            GraphWidget->setObjectName("GraphWidget");
        GraphWidget->resize(600, 419);
        gridLayout = new QGridLayout(GraphWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(GraphWidget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 1, 0, 1, 1);


        retranslateUi(GraphWidget);

        QMetaObject::connectSlotsByName(GraphWidget);
    } // setupUi

    void retranslateUi(QWidget *GraphWidget)
    {
        GraphWidget->setWindowTitle(QCoreApplication::translate("GraphWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphWidget: public Ui_GraphWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHWIDGET_H
