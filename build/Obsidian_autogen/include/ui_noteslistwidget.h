/********************************************************************************
** Form generated from reading UI file 'noteslistwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTESLISTWIDGET_H
#define UI_NOTESLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NotesListWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QListWidget *listWidget;

    void setupUi(QWidget *NotesListWidget)
    {
        if (NotesListWidget->objectName().isEmpty())
            NotesListWidget->setObjectName("NotesListWidget");
        NotesListWidget->resize(236, 499);
        verticalLayout = new QVBoxLayout(NotesListWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(NotesListWidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        listWidget = new QListWidget(NotesListWidget);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);


        retranslateUi(NotesListWidget);

        QMetaObject::connectSlotsByName(NotesListWidget);
    } // setupUi

    void retranslateUi(QWidget *NotesListWidget)
    {
        NotesListWidget->setWindowTitle(QCoreApplication::translate("NotesListWidget", "Form", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("NotesListWidget", "Search...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NotesListWidget: public Ui_NotesListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTESLISTWIDGET_H
