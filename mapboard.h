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
    MapNotes* mapnotes;
    explicit MapBoard(QWidget *parent = nullptr);
    void updateBoard();
    ~MapBoard();

private:
    Ui::MapBoard *ui;
};

#endif // MAPBOARD_H
