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

private:
    Ui::MapBoard *ui;
    MapNotes* mapnotes;

};

#endif // MAPBOARD_H
