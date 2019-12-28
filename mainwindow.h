﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mapboard.h>
#include <iostream>
#include <QPaintEvent>
#include <list.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

signals:
    void notes(List);
private:
    Ui::MainWindow *ui;
    MapBoard *mapboard;
};

#endif // MAINWINDOW_H
