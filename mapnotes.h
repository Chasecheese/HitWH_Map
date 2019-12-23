#ifndef MAPNOTES_H
#define MAPNOTES_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <route.h>
#include <vector>
#include <QMouseEvent>
using namespace std;

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
    void mousePressEvent(QMouseEvent *event);
    vector<int> location;
    vector<Road> re;
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
