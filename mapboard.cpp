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

void MapBoard::updateText(string name){
    emit sendname(name);
}

MapNotes *MapBoard::getMapnotes() const
{
    return mapnotes;
}

void MapBoard::setMapnotes(MapNotes *value)
{
    mapnotes = value;
}
