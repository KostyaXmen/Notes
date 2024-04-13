#include "noteslistwidget.h"
#include "ui_noteslistwidget.h"

#include "note.h"
#include "notewidget.h"

NotesListWidget::NotesListWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::NotesListWidget)
{
    ui->setupUi(this);

    connect(ui->listWidget, &QListWidget::itemSelectionChanged, this, &NotesListWidget::onItemSelectionChanged);
}

NotesListWidget::~NotesListWidget()
{
    delete ui;
}

void NotesListWidget::addNote(const Note &note)
{
    auto *item = new QListWidgetItem();
    ui->listWidget->insertItem(0, item);

    setupNoteItem(note, item);
}

void NotesListWidget::removeCurrentNote()
{
    auto currentItem = ui->listWidget->currentItem();
    if (currentItem != nullptr)
    {
        delete currentItem;
    }
}

void NotesListWidget::updateCurrentNote(const Note &note)
{
    if (ui->listWidget->currentRow() != 0)
    {
        moveCurrentItemToTop(note);
    }
    else
    {
        auto widget = static_cast<NoteWidget*>(ui->listWidget->itemWidget(ui->listWidget->currentItem()));
        widget->updateContent(note);
    }
}

int NotesListWidget::currentNoteId()
{
    auto *currentItem = ui->listWidget->currentItem();
    int noteId = static_cast<NoteWidget*>(ui->listWidget->itemWidget(currentItem))->noteId();
    return noteId;
}

void NotesListWidget::onItemSelectionChanged()
{
    auto *currentItem = ui->listWidget->currentItem();
    if (currentItem != nullptr)
    {
        int id = currentNoteId();

        emit selectedNoteChanged(id);
    }
}

void NotesListWidget::moveCurrentItemToTop(const Note &note)
{
    blockSignals(true);
    auto  item = ui->listWidget->takeItem(ui->listWidget->currentRow());

    ui->listWidget->insertItem(0, item);
    setupNoteItem(note, item);
    blockSignals(false);
}

void NotesListWidget::setupNoteItem(const Note &note, QListWidgetItem *item)
{
    NoteWidget *widget = new NoteWidget(note);
    connect(widget, &NoteWidget::removeNote, this, &NotesListWidget::removeNote);
    connect(widget, &NoteWidget::renameNote, this, &NotesListWidget::renameNote);

    item->setSizeHint(widget->sizeHint());
    ui->listWidget->setItemWidget(item, widget);
    ui->listWidget->setCurrentItem(item);
}