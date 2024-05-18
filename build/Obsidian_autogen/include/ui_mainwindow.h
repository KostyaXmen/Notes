/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "../../../graphwidget.h"
#include "../../../noteslistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QGridLayout *gridLayout_2;
    QPushButton *newNoteButton;
    QPushButton *removeNoteButton;
    QSpacerItem *horizontalSpacer;
    QSplitter *splitter;
    NotesListWidget *notesListWidget;
    QTextEdit *textEdit;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    GraphWidget *graphWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab_1 = new QWidget();
        tab_1->setObjectName("tab_1");
        tab_1->setEnabled(true);
        gridLayout_2 = new QGridLayout(tab_1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        newNoteButton = new QPushButton(tab_1);
        newNoteButton->setObjectName("newNoteButton");

        gridLayout_2->addWidget(newNoteButton, 0, 0, 1, 1);

        removeNoteButton = new QPushButton(tab_1);
        removeNoteButton->setObjectName("removeNoteButton");

        gridLayout_2->addWidget(removeNoteButton, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(585, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        splitter = new QSplitter(tab_1);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        notesListWidget = new NotesListWidget(splitter);
        notesListWidget->setObjectName("notesListWidget");
        notesListWidget->setMinimumSize(QSize(100, 0));
        splitter->addWidget(notesListWidget);
        textEdit = new QTextEdit(splitter);
        textEdit->setObjectName("textEdit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        splitter->addWidget(textEdit);

        gridLayout_2->addWidget(splitter, 1, 0, 1, 3);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        graphWidget = new GraphWidget(tab_2);
        graphWidget->setObjectName("graphWidget");

        gridLayout_3->addWidget(graphWidget, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 30));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Obsidian", nullptr));
        newNoteButton->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        removeNoteButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
