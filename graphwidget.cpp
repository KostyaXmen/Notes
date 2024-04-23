#include <QRandomGenerator>

#include "graphwidget.h"
#include "ui_graphwidget.h"
#include "note.h"

/* Функция для получения рандомного числа
 * в диапазоне от минимального до максимального
 * */
static int randomBetween(int low, int high)
{
    return QRandomGenerator::global()->bounded(low, high + 1);
}

GraphWidget::GraphWidget(QWidget *parent) : QWidget(parent), ui(new Ui::GraphWidget)
{
    ui->setupUi(this);

    this->resize(640, 640);
    this->setFixedSize(640, 640);

    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    ui->graphicsView->resize(600, 600);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    scene->setSceneRect(0, 0, 500, 500);
}

GraphWidget::~GraphWidget()
{
    delete ui;
}

void GraphWidget::addVertex(const Note &note)
{
    MoveItem *item = new MoveItem();
    item->setPos(randomBetween(30, 470), randomBetween(30, 470));
    scene->addItem(item);
    item->setupMoveItem(note);
}

void GraphWidget::removeVertex(int id)
{

}

void GraphWidget::renameVertex(int id)
{
}

void GraphWidget::on_pushButton_clicked()
{
    qDebug() << "Aaaaaaaaaaaaaaaaa";
}
