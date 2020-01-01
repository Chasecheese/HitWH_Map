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

    MapNotes *getMapnotes() const;
    void setMapnotes(MapNotes *value);

private slots:

    void updateText(string);
signals:
    void sendname(string); //发送edittext的内容
private:
    Ui::MapBoard *ui;
    MapNotes* mapnotes;

};

#endif // MAPBOARD_H
