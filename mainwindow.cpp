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
    connect(this->mapboard,SIGNAL(sendname(string)),this,SLOT(showRoute(string)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showRoute(string route){
    this->ui->textEdit->setText(QString::fromStdString(route));
}

void MainWindow::on_Route_clicked()
{
    this->mapboard->updateBoard();
}

void MainWindow::on_Clear_clicked()
{
    this->mapboard->clear();
}

