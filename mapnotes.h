#ifndef MAPNOTES_H
#define MAPNOTES_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <route.h>

namespace Ui {
class MapNotes;
}

class MapNotes : public QWidget
{
    Q_OBJECT

public:
    explicit MapNotes(QWidget *parent = nullptr);
    void updateMapNotes();
    void paintEvent(QPaintEvent *);
    int location[10];
    int roadCo[10];
    ~MapNotes();

private slots:
    void on_BulidH_clicked();

    void on_BulidY_clicked();

    void on_BuildT_clicked();

private:
    Ui::MapNotes *ui;
    Route route;
};

#endif // MAPNOTES_H
