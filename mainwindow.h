#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mapboard.h>
#include <iostream>
#include <QPaintEvent>
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

    void on_Route_clicked();

    void on_Clear_clicked();

private:
    Ui::MainWindow *ui;
    MapBoard *mapboard;
};

#endif // MAINWINDOW_H
