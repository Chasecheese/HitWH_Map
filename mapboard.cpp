#include "mapboard.h"
#include "ui_mapboard.h"

MapBoard::MapBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapBoard)
{
    ui->setupUi(this);
    mapnotes = new MapNotes;
    ui->Board->addWidget(mapnotes);
    connect(this->mapnotes,SIGNAL(updateName(string)),this,SLOT(updateText(string)));
}

void MapBoard::updateBoard(){
    mapnotes->updateMapNotes();
}

void MapBoard::clear(){
    mapnotes->clear();
    mapnotes->updateMapNotes();
}

MapBoard::~MapBoard()
{
    delete ui;
}

void MapBoard::on_clear_clicked()
{
    clear();
}

void MapBoard::on_route_clicked()
{
    updateBoard();
}
void MapBoard::updateText(string name){
    this->ui->textEdit->setText(QString::fromStdString(name));
}
