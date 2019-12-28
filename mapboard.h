#ifndef MAPBOARD_H
#define MAPBOARD_H

#include <QWidget>
#include <mapnotes.h>


namespace Ui {
class MapBoard;
}

class MapBoard : public QWidget
{
    Q_OBJECT

public:

    explicit MapBoard(QWidget *parent = nullptr);
    void updateBoard();
    void clear();
    ~MapBoard();

private slots:
    void on_clear_clicked();

    void on_route_clicked();

    void updateText(string);
private:
    Ui::MapBoard *ui;
    MapNotes* mapnotes;

};

#endif // MAPBOARD_H
