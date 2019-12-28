#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mapboard = new MapBoard;
    ui->MapArea->setWidget(mapboard);

    connect(this,SIGNAL(notes(List)),this->mapboard->getMapnotes(),SLOT(updateNotes(List)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    List list;
    list.ListInsert(1,1);
    list.ListInsert(2,2);
    list.ListInsert(3,3);
    emit notes(list);
}
