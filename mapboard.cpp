#include "mapboard.h"
#include "ui_mapboard.h"

MapBoard::MapBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapBoard)
{
    ui->setupUi(this);
    mapnotes = new MapNotes;
    ui->Board->addWidget(mapnotes);
}

void MapBoard::updateBoard(){
    mapnotes->updateMapNotes();
}

MapBoard::~MapBoard()
{
    delete ui;
}
